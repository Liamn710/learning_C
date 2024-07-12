#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct generic_array {
    void *items;
    int capacity;
    int size;
    int size_of_item;
};



struct generic_array new_generic_array(int size_of_item) {
    struct generic_array ga = {0};
    ga.capacity = 2;
    ga.size_of_item = size_of_item;
    ga.items = malloc(size_of_item * ga.capacity );
    return ga;
}
void * generic_array_insert(struct generic_array * ga,const void *item) {
    void * temp;
    if(ga->size == ga->capacity) {
        ga->capacity *=2;
        temp = realloc(ga->items, ga->capacity * ga->size_of_item);
        if(temp == NULL) {
            ga->capacity /=2;
            return NULL;
        }
        ga->items = temp;
    }
    memcpy( ((char *)(ga->items)) + (ga->size * ga->size_of_item) ,item,ga->size_of_item);
    ga->size++;
    return ((char *)(ga->items)) + (ga->size * ga->size_of_item);
}
void generic_array_destory(struct generic_array * ga) {
    free(ga->items);
}

struct person  {
    int id;
    int height;
};
void print_person_array(struct generic_array * ga) {
    int i;
    struct person * persons = ga->items;
    for(i=0;i<ga->size;i++) {
        printf("ID:%d\theight:%d\n",persons[i].id,persons[i].height);
    }
}
void print_int_arr(int *arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    struct generic_array persons;
    struct generic_array integers;
    struct person dummy;
    int int_counter,person_count;
    int i, num;
    persons = new_generic_array(sizeof(struct person));
    integers  = new_generic_array(sizeof(int));
    scanf("%d %d",&int_counter,&person_count);
    
    for(i=0;i<person_count;i++) {
        scanf("%d %d",&dummy.id,&dummy.height);
        generic_array_insert(&persons, &dummy);
    }
    
    for(i=0;i<int_counter;i++) {
        scanf("%d", &num);
        generic_array_insert(&integers, &num);
    }
    print_person_array(&persons);
    print_int_arr(integers.items, integers.size);
    generic_array_destory(&persons);
    generic_array_destory(&integers);
    return 0;
}