// Коротких Марк Александрович

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>

#include "nodedef.h"
#include "StackWork6.h"

biNode* create_biNode(int val) {
	
	biNode* _tree = (biNode*)malloc(sizeof(biNode));
	
	_tree->parent = NULL;
	_tree->left = NULL;
	_tree->right = NULL;

	_tree->data = val;

	return _tree;

}

void print_tree(biNode* root) {

	if (root) {

		printf("%d", root->data);

		if (root->left || root->right) {

			printf("(");

			if (root->left) {

				print_tree(root->left);

			}

			else {

				printf("NULL");

			}

			printf(",");

			if (root->right) {

				print_tree(root->right);

			}
			else {

				printf("NULL");

			}

			printf(")\n");

		}

	}

}

void preorder_travers(biNode* root) {
	
	if (root) {

		printf("%d ", root->data);

		preorder_travers(root->left);
		preorder_travers(root->right);

	}

}

void postorder_travers(biNode* root) {

	if (root) {

		preorder_travers(root->left);
		preorder_travers(root->right);

		printf("%d ", root->data);

	}

}

// inorder travers 
void inorder_travers(biNode* root) {
	
	if (root) {

		inorder_travers(root->left);

		printf("%d ", root->data);

		inorder_travers(root->right);

	}

}

// inter preorder
void iterpreorder_travers(biNode* root) {

	Stack* _ps = createStack();

	while (_ps->size != 0 || root != NULL) {

		if (root != NULL) {

			printf("%d ", root->data);

			if (root->right) {

				EnqueueStack(_ps, root->right);

			}

			root = root->left;

		}
		else {

			root = DequeueStack(_ps);

		}

	}

	freeStack(&_ps);

}

// inter in order
void iterinorder_travers(biNode* root) {

	Stack* ps = createStack();

	while (ps->size != 0 || root != NULL) {

		if (root != NULL) {

			EnqueueStack(ps, root);
			root = root->left;

		}
		else {

			root = DequeueStack(ps);
			printf("%d ", root->data);
			root = root->right;

		}

	}

	freeStack(&ps);

}

// inter post order
void iterpostorder_travers(biNode* root) {
	
	Stack* _ps = createStack();
	biNode* _lnp = NULL,
		*_peekn = NULL;

	while (!_ps->size == 0 || root != NULL) {
		
		if (root) {

			EnqueueStack(_ps, root);
			root = root->left;

		}
		else {

			_peekn = peekStack(_ps);

			if (_peekn->right && _lnp != _peekn->right) {

				root = _peekn->right;

			}
			else {

				DequeueStack(_ps);
				printf("%d ", _peekn->data);
				_lnp = _peekn;

			}

		}

	}

	freeStack(&_ps);

}

// width travers
void width_travers(biNode* root) {
	
	queLinkedList* _q = createQueLinkedList();
	pushFront(_q, root);
	
	while (_q->size != 0) {

		biNode* _tmp = (biNode*)popFront(_q);

		printf("%d ", _tmp->data);

		if (_tmp->left) {

			pushFront(_q, _tmp->left);

		}

		if (_tmp->right) {

			pushFront(_q, _tmp->right);

		}

	}

	deleteQueLinkedList(&_q);

}

void deleteTree(biNode** root) {
	
	if (*root) {

		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);

	}

}

biNode* getFreeBiNode(int value, biNode* parent) {
	
	biNode* _tmp = (biNode*)malloc(sizeof(biNode));

	_tmp->left = _tmp->right = NULL;
	_tmp->data = value;
	_tmp->parent = parent;

	return _tmp;

}

void insertBiNode(biNode** head, int value) {
	biNode* _tmp;

	if (*head == NULL) {

		*head = getFreeBiNode(value, NULL);

		return;

	}

	_tmp = *head;

	while (_tmp) {
		
		if (value > _tmp->data) {
			
			if (_tmp->right) {
				
				_tmp = _tmp->right;
				
				continue;

			}
			else {
				
				_tmp->right = getFreeBiNode(value, _tmp);
				
				return;

			}
		}
		else if (value < _tmp->data) {
			
			if (_tmp->left) {
				
				_tmp = _tmp->left;

				continue;

			}
			else {
				
				_tmp->left = getFreeBiNode(value, _tmp);
				
				return;

			}
		}
		else {
			
			printf("Wrong biNode.\n");
			
			exit(-2);

		}

	}

}

// search
biNode* getBiNodeByValue(biNode* root, int value) {
	
	while (root) {
		
		if (root->data > value) {
			
			root = root->left;
			
			continue;

		}
		else if (root->data < value) {
			
			root = root->right;
			
			continue;

		}
		else {
			
			return root;

		}

	}

	return NULL;

}

char* a = "12345678";

biNode* Tree(int n) {

	biNode* _newbiNode;

	int _x, 
		_nl, 
		_nr;


	if (n == 0) {

		_newbiNode = NULL;

	}
	else {
		
		_x = (int)*a - 48;
		a++;

		_nl = n / 2;
		_nr = n - _nl - 1;

		_newbiNode = (biNode*)malloc(sizeof(biNode));
		_newbiNode->data = _x;
		_newbiNode->left = Tree(_nl);
		_newbiNode->right = Tree(_nr);

	}

	return _newbiNode;

}