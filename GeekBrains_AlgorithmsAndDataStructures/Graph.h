//Коротких Марк Александрович

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int** ReadGraph(char* fileName, int* sizeMatrix) {
	
	int _sizeMatrix, 
		_value,
		** _arr;

	FILE* _file = fopen(fileName, "r");

	if (_file == NULL) {
		printf("Can't open file.\n");
		exit(-1);
	}

	fscanf(_file, "%d", &_sizeMatrix);

	_arr = (int**)malloc(_sizeMatrix * sizeof(int*));

	for (int i = 0; i < _sizeMatrix; i++) {

		_arr[i] = (int*)malloc(_sizeMatrix * sizeof(int));
		memset(_arr[i], 0, sizeof(int));

		for (int j = 0; j < _sizeMatrix; j++) {

			_arr[i][j] = 0;
			
			fscanf(_file, "%d", &_value);
			
			_arr[i][j] = _value;

		}

	}

	fclose(_file);

	*sizeMatrix = _sizeMatrix;

	return _arr;

}

int PrintGraph(int n, int m, int** a) {

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < m; ++j) {

			printf(" %d ", a[i][j]);

		}

		printf("\n");

	}

	return 0;

}

void StepInDeepGraph(int sizeMatrix, int start, int** arr, int* visited) {
	
	if (visited == 0)
	{

		visited = malloc(sizeMatrix * sizeof(int));

		for (int i = 0; i < sizeMatrix; i++) {

			visited[i] = 0;

		}

		StepInDeepGraph(sizeMatrix, start - 1, arr, visited);

		printf("\n");

	}
	else {

		printf("%d ", start + 1);

		visited[start] = 1;

		for (int r = 0; r < sizeMatrix; r++) {

			if ((arr[start][r] != 0) && (!visited[r])) {

				StepInDeepGraph(sizeMatrix, r, arr, visited);

			}

		}

	}

}

void StepInWidthGraph(int sizeMatrix, int start, int** arr, int* visited) {

	if (visited == 0)
	{
		
		visited = malloc(sizeMatrix * sizeof(int));

		for (int i = 0; i < sizeMatrix; i++) {

			visited[i] = 0;

		}

		StepInWidthGraph(sizeMatrix, start - 1, arr, visited);
		
		printf("\n");

	}
	else {
		
		int* _queue = malloc(sizeMatrix * sizeof(int)),
			_count = 0,
			_head = 0;

		for (int i = 0; i < sizeMatrix; i++) {

			_queue[i] = 0;

		}

		_queue[_count++] = start;
		visited[start] = 1;

		while (_head < _count) {

			start = _queue[_head++];

			printf("%d ", start + 1);

			for (int i = 0; i < sizeMatrix; i++) {

				if (arr[start][i] && !visited[i]) {

					_queue[_count++] = i;
					visited[i] = 1;

				}

			}

		}

	}

	

}