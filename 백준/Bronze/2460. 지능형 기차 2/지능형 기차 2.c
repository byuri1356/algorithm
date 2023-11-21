#include<stdio.h>

int main()
{
	int a, b, c, d, e, f, g, h, max, num;
	int i, j, k, l, m, n, o, p, q, r, s, t;
	scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &i, &j, &k, &l, &m, &n, &o, &p ,&q,&r,&s,&t);

	max = b;
	num = max;
	if (max - c + d > max)
		num = max - c + d;
	if (max - c + d - e + f > num)
		num = max - c + d - e + f;
	if (max - c + d - e + f - g + h > num)
		num = max - c + d - e + f - g + h;
	if (max - c + d - e + f - g + h - i + j > num)
		num = max - c + d - e + f - g + h - i + j;
	if (max - c + d - e + f - g + h - i + j - k + l > num)
		num = max - c + d - e + f - g + h - i + j - k + l;
	if (max - c + d - e + f - g + h - i + j - k + l - m + n > num)
		num = max - c + d - e + f - g + h - i + j - k + l - m + n;
	if (max - c + d - e + f - g + h - i + j - k + l - m + n - o + p > num)
		num = max - c + d - e + f - g + h - i + j - k + l - m + n - o + p;
	if (max - c + d - e + f - g + h - i + j - k + l - m + n - o + p - q + r > num)
		num = max - c + d - e + f - g + h - i + j - k + l - m + n - o + p - q + r;



	printf("%d\n", num);

	return 0;
}