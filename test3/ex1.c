#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5

typedef struct rectangle_t{
    struct point_t{
        double x;
        double y;
    }
    struct rectangle_t  next;
} rec1;

double randDouble(double min, double max);
void push(rec1** , int );
void listFree(rec1** );

int main(void){
    rec1* head = NULL;
for(int i = 0;i<COUNT; i++){
push(&head,randDouble(-10,10));
}

listFree(&head);
return 0;
}


double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);

    void filterRects(rec1** list, double min, double max);
    double areaRects(rec1* list){
    
    }

void push(node_t** head, int val){
    node_t* element = malloc(sizeof(node_t));
    element->value = val; 
    element->next = *head;
    *head = element;
}
void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}