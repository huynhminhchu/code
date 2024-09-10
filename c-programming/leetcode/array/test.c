#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    int index = 0;
    int j = 1;

    int count = 1;

    for (j; j < numsSize; j++){
        if (nums[j] > nums[1]){
            break;
        }
    }

    for (int i = 1; i < numsSize - 1; i++){

        if (nums[i] == nums[i-1]) {
            nums[i] = j;
            count++;
        }
        for (k = j; k < numsSize - 1; k ++){
            
        }
    }


    return count;
}

int main()
{
    int a[10] = {-1,-1,0,1,1,2,2,3,3,4};
    int b[3] = {1,1,2};
    // int a[3] = {1,1,2};
    // int k = removeDuplicates(a, 3);
    int k = removeDuplicates(a, 10);
    // int k2= removeDuplicates(b, 3);
    printf("k=%d\n", k);
    // printf("k2=%d\n", k2);
}