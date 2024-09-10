#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    int index = 0;
    int j;


    for (int i = 1; i < numsSize; i++){

        int j = i + 1;
        for (j; j < numsSize; j++){
            if (nums[j] != nums[i]){
                printf("a[j] = %d\n", nums[j]);
                break;
            }
        }
        if (nums[i] == nums[i-1]){
            nums[i] = nums[j];
        }
    }
    for (int i = 0 ; i < numsSize ; i++){
        printf("%d\n",nums[i]);
    }


    return 0;
}

int main()
{
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(a, 10);
}