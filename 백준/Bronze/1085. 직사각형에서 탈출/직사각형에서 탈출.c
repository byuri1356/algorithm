#include<stdio.h>

int main()
{
	int a, b, c, d,min;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	min = 1000;
	
	if (c - a < min)
		min = c - a;
	if (a < min)
		min = a;
	if (d - b < min)
		min = d - b;
	if (b < min)
		min = b;

	printf("%d", min);

	return 0;
}