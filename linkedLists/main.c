#include <stdio.h>
#include <stdlib.h>

#include "singlyLinkedLists.h"
#include "doublyLinkedLists.h"

int main() {
    NodeD *first = NULL;

    insertDoublyNode(&first,1,1);
    insertDoublyNode(&first,2,2);
    insertDoublyNode(&first,3,3);
    insertDoublyNode(&first,6,1);
    insertDoublyNode(&first,0,1);
    printDoublyList(first);


    deleteDoublyNode(&first,5);
    printDoublyList(first);


    insertDoublyNode(&first,1,1);
    insertDoublyNode(&first,2,2);
    insertDoublyNode(&first,3,3);
    insertDoublyNode(&first,6,1);
    insertDoublyNode(&first,0,1);
    printDoublyList(first);

    deleteDoublyNode(&first,5);
    printDoublyList(first);

    deleteDoublyList(&first);
    printDoublyList(first);






    return 0;
}



