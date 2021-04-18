//Коротких Марк Александрович

#include <memory.h>
#include <stdbool.h>

#ifndef TCH
#define TCH char
#endif // !TCH

struct TNode {

	TCH value;
	struct TNode* next;

};


typedef struct TNode Node;


struct Stack {

	Node* head;
	int size;
	int maxsize;

};


typedef struct Stack TStack;


int stkEmpty(TStack* stack) {

	if (stack->size > 0) {

		return 0;

	}

	return 1;

}

TCH stkTop(TStack* stack) {

	TCH _ret;

	if (stack->size == 0) {
		
		printf("Error! Queue is empty.\n");

		return (TCH)NULL;

	}

	_ret = stack->head->value;

	return _ret;
}

void Enqueue(TCH value, TStack* current) {

	if (current->size >= current->maxsize) {
		
		printf("Error! Stack size.\n");

		return;

	}

	Node* _tmp = (Node*)malloc(sizeof(Node));
	
	if (_tmp == NULL) {

		printf("Error! Out of memory.\n");

		exit(-1);

	}

	_tmp->value = value;
	_tmp->next = current->head;
	current->head = _tmp;
	current->size++;

}

TCH Dequeue(TStack* cur) {

	TCH _value;

	if (cur->size == 0) {
		printf("Error! Stack is empty.\n");
		return (char)NULL;
	}

	Node* _next = cur->head;
	_value = cur->head->value;
	cur->head = cur->head->next;
	free(_next);
	cur->size--;

	return _value;

}

// copy stack, return number's stored elements
int copyStack(TStack* src, TStack* dst) {

	int i = 0;
	TStack _tail;

	dst->head = NULL;
	_tail.head = NULL;
	dst->maxsize = src->maxsize;
	_tail.maxsize = src->maxsize;
	Node* current = src->head;

	while (current != NULL) {

		if (dst->head == NULL) {

			dst->head = (Node*)malloc(sizeof(Node));
			dst->head->value = current->value;
			_tail.head = dst->head;

		}
		else {

			_tail.head->next = (Node*)malloc(sizeof(Node));
			_tail.head = _tail.head->next;
			_tail.head->value = current->value;
			_tail.head->next = NULL;

		}

		current = current->next;
		i++;

	}

	return i;
}

void printStack(TStack* cur) {

	Node* _current = cur->head;

	while (_current != NULL) {
		
		printf("%c", _current->value);
		_current = _current->next;

	}

}