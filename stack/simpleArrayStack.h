typedef struct arrayStack {
    int capacity;
    int top;
    int *a;
}ArrayStack;

ArrayStack *createStack(){
    ArrayStack *s = (ArrayStack*)malloc(sizeof(ArrayStack));

    if (s==NULL){
        printf("memory allocation\n");
        exit(1);
    }

    s->capacity=5;
    s->top=-1;
    s->a = (int*)malloc(s->capacity * sizeof(int));

    if (s->a==NULL){
        printf("memory allocation\n");
        exit(1);
    }

    return s;
}

int isEmpty (ArrayStack *s){
    return (s->top == -1);
}

int isFull (ArrayStack *s){
    return (s->top == s->capacity-1);
}

void push (ArrayStack *s, int givenData){
    if (!isFull(s)){
        s->a[++s->top] = givenData;
    }
    else{
        printf("stack is full - overflow\n");
        return;
    }
}

void pop (ArrayStack *s){
    if (!isEmpty(s)){
        printf("pop = %d\n", s->a[s->top--]);
    }else{
        printf("stack is empty - underflow\n");
        return;
    }
}

void printStack (ArrayStack *s){
    int i;

    if (isEmpty(s)){
        printf("stack empty\n");
        return;
    }
    for (i = 0; i <= s->top ;i++){
        printf("%d ",s->a[i]);
    }
    printf("\n");
}




















