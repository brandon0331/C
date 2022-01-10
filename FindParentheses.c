#include<stdio.h>
#include<stack>

std::stack<int> S;

int main() {
	char string[100];

	gets_s(string, sizeof(string));
	int len = strlen(string);

	for (int i = 0; i < len; i++) {
		if (string[i] == '(') S.push(i);
		if (string[i] == ')') {
			printf("%d %d\n", S.top(), i);
			S.pop();
		}
	}
}
