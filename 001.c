#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
		int i,j;
		int *temp = (int *)malloc(sizeof(int)*2);
		for(i=0;i<numsSize-1;i++)
		{
				for(j=i+1;i<numsSize;j++)
				{
						if(i!=j&&nums[i]+nums[j]==target)
						{
								temp[0] = i;
								temp[1] = j;
						}
				}
		}
		nums = (int *)malloc(sizeof(int)*2);
		nums[0] = temp[0];
		nums[1] = temp[1];
		return nums;
}
int main()
{
		int * nums = (int *)malloc(4*sizeof(int));	
		nums[0] = 2;
		nums[1] = 7;
		nums[2] = 11;
		nums[15] = 15;
		int *a =  twoSum(nums,4,9);
		for(int i=0;nums[i]!='\0';++i)
				printf("i:%d value:%d",i,a[i]);

		return 0;
}
