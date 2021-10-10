#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	returnSize = malloc(2 * sizeof(int));
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				returnSize[0] = i;
				returnSize[1] = j;
				return returnSize;
			}
		}
	}
	return returnSize;
}

int main()
{
	int nums[] = {2, 7, 11, 15};
	int *res;
	res = twoSum(nums, 4, 9, res);
	printf("%d %d\n", nums[res[0]], nums[res[1]]);
	return 0;
}
