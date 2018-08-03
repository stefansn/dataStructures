typedef struct nodeD{
    int key;
    struct nodeD *next;
    struct nodeD *prev;
}NodeD;

NodeD *createDoublyNode (int givenKey);
void printDoublyList (NodeD *head);
void insertDoublyNode (NodeD **head, int givenKey, int position);
void deleteDoublyNode (NodeD **head, int position);
void deleteDoublyList (NodeD **head);

NodeD *createDoublyNode (int givenKey){
    NodeD *p = (NodeD*)malloc(sizeof(NodeD));
    if (!p){
        printf("Error memory - creating node");
        exit(1);
    }

    p->key = givenKey;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void printDoublyList (NodeD *head){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }

    while (head != NULL){
        printf("%d ",head->key);
        head = head->next;
    }
    printf("\n");
}

void insertDoublyNode (NodeD **head, int givenKey, int position){
    NodeD *newNode = createDoublyNode(givenKey);
    int k = 1;

    NodeD *p = *head;

    if (position==1){
        newNode->next = *head;
        newNode->prev = NULL;
        *head = newNode;
        (*head)->prev = newNode;

    }

    else{
        while (p->next!=NULL && k < position - 1){
            p=p->next;
            k++;
        }
        if (p->next==NULL){
            newNode->next = p->next;
            newNode->prev = p;
            p->next = newNode;
        }
        else{
            newNode->next = p->next;
            newNode->prev = p;
            p->next->prev = newNode;
            p->next = newNode;
        }
    }
}

void deleteDoublyNode (NodeD **head, int position){
    NodeD *p = *head;
    NodeD *q = NULL;

    int k = 1;

    if (*head == NULL){
        printf("List is empty\n");
        exit(1);
    }

    if (position == 1){
        *head = p->next;
        if (*head!=NULL){
            (*head)->prev = NULL;
        }
        printf("Key = %d deleted.\n",p->key);
        free(p);
    }
    else{
        while (p->next != NULL && k < position){
            q = p;
            p = p->next;
            k++;
        }

        if (p -> next == NULL){
            q->next = NULL;
            printf("Key = %d deleted.\n",p->key);
            free(p);
        }
        else{
            q->next = p->next;
            p->next->prev = q;
            printf("Key = %d deleted.\n",p->key);
            free(p);
        }
    }
}

void deleteDoublyList (NodeD **head){
    NodeD *p = *head;

    while (*head!=NULL){
        p = *head;
        *head = (*head)->next;
        free(p);
    }
}
