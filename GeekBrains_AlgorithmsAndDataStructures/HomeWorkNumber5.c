//Коротких Марк Александрович


/// <summary>1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.</summary>
/// <returns></returns>
void Solution_5_1() {

}

/// <summary>2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. 
/// Если память не выделяется, то выводится соответствующее сообщение. 
/// Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).</summary>
/// <returns></returns>
void Solution_5_2() {

}

/// <summary>3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. 
/// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
/// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]</summary>
/// <returns></returns>
void Solution_5_3() {

}

/// <summary>4. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).</summary>
/// <returns></returns>
void Solution_5_4() {

}

/// <summary>5. **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.</summary>
/// <returns></returns>
void Solution_5_5() {

}

/// <summary>6. *Реализовать очередь.</summary>
/// <returns></returns>
void Solution_5_6() {

}



int StartHomeWorkNumber5()
{


    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-3): ", 1, 1, 1, 3);


    switch (_numberTask)
    {
    /*case 1:
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
        break;*/
    default:
        printf("This task has not yet been completed :(");
        break;
    }


}