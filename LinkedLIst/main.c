#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
    int data;
    struct node *next;
};

// function declaration

// function definition
void insertAtLast(struct node **root, int data) {
    struct node *tempNode, *traversalNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->data = data;
    tempNode->next = NULL;
    if (*root == NULL)
        *root = tempNode;
    else {
        traversalNode = *root;
        while(traversalNode->next != NULL)
            traversalNode = traversalNode->next;
        traversalNode->next = tempNode;
    }
}

void insertAtFirst(struct node **root, int data) {
    struct node *tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->data = data;
    tempNode->next = NULL;
    tempNode->next = *root;
    *root = tempNode;
}

void afterAtNode(struct node **root, int data) {
    struct node *tempNode, *traversalNode;
    tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->data = data;
    tempNode->next = NULL;
}

void read(struct node *root) {
    if (root == NULL) {
        printf("NULL\n");
    } else {
        struct node *traversalNode = root;
        while (traversalNode != NULL) {
            printf("%d ",traversalNode->data);
            if (traversalNode->next == NULL) {
                traversalNode = NULL;
            } else {
                traversalNode = traversalNode->next;
            }
        }
    }
}

int countNode(struct node *root) {
    if (root == NULL) {
        return -1;
    } else {
        int capacity = 0;
        struct node *traversalNode = root;
        while (traversalNode != NULL) {
            traversalNode = traversalNode->next;
            capacity++;
        }
        return capacity;
    }
}

int menu() {
    printf("1. Append Item\n");
    printf("2. Insert Item\n");
    printf("3. In Between\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    return choice;
}

int main() {
    struct node *root = NULL;
    int data;
    while (1) {
        system("cls");
        printf("Total Element: %d\n",countNode(root));
        printf("List Elements: ");
        read(root);
        printf("\n");
        switch(menu()) {
            case 1:
                printf("Enter item value to append: ");
                scanf("%d",&data);
                insertAtFirst(&root,data);
                break;
            case 2:
                printf("Enter item value to insert: ");
                scanf("%d",&data);
                insertAtLast(&root,data);
                break;
            case 3:
                printf("Under Construction");
                break;
            case 4:
                printf("Press any key to exit: ");
                getch();
                exit(0);
            default:
                printf("Invalid choice, retry");
                break;
        }
    }
    getch();
    return 0;
}

/*
insert new node
1) as a last node
2) as a first node
3) after a node

delete a node
1) first node
2) last node
3) particular node
*/