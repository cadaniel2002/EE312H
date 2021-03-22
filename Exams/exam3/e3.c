
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ONLY MODIFY places marked with "TODO"

/*
 * Problem 1 - Algorithm Complexity (4 points)
 * For parts a - c calculate the Big-O time
 * complexity of the following functions (1 point each):
 */

/*
 * Part a
 * Big-O =  O(n)
 */
int partA(int arr[], int N) {
    int evenSum = 0;
    int i = 0;
    while(i < N) {
        evenSum = evenSum + arr[i];
        i = i + 2;
    }

    return evenSum;
}


/*
 * Part b
 * Big-O =  O(n^2)
 */
int partB(int arr[], int N) {
    int pairwiseSum = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int sum = arr[i] + arr[j];
            pairwiseSum = pairwiseSum + sum;
        }
    }

    return pairwiseSum;
}


/*
 * Part c
 * Big-O =  O(nlog(n))
 */
int partC(int N) {
    int result = 0;
    int index = 1;

    while (index < N) {
        for(int j = 0; j < N; j += 2) {
            result = result * 3;
        }
        index = index * 2;
    }

    return result;
}

/* 
 * Part d
 * Time = 45s
 *
 * A run of insertion sort on 10,000 random elements takes 5 s.  If
 * the data size is increased to 30,000 elements, how long will it
 * take to sort them using the same program?
 */

/*
 * Problem 2 - Linked Lists (6 points)
 *
 * You will implement several functions that deal with 
 * linked lists. None of the functions will have NULL inputs for pointers.
 *
 * Functions to implement:
 * (a)[3 points] checking for cycles in a linked list
 * (c)[3 points] merge two sorted linked lists
 */

/* Linked list node struct */
typedef struct _llnode {
    int data; // data for each node
    struct _llnode *next; // pointer to next node
} LLNode;


/* Linked list root struct */
typedef struct _llroot {
    /* Pointer to the head (first) node of a chain of LLNodes on the
     * heap. head has no useful data, and is a dummy. */
    LLNode* head;

    // Keep in mind:
    // (1) No tail pointer is used or needed in this struct
    // (2) The last LLNode's next should be NULL
    // (3) In an empty list, head is set to NULL
} LLRoot;

// Helper functions provided to you and defined further down
LLNode* createNode(int data);
LLRoot* createList(void);
void addValue(LLRoot *root, int data);


/*
 * Returns 1 if the given linked list contains a cycle, 0 otherwise.
 * Assume each node in the linked list has a unique data value.
 * Assume there are a maximum of 100 nodes in the linked list.
 *
 * Ex. The linked list: head -> 3 -> 7 -> 2 -> 8 -
 *                                    \___________\
 *     contains a cycle (7->2->8->7).
 *
 *     The linked list: head -> 4 -> 8 -> 2 -> 5
 *     does not.
 */
int hasCycle(LLRoot *root) {
    int dataList[100];
    LLNode *p = root->head;
    int cnt = 0;
    while(p != NULL){
        for(int i = 0; i < cnt; i++){
            if(dataList[i] == p->data){
                return 1;
            }
        }
        dataList[cnt] = p->data;
        cnt++;
        p = p->next;
    }
    return 0;
}

/*
 * Returns a new list (with new nodes) that merges values from two
 * given sorted lists.  The original lists, which are given as
 * arguments, should not be modified.  Your merge algorithm should
 * ensure that the resulting list is sorted.
 *
 * IMPORTANT: do not implement any sorting algorithm in this
 * function.  The merged list could have duplicate values.
 *
 * HINT: Separate the loops for merging (a) when both lists are
 * non-empty, and (b) when one list is empty.
 *
 * Finish what you can, as partial credit will be awarded.
 */



LLRoot* mergeLists(LLRoot *one, LLRoot *two) {
    LLNode *nOne = one->head;
    while(nOne->next != NULL){
        nOne = nOne->next;
    }
    LLNode *nTwo = two->head;
    while(nTwo->next != NULL){
        nTwo = nOne->next;
    }
    int oneVal = nOne->data;
    int twoVal = nTwo->data;
    LLNode *oneSave = nOne;
    LLNode *twoSave = nTwo;

    LLRoot *newList = createList();
        while(nOne != one->head && nTwo != two->head){
            if(oneVal>=twoVal){

                addValue(newList, oneVal);
                nOne = one->head;
                while(nOne->next != oneSave){
                    nOne = nOne->next;
                }
                if(nOne != one->head){
                    oneVal = nOne->data; 
                    oneSave = nOne; 
                }  
            }
            else{

                addValue(newList, twoVal);
                nTwo = two->head;
                while(nTwo->next != twoSave){
                    nTwo = nTwo->next;
                }
                if(nTwo != two->head){
                    twoVal = nTwo->data;
                    twoSave = nTwo;
                }
            }
        }
        if(nOne == one->head){
            while(nTwo != two->head){
                addValue(newList, twoVal);
                nTwo = two->head;
                while(nTwo->next!= twoSave){
                    nTwo = nTwo->next;
                }
                if(nTwo != two->head){
                    twoVal = nTwo->data;
                    twoSave = nTwo;
                }             
            }
        }
        else{
            while(nOne != one->head){
                addValue(newList, oneVal);
                nOne = one->head;
                while(nOne->next != oneSave){
                    nOne = nOne->next;
                }
                if(nOne != one->head){
                    oneVal = nOne->data;
                    oneSave = nOne; 
                }  
            }               
        }

    return newList;
}
/* ---------------------------------------- */
/* ONLY DEMO OF YOUR FUNCTIONS BELOW THIS POINT */

LLNode* createNode(int data) {
    LLNode *node = malloc(sizeof(LLNode));
    node->data = data;
    node->next = NULL;
    return node;
}

LLRoot* createList(void) {
    LLRoot *list = malloc(sizeof(LLRoot));
    list->head = NULL;
    return list;
}

/* Add a value at the start of the LLRoot */
void addValue(LLRoot *root, int data) {
    LLNode *node = createNode(data);
    node->next = root->head;
    root->head = node;
}

int main(void) {
    LLRoot *r1 = createList();
    addValue(r1, 8);
    addValue(r1, 5);
    addValue(r1, 2);
    addValue(r1, 1);
    // printList(r1);

    LLRoot *r2 = createList();
    addValue(r2, 6);
    addValue(r2, 1);
    // printList(r2);

    /* Example:
     *
     * r1: head -> 1 -> 2 -> 5 -> 8 -> NULL
     *
     * Recall that C treats 0 as false, and any other integer as true.
     */

    if(!hasCycle(r1)){
        printf("r1 does not have a cycle!\n");
    }

    /*
     * No need to free memory
     */

    return 0;
}
