class yzel{
	public:
	int type;
	int value;
	yzel* left;//числитель, если не дробь, то то, что ближе, в случае функций, аргумент
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
