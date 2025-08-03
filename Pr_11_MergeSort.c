#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 100000

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d \n", arr[i]);
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[size];
    FILE* fp = fopen("File_Best.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            printf("Error reading number at index %d\n", i);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    clock_t end = clock();    

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.6f seconds\n", cpu_time_used);

    return 0;
}
