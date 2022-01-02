#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX 45
#define COUNT 6

bool overlapCheck(int* number, int randNum, int count) {
	bool overlap = false;

	for (int i = 0; i < count; i++) {
		if (randNum == number[i]) {
			overlap = true;
			break;
		}
	}

	return overlap;
}

int main() {
	int number[COUNT];

	srand(time(NULL));

	for (int t = 0; t < COUNT; t++) {
		printf("== Case %d ==\n", t + 1);

		for (int i = 0; i < COUNT; i++) {
			int randNum = rand() % MAX + 1;
			bool overlap = overlapCheck(number, randNum, i);

			if (overlap == true) i--;
			else number[i] = randNum;
		}

		for (int i = 0; i < COUNT; i++) {
			printf("Number %d: %2d\n", i + 1, number[i]);
		}
		printf("\n");
	}
}
