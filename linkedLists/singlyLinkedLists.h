typedef struct node {
    int key;
    struct node *next;
} NodeT;

NodeT *createNode (int givenKey);
void insertNode (NodeT** head, int givenKey, int position);
void deleteNode (NodeT **head, int position);
void deleteLinkedList (NodeT **head);
NodeT *search(NodeT *head, int givenKey);
void print_list(NodeT *head);
void insert_first(NodeT **head, NodeT **tail, int givenKey);
void insert_last(NodeT **head, NodeT **tail, int givenKey);
void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey);
void insert_before_key(NodeT **head, NodeT** tail, int beforeKey, int givenKey);
void delete_first(NodeT** head, NodeT** tail);
void delete_last(NodeT** head, NodeT** tail);
void delete_key(NodeT** first, NodeT** last, int givenKey);

NodeT *createNode (int givenKey){
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));

    if (!p){
        printf("Memory error - allocating node");
        exit(1);
    }

    p->key = givenKey;
    p->next = NULL;

    return p;
}

void insertNode (NodeT** head, int givenKey, int position){
    NodeT *newNode = createNode(givenKey);

    NodeT *q = NULL;
    NodeT *p = *head;

    int k=1;

    //position is at the beginning
    if (position == 1){
        newNode->next = p;
        *head = newNode;
    }
    else{
        while((p!=NULL) && (k < position)){
            k++;
            q = p;
            p = p->next;
        }
        //position is at the end
        if (p==NULL){
            q->next = newNode;
            newNode->next=NULL;
        }
        //position is between two nodes
        else{
            q->next=newNode;
            newNode->next=p;
        }
    }

}

void deleteNode (NodeT **head, int position){
    NodeT *p,*q;
    p = *head;

    int k = 1;
    int key;

    if (position==1){
        *head = (*head)->next;
        key = p->key;
        free(p);
        printf("Key deleted = %d\n",key);
    }
    else{
        while (p!=NULL && k < position){
            k++;
            q=p;
            p=p->next;
        }
        if (p==NULL){
            printf("Position %d does not exist\n",position);
        }
        else{
            q->next = p->next;
            key = p->key;
            free(p);
            printf("Key deleted = %d\n",key);
        }
    }

}

void deleteLinkedList (NodeT **head){
    NodeT *p,*q;

    p = *head;
    while (p!=NULL){
        q=p;
        p=p->next;
        free(q);
    }
    *head = NULL;
}

NodeT *search(NodeT *head, int givenKey) {
    //TODO: search the given key and return the first node containing it or NULL
    while (head!=NULL){
        if (head->key == givenKey)
            return head;
        else
            head = head->next;
    }
    return NULL;
}

void print_list(NodeT *head){
    if (head == NULL){
        printf("List empty\n");
        return;
    }

    while (head != NULL){
        printf("%d ",head->key);
        head = head->next;
    }
    printf("\n");
}

void insert_first(NodeT **head, NodeT **tail, int givenKey) {
    //TODO: insert the given key in the first position of the list given by head and tail;
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;

    if ((*head) == NULL){
        *head = p;
        *tail = p;
    }
    else {
        p->next = *head;
        *head = p;
    }

}

void insert_last(NodeT **head, NodeT **tail, int givenKey) {
    //TODO: insert the given key in the last position of the list given by head and tail;
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;

    if ((*head) == NULL){
        *head = p;
        *tail = p;
    }
    else{
        (*tail)->next = p;
        *tail = p;
    }
}

void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey){
    //TODO: insert the given key after afterKey, in list given by head and tail;
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;

    NodeT *aux = *head;

    if ( (*head) == NULL){
        (*head) = p;
        (*tail) = p;
    }
    else{
        while ( aux !=NULL){
            if (aux->key == afterKey)
                break;
            aux = aux->next;
        }

        if (aux != NULL){
            p->next = aux->next;
            aux->next = p;
            if (p==(*tail))
                *tail = p;
        }
    }
}

void insert_before_key(NodeT **head, NodeT** tail, int beforeKey, int givenKey){
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->next = NULL;

    NodeT *q;
    NodeT *q1 = NULL;
    q = *head;

    if ((*head) == NULL){
        *head = p;
        *tail = p;
    }
    else{
        while (q!=NULL){
            if (q->key == beforeKey)
                break;

            q1 = q;
            q = q->next;

        }

        if (q!=NULL){
            if (q==*head){
                p->next = *head;
                *head = p;
            }
            else{
                q1->next = p;
                p->next = q;
            }
        }

    }
}

void delete_first(NodeT** head, NodeT** tail){
    //TODO: delete first list element
    NodeT *p;

    if ((*head)!=NULL){
        p = *head;
        *head = (*head)->next;
        free(p);
        if (*head == NULL){
            *tail= NULL;
        }
    }
}

void delete_last(NodeT** head, NodeT** tail){
    //TODO: delete last list element
    NodeT *q = *head;
    NodeT *q1 = NULL;

    if (q!=NULL){
        while(q != *tail){
            q1 = q;
            q = q->next;
        }

        if (q1 == *head){
            *head = *tail = NULL;
        }
        else{
            q1->next = NULL;
            *tail = q1;
        }
    }
    free(q);

}

void delete_key(NodeT** first, NodeT** last, int givenKey){
    //TODO: delete element having given key
    NodeT *q = *first;
    NodeT *q1 = NULL;

    if (q!=NULL){
        while (q->next != NULL){
            if (q->key == givenKey)
                break;
            q1 = q;
            q = q->next;
        }

        if (q!=NULL){
            if (q == *first){
                *first = (*first)->next;
                free(q);
                if (*first == NULL)
                    *last = NULL;
            }
            else{
                q1->next = q->next;
                if (q == *last){
                    *last = q1;
                }
                free(q);
            }
        }
    }
}

