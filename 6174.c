#include<stdio.h>
#include<stdlib.h>

int get_max(const void* a, const void* b) {
	const int* p1 = (const int*)a;
	const int* p2 = (const int*)b;
	return (*p2 - *p1);
}

int get_min(const void* a, const void* b) {
	const int* p1 = (const int*)a;
	const int* p2 = (const int*)b;
	return (*p1 - *p2);
}

int get_digit(int n, int* num) {
	num[0] = n / 1000;
	int hun_tmp = n / 100;
	num[1] = hun_tmp % 10;
	int ten_tmp = n / 10;
	num[2] = ten_tmp % 10;
	num[3] = n % 10;

	return *num;
}
int main() {
	int num[4] = { 0 };
	int size = sizeof(num) / sizeof(num[0]);
	int max[4] = { 0 }, min[4] = { 0 };
	int n;
	int max_num, min_num;

	int run_count, count = 0;
	scanf("%d", &run_count);
	int* arr = (int*)malloc(sizeof(int) * run_count);

	for (int i = 0; i < run_count; i++) {
		scanf("%d", &n);
		while (1) {
			if (n == 6174) break;
			count++;
			get_digit(n, num);
			for (int i = 0; i < 4; i++) {
				max[i] = num[i];
				min[i] = num[i];
			}
			qsort(max, size, sizeof(max[0]), get_max);
			qsort(min, size, sizeof(min[0]), get_min);

			max_num = (max[0] * 1000) + (max[1] * 100) + (max[2] * 10) + max[3];
			min_num = (min[0] * 1000) + (min[1] * 100) + (min[2] * 10) + min[3];

			n = max_num - min_num;
		}
		arr[i] = count;
		count = 0;
	}

	for (int i = 0; i < run_count; i++) printf("%d\n", arr[i]);

	free(arr);
}
