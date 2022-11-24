const int	maxi = 2147483647;

int reverse(int x)
{
	long long	result;
	int		last;

	result = 0;
        while (x != 0)
	{
            last = x % 10;
            x /= 10;
            result = result * 10 + last;
        }
        if ((result > maxi) || (result < -maxi))
		return (0);
    return (result);
}

#include <stdio.h>

int	main(void)
{
	int	value;
	int	res;

	value = -123;
	res = reverse(value);
	printf("ilk değer %d , ikinci değer %d dir", value, res);
	return (0);
}

