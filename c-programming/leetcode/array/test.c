#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    for (int i = 1; i < numsSize; i++){
        if (nums[i] == nums[i-1])
            if (i + 1 < numsSize)
                nums[i] = nums[i+1];
    }

    for (int i = 0; i < numsSize; i++)
        printf("%d\n", nums[i]);
    return 0;
}

int main()
{
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(a, 10);
}