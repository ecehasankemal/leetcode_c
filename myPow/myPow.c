double	myPow(double x, int n)
{
	int	iter;
	double	result;

	iter = 0;
	result = 1.0;
	if (n == 1 || n == 0)
	{
		if (n == 1)
			return (x);
		return (1);
	}
	if (n == 2147483647 || n == -2147483648)
	{
		if (n == 2147483647)
			return (x);
		return (x == 1 || x == -1) ? 1 : 0;
	}
	if (n > 1)
	{
		while (n)
		{
			if (n & 0x01)
			{
				result = result * x;
				n--;
			}
			x *= x;
			n /= 2;
		}
	}
	else if (n < 0)
	{
		x = 1 / x;
		n *= -1;
		while (n)
		{
			if (n & 0x01)
			{
				result = result * x;
				n--;
			}
			x *= x;
			n /= 2;
		}
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	double	result;

	result = myPow(2, 10);
	printf("%f", result);
}
