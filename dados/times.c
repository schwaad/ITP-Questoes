#include <stdio.h>

typedef struct {
    char nome[50];
    int golsMarcados;
    int golsSofridos;
} Time;

void ordenarTimes(int tamanho, Time vetor[]) {
    int i, j;
    Time aux;
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho - 1; j++) {
            if (vetor[j].golsMarcados < vetor[j + 1].golsMarcados) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main() {
    int quantidadeTimes;
    int i;
    Time time[100];

    scanf("%d", &quantidadeTimes);

    for (i = 0; i < quantidadeTimes; i++) {
        scanf(" %[^\n]", time[i].nome);
        scanf("%d %d", &time[i].golsMarcados, &time[i].golsSofridos);
    }

    Time times[quantidadeTimes];
    for (i = 0; i < quantidadeTimes; i++) {
        times[i] = time[i];
    }

    ordenarTimes(quantidadeTimes, times);

    for (i = 0; i < quantidadeTimes; i++) {
        printf("%d - %s\n", i+1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].golsMarcados);
        printf("Gols sofridos: %d\n", times[i].golsSofridos);
    }
}
