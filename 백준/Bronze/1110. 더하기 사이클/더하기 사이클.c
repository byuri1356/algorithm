#include<stdio.h>

int main()
{
	int x,y,z,fir,sum,cycle;
	scanf("%d",&x);
	fir=x;
	y=(x%10);     //26 -> 6
	z=(x-y)/10;   //26 -> 2
	sum=y+z;

	for(cycle=1;cycle>=0;cycle++)
	{
	if(sum>=10)
		sum-=10;
		
	if(fir==10*y+sum)
		break;
	else{
		x=10*y+sum;
		y=(x%10);     //26 -> 6
	z=(x-y)/10;   //26 -> 2
	sum=y+z;
	}
	}
	printf("%d",cycle);

	return 0;
}

