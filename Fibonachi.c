#include<stdio.h>

int main() {
	int a, b, c = 0;
	int n;
	
	scanf("%d", &n);

	a = 0;
	b = 1;

	for (int i = 0; i < n; i++) {
		a = b;
		b = c;
		c = a + b;
	}
	printf("%d ", c);
}
