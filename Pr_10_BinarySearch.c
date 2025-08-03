#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10000

int binarySearch(int arr[], int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
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
    int index = binarySearch(arr, key);
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    printf("Time : %.2f seconds\n", cpu_time);

}
