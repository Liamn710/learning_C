#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr = NULL;
    int count;
    int i;
    scanf("%d",&count);
    arr = malloc(count * sizeof(*arr));
    //malloc sets the bytes for the array in the memmory, 
    //calloc does the same only it sets the bytes as 0's before the array is set 
    for (i=0;i<count;i++)
    {
        scanf("%d",&arr[i]);
    }
    return 0;
}