#include <stdio.h>


struct m_base
{
    char name[30];
    int number_of_soldiers;
};


struct soldier
{
    char name[30];
    int age;
    int hight;
    struct m_base * serving_base;
};

int main(){
    int i;
    struct m_base palmachim = {
        "palmachim", 2
    };
    struct m_base hazor = {
        "hazor", 5
    };
    struct soldier soldiers[2] = {
        /*due to c90 limits you cant define a struct value in a struct initially,
         dont it in the next lines*/
        {"liam", 180, 27, NULL},
        {"maor", 175, 28, NULL}
    };
    soldiers[0].serving_base = &palmachim;/*pointing the serving base values to a struct*/
    soldiers[1].serving_base = &hazor;

    for(i = 0; i<2; i++){
        printf("number of soldiers in %s base is %d, and the name of the base is %s\n",soldiers[i].name, soldiers[i].serving_base->number_of_soldiers,soldiers[i].serving_base->name);
    }
    return 0;
}


