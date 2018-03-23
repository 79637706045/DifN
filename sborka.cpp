#include <iostream>        // ����� ������  
#include <fstream>         // ��� ������ � ������ 
#include <strings.h>       // ��� ������ �� ��������  

/*

��� 0 -- �����, �������� ����� -- �����
��� 1 -- ��������, �������� 0 -- ����, 1 -- �����, 2 -- ��������, 3 -- ���������
��� 2 -- ����������, �������� ���������� ����� ����������
��� 3 -- �������, �������� 0 -- ��������, 1 -- �����

*/

class yzel{
	public:
	int type;
	int value;
	yzel* left;//, ���� �� �����, �� ��, ��� �����, � ������ �������, ��������
	yzel* right;//�����������, ���� �� �����, � ��, ��� ������, � ������ ������� -- ����
	
	//����������� � ����������
	yzel(int tip, int znach){
		type = tip;
		value = znach;
		left = NULL;
		right = NULL;
		std::cerr<<"New element created."<<std::endl;
	}
	~yzel(){
		std::cerr<<"One element deleted."<<std::endl;
	}

};

/* ����� ���� ����� ����� � ����� ������� */
class sTree{
	//������ ������
	yzel* root;
	
	
	void delete_tree(yzel* cur);
	
	void view(yzel* cur, int level);
	
	void x_search(yzel* tempr, int* counter);
	
	void rek_d(yzel* stemp, yzel* ftemp);
	
	
	void copy(yzel* stemp, yzel* ftemp);

	
	public:

	//����������� � ����������
	sTree(int tip, int znach){
		std::cerr<<"Vyzvan konstryktor dly classa dif."<<std::endl;
		root = new yzel(tip, znach);
		std::cerr<<"Konstryktor otrabotal"<<std::endl;
	}
	~sTree(){
		std::cerr<<"Vyzvan distryktor dly classa dif."<<std::endl;
		delete_tree(this->root);
		std::cerr<<"Distryktor otrabotal"<<std::endl;
	}
		
	void sozdanye_bazovogo_dereva();

	void print_dif();
	
	sTree* differentiate();
};



int main(){

	std::cout<<"Sozdanie bazovogo dereva"<<std::endl;
	sTree F(-1,-1);
	F.sozdanye_bazovogo_dereva();
	std::cout<<"Bazovoe derevo:"<<std::endl;
	F.print_dif();
	
	std::cout<<"Sozdanie differencirovannogo dereva"<<std::endl;
	sTree* pS = F.differentiate();
	std::cout<<"Ddifferencirovannoe derevo:"<<std::endl;
	pS->print_dif();
	
	delete(pS);
	return 0;
}

