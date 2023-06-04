#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solution.h"


int main() {
    int n, choice;

    printf("Ingrese el tamanio de la lista: ");
    scanf("%d", &n);

    int arrayOriginal[n],array[n];
    int i;

    // Llenar el arreglo con los números del 0 al n-1
    for (i = 0; i < n; i++) {
        arrayOriginal[i] = i;
    }

    // Desordenar el arreglo
    randomizarArarray(arrayOriginal, n);

    // Imprimir el arreglo desordenado
    printf("Arreglo desordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arrayOriginal[i]);
    }
    copiarArray(arrayOriginal, array, n);

    printf("\n");

    printf("\nElija el algoritmo de ordenacion:\n");
    printf("1. Burbuja\n");
    printf("2. Seleccion\n");
    printf("3. Insercion\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Ejecutar todos\n");
    printf("Ingrese su eleccion: ");
    scanf("%d", &choice);

    printf("\n");

    switch (choice) {
        case 1:{
            
            clock_t inicio = clock();
            bubbleSort(array, n);
            clock_t fin = clock();
            printf("Arreglo ordenado por Burbuja: ");
            printArray(array, n);
            double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
            printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
            break;
            }
        case 2:
            {
            
            clock_t inicio = clock();
            selectionSort(array, n);
            clock_t fin = clock();
            printf("Arreglo ordenado por Seleccion: ");
            printArray(array, n);
            double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
            printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
            break;
            }
        case 3:
            {
            
            clock_t inicio = clock();
            insertionSort(array, n);
            clock_t fin = clock();
            printf("Arreglo ordenado por Insercion: ");
            printArray(array, n);
            double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
            printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
            break;
            }    
        case 4:
            {
            
            clock_t inicio = clock();
            mergeSort(array, 0,n-1);
            clock_t fin = clock();
            printf("Arreglo ordenado por Mezcla (Merge Sort): ");
            printArray(array, n);
            double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
            printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
            break;
            }  
        case 5:
            {
            
            clock_t inicio = clock();
            quickSort(array, 0,n-1);
            clock_t fin = clock();
            printf("Arreglo ordenado por Rapida (Quick Sort): ");
            printArray(array, n);
            double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
            printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
            break;
            } 
        case 6:
            {
            printf("Arreglo ordenado por Burbuja: ");
            {
                clock_t inicio = clock();
                bubbleSort(array, n);
                clock_t fin = clock();
                double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;  
                printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
                copiarArray(arrayOriginal, array, n);
                }

            printf("Arreglo ordenado por Seleccion: ");
            {
                clock_t inicio = clock();
                selectionSort(array, n);
                clock_t fin = clock();
                double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
                printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);

                copiarArray(arrayOriginal, array, n);
                }

            printf("Arreglo ordenado por Insercion: ");
            {
                 clock_t inicio = clock();
                insertionSort(array, n);
                clock_t fin = clock();
                double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
                printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);
                
                copiarArray(arrayOriginal, array, n);
                }

            printf("Arreglo ordenado por Mezcla (Merge Sort): ");
            {
                clock_t inicio = clock();
                mergeSort(array, 0,n-1);
                clock_t fin = clock();
                double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
                printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);

                copiarArray(arrayOriginal, array, n);
                }


            printf("Arreglo ordenado por Rapida (Quick Sort): ");{
                clock_t inicio = clock();
                quickSort(array, 0,n-1);
                clock_t fin = clock();
                double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;     
                printf("El tiempo de ejecucion fue: %f segundos\n", tiempo_total);

                copiarArray(arrayOriginal, array, n);
                }
            break;
            }
        default:
            printf("Opcion invalida\n");
            break;
    }

    return 0;
}


