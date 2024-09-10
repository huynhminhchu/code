#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    nums = realloc(nums, sizeof(int) * 100);
    nums[numsSize] = 100;
}

int main()
{
    int a[3] = {1,1,2};
    removeDuplicates(a, 3);
}