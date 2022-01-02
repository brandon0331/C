#include<stdio.h>
#include<stdlib.h>

int main() {
	int num = 160401;
	int* arr;

	int cnt = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			cnt++;
		}
	}

	arr = (int*)malloc(sizeof(int) * cnt);
	for (int i = 0; i < cnt; i++) arr[i] = 0;

	int idx = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			arr[idx] = i;
			printf("%d ", arr[idx]);
			idx++;
		}
	}

	printf("\n");

	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		int check = arr[i] / 2;
		int flag = 0;

		if (arr[i] > 1) {
			for (int j = 2; j <= check; j++) {
				if (arr[i] % j == 0) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				printf("%d ", arr[i]);
				sum += arr[i];
			}
		}
	}

	printf("\n%d", sum);
}
