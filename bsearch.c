#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_strings_arr(const char ** arr, int size){
    int i;
    for ( i = 0; i < size; i++)      
        {
        printf("%s ", arr[i]);
        }
    printf("\n");
}
int string_cmpr(const void *a, const void *b) {
    /*the method for compering the strings for the sort */
    const char *const *str1 = a;
    const char *const *str2 = b;
    return strcmp(*str1, *str2);
}
int str_cmp(const char *a, const char **b){
    /*the method for compering the strings for the search */
    return strcmp(a,*b);
}
int main(){
    char str[80];
    const char *find;
    const char *strings[4] = {
        "abc", "123", "asd", "456"
    };
    qsort(&strings[0], 4, sizeof(void *), string_cmpr);
    for(;;){
        scanf("%s", str);
        find = bsearch(&str[0],&strings[0],4,sizeof(void *),(int (*)(const void*,const void *))str_cmp);
        if(find != NULL){
            printf("found :%s\n", str);
        }
        else{
            printf("not found :%s\n", str);
        }
    }
    print_strings_arr(&strings[0],4);
    return 0;
}