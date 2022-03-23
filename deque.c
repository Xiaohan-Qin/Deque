#include<stdio.h>
#include<stdlib.h>
#include"deque.h"

/*
 * Creates a Deque node by malloc'ing space.
 * INPUT: an integer that specifies the value of node.
 * Returns a pointer to the new Deque node.
 */
Node* CreateNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*
 * Creates an empty Deque.
 * Returns a pointer to the empty Deuqe.
 */
Deque* CreateDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}

/*
 * Checks if a deque is empty.
 * INPUT: a Deque pointer.
 * returns 1 if empty, 0 if not empty.
 */
int isEmpty(Deque* deque) {
    if (deque->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Push a number at the rear of deque.
 * INPUT: A Deque pointer.
 * INPUT: An integer that specifies the value of new node.
 */
void pushRight(Deque* deque, int x) {
    Node* newNode = CreateNode(x);
    if (isEmpty(deque) == 1) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
        newNode->prev = deque->rear;
    }
    deque->rear = newNode;
    deque->size += 1;
}

/*
 * Push a number at the front of deque.
 * INPUT: A Deque pointer.
 * INPUT: An integer that specifies the value of new node.
 */
void pushLeft(Deque* deque, int x) {
    Node* newNode = CreateNode(x);
    if (deque->size == 0) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        newNode->next = deque->front;
    }
    deque->front = newNode;
    deque->size += 1;
}

/*
 * Fetches the rear node but does not remove it.
 * INPUT: A Deque pointer.
 */
void peekRight(Deque* deque) {
    // if deque is empty, return garbage value
    if (isEmpty(deque) == 1) {
        return;
    }
    int data = deque->rear->data;
    printf("The right node is %d\n", data);
}

/*
 * Fetches the front node but does not remove it.
 * INPUT: A Deque pointer.
 */
void peekLeft(Deque* deque) {
    if (isEmpty(deque) == 1) {
        return;
    }
    int data = deque->front->data;
    printf("The left node is %d\n", data);
}

/*
 * Fetches and removes the rear node.
 * INPUT: A Deque pointer.
 */
void popRight(Deque* deque) {
    if (isEmpty(deque) == 1) {
        return;
    }
    Node* node = deque->rear;
    deque->rear = node->prev;
    // if deque is empty after deletion, update front to null
    if (!deque->rear) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    deque->size -= 1;
    int data = node->data;
    free(node);
    printf("You've removed %d\n", data);
}

/*
 * Fetches and removes the dront node.
 * INPUT: A Deque pointer.
 */
void popLeft(Deque* deque) {
    if (isEmpty(deque) == 1) {
        return;
    }
    Node* node = deque->front;
    deque->front = node->next;
    // if deque is empty after deletion, update rear to null
    if (!deque->front) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    deque->size -= 1;
    int data = node->data;
    free(node);
    printf("You've removed %d\n", data);
}

/*
 * Print all nodes' values in the deque.
 * INPUT: A Deque pointer.
 */
void printAll(Deque* deque) {
  Node* temp = deque->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

/*
 * Driver function.
 */
int main() {
    Deque* deque = CreateDeque();
    printf("Push 4 to the left of queue: \n");
    pushLeft(deque, 4);
    printAll(deque);
    printf("Push 1 to the left of queue: \n");
    pushLeft(deque, 1);
    printAll(deque);
    printf("Push 0 to the right of queue: \n");
    pushRight(deque, 0);
    printAll(deque);
    printf("Push 8 to the right of queue: \n");
    pushRight(deque, 8);
    printAll(deque);
    printf("Pop left: \n");
    popLeft(deque);
    printf("Pop right: \n");
    popRight(deque);
    printf("Peek left: \n");
    peekLeft(deque);
    printf("Peek right: \n");
    peekRight(deque);
    printf("The remaining elements is queue are: \n");
    printAll(deque);
    return 0;
}
