//Коротких Марк Александрович

#include "Graph.h"

/// <summary>1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.</summary>
/// <returns></returns>
void Solution_7_1() {

    int** _myMatrix,
        _sizeMatrix;

    char* _fileName = "MyMatrix.txt";


    _myMatrix = ReadGraph(_fileName, &_sizeMatrix);

    PrintGraph(_sizeMatrix, _sizeMatrix, _myMatrix);

}

/// <summary>2. Написать рекурсивную функцию обхода графа в глубину.</summary>
/// <returns></returns>
void Solution_7_2() {

    int** _myMatrix,
        _sizeMatrix,
        _start = 2,
        _visited = 0;

    char* _fileName = "MyMatrixDeep.txt";
    

    _myMatrix = ReadGraph(_fileName, &_sizeMatrix);

    PrintGraph(_sizeMatrix, _sizeMatrix, _myMatrix);

    printf("\n");

    StepInDeepGraph(_sizeMatrix, _start, _myMatrix, _visited);

}

/// <summary>3. Написать функцию обхода графа в ширину.</summary>
/// <returns></returns>
void Solution_7_3() {

    int** _myMatrix,
        _sizeMatrix,
        _start = 2,
        _visited = 0;

    char* _fileName = "MyMatrixWidth.txt";
    

    _myMatrix = ReadGraph(_fileName, &_sizeMatrix);

    PrintGraph(_sizeMatrix, _sizeMatrix, _myMatrix);

    printf("\n");

    StepInWidthGraph(_sizeMatrix, _start, _myMatrix, _visited);

}

int StartHomeWorkNumber7()
{

    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-4): ", 1, 1, 1, 3);

    switch (_numberTask)
    {
    case 1:
        Solution_7_1();
        break;
    case 2:
        Solution_7_2();
        break;
    case 3:
        Solution_7_3();
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    return 1;
}