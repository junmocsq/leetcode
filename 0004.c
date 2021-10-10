#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int mid = (nums1Size + nums2Size) / 2;
    if (mid == 0)
    {
        if (nums1Size == 0)
            return nums2[0];
        if (nums2Size == 0)
            return nums1[0];
    }
    int isOdd = (nums1Size + nums2Size) % 2 == 1;
    int i = 0, j = 0;
    int t1, t2; // 记录相邻大小的两个数
    for (int index = 0; index <= mid; index++)
    {
        if (i == nums1Size)
        {
            if (index == 0)
                t2 = nums2[j];
            else
                t1 = t2, t2 = nums2[j];
            j++;
        }
        else if (j == nums2Size)
        {
            if (index == 0)
                t2 = nums1[i];
            else
                t1 = t2, t2 = nums1[i];
            i++;
        }
        else
        {
            if (nums1[i] < nums2[j])
            {
                if (index == 0)
                    t2 = nums1[i];
                else
                    t1 = t2, t2 = nums1[i];
                i++;
            }
            else
            {
                if (index == 0)
                    t2 = nums2[j];
                else
                    t1 = t2, t2 = nums2[j];
                j++;
            }
        }
    }
    return isOdd ? t2 : (t2 + t1) / 2.0;
}

int main()
{
    int arr1[] = {1, 3};
    int arr2[] = {2, 4};
    printf("%lf\n", findMedianSortedArrays(arr1, 2, arr2, 2));

    return 0;
}