//Коротких Марк Александрович

#ifndef TCH
#define TCH char
#endif // !TCH

struct TQNode {

	TCH value;
	struct TQNode* next;

};
typedef struct TQNode QNode;

struct Queue {

	QNode* head;
	QNode* tail;
	int size;
	int maxsize;

};
typedef struct Queue TQueue;

int QueueSize(TQueue* que) {

	return que->size;

}

void QueueInit(TQueue* que, TCH value) {

	que->head = (QNode*)malloc(sizeof(QNode));
	
	if (que->head == NULL) {
		
		printf("Error! Out of memory.\n");
		exit(-1);

	}

	que->tail = que->head;
	que->head->value = value;
	que->head->next = NULL;
	que->size = 1;

}

// Добавляет(вталкивает) элемент в очередь
void QueueEnqueue(TQueue* que, TCH value) {

	QNode* _temp = (QNode*)malloc(sizeof(QNode));
	
	if (_temp == NULL) {
		
		printf("Error! Out of memory.\n");
		exit(-1);

	}

	_temp->next = NULL;
	_temp->value = value;
	que->tail->next = _temp;
	que->tail = _temp;
	que->size++;

}

// Удаляет элемент(выталкивает) и возвращает его
TCH QueueDequeue(TQueue* que) {
	
	TCH _ret;

	if (que->size == 0) {
		
		printf("Error! Queue is empty.\n");
		
		return (TCH)NULL;

	}

	QNode* _temp = que->head;
	_ret = que->head->value;
	que->head = que->head->next;
	free(_temp);
	que->size--;

	return _ret;

}

// Выгружаем значение головы без удаления
TCH QueuePeek(TQueue* que) {

	TCH _ret;

	if (que->size == 0) {

		printf("Error! Queue is empty.\n");

		return (TCH)NULL;

	}

	_ret = que->head->value;

	return _ret;

}

void QueuePrint(TQueue* cur) {

	QNode* current = cur->head;

	while (current != NULL) {
		
		printf("%c", current->value);
		current = current->next;

	}

}