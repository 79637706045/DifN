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
