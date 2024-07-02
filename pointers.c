#include <stdio.h>

void swap_int_value(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;     
}

void swap_pointer(int **ap, int **bp){
    int *temp = *ap;
    *ap = *bp;
    *bp = temp;
}
void swap_pointer_1_2(int ***appp, int ***bppp){
    int **temp1;
    int  *temp2;
    // second pointer swap:
    temp1 = *appp;
    *appp = *bppp;
    *bppp = temp1;
    // first pointer swap:
    temp2 = **appp;
    **appp = **bppp;
    **bppp = temp2;
}
int main(){
    int a = 5, b = 10;
    int *ap = &a; /*first a pointer*/
    int *bp = &b;/*first b pointer*/
    int **app = &ap;/*second a pointer*/
    int **bpp = &bp;/*second b pointer*/
    printf("before int swap: %d, %d, ap: %p, bp: %p, app: %p, bpp: %p\n",a,b, (void*)ap,(void*)bp, (void*)app,(void*)bpp);
    swap_int_value(&a,&b);
    printf("after_int swap: %d, %d, ap: %p, bp: %p, app: %p, bpp: %p\n",a,b, (void*)ap,(void*)bp, (void*)app,(void*)bpp);
    swap_pointer(&ap,&bp);
    printf("after first pointer swap: %d, %d, ap: %p, bp: %p, app: %p, bpp: %p\n",a,b, (void*)ap,(void*)bp, (void*)app,(void*)bpp);
    swap_pointer_1_2(&app,&bpp);
    printf("after first and second pointer: %d, %d, ap: %p, bp: %p, app: %p, bpp: %p\n",a,b, (void*)ap,(void*)bp, (void*)app,(void*)bpp);
    return 0;
}