//
// Created by leonard221b on 18/03/24.
//
#include "stdio.h"
#include "data_structures.h"

int main(){
    struct Node *head= NULL;
    insertBeginning(&head,500);
    insertBeginning(&head,400);
    insertBeginning(&head,300);
    insertBeginning(&head,200);
    insertBeginning(&head,100);
    showLinkList(head);
    deleteNode(&head,400);
    showLinkList(head);
}