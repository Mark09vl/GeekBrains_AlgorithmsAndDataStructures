//Коротких Марк Александрович

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 45
#include <time.h>

/// <summary>1. Реализовать сортировку подсчетом.</summary>
/// <returns></returns>
int* Solution_8_1(int* array, int sizeArray) {

    int* _sortArray = malloc(sizeArray * sizeof(int));

    for (int i = 0; i < sizeArray; i++) {
        
        _sortArray[i] = 0;

    }
    
    int _index;

    for (int i = 0; i < sizeArray; i++) {

        _index = 0;

        for (int j = 0; j < i; j++) {

            if (array[j] <= array[i]) {

                _index++;

            }

        }

        for (int j = i + 1; j < sizeArray; j++) {

            if (array[j] < array[i]) {

                _index++;

            }

        }

        _sortArray[_index] = array[i];

    }
    
    return _sortArray;

}

/// <summary>2. Реализовать быструю сортировку.</summary>
/// <returns></returns>
void Solution_8_2(int* array, int sizeArray) {

    int i = 0,
        j = sizeArray - 1;

    int _mid = array[sizeArray / 2];

    do {
        
        while (array[i] < _mid)
        { 
            i++; 
        }

        while (array[j] > _mid)
        { 
            j--; 
        }

        if (i <= j) {

            if (array[i] > array[j])
            { 

                SwapValue(&array[i], &array[j]);

            }

            i++;
            j--;

        }

    } while (i <= j);


    if (j > 0) {

        Solution_8_2(array, j + 1);

    }
    
    if (i < sizeArray) {

        Solution_8_2(&array[i], sizeArray - i);

    }

}

/// <summary>3. *Реализовать сортировку слиянием.</summary>
/// <returns></returns>
void Solution_8_3(int* array, int index, int sizeArray, int size) {

    if (sizeArray <= index)
        return;

    int _mid = index + (sizeArray - index) / 2;

    Solution_8_3(array, index, _mid, size);
    Solution_8_3(array, _mid + 1, sizeArray, size);

    int i = index,
        j = _mid + 1,
        * _sortArray = (int*)malloc(sizeArray * sizeof(int));

    memcpy(_sortArray, array, sizeof(int) * size);

    for (int k = index; k <= sizeArray; k++) {

        _sortArray[k] = array[k];

    }

    for (int k = index; k <= sizeArray; k++) {

        if (i > _mid) {

            array[k] = _sortArray[j];

        }
        else if (j > sizeArray) {

            array[k] = _sortArray[i];

        }
        else if (_sortArray[j] < _sortArray[i]) {

            array[k] = _sortArray[j];

        }
        else {

            array[k] = _sortArray[i];
            i++;

        }

    }

}

/// <summary>4. **Реализовать алгоритм сортировки со списком.</summary>
/// <returns></returns>
void Solution_8_4(int* array, int sizeArray) {

    int _min = array[0],
        _max = array[0];

    for (int i = 0; i < sizeArray; i++) {

        if (array[i] < _min) {

            _min = array[i];

        }

        if (array[i] > _max) {

            _max = array[i];

        }

    }

    int* _current = array,
        //_size = _max - _min + 2, 
        _count = 0,
        i,
        * _holes = malloc(sizeArray * sizeof(int));

    for (i = 0; i < sizeArray; i++) {

        _holes[i] = 0;

    }

    for (i = 0; i < sizeArray; i++, _current++) {

        _holes[*_current - _min] += 1;

    }

    for (_count = 0, _current = &array[0]; _count < sizeArray; _count++) {

        while (_holes[_count]-- > 0) {

            *_current++ = _count + _min;

        }

    }

}



int StartHomeWorkNumber8()
{

    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-4): ", 1, 1, 1, 4);

    int* _arrayInSort = malloc(SIZE * sizeof(int));

    RandomizeArray(_arrayInSort, SIZE);

    printf("\nStart array: \n");
    PrintArray(_arrayInSort, SIZE);
    
    if (_numberTask > 0 && _numberTask <= 4)
    {
        printf("\nResult array: \n");
    }
    
    double start = clock();

    switch (_numberTask)
    {
    case 1:
        _arrayInSort = Solution_8_1(_arrayInSort, SIZE);
        break;
    case 2:
        Solution_8_2(_arrayInSort, SIZE);
        break;
    case 3:
        Solution_8_3(_arrayInSort, 0, SIZE - 1, SIZE);
        break;
    case 4:
        Solution_8_4(_arrayInSort, SIZE);
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    PrintArray(_arrayInSort, SIZE);

    printf("\nSorting time: %.3lf\n", (clock() - start) / CLOCKS_PER_SEC);

    return 1;
}