//
// Created by leonard221b on 23/04/24.
//
#include "stdio.h"
#include "data_structures.h"

int main(){
    //below is the stack implementation using link list
    struct Stack_LL *stack_LL = (struct Stack_LL*)malloc(sizeof(struct Stack_LL));
    initializeStack_LL(&stack_LL);

    pushStack_LL(&stack_LL,10);
    pushStack_LL(&stack_LL,20);
    pushStack_LL(&stack_LL,30);
    pushStack_LL(&stack_LL,40);

    peakStack_LL(&stack_LL);

    printf("this is popped data - %d\n",popStack_LL(&stack_LL));
    printf("this is popped data - %d\n",popStack_LL(&stack_LL));

    peakStack_LL(&stack_LL);

    //below is the stack implementation using array
    struct Stack *stack;
    initialize_stack(&stack);
    push_stack(&stack,10);
    push_stack(&stack,20);
    push_stack(&stack,30);
    push_stack(&stack,40);
    push_stack(&stack,50);
    push_stack(&stack,60);

    show_stack_data(&stack);


    printf("This is the popped stack data : %d\n",pop_stack(&stack));
    printf("This is the popped stack data : %d\n",pop_stack(&stack));
    printf("This is the popped stack data : %d\n",pop_stack(&stack));


    show_stack_data(&stack);
}