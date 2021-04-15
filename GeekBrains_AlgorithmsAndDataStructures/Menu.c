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

	_numberHomeWork = GetInt("Enter the homework number(1-4): ", 1, 1, 1, 4);

	
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
	case 4:
		StartHomeWorkNumber4();
		break;
	case 5:
		StartHomeWorkNumber5();
		break;
	default:
		printf("This task has not yet been completed :(");
		break;
	}



	printf("\n");
	system("pause");


}