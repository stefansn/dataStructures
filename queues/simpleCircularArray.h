typedef struct queueSA {
    int head,rear;
    int capacity;
    int *a;
}QueueSA;

QueueSA *createQueueSA (int capacity){
    QueueSA *q = (QueueSA*)malloc(sizeof(QueueSA));

    if (q==NULL){
        printf("malloc error\n");
        exit(1);
    }

    q->head = q->rear = -1;
    q->capacity = capacity;
    q->a = (int*)malloc(q->capacity * sizeof(int));

    if (q->a==NULL){
        printf("malloc error\n");
        exit(1);
    }

    return q;
}

int isFullSA (QueueSA *q){
    return (( (q->rear+1)%q->capacity) == q->head);
}

int isEmptySA (QueueSA *q){
    return (q->rear==-1);
}

void enqueueSA (QueueSA *q, int data){
    if (isFullSA(q)){
        printf("queue is full\n");
        return;
    }
    else{
        q->rear = (q->rear + 1) % q->capacity;
        q->a[q->rear] = data;
        printf("Enqueued %d\n",data);
        if (q->head == -1){
            q->head = q->rear;
        }
    }
}

void dequeueSA (QueueSA *q){
    if (isEmptySA(q)){
        printf("queue is empty\n");
        return;
    }
    else{
        printf("Element dequeued is: %d\n", q->a[q->head]);
        if (q->head == q->rear){
            q->head=q->rear=-1;
        }
        else{
            q->head = (q->head+1)%q->capacity;
        }
    }
}

void frontSA (QueueSA *q){
    if (isEmptySA(q)){
        printf("Queue is empty\n");
        return;
    }
    else
        printf("Front element is %d\n",q->a[q->head]);
}

void printQueueSA (QueueSA *q){
    int i=0;
    if (isEmptySA(q)){
        printf("queue is empty\n");
        return;
    }
    else{
        int sizeSA = (q->rear + q->capacity - q->head) % q->capacity + 1;
        for (i=0;i<sizeSA;i++){
            printf("%d ", q->a[(q->head+i)%q->capacity]);
        }
        printf("\n");
    }
}

void deleteQueueSA (QueueSA *q){
    if (q){
        if (q->a){
            free(q->a);
        }
        free(q);
    }
}
