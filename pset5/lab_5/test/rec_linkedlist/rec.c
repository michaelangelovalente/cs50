#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
    int a;
    struct list *next;
}list;

list *create_list(int n, list *head);

int main(int argc, char *argv[]){
    

    //list *head_box = &test_box;
    //dumb approach :DDD
    list *headOfBox = create_list(3, headOfBox);
    printf("item n == %d\naddr of head: %p\naddr of next: %p\n", (*headOfBox).a, headOfBox, headOfBox->next );
    printf("\n");
    printf("item n == %d\naddr of head: %p\naddr of next: %p\n", ( *(*headOfBox).next).a, headOfBox, (*(*headOfBox).next).next );
    printf("\n");
    printf("item n == %d\naddr of head: %p\naddr of next: %p\n", headOfBox->next->next->a, headOfBox, headOfBox->next->next->next );
    printf("\n");
    printf("item n == %d\naddr of head: %p\naddr of next: %p\n", headOfBox->next->next->next->a, headOfBox, headOfBox->next->next->next->next );

}

//recursively creates a list with n nodes
//returns pointer to head
list *create_list(int n, list *head){
    list *ptr_2Lst = malloc(sizeof(list));
    //invalid addr ctr missing.
    head = ptr_2Lst;
    if(n == 0){
        
        (*ptr_2Lst).a = n; //srand( time(0) );
        (*ptr_2Lst).next = NULL;
        return head;
    }

    (*head).a = n; //srand( time(0) );
    (*head).next = create_list(n-1, head);

    return head;
    
    
}