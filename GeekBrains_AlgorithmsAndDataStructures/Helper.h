//Коротких Марк Александрович

#pragma warning(disable : 4996)
#include <stdio.h>


double GetDouble(char *text, int checkMinValue, double minValue) {

    double _result;
    int validation;

    while (1) {
        printf("%s", text);
        validation = scanf("%lf", &_result);
        
        if (validation ||
            (checkMinValue && _result < minValue 
            || !checkMinValue)) {
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
            (checkMinValue && _result < minValue
                || !checkMinValue)
            || (checkMaxValue && _result > maxValue
                || !checkMaxValue)) {
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
        if (validation ||
            (checkMinRange && length < minRange 
                || !checkMinRange)
            || (checkMaxRange && length > maxRange 
                || !checkMaxRange)) {
            printf("Incorrect value!\n\n");
        }
        else {
            break;
        }
    }

    return _result;
}

