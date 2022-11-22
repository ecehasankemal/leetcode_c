#include <stdlib.h>
#include <stdio.h>

int	*twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int	count;
	int	dop;
	int	*result;

	*returnSize = 2;
	result = (int *)malloc(sizeof(int) * 2);
	count = -1;
	while (++count < numsSize)
	{
		dop = count;
		while (++dop < numsSize)
		{
			if (nums[count] + nums[dop] == target)
			{
				result[0] = count;
				result[1] = dop;
				return (result);
			}
		}
	}
	return (result);
}

int	main(void)
{
	int	nums[] = {2,7,11,15};
	int	returnSize;

	int	*data = twoSum(nums, 4, 9, &returnSize);

	while (returnSize--)
	{
		printf("%d ", data[returnSize]);
	}

	free(data);
	return (0);
}
