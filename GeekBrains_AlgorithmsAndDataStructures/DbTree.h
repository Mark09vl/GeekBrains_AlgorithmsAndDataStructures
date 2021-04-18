// Коротких Марк Александрович

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

#include "nodedef.h"

int strToHash(char* str, int len) {

	int _seed = 31,
		_hash = 0;

	for (int i = 0; i < len; str++, i++)
	{

		_hash = (_hash * _seed) + *str + i;

	}

	return _hash;

}

dbNode* create_dbNode(char* name, int age, int tabid) {

	dbNode* _tree = (dbNode*)malloc(sizeof(dbNode));

	_tree->parent = NULL;
	_tree->left = NULL;
	_tree->right = NULL;
	_tree->name = name;
	_tree->hashName = strToHash(name, strlen(name));
	_tree->age = age;
	_tree->tabid = tabid;
	_tree->idHash = strToHash(name, strlen(name)) + age + tabid;

	return _tree;

}

void printDb(dbNode* root) {
	
	if (root) {

		printf("#%d\t Name: %s\t Age: %d\t TabId: %d\n", root->idHash, root->name, root->age, root->tabid);
		printDb(root->left);
		printDb(root->right);

	}

}

// search by name
void getDbNodeByName(dbNode* root, char* value) {
	
	int _idxValue = strToHash(value, strlen(value));

	if (root) {
		if (root->hashName == _idxValue) {

			printf("#%d\t Name: %s\t Age: %d\t TabId: %d\n", root->idHash, root->name, root->age, root->tabid);

			return;

		}
		else {

			getDbNodeByName(root->left, value);
			getDbNodeByName(root->right, value);

		}

	}

}

// search by age
void getDbNodeByAge(dbNode* root, int value) {

	if (root) {

		if (root->age == value) {

			printf("#%d\t Name: %s\t Age: %d\t TabId: %d\n", root->idHash, root->name, root->age, root->tabid);

			return;

		}
		else {

			getDbNodeByAge(root->left, value);
			getDbNodeByAge(root->right, value);

		}

	}

}

dbNode* getFreeDbNode(dbNode* parent, char* name, int age, int tabid) {
	
	dbNode* _tmp = (dbNode*)malloc(sizeof(dbNode));

	_tmp->left = _tmp->right = NULL;
	_tmp->name = name;
	_tmp->hashName = strToHash(name, strlen(name));
	_tmp->age = age;
	_tmp->tabid = tabid;
	_tmp->idHash = strToHash(name, strlen(name)) + age + tabid;
	_tmp->parent = parent;

	return _tmp;

}

void insertDbNode(dbNode** head, char* name, int age, int tabid) {
	
	dbNode* _tmp;

	if (*head == NULL) {

		*head = getFreeDbNode(NULL, name, age, tabid);

		return;

	}

	_tmp = *head;

	int _idHash = strToHash(name, strlen(name)) + age + tabid;

	while (_tmp) {
		
		if (_idHash > _tmp->idHash) {
			
			if (_tmp->right) {

				_tmp = _tmp->right;

				continue;

			}
			else {

				_tmp->right = getFreeDbNode(_tmp, name, age, tabid);
				
				return;

			}
		}
		else if (_idHash < _tmp->idHash) {

			if (_tmp->left) {

				_tmp = _tmp->left;

				continue;

			}
			else {

				_tmp->left = getFreeDbNode(_tmp, name, age, tabid);

				return;

			}

		}
		else {

			printf("Wrong biNode.\n");

			exit(-2);

		}

	}

}