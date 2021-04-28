#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include "Helper.h"
#include <string.h>


int main(int argc, char** argv)
{
	char* locale = setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	
	int _numberHomeWork;

	_numberHomeWork = GetInt("Enter the homework number(1-8): ", 1, 1, 1, 8);

	
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
	case 6:
		StartHomeWorkNumber6(argc, argv);
		break;
	case 7:
		StartHomeWorkNumber7();
		break;
	case 8:
		StartHomeWorkNumber8();
		break;
	default:
		printf("This task has not yet been completed :(");
		break;
	}



	printf("\n");
	system("pause");


}