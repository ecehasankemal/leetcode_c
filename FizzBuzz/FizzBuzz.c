char	**fizzBuzz(int n, int *returnSize)
{
	int	iter;
	int	dop;

	iter = 0;
	dop = 1;
	*returnSize = n;
	char **result = (char **)malloc(n * sizeof(char *));
	while
