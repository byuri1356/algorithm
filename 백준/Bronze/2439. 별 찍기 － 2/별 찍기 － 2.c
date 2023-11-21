#include<stdio.h>

int main()
{
	int x,y,z;
	scanf("%d",&z);

	for(y=0 ;y<z ; y++)
	{
		for(x = 0 ; x<z-y-1 ; x++)
		{
			printf(" ");
		}
		for(x = 0 ; x<=y ; x++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}