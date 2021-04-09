//�������� ���� �������������

/// <summary>1. ����������� ������� �������� �� ���������� ������� � ��������, ��������� ��������.</summary>
/// <returns></returns>
void Solution_2_1() {

    int _value, i, _arrValue[17];

    for (i = 0; i < 10; i++)
    {
        _arrValue[i] = 0;
    }

    _value = GetInt("Enter value(0-100000): ", 1, 0, 1, 100000);

    i = 0;
    while (_value != 0)
    {
        if (_value % 2 == 0)
        {
            _arrValue[i] = 0;
            _value = _value / 2;
        }
        else
        {
            _arrValue[i] = 1;
            _value = _value / 2;
        }
        i++;
    }

    i--;

    while (i >= 0) {
        printf("%d", _arrValue[i]);
        i--;
    }

}

/// <summary>������� ��� ������������ ���������� � �������</summary>
/// <returns></returns>
double GetExponentiationValue(int value, int extent) {

    double _result;

    if (extent > 1)
    {
        _result = (double)value * GetExponentiationValue(value, extent - 1);
    }
    else if (extent < -1)
    {
        _result = (double)1 / value * GetExponentiationValue(value, extent + 1);
    }
    else if (extent == -1) {
        _result = (double)1 / value;
    }
    else
    {
        _result = (double)value;
    }

    return _result;

}

/// <summary>2. ����������� ������� ���������� ����� a � ������� b:
/// a.��� ��������;
/// b.����������;
/// c.* ����������, ��������� �������� �������� �������.</summary>
/// <returns></returns>
void Solution_2_2() {
    
    int _extent, _value;
    double _result;

    _value = GetInt("Enter value: ", 0, 0, 0, 0);

    _extent = GetInt("Enter extent: ", 0, 0, 0, 0);
    
    _result = GetExponentiationValue(_value, _extent);

    printf("%.3f", _result);
}

/// <summary>3. **����������� ������������ ����������� ����� �����, ���������� �� ������. �
/// ����������� ��� �������, ������ �������� ����� :
/// 1. ������� 1.
/// 2. ������ �� 2.
/// ������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� � 2 ����.�������
/// ���������� ��������, ������� ����� 3 ����������� � ����� 20 :
///     �.� �������������� �������.
///     b. * � �������������� ��������.</summary>
/// <returns></returns>
void Solution_2_3() {

    int _extent, _value;
    double _result;

    _value = GetInt("Enter value: ", 0, 0, 0, 0);

    _extent = GetInt("Enter extent: ", 0, 0, 0, 0);

    _result = GetExponentiationValue(_value, _extent);

    printf("%.3f", _result);
}

int StartHomeWorkNumber2()
{

    int _numberTask;

    _numberTask = GetInt("Enter the task number(1-3): ", 1, 1, 1, 3);

    switch (_numberTask)
    {
    case 1:
        Solution_2_1();
        break;
    case 2:
        Solution_2_2();
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }

	return 1;
}