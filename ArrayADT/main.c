#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct ArrayADT {
    int capacity;
    int lastIndex;
    int *ptr;
};

struct ArrayADT *createArray(int capacity) {
    struct ArrayADT *arr = NULL;
    arr = (struct ArrayADT*)malloc(sizeof(struct ArrayADT));
    arr->capacity = capacity;
    arr->lastIndex = -1;
    arr->ptr = (int*) malloc(sizeof(int)*capacity);
    return arr;
}

void insert(struct ArrayADT* arr, int index, int data) {
    if (index < 0) {
        printf("\nInvalid Index");
    }
    else if (arr->lastIndex+1 == arr->capacity) {
        printf("\nOverflow");
    }
    else if (index > arr->lastIndex + 1) {
        arr->ptr[arr->lastIndex+1] = data;
        arr->lastIndex += 1;
    }
    else {
        for (int i = arr->lastIndex ; i >= index ; i--) {
            arr->ptr[i+1] = arr->ptr[i];
        }
        arr->ptr[index] = data;
        arr->lastIndex += 1;
    }
}

void read(struct ArrayADT *arr) {
    for (int i = 0 ; i <= arr->lastIndex ; i++) {
        printf("%d ", arr->ptr[i]);
    }
    printf("\n");
}

void update(struct ArrayADT *arr, int index, int data) {
    if (index <= arr->lastIndex) {
        arr->ptr[index] = data;
    } else {
        printf("\nInvalid Index!");
    }
    read(arr);
}

void delete(struct ArrayADT *arr, int index) {
    if (index > arr->lastIndex) {
        printf("\nInvalid Index");
    } else {
        for (int i = index ; i <= arr->lastIndex ; i++) {
            arr->ptr[i] = arr->ptr[i+1];
        }
        arr->lastIndex -= 1;
    }
}

int main() {
    struct ArrayADT *arr;
    arr = createArray(6);
    insert(arr, 0, 10);
    insert(arr, 1, 20);
    insert(arr, 9, 40);
    read(arr);
    update(arr, 1, 55);
    delete(arr,0);
    read(arr);
    // printf("Capaicty is: %d\n",arr->capacity);
    // printf("Last Index is: %d\n",arr->lastIndex);
    // arr->ptr[1] = 20;
    // printf("\n1st Index data is: %d",*(arr->ptr+1));
}