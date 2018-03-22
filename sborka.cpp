#include <iostream>        // Ввода вывода  
#include <fstream>         // Для работа с фалами 
#include <strings.h>       // Для работы со строками  

/*

тип 0 -- цифры, значение любое -- число
тип 1 -- действие, значение 0 -- плюс, 1 -- минус, 2 -- умножить, 3 -- разделить
тип 2 -- переменная, значение порядковый номер переменной
тип 3 -- функция, значение 0 -- логарифм, 1 -- синус

*/

class yzel{
	public:
	int type;
	int value;
	yzel* left;//, если не дробь, то то, что ближе, в случае функций, аргумент
	yzel* right;//знаменатель, если не дробь, т то, что дальше, в случае функций -- нулл
	
	//конструктор и диструктор
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


class sTree{
	//данные класса
	yzel* root;
	
	
	void delete_tree(yzel* cur){
		if(cur){
			delete_tree(cur->left);
			delete_tree(cur->right);
			delete(cur);
		}
	}
	
	void view(yzel* cur, int level);
	
	void rek_d(sTree* stemp, sTree* ftemp){
		;
	}
/*	void reck_for_dif(sTree* temp){
		//в неу вузувать функксии для диффинга некоторых вещей
	}*/
	
	public:

	//конструктор и деструктор
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
	
	sTree* differentiate(){//ranche differ
	/* План: для кажого узла вызывать функцию дифференциате, котораю и трансформирует узел,
	может она и что-то возваращать, когда умножить и поделить. */
		
		sTree* pS = new sTree(0,0);
			
		rek_d(pS, this);
	
		puts(" ");
		return pS;
	}
};



int main(){

	std::cout<<"Sozdanie bazovogo dereva"<<std::endl;
	sTree F(0,0);
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

void sTree::view(yzel* cur, int level){//рекурсивная распечатка с графическим представлением
		if(cur){
			view(cur->right , level+1);//вывод правого поддерева
			for(int i = 0; i<level; i++){
				std::cout<<"                     ";
			} 	
		
			std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;

			view(cur->left , level+1);//вывод левого поддерева
		}
}


void sTree::sozdanye_bazovogo_dereva(){
	
/*
Строит дерево:
 $((ln(2))*x)+(sin(x))/48))$
 */
 /*this имеет type 1; value 0;*/
	
	this->root->type = 1;
	this->root->value = 0;
	
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
	
