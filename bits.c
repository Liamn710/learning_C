#include <stdio.h>

void print_reverse_bin(unsigned int n){
    unsigned int result = 0;
    int insert_idx = 31;
    while ((n))
    {
        result |= (n & 1) <<insert_idx;
        n >>=1;
        insert_idx--;
    }
    printf("%u",result);
    
}
void print_bin(unsigned int num){
    int i = 32;
    while (i)
    {
        if(num&0x80000000){
            printf("1");
        }
        else{
            printf("0");
        }
        i--;
        num <<=1;
    }
    
}

int main(){
    int i1 = 0x00000001;
    print_bin(i1);
    printf("\n");
    print_reverse_bin(i1);
    printf("\n");
    return 0;
}