//Коротких Марк Александрович

#define _CRT_SECURE_NO_WARNINGS
#include "QueueWork6.h"
#include "Bitree.h"
#include "dbTree.h"

int HashFunction(char* str, int len)
{
    int _seed = 72231;
    int _hash = 0;

    for (int i = 0; i < len; str++, i++)
    {
        _hash = (_hash + _seed) + *str + i;
    }
    return _hash;
}

/// <summary>1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.</summary>
/// <returns></returns>
void Solution_6_1() {

    char* str = "String for my hash function.";
    printf("String = %s\nHash = %d", str, HashFunction(str, strlen(str)));

}

/// <summary>Переписать программу, реализующую двоичное дерево поиска.</summary>
/// а) Добавить в него обход дерева различными способами;
/// б) Реализовать поиск в двоичном дереве поиска;
/// в) *Добавить в программу обработку командной строки с помощью которой можно указывать из какого файла считывать данные, каким образом обходить дерево.
/// <returns></returns>
void Solution_6_2(int argc, char** argv) {

	biNode* _tree1 = NULL;
	char* _filename = "";
	int _sortSwitch = 1,
		_value,
		_idx = 0;

	if (argc <= 1 || !strcmp(argv[1], "--help")) {

		printf("%s --help or\n%s --file filename --travers [1..7]\n", argv[0], argv[0]);
		printf("\t filename - the file must contain int numbers. One number is one line.\n");
		printf("\t default travers: 1 - pre order\n");
		printf("\t travers: 2 - post order\n");
		printf("\t travers: 3 - in order\n");
		printf("\t travers: 4 - inter pre order\n");
		printf("\t travers: 5 - inter in order\n");
		printf("\t travers: 6 - inter post order\n");
		printf("\t travers: 7 - width travers\n");

		return 0;
	}
	if (argc > 1 && argc == 3) {
		
		if (!strcmp(argv[1], "--file")) {
			
			if (argv[2] != NULL) {
				
				_filename = argv[2];

			}
			else {
				
				printf("'--file' requered file name.\n");
				
				return -1;

			}
		}
		else {
			
			printf("Unknown parameter: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
			
			return -1;

		}
	}
	else if (argc > 2 && argc == 5) {
		
		if (!strcmp(argv[1], "--file") && !strcmp(argv[3], "--travers")) {
			
			if (argv[2] != NULL) {
				
				_filename = argv[2];

			}
			else {
				
				printf("'--file' requered file name.\n");
				
				return -1;

			}
			if (sscanf(argv[4], "%d", &_idx) == 1) {
				
				if (_idx >= 1 && _idx <= 7) {
					
					_sortSwitch = _idx;
				
				}
				else {
					
					printf("'--travers' requered one int parametrs between 1 to 7.\n");
					
					return -1;

				}
			}
			else {
				
				printf("'--travers' requered one int parametrs between 1 to 7.\n");
				
				return -1;

			}
		}
		else {
			
			printf("Unknown parameter: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
			
			return -1;

		}
	}
	else {
		
		printf("Unknown parameter(s). Type %s --help for help.\n", argv[0]);
		
		return -1;

	}

	printf("file name: %s\tsortSwitch: %d\n\n", _filename, _sortSwitch);


	FILE* file = fopen(_filename, "r");
	if (file == NULL) {
		
		printf("Can't open file.\n");

		exit(-1);

	}

	int tmp = 0;
	while (!feof(file)) {
		
		fscanf(file, "%d", &_value);

		if (tmp != _value) {
			
			insertBiNode(&_tree1, _value);

		}
		
		tmp = _value;

	}
	
	fclose(file);


	print_tree(_tree1);

	switch (_sortSwitch) {
	case 1:
		printf("\nPre Order\n");
		preorder_travers(_tree1);
		break;
	case 2:
		printf("\nPost Order\n");
		postorder_travers(_tree1);
		break;
	case 3:
		printf("\nIn Order\n");
		inorder_travers(_tree1);
		break;
	case 4:
		printf("\nInter Pre Order\n");
		iterpreorder_travers(_tree1);
		break;
	case 5:
		printf("\nInter In Order\n");
		iterinorder_travers(_tree1);
		break;
	case 6:
		printf("\nInter Post Order\n");
		iterpostorder_travers(_tree1);
		break;
	case 7:
		printf("\nWidth Travers\n");
		width_travers(_tree1);
		break;
	default:
		printf("\nPre Order\n");
		preorder_travers(_tree1);
		break;

	}

	printf("\nSearch 8\n");

	biNode* _sBiNode = getBiNodeByValue(_tree1, 8);
	print_tree(_sBiNode);
	printf("\n");

	return 0;

}

/// <summary>3. *Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер», в которой использовать все знания, полученные на уроках.</summary>
/// Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес).
/// <returns></returns>
void Solution_6_3() {

	dbNode* _stdDb = create_dbNode("Mark", 24, 1);
	
	insertDbNode(&_stdDb, "Pavel", 35, 2);
	insertDbNode(&_stdDb, "Nikita", 26, 3);
	insertDbNode(&_stdDb, "Ruslan", 24, 4);

	printDb(_stdDb);
	printf("\n");

	printf("Search by Name:\t");
	getDbNodeByName(_stdDb, "Mark");

	printf("Search by Age:\t");
	getDbNodeByAge(_stdDb, 24);
	printf("\n");

}

int StartHomeWorkNumber6(int argc, char** argv)
{


    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-3): ", 1, 1, 1, 3);


    switch (_numberTask)
    {
    case 1:
        Solution_6_1();
        break;
    case 2:
        Solution_6_2(argc, argv);
        break;
    case 3:
        Solution_6_3();
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }


}