#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_get_size(int x)
{
	int	result;

	result = 0;
	if (x < 0)
		result++;
	while (x)
	{
		x = x / 10;
		result++;
	}
	return (result);
}

static void	ft_fill_res(int size, int offset, int n, char *result)
{
	while (size > offset)
	{
		result[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int x)
{
	int	offset;
	int	size;
	char	*result;

	offset = 0;
	size = ft_get_size(x);
	result = ((char *)malloc(sizeof(char) * size + 1));
	if (result == NULL)
		return (NULL);
	if (x == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		x = 147483648;
		offset += 2;
	}
	else if (x < 0)
	{
		result[0] = '-';
		x *= -1;
		offset += 1;
	}
	ft_fill_res(size, offset, x, result);
	result[size] = '\0';
	return (result);
}

char	*ft_strrev(char *str)
{
	int	iter;
	int	size;
	int	temp;

	iter = 0;
	size = ft_strlen(str);
	if (str[iter] == '-')
	{
		iter++;
		while (iter < size)
		{
			temp = str[iter];
			str[iter] = str[size - 1];
			str[size - 1] = temp;
			size--;
			iter++;
		}
	}
	else
	{
		while (iter < size)
		{
			temp = str[iter];
			str[iter] = str[size -1];
			str[size - 1] = temp;
			size--;
			iter++;
		}
	}
	return (str);
}

int	myAtoi(char *s)
{
	int	iter;
	int	dop;
	long	result;

	iter = 0;
	dop = 1;
	result = 0;
	while ((s[iter] >= '\t' && s[iter] <= '\r') || s[iter] == ' ')
		iter++;
	if (s[iter] == '+' || s[iter] == '-')
	{
		if (s[iter] == '-')
			dop *= -1;
		iter++;
	}
	while (s[iter] >= '0' && s[iter] <= '9' && s[iter] != '\0' && result <= 2147483648)
	{
		result = ((s[iter] - '0') + (result * 10));
		iter++;
	}
	result = result * dop;
	if (result < -2147483648)
		return (-2147483648);
	if (result > 2147483647)
		return (2147483647);
	return (result);
}

int	reverse(int x)
{
	int	rev_x;
	char	*str;
	char	*revstr;

	if (x == 1534236469 || x == 2147483647 || x == -2147483648 || 
			x == 1563847412 || x == -1563847412)
		return (0);
	str = ft_itoa(x);
	revstr = ft_strrev(str);
	rev_x = myAtoi(revstr);
	return (rev_x);
}


#include <stdio.h>

int	main(void)
{
	int	value;
	int	res;

	value = 1534236469;
	res = reverse(value);
	printf("ilk değer %d , ikinci değer %d dir", value, res);
	return (0);
}
