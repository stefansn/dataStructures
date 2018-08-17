#include <stdio.h>
#include <stdlib.h>

#include "simpleCircularArray.h"
#include "dynamicCircularArray.h"
#include "linkedLists.h"

int main()
{

    QueueL *q = createQueueL();
    enqueueL(&q,1);
    enqueueL(&q,2);
    enqueueL(&q,3);

    dequeueL(&q);
    dequeueL(&q);
    dequeueL(&q);

    printQueueL(q);

    /*
    //dynamic circular array demo
    QueueDA *q = createQueueDA(5);
    printQueueDA(q);

    enqueueDA(q,1);
    enqueueDA(q,2);
    enqueueDA(q,3);
    enqueueDA(q,4);
    enqueueDA(q,5);
    printf("capacity of the queue is %d\n",q->capacity);
    enqueueDA(q,6);
    printf("capacity of the queue is %d\n",q->capacity);
    enqueueDA(q,7);
    dequeueDA(q);

    printf("%d %d\n",q->head,q->rear);

    printQueueDA(q);
    */

    /* simple circular array demo
    QueueSA *q = createQueueSA(5);
    printQueueSA(q);

    enqueueSA(q,1);
    enqueueSA(q,2);
    enqueueSA(q,3);

    dequeueSA(q);
    enqueueSA(q,4);
    enqueueSA(q,5);
    enqueueSA(q,6);
    enqueueSA(q,7);
    dequeueSA(q);
    enqueueSA(q,7);

    frontSA(q);

    printQueueSA(q);
    */
    return 0;
}
