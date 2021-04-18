#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include "nodedef.h"

typedef struct Stack {

	size_t size;
	size_t limit;
	void** data;

} Stack;

Stack* createStack() {

	Stack* _tmp = (Stack*)malloc(sizeof(Stack));

	_tmp->limit = STACK_INIT_SIZE;
	_tmp->size = 0;
	_tmp->data = (biNode**)malloc(_tmp->limit * sizeof(biNode*));

	return _tmp;

}

void freeStack(Stack** s) {
	
	free((*s)->data);
	free(*s);
	*s = NULL;

}

void EnqueueStack(Stack* s, void* item) {
	
	if (s->size >= s->limit) {
		
		s->limit *= 2;
		s->data = (biNode**)realloc(s->data, s->limit * sizeof(biNode*));

	}

	s->data[s->size++] = item;

}

biNode* DequeueStack(Stack* s) {

	if (s->size == 0) {

		exit(-7);

	}

	s->size--;

	return s->data[s->size];

}

biNode* peekStack(Stack* s) {

	return s->data[s->size - 1];

}