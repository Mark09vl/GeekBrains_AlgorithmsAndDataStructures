//Коротких Марк Александрович

#define N 3
#define M 3

#define ChessN 8
#define ChessM 3

/// <summary>1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.</summary>
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

/// <summary>2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.</summary>
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

int CheckCorrectMove(int x, int y, int** board, int a, int b)
{
    return
        x >= 0 && x < a&&
        y >= 0 && y < b&&
        board[y][x] == 0;
}

int compar(const void* a, const void* b)
{
    return ((int*)a)[0] - ((int*)b)[0];
}

int HorseAlgorithm(int x, int y, int n, int** board, int a, int b) {

    int _moves[ChessN][ChessM] = {
        { -2,  1 },{ -1,  2 },{ 1,  2 },{ 2,  1 },
        { 2, -1 },{ 1, -2 },{ -1, -2 },{ -2, -1 }
    };

    board[y][x] = n;
    if (n == a * b)
        return 1;

    int i, j, _valids[ChessN][ChessM];
    for (i = 0; i < ChessN; i++) {
        _valids[i][0] = 0;
        _valids[i][1] = x + _moves[i][0];
        _valids[i][2] = y + _moves[i][1];
        if (CheckCorrectMove(_valids[i][1], _valids[i][2], board, a, b)) {
            for (j = 0; j < ChessN; j++) {
                if (CheckCorrectMove(_valids[i][1] + _moves[j][0],
                    _valids[i][2] + _moves[j][1], board, a, b))
                    _valids[i][0]++;
            }
        }
    }

    qsort(&_valids[0][0], ChessN, ChessM * sizeof(int), &compar);
    for (i = 0; i < ChessN; i++) {
        if (CheckCorrectMove(_valids[i][1], _valids[i][2], board, a, b) &&
            HorseAlgorithm(_valids[i][1], _valids[i][2], n + 1, board, a, b))
            return 1;
    }

    board[y][x] = 0;
    return 0;

}

/// <summary>3. ***Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу. Здесь алгоритм решения такой же, как в задаче о 8 ферзях. Разница только в проверке положения коня.</summary>
/// <returns></returns>
void Solution_4_3() {

    int x = 8,
        y = 8;

    int** _board = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < y; i++) {
        _board[i] = (int*)malloc(y * sizeof(int));
        memset(_board[i], 0, sizeof(int));
        for (int j = 0; j < x; j++) {
            _board[i][j] = 0;
        }
    }

    if (HorseAlgorithm(5, 0, 1, _board, x, y)) {
        
        for (int i = 0; i < x; ++i) {
            
            for (int j = 0; j < y; ++j) {
                
                printf("%6d", _board[i][j]);

            }

            printf("\n");

        }

    }
    else {
        printf("No solution.\n");
    }

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
    case 3:
        Solution_4_3();
        break;
    default:
        printf("This task has not yet been completed :(");
        break;
    }

    return 1;

}