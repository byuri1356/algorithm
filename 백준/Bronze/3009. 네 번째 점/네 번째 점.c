#include<stdio.h>

int main()
{
	int x,y;
	int	z,a;
	int	b,c;
	scanf("%d %d %d %d %d %d",&x,&y,&z,&a,&b,&c);

	if(x==z)
	{
		if(y==c)
			printf("%d %d",b,a);
		else
			printf("%d %d",b,y);
	}
	else if(x==b)
	{
		if(y==a)
			printf("%d %d",z,c);
		else
			printf("%d %d",z,y);
	}
	else
	{
		if(a==y)
			printf("%d %d",x,c);
		else
			printf("%d %d",x,a);
	}

	return 0;
}