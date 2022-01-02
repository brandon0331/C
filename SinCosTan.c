#include<stdio.h>
#include<math.h>
#include<Windows.h>

#define PI 3.1415926

int main() {
	int x;

	printf("x = ");
	scanf("%d", &x);

	printf("sin %d = %.6f\n", x, sin(PI * x / 180));
	printf("cos %d = %.6f\n", x, cos(PI * x / 180));
	printf("tan %d = %.6f\n", x, tan(PI * x / 180));

	return 0;
}
