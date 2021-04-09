//Коротких Марк Александрович

#pragma warning(disable : 4996)
#include <stdio.h>


double GetDouble(char *text, int checkMinValue, double minValue) {

    double _result;
    int validation;

    while (1) {
        printf("%s", text);

        // #Вопрос: Если ввести букуву, то уходит в вечный цикл. 
        // getchar из курса частично решает проблему: в цикл не уходит, но перестаёт принимать значения
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

