//
// Created by leonard221b on 18/03/24.
//
#include "stdio.h"
#include "data_structures.h"

int main(){
    struct Stack *stack;
    struct Stack_LL *stack_LL;
    struct Node *head= NULL;
//    initialize_stack(&stack);
//    insertBeginning(&head,500);
//    insertBeginning(&head,400);
//    insertBeginning(&head,300);
//    insertBeginning(&head,200);
//    insertBeginning(&head,100);
//    showLinkList(head);
//    deleteNode(&head,400);
//    showLinkList(head);
    //above is link list and below is stack
////    push_stack(&stack,10);
////    push_stack(&stack,20);
////    push_stack(&stack,30);
////    push_stack(&stack,40);
////    push_stack(&stack,50);
////    push_stack(&stack,60);
//    show_stack_data(&stack);
    //below is stack with link list
    initializeStack_LL(&stack_LL);
    pushStack_LL(&stack_LL,10);
    pushStack_LL(&stack_LL,20);
    pushStack_LL(&stack_LL,30);
    pushStack_LL(&stack_LL,40);
    printf("this is popped data - %d\n",popStack_LL(&stack_LL));
    printf("this is popped data - %d\n",popStack_LL(&stack_LL));
    printf("this is popped data - %d\n",popStack_LL(&stack_LL));
    printf("this is popped data - %d\n",popStack_LL(&stack_LL));
    printf("this is popped data - %d\n",popStack_LL(&stack_LL));

}