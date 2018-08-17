typedef struct queueDA{
    int head,rear;
    int capacity;
    int *a;
}QueueDA;

QueueDA *createQueueDA (int capacity){
    QueueDA *q = (QueueDA*)malloc(sizeof(QueueDA));

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

int isFullDA (QueueDA *q){
    return (( (q->rear+1)%q->capacity) == q->head);
}

int isEmptyDA (QueueDA *q){
    return (q->rear==-1);
}

void resizeDA (QueueDA *q){
    int i;
    int oldSize = q->capacity;
    q->a = realloc (q->a,q->capacity*2);
    if (q->a==NULL){
        printf("error realloc\n");
        exit(1);
    }
    q->capacity*=2;

    if (q->head > q->rear){
        for (i=0;i<q->head;i++){
            q->a[oldSize+i] = q->a[i];
        }
        q->rear=q->rear+oldSize;
    }
}

void enqueueDA (QueueDA *q, int data){
    if (isFullDA(q)){
        resizeDA(q);
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->a[q->rear] = data;
    printf("Enqueued %d\n",data);
    if (q->head == -1){
        q->head = q->rear;
    }
}

void dequeueDA (QueueDA *q){
    if (isEmptyDA(q)){
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

void frontDA (QueueDA *q){
    if (isEmptyDA(q)){
        printf("Queue is empty\n");
        return;
    }
    else
        printf("Front element is %d\n",q->a[q->head]);
}

void printQueueDA (QueueDA *q){
    int i=0;
    if (isEmptyDA(q)){
        printf("queue is empty\n");
        return;
    }
    else{
        int sizeDA = (q->rear + q->capacity - q->head) % q->capacity + 1;
        for (i=0;i<sizeDA;i++){
            printf("%d ", q->a[(q->head+i)%q->capacity]);
        }
        printf("\n");
    }
}

void deleteQueueDA (QueueDA *q){
    if (q){
        if (q->a){
            free(q->a);
        }
        free(q);
    }
}

