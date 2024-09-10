#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    int index = 0;
    int j = 1;

    int count = 1;
    int valid = 0;
    for (j; j < numsSize; j++){
        if (nums[j] > nums[0]){
            valid = 1;
            break;
        }
    }
    if (valid == 0)
        return 1;

    for (int i = 1; i < numsSize; i++){

        count++;
        if (nums[i] == nums[numsSize - 1]){
            return count;
        }
        if (nums[i] <= nums[i-1]) {
            nums[i] = nums[j];
            if (nums[i] == nums[numsSize - 1]){
                return count;
            }
            for (int k = j + 1; k < numsSize; k ++){
                if (nums[k] > nums[j]){
                    j = k;
                    break;
                }
            }
        }
    }
    return count;
}

int main()
{
    int a[] = {-1,-1,1,1,2,2,2,3,3,4,4,4,4,4};
    int b[] = {1,2,2,3};
    // int a[3] = {1,1,2};
    int k = removeDuplicates(a, 11);
    int k2= removeDuplicates(b, 4);
    printf("k=%d\n", k);
    printf("k2=%d\n", k2);

    
}