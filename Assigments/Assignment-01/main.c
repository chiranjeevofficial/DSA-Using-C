// 1. Define a function to find the greatest number in a given array.
// a. int maxValue(int A[], int size);

#include<stdio.h>

int findGreatest (int array[], int size) {
    int max = 0;
    for (int i = 0; i < size ; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

float findAverage (int array[], int size) {
    float sum = 0;
    for (int i = 0 ; i < size ; i++) {
        sum += array[i];
    }
    return sum/size;
}

int findSum (int array[], int size) {
    int sum = 0;
    for (int i = 0 ; i < size ; i++) {
        sum += array[i];
    }
    return sum;
}

int main () {
    int array[5] = {1, 2, 3, 4, 5};
    printf("maximum value is: %d\n",findGreatest(array,5));
    printf("average value is: %0.2f\n",findAverage(array,5));
    printf("sum of array is:  %d\n",findSum(array,5));
}