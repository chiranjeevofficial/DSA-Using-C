#include<stdio.h>
#include<stdlib.h>
int main() {
    //malloc() method makes variable of 4Bytes.
    //int *p = malloc(4);
    
    //calloc() method makes the dynamic array 3 is number of variable and 4 is size of variabe.
    int *q = NULL;
    q = calloc(5,4);
    printf("Enter 5 numbers: ");
    for(int i = 0 ; i < 5 ; i++) {
        scanf("%d",(q+i));
    }
    // printf("%d",*(q+2));
    printf("You entered: ");
    for (int i = 0 ; i < 5 ; i++) {
        printf("%d ",*(q+i));
    }
    return 0;
}