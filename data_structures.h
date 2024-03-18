//
// Created by leonard221b on 18/03/24.
//

#ifndef DATASTRUCTURE_DATA_STRUCTURES_H
#define DATASTRUCTURE_DATA_STRUCTURES_H

#define MAX_SIZE 10
#include "stdio.h"
#include "stdlib.h"


//below is the section of stack data structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};
struct Node{
    int data;
    struct Node *next;
};
void initialize_stack(struct Stack *stack){
    stack->top = -1;
}
int is_stack_full(struct Stack *stack){
    return (stack->top == MAX_SIZE-1);
}
void push_stack(struct Stack *stack,int data){
    if(is_stack_full==1){
        printf("Stack overflow error occured");
        exit(1);
    }else{
        stack->data[++stack->top] = data;
    }
}
int is_stack_empty(struct Stack *stack){
    return (stack->top == -1);
}
int pop_stack(struct Stack *stack){
    if(is_stack_empty==1){
        printf("There is no data in stack");
        exit(1);
    }else{
        return stack->data[stack->top--];
    }
}
void peak_stack(struct Stack *stack){
    if(is_stack_empty==1){
        printf("There is no data in stack");
        exit(1);
    }else{
        printf("%d\n",stack->data[stack->top]);
    }
}
void show_stack_data(struct Stack *stack){
    if(is_stack_empty==1){
        printf("There is no data in stack");
        exit(1);
    }else{
        for(int i=stack->top;i>=0;i--){
            printf("stack data - %d\n",stack->data[i]);
        }
    }
}

//below is the section of link list data structure
struct Node *createNode(int data){
    struct Node *newNode = malloc(sizeof (struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertBeginning(struct Node **head,int newData){
    struct Node *newNode = createNode(newData);
    newNode->next = *head;
    *head = newNode;
}
void showLinkList(struct Node *head){
    while(head != NULL){
        printf("Data : %d\n",head->data);
        head = head->next;
    }
}
void deleteNode(struct Node **head,int key){
    struct Node *temp = *head,*prev;
    //below if section is for when the deletion node is the first node of the linklist
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
    }
    //below section will search for the deletion nodes in the linklist
    while(temp!=NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){return;}
    //now link the prev node and next node.
    //only then i will be able to free the deletion or middle one with free()
    prev->next = temp->next;
    free(temp);

}

#endif //DATASTRUCTURE_DATA_STRUCTURES_H
