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
	int type;
	int value;
	yzel* left;//���������, ���� �� �����, �� ��, ��� �����, � ������ �������, ��������
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
