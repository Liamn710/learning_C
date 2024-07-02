#include <stdio.h>
/* this code is meant to show how "strings" in C work, the char** is pointing on multiple char* 
that each of them is a char. The argc counts how much char* we have. The argv is the chars* array,
so each value of the array points to an argument that is added to the code.
compile the code with gcc and run the a.out file with arguments.
*/
int main(int argc, char ** argv){
    int i;
    argc--; /*removing the first arg that is the program name, which will be a segmentation fault*/
    argv++; /*moving the pointer to the next value in the array because we removed it the line before*/
    for(i = 0; i<argc; i++){
        printf("%s\n",argv[i]);
    }
    return 0;
}