#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    int index = 0;
    int j;

    int count = 1;
    for (int i = 1; i < numsSize - 1; i++){

        int j = i + 1;
        for (j; j < numsSize - 1; j++){
            if (nums[j] > nums[i] && nums[j] > nums[i-1]){
                count++;
                break;
            }
        }
        if (nums[i] <= nums[i-1]){
            printf("nums[%d] = %d | nums[%d] = %d\n", i,nums[i], j,nums[j]);
            nums[i] = nums[j];


        }
    }
    for (int i = 0 ; i < numsSize ; i++){
        printf("%d\n",nums[i]);
    }


    return count;
}

int main()
{
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    // int a[3] = {1,1,2};
    // int k = removeDuplicates(a, 3);
    int k = removeDuplicates(a, 10);
    printf("k=%d\n", k);
}