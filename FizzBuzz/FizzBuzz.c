#include <stdio.h>
#include <stdlib.h>

char	**fizzBuzz(int n, int *returnSize)
{
	char	**return_var;
	int	count;

	count = 0;
	return_var = (char **)(malloc(sizeof(char *) * n));
	while (++count <= n)
	{
		if ((count % 3 == 0) && (count % 5 == 0))
			return_var[count - 1] = "FizzBuzz";
		else if (count % 3 == 0)
			return_var[count - 1] = "Fizz";
		else if (count % 5 == 0)
			return_var[count - 1] = "Buzz";
		else
		{
			return_var[count - 1] = (char *)(malloc(sizeof(char) * 10));
			sprintf((char *)return_var[count - 1], "%d", count);
		}
	}
	*returnSize = n;
	return (return_var);
}

int    main(void)
{
    char	**str;
    int		in;
    int		*tmp;

    *tmp = 0;
    printf("enter input: ");
    scanf("%d",&in);
    str = fizzBuzz(in,tmp);
    for(int i = 0; i < in ; i++)
    {
        printf("%s\n",str[i]);
    }
    free(str);
    return (0);
}
