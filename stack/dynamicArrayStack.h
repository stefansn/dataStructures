typedef struct dynamicArrayStack {
    int capacity;
    int top;
    int *a;
}DynamicArrayStack;

DynamicArrayStack *createStackD(){
    DynamicArrayStack *s = (DynamicArrayStack*)malloc(sizeof(DynamicArrayStack));

    if (s==NULL){
        printf("memory allocation\n");
        exit(1);
    }

    s->capacity=1;
    s->top=-1;
    s->a = (int*)malloc(s->capacity * sizeof(int));

    if (s->a==NULL){
        printf("memory allocation\n");
        exit(1);
    }

    return s;
}

int isEmptyD (DynamicArrayStack *s){
    return (s->top == -1);
}

int isFullD (DynamicArrayStack *s){
    return (s->top == s->capacity-1);
}

void doubleArray (DynamicArrayStack *s){
    s->capacity*=2;
    s->a = realloc(s->a,s->capacity);
}

void pushD (DynamicArrayStack *s,int givenData){
    if (isFullD(s)){
        printf("Stack full - double array\n");
        doubleArray(s);
    }
    s->a[++s->top] = givenData;
}

void popD (DynamicArrayStack *s){
    if (isEmptyD(s)){
        printf("stack is empty - underflow");
        return;
    }
    else{
        printf("Pop = %d \n",s->a[s->top--]);
    }
}

void printStackD (DynamicArrayStack *s){
    int i;
    if (isEmptyD(s)){
        printf("Stack is empty.\n");
        return;
    }
    else{
        for (i=0;i<=s->top;i++){
            printf("%d ",s->a[i]);
        }
        printf("\n");
    }
}











