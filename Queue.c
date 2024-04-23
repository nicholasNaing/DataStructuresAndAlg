//
// Created by leonard221b on 23/04/24.
//
#include "stdio.h"
#include "data_structures.h"

int main(){
    //Below implementation use Link List
    struct QueueNode *queueHead = NULL;
    Enqueue_LL(&queueHead,10);
    Enqueue_LL(&queueHead,20);
    Enqueue_LL(&queueHead,30);
    Enqueue_LL(&queueHead,40);
    Enqueue_LL(&queueHead,50);
    peekQueue_LL(queueHead);
    printf("This is dequeued data - %d\n", Dequeue_LL(&queueHead));
    peekQueue_LL(queueHead);

    //Below implementation use Array
    arrayEnqueue(10);
    arrayEnqueue(20);
    arrayEnqueue(30);
    arrayEnqueue(40);
    arrayEnqueue(50);
    arrayQueuePeek();
    printf("Dequeue number - %d\n",arrayDequeue());
    printf("Dequeue number - %d\n",arrayDequeue());
    arrayQueuePeek();
}