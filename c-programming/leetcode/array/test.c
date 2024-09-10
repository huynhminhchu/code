#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    int *a = malloc(numsSize * sizeof(int));
    a[0] = nums[0];
    printf("Hello World.\n");
    if (numsSize == 1){
        return 1;
    }
    printf("Hello World.\n");
    int j = 1;
    for (int i = 1; i < numsSize; i++){
        if (nums[i] != nums[i-1]) {
            a[j] = nums[i];
            printf("nums[i]=%d\n", nums[i]);
            printf("A[j]=%d\n", a[j]);
            j++;
        }
    }
    return j;
}

int main()
{
    int a[3] = {1,1,2};
    removeDuplicates(a, 3);
}