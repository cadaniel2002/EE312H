
#include <stdio.h>
#include <stdlib.h>
/* no need to import anything else */

/*
 * Your task is to implement an abstract data type (ADT) that
 * represents a vector (an array of integers) and several functions to
 * manipulate the vector.  A vector struct keeps two pointers (one
 * pointing to the very first element in the array and one pointing
 * immediately after the last valid element of the array).  Functions
 * to implement:
 *
 * (a)[2 points] allocating vector on the heap
 * (d)[2 points] checking if the number of elements is even or odd
 * (e)[2 points] finding length of a vector
 * (f)[2 points] appending one vector to another
 * (g)[1 point]  freeing heap space
 */

typedef struct _vec {
    int* start;
    int* end;
} Vec;

/*
 * Allocate and return a vector that is properly initialized (i.e.,
 * allocate array of integer elements and set members of the vector).
 * You can initialize the values of the array any way you wish.
 *
 * n - number of elements in a vector (assume it is a positive integer, i.e., n > 0)
 */
Vec* allocVec(int n) {
    Vec *v = malloc(sizeof(Vec)); 
    v->start = malloc(n * sizeof(int));
    v->end = v->start + n * (sizeof(int));
    return v;
}
/*
 * Return 1 if the number of elements in the give vector is even; 0
 * otherwise.  IMPORTANT: Use only variables that are pointers.  Also,
 * function calls are not permitted.
 */
int vecEven(Vec *v) {
    if(((v->end - v->start)/sizeof(int))%2 == 0){
        return 1;
    }
    return 0;
}

/*
 * Return the length of the given vector (i.e., number of elements).
 */
int vecLen(Vec *v) {
    return (v->end  - v->start)/sizeof(int);
}

/*
 * Appends all elements from "other" to "v".  IMPORTANT: Use can only
 * use realloc and vecLen functions here.  You can invoke realloc only once.
 */
void vecAppend(Vec *v, Vec *other) {
    v->start = realloc(v, (vecLen(v) * sizeof(int)) + (vecLen(other) * sizeof(int)));
    for(int i = 0; i < vecLen(other); i++){
        *v->end = *(other->start + i);
        v->end++;
    }
}

/*
 * Free all memory taken by the given vector.
 */
void vecFree(Vec *vec) {
    free(vec);
}

/* This function illustrates the way your vector will be used */
int main(void) {
    int len = 10;

    Vec *v1 = allocVec(len);
    Vec *v2 = allocVec(len);
    printf("%d", vecLen(v1));
    printf("%d", vecEven(v2));


    /* example (with some random values) */
    /* v1: 3 6 7 5 3 5 6 2 9 1 */
    /* v2: 2 7 0 9 3 6 0 6 2 6 */

    vecAppend(v1, v2);

    /* example */
    /* v1: 3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6  */
    /* v2: 2 7 0 9 3 6 0 6 2 6 */

    vecFree(v1);
    vecFree(v2);

    return 0;
}
