//Коротких Марк Александрович

#include <stdio.h>
#include "Helper.h"


/// <summary>1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где
/// m - масса тела в килограммах, h - рост в метрах.</summary>
/// <returns></returns>
void Solution1() {

    double _weight, _height;
    

    _height = GetDouble("Enter height: ", 1, 0.01);

    _weight = GetDouble("Enter weight: ", 1, 0.01);

    printf("Index = %lf", _weight / ((_height / 100) * (_height / 100)));
}

/// <summary>2. Найти максимальное из четырех чисел. Массивы не использовать.</summary>
/// <returns></returns>
void Solution2() {

    int _value1, _value2, _value3, _value4, _result = 0;


    _value1 = GetInt("Enter value 1: ", 0, 0, 0, 0);

    _value2 = GetInt("Enter value 2: ", 0, 0, 0, 0);

    _value3 = GetInt("Enter value 1: ", 0, 0, 0, 0);

    _value4 = GetInt("Enter value 2: ", 0, 0, 0, 0);

    
    if (_result < _value1)
        _result = _value1;
    
    if (_result < _value2)
        _result = _value2;
    
    if (_result < _value3)
        _result = _value3;

    if (_result < _value4)
        _result = _value4;

    printf("Max value = %d", _result);

}

/// <summary>3. Написать программу обмена значениями двух целочисленных переменных.</summary>
/// <returns></returns>
void Solution3() {

    int _value1, _value2;


    _value1 = GetInt("Enter value 1: ", 0, 0, 0, 0);
    
    _value2 = GetInt("Enter value 2: ", 0, 0, 0, 0);

    
    _value1 = _value1 + _value2;
    _value2 = _value1 - _value2;
    _value1 = _value1 - _value2;

    printf("Value 1 = %d\n", _value1);
    printf("Value 2 = %d", _value2);

}


int main(void)
{
    int numberTask;

    numberTask = GetInt("Enter the task number(1-14): ", 1, 1, 1, 14);
    
    switch (numberTask)
    {
    case 1:
        Solution1();
        break;
    case 2:
        Solution2();
        break;
    case 3:
        Solution3();
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    
    

    printf("\n");
    system("pause");
    
    return 0;
}

