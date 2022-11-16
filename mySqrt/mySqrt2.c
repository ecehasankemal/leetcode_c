int	mySqrt(int x)
{
	if (x < 0)
		return (0);
	long	res;

	res = x;
	while (res * res > x)
	{
		res = (res + x / res) / 2;
	}
	return ((int)res);
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;

	a = 4;
	b = 8;
	c = -4;
	printf("%d\n", mySqrt(a));
	printf("%d\n", mySqrt(b));
	printf("%d", mySqrt(c));

	return (0);
}

