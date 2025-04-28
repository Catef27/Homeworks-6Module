#include<stdio.h>
#include<stdlib.h>

typedef struct {

	struct Node* next;
	int value;
	int mins;
} Node;

Node* createNode(int key, int mins) {

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = key;
	tmp->mins = mins;
	tmp->next = NULL;

	return tmp;
}

typedef struct {

	Node* top;
	int size;
} Stack;

Stack* create(int n) {

	Stack* stk = (Stack*)malloc(sizeof(Stack));

	stk->top = NULL;
	stk->size = 0;

	return stk;
}

void push(Stack* stk, int val) {

	int newMin = val;

	if (stk->top != NULL && stk->top->mins < newMin) {

		newMin = stk->top->mins;
	}
	
	Node* newNode = createNode(val, newMin);

	newNode->next = stk->top;
	stk->top = newNode;
	stk->size++;
}

void pop(Stack* stk) {

	if (stk->top == NULL) {

		return;
	}

	Node* tmp = stk->top;
	stk->top = stk->top->next;
	free(tmp);
	stk->size--;
}

void min(Stack* stk) {

	if (stk->top == NULL) {
		printf("empty\n");
		return;
	}

	printf("%d\n", stk->top->mins);
}

int main() {

	int n;
	scanf("%d", &n);

	Stack* stk = create(n);

	for (int i = 0; i < n; i++) {

		char s[5];
		scanf("%s", &s);

		if (s[0] == 'p' && s[1] == 'u') {

			int val;
			scanf("%d", &val);

			push(stk, val);
		}
		else if (s[0] == 'p' && s[1] == 'o') {

			pop(stk);
		}
		else {

			min(stk);
		}
	}

	return 0;
}