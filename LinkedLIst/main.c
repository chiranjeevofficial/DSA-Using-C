#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *nextNode;
};

// function declaration

// function definition
void insertAtLast(struct node **root, int data) {
    struct node *tempNode, *traversalNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->data = data;
    tempNode->nextNode = NULL;
    if (*root == NULL)
        *root = tempNode;
    else {
        traversalNode = *root;
        while(traversalNode->nextNode != NULL)
            traversalNode = traversalNode->nextNode;
        traversalNode->nextNode = tempNode;
    }
}

void insertAtFirst(struct node **root, int data) {
    struct node *tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->data = data;
    tempNode->nextNode = NULL;
    tempNode->nextNode = *root;
    *root = tempNode;
}

void afterAtNode(struct node **root, int data) {
    struct node *tempNode, *traversalNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->data = data;
    tempNode->nextNode = NULL;
}

int main() {
    struct node *root = NULL;
    insertAtLast(&root,25);
    return 0;
}

/*
insert new node
1) as a last node
2) as a first node
3) after a node

define a node
1) first node
2) last node
3) particular node
*/