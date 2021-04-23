//Коротких Марк Александрович

#include <time.h>
#define ARRLENGTH 15



void SwapValue(int* a, int* b)
{
    int _c = *a;
    *a = *b;
    *b = _c;
}

int BubbleSort(int* array, int arrLength)
{
    int _index = 0,
        _length = arrLength;

    for (int i = 1; i < _length; i++)
    {
        
        for (int j = 0; j < (_length - i); j++)
        {
            
            if (array[j] < array[j + 1])
            {
                
                SwapValue(&array[j], &array[j + 1]);
                _index++;

            }

        }

    }

    return _index;

}

int BubbleSort_Optimized(int* array, int arrLength)
{
    int _index = 0,
        _maxIndex = 0;
    
    for (int i = 0; i < arrLength - 1; i++)
    {
        
        _maxIndex = i;

        for (int j = i + 1; j < arrLength; j++)
        {
            
            if (array[_maxIndex] < array[j])
            {
                _maxIndex = j;
            }

        }

        SwapValue(&array[_maxIndex], &array[i]);

        _index++;

    }

    return _index;

}

/// <summary>1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.</summary>
/// <returns></returns>
void Solution_3_1(int* array, int* array1, int* array2, int arrLength) {

    int _length = arrLength;

    printf("\nBubbleSort: %d\n", BubbleSort(array1, _length));
    printf("BubbleSort_Optimized: %d\n", BubbleSort_Optimized(array2, _length));

    for (size_t i = 0; i < _length; i++)
    {

        printf("%-5d|%5d|%5d\n", array[i], array1[i], array2[i]);

    }

}

/// <summary>2. *Реализовать шейкерную сортировку.</summary>
/// <returns></returns>
void Solution_3_2(int* array, int* array1, int arrLength) {

    int _length = arrLength,
        _firstItem = 0,
        _lastItem = _length - 1;

    while (_firstItem < _lastItem)
    {
        
        for (int i = _firstItem; i < _lastItem; i++)
        {
            if (array[i] > array[i + 1]) { 
                
                SwapValue(&array[i], &array[i + 1]);

            }
        }

        _lastItem -= 1;


        for (int i = _lastItem; i > _firstItem; i--)
        {
            if (array[i] < array[i - 1]) { 
               
                SwapValue(&array[i], &array[i - 1]);

            }
        }

        _firstItem += 1;
        
    }

    for (size_t i = 0; i < _length; i++)
    {

        printf("%-5d|%5d\n", array[i], array1[i]);

    }

}

int SearchValueInArray(int* array, int arrLength, int value)
{
    int _length = arrLength, 
        _firstItem = 0,
        _lastItem = _length - 1, 
        _middleItem = (_firstItem + _lastItem) / 2;
    
    while (_firstItem <= _lastItem)
    {
        
        if (array[_middleItem] > value)
        {
            _firstItem = _middleItem + 1;
        }
        
        if (array[_middleItem] < value)
        {
            _lastItem = _middleItem - 1;
        }
        
        if (array[_middleItem] == value)
        {
            return _middleItem;
        }

        _middleItem = (_lastItem + _firstItem) / 2;

    }

    return -1;

}

/// <summary3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.</summary>
/// <returns></returns>
void Solution_3_3(int* array, int arrLength) {

    int _value = GetInt("Enter the value(1-1000): ", 1, 1, 1, 1000),
        _result = SearchValueInArray(array, arrLength, _value);
    
    if (_result == -1)
    {

        printf("%s", "Value not found!");

    }
    else {

        printf("%s", "Value found!");

    }
    
}

/// <summary>4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.</summary>
/// <returns></returns>
void Solution_3_4() {

}


int StartHomeWorkNumber3()
{

    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-4): ", 1, 1, 1, 4);

    int array[ARRLENGTH], array1[ARRLENGTH], array2[ARRLENGTH],
        arrLength = sizeof(array) / sizeof(array[0]);

    srand(time(NULL));
    
    for (int i = 0; i < arrLength; i++) {
        int value = (rand() % 1000);
        array[i]  = value;
        array1[i] = value;
        array2[i] = value;
    }
    


    switch (_numberTask)
    {
    case 1:
        Solution_3_1(&array, &array1, &array2, arrLength);
        break;
    case 2:
        Solution_3_2(&array, &array1, arrLength);
        break;
    case 3:
        Solution_3_3(&array, arrLength);
        break;
    /*case 4:
        Solution_3_4();
        break;*/
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    return 1;
}