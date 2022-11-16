#include <stdbool.h>

bool	isPalindrome(int x)
{
	int	temp;
	int	reverse;
	int	remove;

	if (x < 0)
		return (false);
    if (x >= 0 && x < 10)
        return (true);
	temp = x;
	while (temp != 0)
	{
		remove = temp % 10;
        if (reverse > (2147483647 - remove) / 10)
            return (false);
		reverse = reverse * 10 + remove;
		temp = temp / 10;
	}
	return (reverse == x);
}

#include <stdio.h>

int	main(void)
{
	int	a;

	a = 120;
	printf("%d", isPalindrome(a));
}
