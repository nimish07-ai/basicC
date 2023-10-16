#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void enter(int *size, int *counter, int **array) {
    int tmp;
    scanf("%d", &tmp);
    if (*size >= pow(2, *counter)) {
        (*counter)++;
        *array = (int *)realloc(*array, sizeof(int) * (int)pow(2, *counter));
    }
    (*array)[(*size)++] = tmp;
}

void print(int size, int capacity, int *array) {
    printf("\n Capacity = %d; size = %d; elements = ", (int)pow(2, capacity), size);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void pop_back(int *size, int *counter, int **array){
    if (*size <= pow(2, (*counter)-1)) {
        (*counter)--;
        *array = (int *)realloc(*array, sizeof(int) * (int)pow(2, (*counter)));
    }
    (*size)--;   
}

int main() {
    int *array = (int *)malloc(sizeof(int));
    int size = 0;
    int counter = 0;
    while (size <5) {
        enter(&size, &counter, &array);
        print(size, counter, array);
    }
    while (size >0) {
        pop_back(&size, &counter, &array);
        print(size, counter, array);
    }

    // Clean up: free the dynamically allocated memory
    free(array);

    return 0;
}
