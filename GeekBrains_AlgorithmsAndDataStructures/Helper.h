//Коротких Марк Александрович

#pragma warning(disable : 4996)
#include <stdio.h>


double GetDouble(char *text, int checkMinValue, double minValue) {

    double _result;
    int validation;

    while (1) {
        printf("%s", text);

        validation = scanf("%lf", &_result);        
        if (!validation ||
            (checkMinValue && _result < minValue)) {
            printf("Incorrect value!\n\n");
        }
        else {
            break;
        }
    }

    return _result;
}

int GetInt(char* text, int checkMinValue, int minValue, int checkMaxValue, int maxValue) {

    int _result, validation;
    while (1) {
        printf("%s", text);
        validation = scanf("%d", &_result);
        if (!validation ||
            (checkMinValue && _result < minValue)
            || (checkMaxValue && _result > maxValue)) {
            printf("Incorrect value!\n\n");
        }
        else {
            break;
        }
    }

    return _result;
}

char* GetChar(char* text, int checkMinRange, int minRange, int checkMaxRange, int maxRange) {

    char* _result;
    int validation;

    while (1) {
        printf("%s", text);
        validation = scanf("%s", &_result);
        int length = strlen(&_result);
        if (!validation ||
            (checkMinRange && length < minRange)
            || (checkMaxRange && length > maxRange)) {
            printf("Incorrect value!\n\n");
        }
        else {
            break;
        }
    }

    return _result;
}

void CopyIntArray(int* array, int* newArray, int arrLength) {
    for (size_t i = 0; i < arrLength; i++)
    {
        newArray[i] = array[i];
    }
}

void printarray(int* arr, int len)
{
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%2i", arr[i]);
        if (i + 1 < len) {
            printf(", ");
        }
    }
    printf("]\n");
}

//srand(time(NULL));
void fill_array(int* arr, int len)
{
    //srand(time(NULL));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

void printmatrix(int n, int m, int** a)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}

/*
* swap function
*/
void swap(int* x, int* y)
{
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;

}

