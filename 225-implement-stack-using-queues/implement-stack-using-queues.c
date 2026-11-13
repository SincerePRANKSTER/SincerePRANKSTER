
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

typedef struct {
    int *q1;
    int *q2;

    int f1, r1;
    int f2, r2;

} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));

    obj->q1 = malloc(SIZE * sizeof(int));
    obj->q2 = malloc(SIZE * sizeof(int));

    obj->f1 = 0;
    obj->r1 = -1;

    obj->f2 = 0;
    obj->r2 = -1;

    return obj;
}

void myStackPush(MyStack* obj, int x) {

    // Insert new element into q2
    obj->q2[++obj->r2] = x;

    // Move all elements from q1 to q2
    while(obj->f1 <= obj->r1) {
        obj->q2[++obj->r2] = obj->q1[obj->f1++];
    }

    // Swap queue pointers
    int *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    // Reset queue indices
    obj->f1 = 0;
    obj->r1 = obj->r2;

    obj->f2 = 0;
    obj->r2 = -1;
}

int myStackPop(MyStack* obj) {

    if(obj->r1 == -1)
        return -1;

    return obj->q1[obj->f1++];
}

int myStackTop(MyStack* obj) {

    if(obj->r1 == -1)
        return -1;

    return obj->q1[obj->f1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->f1 > obj->r1;
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
