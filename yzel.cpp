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
