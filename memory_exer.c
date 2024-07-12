#include <stdio.h>
#include <stdlib.h>

struct array_pair
{
    int * nums;
    /* nums is the actual integers in the area */
    int nums_count;
    /* the number of integers in the array */
};

int main(){
    struct array_pair * arrays;
    int i, j;
    int array_count;
    printf("please enter number of arrays:\n");
    /*  the first scan to count how much arrays are there */
    scanf("%d", &array_count);
    arrays = malloc(sizeof(struct array_pair) * array_count);
    /* the malloc setted the memory by the size of the array * the size of the struct */
    for (i = 0; i < array_count; i++)
    {
        printf("please enter size of %d array\n",i);
        /* here we size of each array */
        scanf("%d",&(arrays[i].nums_count));
        arrays[i].nums = malloc(sizeof(int) * arrays[i].nums_count);
    }
    for(i =0; i<array_count; i++){
        printf("please enter %d integers for array%d:\n",arrays[i].nums_count,i);
        for (j = 0; j < arrays[i].nums_count ; j++)
        {
            scanf("%d", &(arrays[i].nums[j]));
        }
    }
    for(i = 0;i< array_count;i++){
        printf("the integers of array %d are:\n",i);
        for (j = 0; j < arrays[i].nums_count; j++)
        {
            printf("%d ",arrays[i].nums[j]);
        }
        printf("\n");
    }
    return 0;

}
