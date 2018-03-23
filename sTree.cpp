class sTree{
	//данные класса
	yzel* root;
	
	
	void delete_tree(yzel* cur);
	
	void view(yzel* cur, int level);
	
	void x_search(yzel* tempr, int* counter);
	
	void rek_d(yzel* stemp, yzel* ftemp);
	
	
	void copy(yzel* stemp, yzel* ftemp);

	
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

	void print_dif();
	
	sTree* differentiate();
};
