#include <stdio.h>

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

int	main(void)
{
	printf("%d", myAtoi("20000000000000000000"));
}
