#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	romanToInt(char *s)
{
	int	I;
	int	V;
	int	X;
	int	L;
	int	C;
	int	D;
	int	M;
	int	iter;
	int	result;

	I = 1;
	V = 5;
	X = 10;
	L = 50;
	C = 100;
	D = 500;
	M = 1000;
	iter = 0;
	result = 0;

	while (s[iter] != '\0')
	{
		if (s[iter] == 'M')
			result += M;
		if (s[iter] == 'D')
			result += D;
		if (s[iter] == 'C')
		{
			if ((s[iter + 1] == 'D' || s[iter + 1] == 'M') 
				&& (iter + 1 != ft_strlen(s)))
				result -= C;
			else
				result += C;
		}
		if (s[iter] == 'L')
			result += L;
		if (s[iter] == 'X')
		{
			if ((s[iter + 1] == 'L' || s[iter + 1] == 'C') 
				&& (iter + 1 != ft_strlen(s)))
				result -= X;
			else
				result += X;
		}
		if (s[iter] == 'V')
			result += V;
		if (s[iter] == 'I')
		{
			if ((s[iter + 1] == 'V' || s[iter + 1] == 'X')
				&& (iter + 1 != ft_strlen(s)))
				result -= I;
			else
				result += I;
		}
		iter++;
	}
	return (result);
}


int	main(void)
{
	int	result;
	char	*str;

	str = "MCMXCIV";
	result = romanToInt(str);
	printf("%d", result);
}
