#include<stdio.h>

int main()
{
	int x,y,z;
	scanf("%d",&z);

	for(y=z ;y>0 ; y--)
	{
		for(x = 0; x<z-y ; x++)
		{
			printf(" ");
		}

		for(x = 0 ; x<y ; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}