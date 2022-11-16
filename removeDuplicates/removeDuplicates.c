int	removeDuplicates(int *nums, int numSize)
{
	int	iter;
	int	count;

	iter = 0;
	count = 0;
	while (iter < numSize)
	{
		if (iter == 0 || nums[iter] > nums[iter - 1])
			nums[count++] = nums[iter];
		iter++;
	}
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int	array[] = {1, 1, 2, 3};
	int	result;

	result = removeDuplicates(array, 4);
	printf("%d", result);
}
