#include <stdio.h>

struct context 
{
    char operator; /*'+','-','/','*'*/
    int operand;
};
/*this is the actual action, depends on the context struct it will do what ever*/
void my_function(int *item,void *context){
    struct context * c = context;
    switch (c->operator)
    {
    case '+':
        (*item)+= c->operand;
        break;
    case '-':
        (*item)-= c->operand;
        break;
    case '/':
        (*item)/= c->operand;
        break;
    case '*':
        (*item)*= c->operand;
        break;
    default:
        break;
    }
}

/* this function iterates an array and does an action by a function chosen*/
void itererate_and_do(int *arr, int arr_size, void * context, void(*my_function)(int *item, void * context)){
    int i;
    for(i = 0; i <arr_size; i++){
        my_function(&arr[i], context);
    }
}
/* just an example of a regular func*/
void add_c(int * arr, int arr_size, const int c){
int i;
for(i = 0; i< arr_size; i++){
    arr[i]+=c;
}
}
/* we use this to show it works*/
void print_array(int * arr, int arr_size){
int i;
for ( i = 0; i < arr_size; i++)
{
    printf("%d \n",arr[i]);
}

}
/*first we chose the context(the action) for our generic funcs, hen we init the array and performed 
 the generic function a few time with different context to show the versitiliy*/
int main(){
    struct context c = {'+', 2};
    int x[10] = {1,2,3,4,5,6,7,8,9,};
    print_array(x,10);
    itererate_and_do(&x[0],10,&c,my_function);
    print_array(x,10);
    c.operator = '-';
    itererate_and_do(&x[0],10,&c,my_function);
    print_array(x,10);
    return 0;

}