#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int chapa1 = 0, chapa2 = 0;
    int max1 = -1, max2 = -1;

    for (int i = 0; i < n; i++) {
        int voto = votes[i];
        int contador = 0;

        for (int j = 0; j < n; j++) {
            if (votes[j] == voto) {
                contador++;
            }
        }

        if (contador > max1) {
            max2 = max1;
            chapa2 = chapa1;
            max1 = contador;
            chapa1 = voto;
        } else if (contador > max2 && voto != chapa1) {
            max2 = contador;
            chapa2 = voto;
        }
    }

    *most_voted = chapa1;
    *second_most_voted = chapa2;
}

int main() {
    int quantidadeChapas;
    scanf("%d", &quantidadeChapas);
    int votos[quantidadeChapas];
    int chapaVencedora, chapaVice;

    for (int i = 0; i < quantidadeChapas; i++) {
        scanf("%d", &votos[i]);
    }

    compute_votes(quantidadeChapas, votos, &chapaVencedora, &chapaVice);

    printf("%d %d", chapaVencedora, chapaVice);

    return 0;
}
