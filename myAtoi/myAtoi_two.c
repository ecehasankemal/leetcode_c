int
	myAtoi(char *string)
{
	register int    sign;
	register long   result;
	
	result = 0;
	sign = 1;
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	if (*string == '+' || *string == '-')
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (*string >= 48 && *string <= 57 && *string && result < 2147483648)
		result = (result * 10) + (*string++ & 15);
	if (result > 2147483647)
	{
		if (sign == -1)
			return (-2147483648);
		else
			return (2147483647);
	}
	return (result * sign);
}
