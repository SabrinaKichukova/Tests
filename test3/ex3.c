#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;


struct Node* firstEl(struct Node* last, int data) {
if (last != NULL) return last;
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
last = newNode;
last->next = last;

return last;
}

struct Node* push(struct Node* last, int data) {
  if (last == NULL) return firstEl(last, data);
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;

  return last;
}

void freeList(node_t** head){
    node_t* current = *head;
    while (current != NULL){
        node_t* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}   
void printList(struct Node* head)
{
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
 
    printf("\n");
}
struct Node* insertAfter(struct Node *cll, int skipCount, int newElem){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    for(int i = 0; i<skipCount;i++){
      newNode = (*cll)->next;
    }
   
  newNode->data = newElem;
  newNode->next = last->next;
  last->next = newNode;
}



 int main(void)
 {
    node_t* last = NULL;
    unsigned int n;
    printf("Please enter N:");
    scanf("%hd",&n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d ",&a);
        push(&last,a);
    }
    printList(last);
    insertAfter(last,5,6);
    printList(last);
    freeList(&last);

    return 0;
 }
 
}
