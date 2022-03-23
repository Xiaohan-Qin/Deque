#ifndef DEQUE_H
#define DEQUE_H


/*
======================================================
DEQUE
======================================================


/*
 * This struct represents an individual node within a deque.
 * A node has data and a next and prev pointers.
 */
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


/*
 * This struct represents the entire deque.
 * A Deque has size, and a front and rear pointers.
 */
typedef struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
} Deque;


/*
 * Creates a Deque node by malloc'ing space.
 * INPUT: an integer that specifies the value of node.
 * Returns a pointer to the new Deque node.
 */
Node* CreateNode(int x);


/*
 * Creates an empty Deque.
 * Returns a pointer to the empty Deuqe.
 */
Deque* CreateDeque();


/*
 * Checks if a deque is empty.
 * INPUT: a Deque pointer.
 * returns 1 if empty, 0 if not empty.
 */
int isEmpty(Deque* deque);


/*
 * Push a number at the rear of deque.
 * INPUT: A Deque pointer.
 * INPUT: An integer that specifies the value of new node.
 */
void pushRight(Deque* deque, int x);


/*
 * Push a number at the front of deque.
 * INPUT: A Deque pointer.
 * INPUT: An integer that specifies the value of new node.
 */
void pushLeft(Deque* deque, int x);


/*
 * Fetches the rear node but does not remove it.
 * INPUT: A Deque pointer.
 */
void peekRight(Deque* deque);


/*
 * Fetches the front node but does not remove it.
 * INPUT: A Deque pointer.
 */
void peekLeft(Deque* deque);


/*
 * Fetches and removes the rear node.
 * INPUT: A Deque pointer.
 */
void popRight(Deque* deque);


/*
 * Fetches and removes the dront node.
 * INPUT: A Deque pointer.
 */
void popLeft(Deque* deque);


/*
 * Print all nodes' values in the deque.
 * INPUT: A Deque pointer.
 */
void printAll(Deque* deque);
