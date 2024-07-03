#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_compare(const void *a, const void *b){
    const int *ai = a;
    const int *bi = b;
    return (*ai) - (*bi); 
}
int int_compare_for_even_odd(const void *a, const void *b){
    const int *ai = a;
    const int *bi = b;
    /* in this comare func we give the weights of each value, if the value is even and the is odd the
    odd value will come before the even one. if they are both even, the weights are meaningless and 
    they will be compared for the face value*/
    if((*ai)%2 == 0 && (*bi)%2 == 0){
        return 0;
        /*both are even so the weights are meaningless, 0 is meaningless*/
    } 
    else if ((*ai)%2 == 0)
    {
        return -1;
        /* the negative shows that the value should be in a lower position in the array */
    }
    else if((*bi)%2 == 0){
        return 1;
        /* the positive shows that the value should be in a higher position in the array */
    }
    /*the only case left is all odd, that we dont need to state cause it will get no weights(0)*/
    return 0;
}
void print_strings_arr(const char ** arr, int size){
    int i;
    for ( i = 0; i < size; i++)      
        {
        printf("%s ", arr[i]);
        }
    printf("\n");
    
}
int string_cmpr(const void *a, const void *b){
    /*the method for compering the strings */
    const char *const *str1 = a;
    const char *const *str2 = b;
    return strcmp(*str1, *str2);
}
void print_arr(const int * arr, int size){
    int i;
    for(i = 0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[10] = {4,9,2,1,3,6,5,7,8};
    const char *strings[4] = {
        "cdb", "asd", "tsd", "ils"
    };
    print_arr(arr,10);
    qsort(&arr[0], 10, sizeof(int),int_compare);
    print_arr(arr,10);
    qsort(&arr[0], 10, sizeof(int),int_compare_for_even_odd);
    print_arr(arr,10);
    print_strings_arr(&strings[0],4);
    qsort(&strings[0], 4, sizeof(void *), string_cmpr);
    print_strings_arr(&strings[0],4);
    return 0;
}