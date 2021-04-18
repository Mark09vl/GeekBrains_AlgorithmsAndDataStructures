#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "nodedef.h"

// создания очереди
queLinkedList* createQueLinkedList() {

	queLinkedList* _tmp = (queLinkedList*)malloc(sizeof(queLinkedList));

	_tmp->size = 0;
	_tmp->head = _tmp->tail = NULL;

	return _tmp;

}

// удаление
void deleteQueLinkedList(queLinkedList** list) {

	qNode* _tmp = (*list)->head;
	qNode* _next = NULL;

	while (_tmp) {

		_next = _tmp->next;
		free(_tmp);
		_tmp = _next;

	}

	free(*list);
	(*list) = NULL;

}

void pushFront(queLinkedList* list, void* data) {

	qNode* _tmp = (qNode*)malloc(sizeof(qNode));
	
	if (_tmp == NULL) {

		exit(-1);

	}

	_tmp->value = data;
	_tmp->next = list->head;
	_tmp->prev = NULL;

	if (list->head) {

		list->head->prev = _tmp;

	}

	list->head = _tmp;

	if (list->tail == NULL) {
		
		list->tail = _tmp;

	}

	list->size++;

}

void* popFront(queLinkedList* list) {

	qNode* _prev;
	void* _tmp;

	if (list->head == NULL) {
		
		exit(-2);

	}

	_prev = list->head;
	list->head = list->head->next;

	if (list->head) {

		list->head->prev = NULL;

	}

	if (_prev == list->tail) {

		list->tail = NULL;

	}

	_tmp = _prev->value;
	free(_prev);

	list->size--;
	return _tmp;

}

void pushBack(queLinkedList* list, void* value) {

	qNode* _tmp = (qNode*)malloc(sizeof(qNode));

	if (_tmp == NULL) {
		
		exit(3);

	}

	_tmp->value = value;
	_tmp->next = NULL;
	_tmp->prev = list->tail;

	if (list->tail) {

		list->tail->next = _tmp;

	}

	list->tail = _tmp;

	if (list->head == NULL) {
		
		list->head = _tmp;

	}

	list->size++;

}

void* popBack(queLinkedList* list) {

	qNode* _next;
	void* _tmp;

	if (list->tail == NULL) {

		exit(4);

	}

	_next = list->tail;
	list->tail = list->tail->prev;

	if (list->tail) {

		list->tail->next = NULL;

	}

	if (_next == list->head) {

		list->head = NULL;

	}

	_tmp = _next->value;
	free(_next);
	list->size--;

	return _tmp;

}

qNode* getNth(queLinkedList* list, size_t index) {

	qNode* _tmp = list->head;
	int i = 0;

	while (_tmp && i < index) {

		_tmp = _tmp->next;
		i++;

	}

	return _tmp;

}

qNode* getNthq(queLinkedList* list, size_t index) {

	qNode* _tmp = NULL;
	int i;

	if (index < list->size / 2) {

		i = 0;
		_tmp = list->head;

		while (_tmp && i < index) {

			_tmp = _tmp->next;
			i++;

		}

	}
	else {

		i = list->size - 1;
		_tmp = list->tail;

		while (_tmp && i > index) {

			_tmp = _tmp->prev;
			i--;

		}

	}

	return _tmp;

}

void insert(queLinkedList* list, size_t index, void* value) {

	qNode* _elm = NULL,
		*_ins = NULL;

	_elm = getNth(list, index);

	if (_elm == NULL) {

		exit(-5);

	}

	_ins = (qNode*)malloc(sizeof(qNode));
	_ins->value = value;
	_ins->prev = _elm;
	_ins->next = _elm->next;

	if (_elm->next) {

		_elm->next->prev = _ins;

	}

	_elm->next = _ins;

	if (!_elm->prev) {

		list->head = _elm;

	}

	if (!_elm->next) {

		list->tail = _elm;

	}

	list->size++;

}

void* deleteNth(queLinkedList* list, size_t index) {

	qNode* _elm = NULL;
	void* _tmp = NULL;

	_elm = getNth(list, index);

	if (_elm == NULL) {

		exit(-5);

	}

	if (_elm->prev) {

		_elm->prev->next = _elm->next;

	}

	if (_elm->next) {

		_elm->next->prev = _elm->prev;

	}

	_tmp = _elm->value;

	if (!_elm->prev) {

		list->head = _elm->next;

	}
	if (!_elm->next) {

		list->tail = _elm->prev;

	}

	free(_elm);
	list->size--;

	return _tmp;

}

void printQueLinkedList(queLinkedList* list, void(*fun)(void*)) {
	
	qNode* _tmp = list->head;

	while (_tmp) {

		fun(_tmp->value);
		_tmp = _tmp->next;

	}

	printf("\n");

}

void printInt(void* value) {
	printf("%d", *((int*)value));
}

queLinkedList* fromArray(void* arr, size_t n, size_t size) {

	queLinkedList* _tmp = NULL;

	if (arr == NULL) {
		exit(-7);
	}

	_tmp = createQueLinkedList();

	int i = 0;

	while (i < n) {

		pushBack(_tmp, ((char*)arr + i * size));
		i++;

	}

	return _tmp;

}