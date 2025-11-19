#include <stdio.h>

void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Cac phan tu trong mang: ");
    printArray(a, size);

    return 0;
}


