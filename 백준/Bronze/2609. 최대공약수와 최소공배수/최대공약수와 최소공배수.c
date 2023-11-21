#include<stdio.h>

int main()
{
	int x, y,k;
	scanf("%d %d", &x, &y);

	if (x > y)
	{
		for (k = y ; k>0 ; k--)
		{
			if (x%k == 0 && y%k== 0)
				break;
		 }
		printf("%d ", k);
		for (k = x; k >= x; k++)
		{
			if (k%x == 0 && k%y == 0)
				break;
		}
		printf("%d", k);

	}
	else
	{
		for (k = x; k>0; k--)
		{
			if (x%k == 0 && y%k == 0)
				break;
		}
		printf("%d ", k);
		for (k = y; k >= y; k++)
		{
			if (k%x == 0 && k%y == 0)
				break;
		}
		printf("%d", k);
	}

	return 0;
}