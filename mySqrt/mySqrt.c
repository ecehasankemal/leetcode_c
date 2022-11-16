int	mySqrt(int x)
{
	int	tut;
	int	cikar;
	
	if (x < 0)
		return (0);
	cikar = 1;
	tut = 0;
	while (x > 0)
	{
		x -= cikar;
		cikar += 2;
		tut++;
	}
	if (x == 0)
		return (tut);
	return (tut - 1);
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 4;
	b = 8;
	printf("%d\n", mySqrt(a));
	printf("%d", mySqrt(b));

	return (0);
}
