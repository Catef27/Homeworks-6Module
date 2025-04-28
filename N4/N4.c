#include<stdio.h>
#include<stdlib.h>

int main() {

	int n;
	scanf("%d", &n);
	
	int col;
	scanf("%d", &col);
	
	int result = 0;

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &arr[i]);
	}

	int swap = 1;
	int start = 0;
	int end = n - 1;

	while (swap) {

		swap = 0;

		for (int i = start; i < end - 1; i++) {

			if (arr[i] > arr[i + 1]) {

				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;

				swap = 1;
				
				result++;
			}
		}

		if (swap == 0) {

			break;
		}

		swap = 0;
		end--;

		for (int i = end - 1; i >= start; i--) {

			if (arr[i] > arr[i + 1]) {

				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;

				swap = 1;
				
				result++;
			}
		}

		start++;
	}

	if(result <= col){
	    
	    printf("true");
	}
	else{
	    
	    printf("false");
	}

	free(arr);

	return 0;
}