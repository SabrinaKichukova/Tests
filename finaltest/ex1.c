#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<inttypes.h>

#define ITEM_COUNT 5

int randInt(int, int);
double randDouble(double, double);

typedef struct item {
    u_int16_t number;
    char op[250];
    double  weight;
    double price;
    struct item *next;
} item;

void push(item** head){
srand(time(NULL)); 
item* items = malloc(sizeof(item));
if(!items){
     fprintf(stderr,"Error! Problem with memory allocation!");
     exit(-1);
}
items->next = (*head);
items->number = randInt(0,10000);

for(int i = 0; i < 5; i++){
int oplen = randint(5,10);
char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
char rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
for (int j = 0; j < oplen; j++)
    {   
        if(i == 1 && j == 1){
        rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
        rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
        int random_bit = rand() % 2;
 
        if (random_bit)
        {
            items->op[j] = rand_lowercase;
        }
        else
        {
            items->op[j] = rand_uppercase;
        }    
    } else {
        rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);

    }
        items->op[oplen] = '\0';

    }
 
    items->price = randDouble(1.0,1500);
    (*head) = items;   

    }
}

double totalItemsWeight(item* head){
    double* sum = malloc(sizeof(double));
    sum = 0;
    item* current = head;
    while (current){
        *sum += current->weight;
        current = current->next;
    }
    if(sum == 0){
        perror("There is no elements for sum.");
        return EXIT_FAILURE;
    }
    return *sum;
}

item *minPriceItem(item* head){
    item* current = head;
    double* min = malloc(sizeof(double));
    *min = 0;
    while (current){
        if(*min > current->price){
        *min = current->price;
        }
        current = current->next;
    }
return &min;

}
void freeList(item** head){
    item* current = *head;
    while (current != NULL){
        item* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void printData(item* head){
    item* current = head;
    while (current != NULL){
        printf("Number:   %hd   ", current->number); 
        printf("Discription: %s ", current->op);
        printf("Price:  %.2lf   \n", current->price);

        current = current->next;
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    item* head = NULL;

    for(int i = 0; i < ITEM_COUNT; i++){
        push(&head);
    }
    
    printData(&head);

    double total = totalItemsWeight(head);
    printf("Sum of weight is: %lf", total);

    double* minPrice = minPriceItem(head);
    printf("Min price is: %lf", &minPrice);

    freeList(&head);
    
    return 0;
}


int randInt(int min, int max){
    return min + rand() % (max -min + 1); 
}
double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}