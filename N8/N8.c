#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int a[201] = {0};

	for (int i = 0; i < n; i++) {

		int num;
		scanf("%d", &num);
		
		if(num < -100){
		    
		    num == -100;
		}
		else if(num > 100){
		    
		    num = 100;
		}

		a[num + 100]++;
	}

	for (int i = 0; i < 201; i++) {

		int result = i - 100;

		for (int j = 0; j < a[i]; j++) {

			printf("%d ", result);
		}
	}

	return 0;
}