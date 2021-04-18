//Коротких Марк Александрович

#include "stack.h"
#include "queue.h"

/// <summary>1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.</summary>
/// <returns></returns>
void Solution_5_1() {

    TCH _newValue;
    TStack _stack;

    _stack.maxsize = 100;
    _stack.head = NULL;

    int _value = GetInt("Enter value(0-99): ", 1, 0, 1, 99);

    for (int i = _value; i > 0; ) {
        if (i) {
            _newValue = i % 2 ? '1' : '0';
            Enqueue(_newValue, &_stack);
        }
        i /= 2;
    }
    
    printStack(&_stack);

}

/// <summary>2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. 
/// Если память не выделяется, то выводится соответствующее сообщение. 
/// Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).</summary>
/// <returns></returns>
void Solution_5_2() {
    
    TStack _stack;

    _stack.maxsize = 100;
    _stack.head = NULL;

    Enqueue('1', &_stack);
    Enqueue('2', &_stack);
    Enqueue('3', &_stack);
    Enqueue('4', &_stack);
    Enqueue('5', &_stack);
    Enqueue('6', &_stack);
    Enqueue('7', &_stack);
    Enqueue('8', &_stack);
    Enqueue('9', &_stack);

    printStack(&_stack);

    printf("\n");

    printf("%c, ", Dequeue(&_stack));
    printf("%c, ", Dequeue(&_stack));
    printf("%c, ", Dequeue(&_stack));
    printf("%c, ", Dequeue(&_stack));
    printf("%c\n", Dequeue(&_stack));

    printStack(&_stack);

}

char* CheckValue(const char* s) {
    
    switch (*s) {
    case '\0':
    case ')':
    case '}':
    case ']':
        return (char*)s;
    case '(': {
        char* _ret = CheckValue(s + 1);
        return (*_ret == ')') ? CheckValue(_ret + 1) : (char*)s;
    }
    case '{': {
        char* _ret = CheckValue(s + 1);
        return (*_ret == '}') ? CheckValue(_ret + 1) : (char*)s;
    }
    case '[': {
        char* _ret = CheckValue(s + 1);
        return (*_ret == ']') ? CheckValue(_ret + 1) : (char*)s;
    }
    default:
        return CheckValue(s + 1);
    }

}

/// <summary>3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. 
/// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
/// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]</summary>
/// <returns></returns>
void Solution_5_3() {

    char* _valueCheck1 = "(), ([])(), {}(), ([{}])";
    char* _valueCheck2 = ")(, ())({), (, ])}), ([(])";
    printf("%s - %s\n", _valueCheck1, (*CheckValue(_valueCheck1)) ? "not ok" : "ok");
    printf("%s - %s\n", _valueCheck2, (*CheckValue(_valueCheck2)) ? "not ok" : "ok");

}

/// <summary>4. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).</summary>
/// <returns></returns>
void Solution_5_4() {

    TStack _st01;

    _st01.maxsize = 100;
    _st01.head = NULL;

    Enqueue('1', &_st01);
    Enqueue('2', &_st01);
    Enqueue('3', &_st01);
    Enqueue('4', &_st01);
    Enqueue('5', &_st01);
    Enqueue('6', &_st01);
    Enqueue('7', &_st01);
    Enqueue('8', &_st01);
    Enqueue('9', &_st01);

    printStack(&_st01);

    TStack _st02;

    printf("\n");

    copyStack(&_st01, &_st02);

    printStack(&_st02);

}

int prior(char v)
{
    switch (v) {
    case '(': 
        return 1;
    case '+':
    case '-': 
        return 2;
    case '*':
    case '/': 
        return 3;
    default: 
        return 0;
    }
}

bool is_op(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

void PostfixNotation(char* a, char* out)
{
    TStack _st01;
    _st01.size = 0;
    _st01.maxsize = 100;

    int i = 0, j = 0;
    for (; a[i] != '\0'; ++i) {
        if (is_digit(a[i]))
        {
            out[j] = a[i];
            ++j;
        }
        else {
            if (j != 0 && out[j - 1] >= '0' && out[j - 1] <= '9' || (j != 0 &&
                (out[j - 1] == '-' || out[j - 1] == '+' ||
                    out[j - 1] == '/' || out[j - 1] == '*'))) {
                out[j] = ' ';
                ++j;
            }
            if (is_op(a[i])) {
                if (stkEmpty(&_st01) || prior(stkTop(&_st01)) < prior(a[i])) {
                    Enqueue(a[i], &_st01);
                }
                else {
                    while (!stkEmpty(&_st01) && (prior(stkTop(&_st01)) >= prior(a[i]))) {
                        out[j++] = stkTop(&_st01);
                        Dequeue(&_st01);
                    }
                    Enqueue(a[i], &_st01);
                }
            }
            else {
                if (a[i] == '(') {
                    Enqueue(a[i], &_st01);
                }
                else {
                    if (a[i] == ')') {
                        if (stkEmpty(&_st01) || stkTop(&_st01) == '(') {
                            printf("Error!\n");
                            exit(-1);
                        }
                        else {
                            while (stkTop(&_st01) != '(') {
                                out[j] = stkTop(&_st01);
                                Dequeue(&_st01);
                                j++;
                            }
                        }
                        Dequeue(&_st01);
                    }
                }
            }
        }
    }
    while (!stkEmpty(&_st01)) {
        if (stkTop(&_st01) == '(')
        {
            printf("Error!\n");
            exit(-1);
        }
        else {
            out[j] = stkTop(&_st01);
            Dequeue(&_st01);
            j++;
        }
    }
    out[j++] = '\0';
}

/// <summary>5. **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.</summary>
/// <returns></returns>
void Solution_5_5() {

    char* _src = "5 * 8 * (2 + 9) + (7 * 5 + 8 - 9 * (5 * 5) + 5)";
    char* _dst = (char*)malloc(strlen(_src) * sizeof(char));

    PostfixNotation(_src, _dst);

    printf("%s -> %s", _src, _dst);

}

/// <summary>6. *Реализовать очередь.</summary>
/// <returns></returns>
void Solution_5_6() {

    TQueue _que;

    QueueInit(&_que, '1');
    QueueEnqueue(&_que, '2');
    QueueEnqueue(&_que, '3');
    QueueEnqueue(&_que, '4');
    QueueEnqueue(&_que, '5');
    QueueEnqueue(&_que, '6');
    QueueEnqueue(&_que, '7');
    QueueEnqueue(&_que, '8');
    QueueEnqueue(&_que, '9');

    QueuePrint(&_que);

    printf("\n");

    printf("%c,", QueueDequeue(&_que));
    printf("%c,", QueueDequeue(&_que));
    printf("%c,", QueueDequeue(&_que));
    printf("%c,", QueueDequeue(&_que));
    printf("%c\n", QueueDequeue(&_que));

    QueuePrint(&_que);

}



int StartHomeWorkNumber5()
{


    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-6): ", 1, 1, 1, 6);


    switch (_numberTask)
    {
    case 1:
        Solution_5_1();
        break;
    case 2:
        Solution_5_2();
        break;
    case 3:
        Solution_5_3();
        break;
    case 4:
        Solution_5_4();
        break;
    case 5:
        Solution_5_5();
        break;
    case 6:
        Solution_5_6();
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }


}