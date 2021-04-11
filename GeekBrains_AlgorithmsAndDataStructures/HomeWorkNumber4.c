//�������� ���� �������������

#define N 3
#define M 3


/// <summary>1. *���������� ��������� � �������������. ����������� ������ ������� � ������������ � ���������� ���������� ���������.</summary>
/// <returns></returns>
void Solution_4_1() {

    int _map[N][M] = {   
                        {1, 1, 1},
                        {0, 1, 0},
                        {0, 1, 0} 
                    },
        _result[N][M];


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            _result[i][j] = 0;
        }
    }
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (_map[i][j] == 0) { 
                continue; 
            }
            else
            {
                _result[i][j] = _result[i - 1 >= 0 ? i - 1 : 0][j] + _result[i][j - 1 >= 0 ? j - 1 : 0];
                
                if (_result[i][j] == 0) { 
                    _result[i][j]++; 
                }

            }

        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", _result[i][j]);
        }
        printf("\n");
    }

}

/// <summary>2. ������ ������ � ���������� ����� ������������ ������������������ � ������� �������.</summary>
/// <returns></returns>
void Solution_4_2() {

    int _arr1[] = { 3, 4, 5},
        _arr2[] = { 4, 5, 6},
        _matrix[N][M];
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            _matrix[i][j] = 0;
        }
    }

    int i1 = 0,
        i2 = 0,
        _iCheck1 = -1,
        _iCheck2 = -1,
        _flag = 0;

    while (i1 < N && i2 < M)
    {
        
        for (int i = i1; i < N; i++)
        {
            
            _matrix[i][i2] = 
                _matrix[i - 1 >= 0 ? i - 1 : 0][i2] > _matrix[i][i2 - 1 >= 0 ? i2 - 1 : 0] ?
                _matrix[i - 1 >= 0 ? i - 1 : 0][i2] : 
                _matrix[i][i2 - 1 >= 0 ? i2 - 1 : 0];

            if (_flag == 0 
                && _iCheck2 != i2 
                && _arr1[i] == _arr2[i2]) {

                _matrix[i][i2]++; 
                _flag = 1; 
                _iCheck1 = i; 
                _iCheck2 = i2;

            }

        }

        for (int j = i2 + 1; j < M; j++)
        {

            _matrix[i1][j] = 
                _matrix[i1][j - 1 >= 0 ? j - 1 : 0] > _matrix[i1 - 1 >= 0 ? i1 - 1 : 0][j] ?
                _matrix[i1][j - 1 >= 0 ? j - 1 : 0] : 
                _matrix[i1 - 1 >= 0 ? i1 - 1 : 0][j];

            if (_flag == 0 
                && _iCheck1 != i1 
                && _arr1[i1] == _arr2[j]) {

                _matrix[i1][j]++; 
                _flag = 1; 
                _iCheck1 = i1; 
                _iCheck2 = j;

            }

        }

        i1++;
        i2++;
        _flag = 0;

    }
    
    printf("\n  ");

    for (int i = 0; i < N; i++)
    {
        printf("%2d", _arr2[i]);
    }

    printf("\n");
    
    for (int i = 0; i < N; i++)
    {
        
        printf("%2d", _arr1[i]);

        for (int j = 0; j < M; j++)
        {
            printf("%2d", _matrix[i][j]);
        }

        printf("\n");

    }
    
    printf("\nMax: %d", _matrix[N - 1][M - 1]);

}

/// <summary>3. ***��������� ������ ����� ��������� ����� �������� NxM, ������ ����� ��� ���� ����� �� ������ ����. ����� �������� ������� ����� ��, ��� � ������ � 8 ������. ������� ������ � �������� ��������� ����.</summary>
/// <returns></returns>
void Solution_4_3() {

    
}

int StartHomeWorkNumber4()
{

	int _numberTask;

	_numberTask = GetInt("Enter the task number(1-3): ", 1, 1, 1, 3);


    switch (_numberTask)
    {
    case 1:
        Solution_4_1();
        break;
    case 2:
        Solution_4_2();
        break;
    /*case 3:
        Solution_4_3();
        break;*/
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    return 1;

}