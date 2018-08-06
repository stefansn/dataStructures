#include <stdio.h>
#include <stdlib.h>

#include "simpleArrayStack.h"
#include "dynamicArrayStack.h"
#include "linkedListStack.h"

int main()
{

    StackList *s = createStackList();


    pushList(&s,1);
    pushList(&s,2);
    pushList(&s,3);
    popL(&s);
    printStackL(s);


    /*
    DynamicArrayStack *d = createStackD();

    pushD(d,1);
    pushD(d,2);
    pushD(d,3);

    printStackD(d);

    pushD(d,4);
    pushD(d,5);
    pushD(d,6);
    pushD(d,7);

    printStackD(d);

    popD(d);


    printStackD(d);
    */

    /*
    ArrayStack *s = createStack();

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);

    printStack(s);

    pop(s);
    push(s,6);
    printStack(s);

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    printStack(s);

    pop(s);
    */



    return 0;
}
