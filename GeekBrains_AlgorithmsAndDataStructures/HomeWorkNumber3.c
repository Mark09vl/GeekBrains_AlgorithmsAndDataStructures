//�������� ���� �������������

/// <summary>1. ����������� �������������� ����������� ����������. �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������. �������� ������� ����������, ������� ���������� ���������� ��������.</summary>
/// <returns></returns>
void Solution_3_1() {

}

/// <summary>2. *����������� ��������� ����������.</summary>
/// <returns></returns>
void Solution_3_2() {

}

/// <summary3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������. ������� ���������� ������ ���������� �������� ��� -1, ���� ������� �� ������.</summary>
/// <returns></returns>
void Solution_3_3() {

}

/// <summary>4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ��������������� ���������� ���������.</summary>
/// <returns></returns>
void Solution_3_4() {

}

int StartHomeWorkNumber3()
{

    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-4): ", 1, 1, 1, 3);

    switch (_numberTask)
    {
    /*case 1:
        Solution_3_1();
        break;
    case 2:
        Solution_3_2();
        break;
    case 3:
        Solution_3_3();
        break;
    case 4:
        Solution_3_4();
        break;*/
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    return 1;
}