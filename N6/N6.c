#include<stdio.h>
#include<stdlib.h>

int* merge(int* a, int* b, int sizeA, int sizeB) {

	int i = 0;
	int j = 0;
	int k = 0;

	int* c = (int*)malloc(sizeof(int) * (sizeA + sizeB));

	while (i < sizeA || j < sizeB) {

		if (j == sizeB || a[i] <= b[j]) {

			c[k++] = a[i++];
		}
		else {

			c[k++] = b[j++];
		}
	}

	free(a);
	free(b);

	return c;
}

int* mergeSort(int* a, int size) {

	if (size == 1) {

		int* copy = (int*)malloc(sizeof(int));

		*copy = a[0];

		return copy;
	}

	int mid = size / 2;
	int* left = (int*)malloc(sizeof(int) * mid);
	int* right = (int*)malloc(sizeof(int) * (size - mid));

	for (int i = 0; i < mid; i++) {

		left[i] = a[i];
	}

	for (int i = 0; i < size - mid; i++) {

		right[i] = a[i + mid];
	}

	return merge(mergeSort(left, mid), mergeSort(right, size - mid), mid, size - mid);
}

int main() {

	int n;
	scanf("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &a[i]);
	}

	int* sort = mergeSort(a, n);

	for (int i = 0; i < n; i++) {

		printf("%d ", sort[i]);
	}

	free(sort);
	free(a);

	return 0;
}