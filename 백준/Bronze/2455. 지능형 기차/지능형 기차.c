#include<stdio.h>

int main()
{
	int a, b, c, d, e, f, g, h, max, num;
	scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);

	max = b;
	num = max;
	if (max - c + d > max)
		num = max - c + d;
	if (max - c + d - e + f > num)
		num = max - c + d - e + f;

	printf("%d\n", num);

	return 0;
}