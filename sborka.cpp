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
/**************************/
class sTree{
	//������ ������
	yzel* root;
	
	
	void delete_tree(yzel* cur){
		if(cur){
			delete_tree(cur->left);
			delete_tree(cur->right);
			delete(cur);
		}
	}
	
	void view(yzel* cur, int level);
	
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

	void print_dif(){
		view(root,0);
		std::cout<<std::endl;
	}
	
	
};





int main(){

	sTree L(1,0);
	L.print_dif();
	L.sozdanye_bazovogo_dereva();
	L.print_dif();
	return 0;
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
	
	
	this->root->left = new yzel(1,2);
	this->root->left->left = new yzel(3,0);
	this->root->left->right = new yzel(2,0);
	this->root->left->left->left = new yzel(0,2);
	this->root->left->left->right = NULL;
	
	this->root->right = new yzel(1,3);
	this->root->right->left = new yzel(3,2);
	this->root->right->right = new yzel(0,48);
	this->root->right->left->left = new yzel(2,0);
	this->root->left->left->right = NULL;
}
	