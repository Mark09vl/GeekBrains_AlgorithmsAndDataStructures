#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include "Helper.h"
#include <string.h>


int main(void)
{
	char* locale = setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	
	int _numberHomeWork;

	_numberHomeWork = GetInt("Enter the homework number(1-3): ", 1, 1, 1, 3);

	
	switch (_numberHomeWork)
	{
	case 1:
		StartHomeWorkNumber1();
		break;
	case 2:
		StartHomeWorkNumber2();
		break;
	case 3:
		StartHomeWorkNumber3();
		break;
	default:
		printf("This task has not yet been completed :(");
		break;
	}



	printf("\n");
	system("pause");


}