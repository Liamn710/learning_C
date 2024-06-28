#include <stdio.h>

struct person {
    char *name;
    int age;
};

int main(){
    struct person liam ={"Liam", 28};
    printf("Hi my name is %s and my age is %i\n",liam.name,liam.age);
    return 0;
}
