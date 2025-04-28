#include<stdio.h>
#include<stdlib.h>

typedef struct {

	struct Node* next;
	int value;
} Node;

Node* createNode(int key) {

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = key;
	tmp->next = NULL;

	return tmp;
}

typedef struct {

	Node* head;
	Node* tail;
	int size;

} List;

List* create() {

	List* l = (List*)malloc(sizeof(List));

	l->head = NULL;
	l->tail = NULL;
	l->size = 0;

	return l;
}

void insert(List* l, int val) {

	Node* newNode = createNode(val);

	if (l->size == 0) {

		l->head = newNode;
		l->tail = newNode;
	}
	else {

		l->tail->next = newNode;
		l->tail = l->tail->next;
	}

	l->size++; 
}

void print(List* l) {

	int* arr = (int*)malloc(sizeof(int) * l->size);
	int i = 0;

	while (l->head != NULL) {

		arr[i++] = l->head->value;
		l->head = l->head->next;
	}

	for (int i = l->size - 1; i >= 0; i--) {

		printf("%d ", arr[i]);
	}

	printf("\n");

	for (int i = 0; i < l->size; i++) {

		printf("%d ", arr[i]);
	}
}

int main() {

	List* l = create();

	int n;
	scanf("%d", &n);

	while (n != 0) {

		insert(l, n);
		scanf("%d", &n);
	}

	print(l);

	return 0;
}