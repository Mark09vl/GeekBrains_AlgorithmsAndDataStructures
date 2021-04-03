//Коротких Марк Александрович

#include <stdio.h>
//#include "Helper.h"
#include <string.h>
#include <time.h>

/// <summary>1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где
/// m - масса тела в килограммах, h - рост в метрах.</summary>
/// <returns></returns>
void Solution1() {

    double _weight, _height;
    

    _height = GetDouble("Enter height: ", 1, 0.01);

    _weight = GetDouble("Enter weight: ", 1, 0.01);

    printf("Index = %0.3f", _weight / ((_height / 100) * (_height / 100)));
}

/// <summary>2. Найти максимальное из четырех чисел. Массивы не использовать.</summary>
/// <returns></returns>
void Solution2() {

    int _value1, _value2, _value3, _value4, _result = 0;


    _value1 = GetInt("Enter value 1: ", 0, 0, 0, 0);

    _value2 = GetInt("Enter value 2: ", 0, 0, 0, 0);

    _value3 = GetInt("Enter value 3: ", 0, 0, 0, 0);

    _value4 = GetInt("Enter value 4: ", 0, 0, 0, 0);

    
    /*if (_result < _value1)
        _result = _value1;*/
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

/// <summary>4. Написать программу нахождения корней заданного квадратного уравнения.</summary>
/// <returns></returns>
void Solution4() {

}

/// <summary>5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.</summary>
/// <returns></returns>
void Solution5() {

    int _value;

    _value = GetInt("Enter month: ", 1, 1, 1, 12);

    if (_value >= 1 && _value <= 2
        || _value == 12)
    {
        printf("Winter");
    }
    else if (_value >= 3 && _value <= 5) {
        printf("Spring");
    }
    else if (_value >= 6 && _value <= 8) {
        printf("Summer");
    }
    else {
        printf("Autumn");
    }
}

/// <summary>6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».</summary>
/// <returns></returns>
void Solution6() {
    int _value, _penultValue, _lastValue;

    _value = GetInt("Enter age: ", 1, 1, 1, 150);

    _penultValue = ((_value - (_value % 10)) - (_value - (_value % 100))) / 10;
    _lastValue = _value % 10;

    char* _endWord = "";

    if (_penultValue == 1 || _lastValue == 0
        || ((_lastValue == 0 || _lastValue > 4) && _penultValue != 1)) {
        _endWord = "лет";
    }
    else if (_lastValue > 1 && _lastValue < 5) {
        _endWord = "года";
    }
    else {
        _endWord = "год";
    };

    printf("%d %s", _value, _endWord);
}

/// <summary>7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся поля к одному цвету или нет.</summary>
/// <returns></returns>
void Solution7() {

}

/// <summary>8. Ввести a и b и вывести квадраты и кубы чисел от a до b.</summary>
/// <returns></returns>
void Solution8() {

    int _lastValue, _firstValue, _tempValue, _resultValue;

    while (1) {
        _firstValue = GetInt("Enter value A: ", 0, 0, 0, 0);
        _lastValue = GetInt("Enter value B: ", 0, 0, 0, 0);

        if (_firstValue >= _lastValue) {
            printf("Incorrect value! A must be more than B!\n\n");
        }
        else {
            break;
        }
    }

    _tempValue = _firstValue;

    printf("\n\n");
    printf("%-10s|%10s\n", "x^2", "x^3");
    printf("%-10s|%10s\n", "---", "---");

    while (_tempValue != _lastValue) {

        _resultValue = _tempValue * _tempValue;

        printf("%-10d|%10d\n", _resultValue, _resultValue * _tempValue);

        _tempValue++;
    }

}

/// <summary>9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.</summary>
/// <returns></returns>
void Solution9() {

}

/// <summary>10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.</summary>
/// <returns></returns>
void Solution10() {

}

/// <summary>11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.</summary>
/// <returns></returns>
void Solution11() {

    double ENDVALUE = 0, _allValue = 0, _tempValue, i = 0;


    while (1)
    {

        _tempValue = GetDouble("Enter value: ", 1, 0);

        if (_tempValue == ENDVALUE)
        {
            break;
        }

        _allValue = _allValue + _tempValue;

        i++;
        
    }

    if (i == 0)
    {
        printf("%.3f", 0.000);
    }
    else {
        printf("%.3f", (_allValue / i));
    }

}

/// <summary>12. Написать функцию нахождения максимального из трех чисел.</summary>
/// <returns></returns>
void Solution12() {

    int _value1, _value2, _value3;

    _value1 = GetInt("Enter value 1: ", 0, 0, 0, 0);
    _value2 = GetInt("Enter value 2: ", 0, 0, 0, 0);
    _value3 = GetInt("Enter value 3: ", 0, 0, 0, 0);

    printf("%d", SearchMaxValue(_value1, _value2, _value3));

}

/// <summary>Функция нахождения максимального из трех чисел.</summary>
/// <returns></returns>
int SearchMaxValue(int value1, int value2, int value3) {

    int result = 0;

    /*if (result < value1)
        result = value1;*/
    result = value1;

    if (result < value2)
        result = value2;

    if (result < value3)
        result = value3;

    return result;

}

/// <summary>13. * Написать функцию, генерирующую случайное число от 1 до 100.
/// а) с использованием стандартной функции rand();
/// б) без использования стандартной функции rand(). </summary>
/// <returns></returns>
void Solution13() {
    
    int _time = (int)time(NULL);

    char* _charTime = _time;

    printf("%d", (int)&_charTime % 100);

}

/// <summary>14. *Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. Например, 252 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.</summary>
/// <returns></returns>
void Solution14() {

}


int StartHomeWorkNumber1()
{
    
    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-14): ", 1, 1, 1, 14);
    
    switch (_numberTask)
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
    /*case 4:
        Solution4();
        break;*/
    case 5:
        Solution5();
        break;
    case 6:
        Solution6();
        break;
    /*case 7:
        Solution8();
        break;*/
    case 8:
        Solution8();
        break;
    /*case 9:
        Solution9();
        break;*/
    /*case 10:
        Solution10();
        break;*/
    case 11:
        Solution11();
        break;
    case 12:
        Solution12();
        break;
    case 13:
        Solution13();
        break;
    /*case 14:
        Solution14();
        break;*/
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    
    

    printf("\n");
    system("pause");
    
    return 1;
}

