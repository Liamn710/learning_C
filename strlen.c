#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    size_t len;
    char * new_argv2;
    char * copy;
    int i = 0;
    printf("original argv[2]:%s\n",argv[2]);
    len =  strlen(argv[2]);
    new_argv2 = malloc(len +1);
    copy = &argv[2][len - 1];
    while (copy >= &argv[2][0])
    {
        new_argv2[i] = *copy;
        copy--;
        i++;
    }
    new_argv2[i] = '\0';
    printf("new arvg[2]: %s \n",new_argv2);
    free(new_argv2);
    return 0;
    
}