typedef struct nodeC {
    int key;
    struct nodeC *next;
}NodeC;

NodeC *createCircularNode (int givenKey){
    NodeC *newNode = (NodeC*)malloc(sizeof(NodeC));
    if (!newNode){
        printf("Memory allocation error\n");
        exit(1);
    }

    newNode->key = givenKey;
    newNode->next = newNode;

    return newNode;
}

void printCircularLinkedList (NodeC *head){
    NodeC *p = head;

    if (p == NULL){
        printf("Empty circular list.\n");
        return;
    }

    do{
        printf("%d ",p->key);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

void insertCircularNode (NodeC **head, int givenKey, int position){
    NodeC *newNode = createCircularNode(givenKey);

    int k = 1;

    NodeC *p = *head;
    NodeC *q = *head;

    if (p==NULL){
        *head = newNode;
        return;
    }
    //insert at beginning (there exists only one node)
    if (position==1 && (*head)->next == *head){
        newNode->next = *head;
        (*head)->next = newNode;
        *head=newNode;
    }
    else{
        //find the last node
        while (q->next!=*head){
            q=q->next;
        }

        if (position==1){
            q->next = newNode;
            newNode->next = *head;
            *head = newNode;
        }else{
            do{
                q=p;
                p=p->next;
                k++;
            }while(p!=*head && k<position);

            q->next=newNode;
            newNode->next=p;
        }
    }
}

void deleteCircularNode (NodeC **head, int position){
    NodeC *p = *head;
    NodeC *q = *head;

    int k = 1;

    if (*head == NULL){
        printf("Circular list is empty\n");
        return;
    }

    //insert at beginning (there is only a node)
    if (position==1 && *head == (*head)->next){
        printf("1.Deleted key = %d\n",(*head)->key);
        *head = NULL;
        free(p);
    }else{
        //find the last node
        while(q->next != *head){
            q=q->next;
        }

        //insert at beginning but there are more than one nodes
        if (position==1){
            q->next = p->next;
            *head = q->next;
            printf("2.Deleted key = %d\n",p->key);
            free(p);
        }
        //insert anywhere else, including the end
        else{
            while (p->next != *head && k<position){
                q=p;
                p=p->next;
                k++;
            }

            q->next = p->next;
            printf("3.Deleted key = %d\n",p->key);
            free(p);
        }

    }





}
