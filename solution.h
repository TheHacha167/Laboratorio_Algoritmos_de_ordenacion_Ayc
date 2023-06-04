#ifndef SOLUTION_H
#define SOLUTION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int array[], int n);
void selectionSort(int array[], int n);
void insertionSort(int array[], int n);
void mergeSort(int array[], int left, int right);
void quickSort(int array[], int low, int high);
void randomizarArarray(int array[], int size);
void merge(int A[], int left, int center, int right);


void merge(int A[], int left, int center, int right) {
    int i, j, k;
    int n1 = center - left + 1;
    int n2 = right - center;

    // Crear array temporales
    int L[n1], R[n2];

    // Copiar los datos a los array temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[center + 1 + j];

    // Mezclar los array temporales en el arreglo original A[]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void randomizarArarray(int array[], int size) {
    srand(time(NULL));
    int i;
    for (i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void copiarArray(int original[], int destino[], int size) {
    for (int i = 0; i < size; i++) {
        destino[i] = original[i];
    }
}

void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Intercambiar los elementos
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selectionSort(int A[], int n) {
    int i, j, min_index;

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        // Encuentra el índice del elemento mínimo en el subarreglo no ordenado
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }

        // Intercambia el elemento mínimo con el primer elemento no ordenado
        swap(&A[i], &A[min_index]);
    }
}

void insertionSort(int array[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;

        // Ordenar la primera y segunda mitad del arreglo
        mergeSort(A, left, center);
        mergeSort(A, center + 1, right);

        // Mezclar las dos mitades ordenadas
        merge(A, left, center, right);
    }
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}



#endif