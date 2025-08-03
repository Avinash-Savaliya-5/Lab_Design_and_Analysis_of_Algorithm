#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100000

int linearSearch(int arr[], int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

void main() {
    int arr[size];
    FILE* fp = fopen("File_Best.txt", "r");

    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);

    clock_t start, end;
    double cpu_time;

    start = clock();
    int index = linearSearch(arr, key);
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    printf("Time : %.2f", cpu_time);

}
