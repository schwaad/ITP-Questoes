#include <stdio.h>
#include <stdlib.h>

void ordenarNumeros(int *vetor, int n) {
    int temp;
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (vetor[i] > vetor[i + 1]) {
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    int *arrayNumeros = NULL;
    int contadorEspacos = 0;

    while (1) {
        int inputNumero;
        char espaco;
        if (scanf("%d%c", &inputNumero, &espaco) != 2 || espaco == '\n') {
            int *tempArray = (int *)realloc(arrayNumeros, (contadorEspacos + 1) * sizeof(int));
            arrayNumeros = tempArray;
            arrayNumeros[contadorEspacos++] = inputNumero;
            break;
        }

        int *tempArray = (int *)realloc(arrayNumeros, (contadorEspacos + 1) * sizeof(int));
        if (tempArray == NULL) {
            printf("Erro de alocação\n");
            free(arrayNumeros);
            return 1;
        }

        arrayNumeros = tempArray;
        arrayNumeros[contadorEspacos++] = inputNumero;
    }

    ordenarNumeros(arrayNumeros, contadorEspacos);

    for (int i = 0; i < contadorEspacos; i++) {
        printf("%d ", arrayNumeros[i]);
    }
    printf("\n");

    free(arrayNumeros);

    return 0;
}
