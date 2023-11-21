#include<stdio.h>

int main()
{
	int a[100],b[100],sc,k,i,gar[100],add;
	scanf("%d", &k);
	add = 0;

	for (sc = 0; sc < k; sc++)
	{
		scanf("%d %d", &a[sc], &b[sc]);
	}
	for (sc = 0; sc<k; sc++)
	{
		for (i=0; i>=0 ;i++)
		{
			gar[sc]= b[sc] - i*a[sc];
			if (b[sc] - i*a[sc] < a[sc])
				break;
		}
	}
	for (sc = 0; sc < k; sc++)
	{
		add += gar[sc];
	}
	printf("%d", add);


	return 0;
}