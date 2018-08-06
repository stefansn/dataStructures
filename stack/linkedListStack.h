typedef struct stackList {
    int data;
    struct stackList *next;
}StackList;

StackList *createStackList (){
    return NULL;
}

int isEmptyL (StackList *s){
    return s == NULL;
}

void pushList (StackList **s, int givenData){
    StackList *newNode = (StackList*)malloc(sizeof(StackList));

    if (!newNode){
        printf("memory allocation\n");
        exit(1);
    }

    newNode->data = givenData;

    if (isEmptyL(s)){
        *s = newNode;
    }
    else{
        newNode->next = *s;
        *s = newNode;
    }
}

void popL (StackList **s){
    StackList *p;

    if (isEmptyL(s)){
        printf("underflow\n");
        return;
    }

    p = *s;
    *s = p->next;
    printf("pop = %d\n",p->data);
    free(p);
}

void printStackL (StackList *s){
    if (isEmptyL(s)){
        printf("List empty.\n");
        return;
    }
    while (s!=NULL){
        printf("%d ", s->data);
        s=s->next;
    }

    printf("\n");
}