void sTree::rek_d(yzel* stemp, yzel* ftemp){
		switch (ftemp->type){
/*****************************************/			
			case 0 : {//�����
			
       		stemp->type = 0;
       		stemp->value = 0;
       		
			break;
			}
/****************************************/			
			case 1: {//��������
				
				switch(ftemp->value){
					
					case 0 : {//��������
						
						stemp->type = 1;
						stemp->value = 0;
						
						stemp->left = new yzel(-1,-1);
						stemp->right = new yzel(-1,-1);
						
						rek_d(stemp->left, ftemp->left);
						rek_d(stemp->right, ftemp->right);
						break;
					}	
					
					case 1 : {//���������
						
						stemp->type = 1;
						stemp->value = 1;
						
						stemp->left = new yzel(-1,-1);
						stemp->right = new yzel(-1,-1);
						
						rek_d(stemp->left, ftemp->left);
						rek_d(stemp->right, ftemp->right);
						break;
					}
					
					case 2 : {//���������
						
						stemp->type = 1;
						stemp->value = 0;
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 2;
						
						stemp->right = new yzel(-1,-1);
						stemp->right->type = 1;
						stemp->right->value = 2;
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->right = new yzel(-1,-1);
						rek_d(stemp->left->left, ftemp->left);
						copy(stemp->left->right, ftemp->right);
						
						stemp->right->left = new yzel(-1,-1);
						stemp->right->right = new yzel(-1,-1);
						copy(stemp->right->left, ftemp->left);
						rek_d(stemp->right->right, ftemp->right);
						
						break;
					}
					
					case 3 : {//�������
						
						stemp->type = 1;
						stemp->value = 3;
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 1;
						
						stemp->right = new yzel(-1,-1);
						stemp->right->type = 1;
						stemp->right->value = 2;
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->right = new yzel(-1,-1);
						stemp->left->left->type = 1;
						stemp->left->left->value = 2;
						stemp->left->right->type = 1;
						stemp->left->right->value = 2;
						
						stemp->right->left = new yzel(-1,-1);
						stemp->right->right = new yzel(-1,-1);
						copy(stemp->right->left, ftemp->right);
						copy(stemp->right->right, ftemp->right);
						
						stemp->left->left->left = new yzel(-1,-1);
						stemp->left->left->right = new yzel(-1,-1);
						stemp->left->right->left = new yzel(-1,-1);
						stemp->left->right->right = new yzel(-1,-1);
						rek_d(stemp->left->left->left, ftemp->left);
						copy(stemp->left->left->right, ftemp->right);
						copy(stemp->left->right->left, ftemp->left);
						rek_d(stemp->left->right->right, ftemp->right);
						
						break;
					}
					
					default: {        	
    		
       					std::cout<<"ERROR, incorrect value, of the element"<<std::endl;
       		
						break;
					}
				
				};
					
			break;
			}
/**************************************/

			case 2 : {//����������  x1, x2, x3 ...
			
       		stemp->type = 0;
       		stemp->value = 1;
       		
			break;
			}
			
/************************************/
			case 3 : {//�������
			
					switch(ftemp->value){
					
					case 0 : {//ln
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
							
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 3;
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->left->type = 0;
						stemp->left->left->value = 1;
						
						stemp->left->right = new yzel(-1,-1);
						copy(stemp->left->right, ftemp->left);
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;
						/*
						stemp->right = new yzel(-1,-1);
						copy(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 0;
						stemp->left->value = 1;*/
						
						}
						
						break;
					}	
					
					case 1 : {//sin
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
						
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 3;
						stemp->left->value = 2;
						stemp->left->right = NULL;
						
						stemp->left->left = new yzel(-1,-1);
						
						copy(stemp->left->left, ftemp->left);
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;
						
						}
						
						break;
					}
					
					case 2 : {//cos
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
						
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 2;
						
						stemp->left->right = new yzel(-1,-1);
						stemp->left->right->type = 3;
						stemp->left->right->value = 1;
						
						stemp->left->right->right = NULL;
						
						stemp->left->right->left = new yzel(-1,-1);
						copy(stemp->left->right->left, ftemp->left);
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->left->type = 0;
						stemp->left->left->value = -1;
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;

						}
						
						break;
					}
					
					case 3 : {//exp
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
							
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 3;
						
						stemp->left->right = NULL;
						
						stemp->left->left = new yzel(-1,-1);
						copy(stemp->left->left, ftemp->left);
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;
						}
						
						break;
					}
					
					
					default: {        	
    		
       					std::cout<<"ERROR, incorrect value, of the element"<<std::endl;
       		
						break;
					};
				
					};
					
       		
			break;
			}
			
/****************************************/			
			
    		default: {        	
    		
       		std::cout<<"ERROR, incorrect type, of the element"<<std::endl;
       		
			break;
			}
				
		};
	}

void sTree::print_dif(){
	view(root,0);
	std::cout<<std::endl;
}

sTree* sTree::differentiate(){
		
	sTree* pS = new sTree(-1,-1);
			
	rek_d(pS->root, this->root);
	
	puts(" ");
	return pS;
}

void sTree::x_search(yzel* tempr, int* counter){
	if(tempr){
		if(tempr->type == 2){
			(*counter)++;
		}
	x_search(tempr->left, counter);
	x_search(tempr->right, counter);
	}
}

void sTree::delete_tree(yzel* cur){
	if(cur){
		delete_tree(cur->left);
		delete_tree(cur->right);
		delete(cur);
	}
}

void sTree::copy(yzel* stemp, yzel* ftemp){
		if(ftemp){
			
			stemp->type = ftemp->type;
			stemp->value = ftemp->value;
			
			if(ftemp->left != NULL){
				stemp->left = new yzel(-1,-1);
			}
			
			if(ftemp->right != NULL){
				stemp->right = new yzel(-1,-1);
			}
			
			copy(stemp->left, ftemp->left);
			copy(stemp->right, ftemp->right);
		}
}

void sTree::view(yzel* cur, int level){//����������� ���������� � ����������� ��������������
		if(cur){
			view(cur->right , level+1);//����� ������� ���������
			for(int i = 0; i<level; i++){
				std::cout<<"                     ";
			} 	
		
			std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;

			view(cur->left , level+1);//����� ������ ���������
		}
}


void sTree::sozdanye_bazovogo_dereva(){
	
/*
������ ������:
 $((ln(2))*x)+(sin(x))/48))$
 */
 /*this ����� type 1; value 0;*/
	
	this->root->type = 1;
	this->root->value = 0;
	
	this->root->left = new yzel(1,2);
	this->root->left->left = new yzel(3,0);
	this->root->left->right = new yzel(2,0);
	this->root->left->left->left = new yzel(0,2);
	this->root->left->left->right = NULL;
	
	this->root->right = new yzel(1,3);
	this->root->right->left = new yzel(3,1);
	this->root->right->right = new yzel(0,48);
	this->root->right->left->left = new yzel(2,0);
	this->root->left->left->right = NULL;
}
	
