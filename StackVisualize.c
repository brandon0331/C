#include<stdio.h>
#include<Windows.h>
#include<stack>

std::stack<int> S;
std::stack<int> S2;

int main() {
	int choice;

	while (1) {
		system("cls");
		int S_size = S.size();
		for (int i = 0; i < S_size; i++) {
			printf("|  %2d  |\n+------+\n", S.top());
			S2.push(S.top());
			S.pop();
		}
		int S2_size = S2.size();
		for (int i = 0; i < S2_size; i++) {
			S.push(S2.top());
			S2.pop();
		}
		printf("\n1.Push\n2.Pop\n> ");
		scanf("%d", &choice);

		if (choice == 1) {
			int tmp;
			printf("Number: ");
			scanf("%d", &tmp);
			S.push(tmp);
		}
		else if (choice == 2) {
			S.pop();
		}
	}
}
