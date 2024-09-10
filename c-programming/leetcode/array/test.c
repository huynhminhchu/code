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
    printf("j=%d\n", j);

    for (int i = 1; i < numsSize; i++){
        // if (j + 1 > numsSize){
        //     printf("break.\n");
        //     break;
        // }
        count++;
        if (nums[i] <= nums[i-1]) {
            nums[i] = nums[j];
            if (nums[i] == nums[numsSize - 1])
                break;
            for (int k = j + 1; k < numsSize; k ++){
                if (nums[k] > nums[j]){
                    j = k;
                    break;
                }
                    
            }
            printf("k=%d after the loop.\n", j);
        }

    }
    for (int i  = 0; i < numsSize - 1; i++){
        printf("%d\n", nums[i]);
    }
    return count;
}

int main()
{
    int a[10] = {-1,-1,1,1,2,2,2,3,3,4};
    int b[] = {1,1};
    // int a[3] = {1,1,2};
    // int k = removeDuplicates(a, 3);
    // int k = removeDuplicates(a, 10);
    int k2= removeDuplicates(b, 2);
 //   printf("k=%d\n", k);
    printf("k2=%d\n", k2);
}