#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

bool overlapCheck(int* used, int num, int i) {
	bool overlap = false;

	for (int j = 0; j < i; j++) {
		if (num == used[i]) {
			overlap = true;
			break;
		}
	}

	return overlap;
}

int main() {
	char suit[4][64] = { "Spades", "Diamonds", "Hearts", "Clubs" };
	char card[13][16] = { "A", "2", "3", "4", "5", "6", "7", "8", "10", "10", "J", "Q", "K" };
	int sRand, cRand;
	int used[52];
	char deck[52][64];

	int player = 0;
	int card_per_player = 0;

	srand(time(0));

	printf("How many players? ");
	scanf("%d", &player);
	printf("How many cards per player? ");
	scanf("%d", &card_per_player);

	int k = 0;
	for (int p = 0; p < player; p++) {
		printf("--Player %d--\n", p + 1);
		for (int i = 0; i < card_per_player; i++) {
			sRand = rand() % 4;
			cRand = rand() % 13;

			int num = sRand * 100 + cRand;
			sprintf(deck[i], "%2s %s", card[cRand], suit[sRand]);
			if (overlapCheck(used, num, i) == true) {
				i--;
			}
			else {
				used[k] = num;
				k++;
			}
			printf("%s\n", deck[i]);
		}
		printf("\n");
	}
}
