#include<stdio.h>
#include<stdlib.h>

void qSort(int* arr, int left, int right) {

	int p = arr[(left + right) / 2];
	int i = left, j = right;

	if (left > right) {

		return;
	}

	while (i <= j) {

		while (arr[i] < p) {

			i++;
		}
		while (arr[j] > p) {

			j--;
		}

		if (i <= j) {

			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			
			i++;
			j--;
		}
	}

	qSort(arr, left, j);
	qSort(arr, i, right);
}

int main() {

	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &arr[i]);
	}

	qSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {

		printf("%d ", arr[i]);
	}
    
    free(arr);
    
	return 0;
}