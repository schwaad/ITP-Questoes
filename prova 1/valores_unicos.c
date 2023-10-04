#include <stdio.h>

void sortArray(int tamanho, int array[]) {
    int i, j, aux;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    for (i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int tamanho;

    scanf("%d", &tamanho);

    int vetor[tamanho];
    int vetorUnicos[tamanho];
    int i, j, entrada, repetido = 0;
    int tamanhoUnicos = 0;

    for (i = 0; i < tamanho; i++) {
        scanf("%d", &entrada);
        vetor[i] = entrada;
        repetido = 0;

        for (j = 0; j < i; j++) {
            if (vetor[i] == vetor[j]) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            vetorUnicos[tamanhoUnicos] = vetor[i];
            tamanhoUnicos++;
        }
    }

    sortArray(tamanhoUnicos, vetorUnicos);

    

    return 0;
}
