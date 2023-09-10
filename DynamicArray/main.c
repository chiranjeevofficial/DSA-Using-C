#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ArrayDYN {
    int capacity;
    int lastIndex;
    int *ptr;
};

// function declaration
struct ArrayDYN* create(int);
void insert(struct ArrayDYN*, int, int);
void extend(struct ArrayDYN*);
void append(struct ArrayDYN*, int);
void read(struct ArrayDYN*);
void shrink(struct ArrayDYN*);
void delete(struct ArrayDYN*, int);
int countItem(struct ArrayDYN*);
void edit(struct ArrayDYN*, int, int);
int getItem(struct ArrayDYN*, int);

// function definition
struct ArrayDYN* create(int arraySize) {
    struct ArrayDYN *temp = NULL;
    temp = (struct ArrayDYN*)malloc(sizeof(struct ArrayDYN));
    temp->capacity = arraySize;
    temp->lastIndex = -1;
    temp->ptr = (int*)malloc(sizeof(int) * arraySize);
    return temp;
}

void insert(struct ArrayDYN* array, int index, int data) {
    if (index < 0 || index > array->lastIndex+1)
        printf("Invalid Index\n");
    else {
        if (array->lastIndex+1 == array->capacity)
            extend(array);
        for (int i = array->lastIndex ; i >= index ; i--)
            array->ptr[i+1] = array->ptr[i];
        array->ptr[index] = data;
        array->lastIndex++;
        printf("Inserted\n");
    }
}

void extend(struct ArrayDYN *array) {
    int *temp = NULL;
    temp = (int*)malloc(sizeof(int) * (array->capacity * 2));
    for (int i = 0 ; i < array->lastIndex+1 ; i++)
        temp[i] = array->ptr[i];
    free(array->ptr);
    array->ptr = temp;
    array->capacity *= 2;
}

void append(struct ArrayDYN *array, int data) {
    if (array->lastIndex+1 == array->capacity)
        extend(array);
    array->ptr[array->lastIndex+1] = data;
    array->lastIndex++;
    printf("Appended\n");
}

void read(struct ArrayDYN *array) {
    for (int i = 0 ; i <= array->lastIndex ; i++) {
        printf("%d ",array->ptr[i]);
    }
    printf("\n");
}

void shrink(struct ArrayDYN *array) {
    int *temp;
    temp = (int*)malloc(sizeof(int) * (array->lastIndex+1));
    for (int i = 0 ; i <= array->lastIndex ; i++)
        temp[i] = array->ptr[i];
    free(array->ptr);
    array->ptr = temp;
    array->capacity /= 2;
    printf("Shrink\n");
}

void delete(struct ArrayDYN *array, int index) {
    if (array->lastIndex == -1)
        printf("Underflow\n");
    else if (index < 0 || index > array->lastIndex)
        printf("Invalid Index\n");
    else {
        if (index == array->lastIndex) {
            array->lastIndex--;
        } else {
            for (int i = index ; i < array->lastIndex ; i++ ) {
                array->ptr[i] = array->ptr[i+1];
            }
            array->lastIndex--;
        }
        printf("Deleted\n");
        if (array->lastIndex+1 == array->capacity / 2 && array->capacity > 1)
            shrink(array);
    }
}

int countItem(struct ArrayDYN *array) {
    if (array->lastIndex == -1)
        return -1;
    else
        return array->lastIndex+1;
}

void edit(struct ArrayDYN *array, int index, int data) {
    if (index > array->lastIndex || index < -1)
        printf("Invalid Index");
    else
        array->ptr[index] = data;
}

int getItem(struct ArrayDYN *array, int index) {
    if (index > array->lastIndex || index < -1)
        return -1;
    else
        return array->ptr[index];
}

int menu() {
    printf("1. Append Item\n");
    printf("2. Insert Item\n");
    printf("3. Remove Item\n");
    printf("4. Edit Item\n");
    printf("5. Retreive Item\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    return choice;
}

int main() {
    struct ArrayDYN *array;
    array = create(2);
    int index, data;
    while (1) {
        system("cls");
        printf("Array Capacity: %d\n",array->capacity);
        printf("Total Element : %d\n",countItem(array));
        printf("Array Value   : ");
        read(array);
        printf("\n");
        switch (menu()) {
            case 1:
                printf("Enter item value to append: ");
                scanf("%d",&data);
                append(array,data);
                break;
            case 2:
                printf("Enter index to insert new item: ");
                scanf("%d",&index);
                printf("Enter item value to insert: ");
                scanf("%d",&data);
                insert(array,index,data);
                break;
            case 3:
                printf("Enter index to delete the item: ");
                scanf("%d",&index);
                delete(array,index);
                break;
            case 4:
                printf("Enter index to edit the item: ");
                scanf("%d",&index);
                printf("Enter item value to edit: ");
                scanf("%d",&data);
                edit(array, index, data);
                break;
            case 5:
                printf("Enter index to retrieve an item: ");
                scanf("%d",&index);
                data = getItem(array,index);
                if (data != -1)
                    printf("Item value: %d",data);
                break;
            case 6:
                printf("Press any key to exit: ");
                getch();
                exit(0);
            default:
                printf("Invalid choice, retry");
                break;
        }
    }
    return 0;
}