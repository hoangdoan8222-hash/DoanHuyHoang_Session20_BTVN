#include <stdio.h>

#define SIZE 6 

int search(int arr[], int key) {
    int i; 
    for (i = 0; i < SIZE; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int a[SIZE] = {1, 2, 4, 5, 6, 7};
    int key = 7;

    int result = search(a, key);

    if (result != -1)
        printf("%d\n", result);
    else
        printf("Khong tim thay phan tu!\n");

    return 0;
}

