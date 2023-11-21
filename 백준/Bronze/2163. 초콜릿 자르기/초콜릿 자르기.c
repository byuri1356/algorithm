#include<stdio.h>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	if (x==1 && y!=1)
		printf("%d", y - 1);
	if (x != 1 && y == 1)
		printf("%d", x - 1);
	if (x == 1 && y == 1)
		printf("0");
	if (x != 1 && y != 1)
		printf("%d", x*(y - 1) + (x - 1));

	return 0;
}