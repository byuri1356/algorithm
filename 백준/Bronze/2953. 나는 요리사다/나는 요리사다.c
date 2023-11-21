#include<stdio.h>

int main()
{
	int a[4], b[4], c[4], d[4], y[4], k;
	int q, w, e, r, t, max;
	q = 0, w = 0, e = 0, r = 0, t = 0;
	for (k = 0; k <= 3; k++)
	{
		scanf("%d", &a[k]);
	}
	for (k = 0; k <= 3; k++)
	{
		scanf("%d", &b[k]);
	}
	for (k = 0; k <= 3; k++)
	{
		scanf("%d", &c[k]);
	}
	for (k = 0; k <= 3; k++)
	{
		scanf("%d", &d[k]);
	}
	for (k = 0; k <= 3; k++)
	{
		scanf("%d", &y[k]);
	}
	for (k = 0; k <= 3; k++)
	{
		q += a[k];
		w += b[k];
		e += c[k];
		r += d[k];
		t += y[k];
	}
	max = 0;
	if (q > max)
		max = q;
	if (w > max)
		max = w;
	if (e > max)
		max = e;
	if (r > max)
		max = r;
	if (t > max)
		max = t;

	if (max == q)
		printf("1 ");
	if (max == w)
		printf("2 ");
	if (max == e)
		printf("3 ");
	if (max == r)
		printf("4 ");
	if (max == t)
		printf("5 ");
	printf("%d", max);



	return 0;
}