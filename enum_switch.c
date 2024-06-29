#include <stdio.h>
int i;

enum color_options {RED = 0, BLUE = 1,PURPLE = 2,YELLOW = 3};

int main() {
    enum color_options co;
    scanf("%d",&i);
    co = i;
    switch(co)
    {
    case RED:
        printf("red\n");
    break;
    case BLUE:
        printf("blue\n");
    break;
    case PURPLE: case YELLOW:
        printf("purple or yellow\n");
    break;
    default:
        break;
    }
    return 0;
}

