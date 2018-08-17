typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct queueL{
    Node *head;
    Node *rear;
}QueueL;

QueueL *createQueueL(){
    QueueL *q = (QueueL*)malloc(sizeof(QueueL));
    if(q==NULL){
        printf("malloc error\n");
        exit(1);
    }
    q->head = q->rear = NULL;
    return q;
}

int isEmptyL (QueueL *q){
    return (q->head == NULL);
}

void enqueueL (QueueL **q, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL){
        printf("malloc error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if ((*q)->rear == NULL){
        (*q)->head = newNode;
        (*q)->rear = newNode;
    }
    else{
        ((*q)->rear)->next = newNode;
        (*q)->rear = newNode;
    }
    printf("Enqueued %d\n", data);
}

void dequeueL (QueueL **q){
    Node *temp;

    if (isEmptyL(*q)){
        printf("Queue is empty\n");
        return;
    }
    else{
        temp = (*q)->head;
        (*q)->head = ((*q)->head)->next;
        printf("Dequeued %d\n",temp->data);
        free(temp);

    }
}

void printQueueL (QueueL *q){
    if (isEmptyL(q)){
        printf("Queue is empty\n");
        return;
    }
    else{
        while (q->head!=NULL){
            printf("%d ",(q->head)->data);
            q->head=(q->head)->next;
        }
        printf("\n");
    }
}

void deleteQueueL (QueueL **q){
    Node *temp;
    while((*q)->head){
        temp = (*q)->head;
        (*q)->head = ((*q)->head)->next;
        free(temp);
    }
    free(*q);
}
