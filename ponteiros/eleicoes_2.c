#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int chapa;
    char deputado[10];
    int votos;
} Party;

void compute_votes(int num_votes, int votes[num_votes], int num_parties, Party parties[num_parties], Party *most_voted, Party *second_most_voted){
    int votos_validos = 0;
    float prct_vencedor, prct_vice;
    
    for (int i = 0; i < num_parties; i++){
        parties[i].votos = 0; 

        for (int j = 0; j < num_votes; j++)
            if (votes[j] == parties[i].chapa){
                parties[i].votos++;
                votos_validos++;
            }
    }
    *most_voted = parties[0];
    *second_most_voted = parties[0];

    for (int i = 1; i < num_parties; i++)
        if (parties[i].votos > most_voted->votos){
            *second_most_voted = *most_voted;
            *most_voted = parties[i];
        } else if (parties[i].votos > second_most_voted->votos)
            *second_most_voted = parties[i];

    prct_vencedor = (most_voted->votos * 100.0) / votos_validos;
    prct_vice = (second_most_voted->votos * 100.0) / votos_validos;


    printf("VENCEDOR: %s (%d votos = %.2f%%)\n", most_voted->deputado, most_voted->votos, prct_vencedor);
    printf("VICE: %s (%d votos = %.2f%%)", second_most_voted->deputado, second_most_voted->votos, prct_vice);

}

int main() {
    int qtd_chapas;
    Party *chapas;

    scanf("%d", &qtd_chapas);

    chapas = (Party*) malloc(qtd_chapas * sizeof(Party));
    if (chapas == NULL){
        printf("Erro em alocar memória\n");
        return 1;
    }

    for (int i = 0; i < qtd_chapas; i++) {
        scanf("%d", &chapas[i].chapa);
        scanf(" %s", chapas[i].deputado);
    }

    int qtd_votos;
    int *votacao;
    Party maisVotado, segundoMaisVotado;
    scanf(" %d", &qtd_votos);

    votacao = (int*) malloc(qtd_votos * sizeof(int));
    if (votacao == NULL){
        printf("Erro em alocar memória\n");
        free(chapas);
        return 1;
    }

    for (int i = 0; i < qtd_votos; i++)
        scanf("%d", &votacao[i]);

    compute_votes(qtd_votos, votacao, qtd_chapas, chapas, &maisVotado, &segundoMaisVotado);

    free(votacao);
    free(chapas);

    return 0;
}