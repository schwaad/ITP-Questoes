#include <stdio.h>
#include <string.h>
#include <math.h>

enum TipoChocolates {
    BRANCO,
    AMARGO,
    AO_LEITE,
    COM_CASTANHAS
};

struct Chocolate {
    char nome[50];
    float peso;
    float valor;
    enum TipoChocolates tipoChocolate;
};

int main() {
    struct Chocolate choco[100];
    int i;
    int j;
    float maior = -1.0; 
    float menor = 100000.0; 
    int indiceMaior = 0;  
    int indiceMenor = 0; 
    int quantidadeChocolates;
    int contadorBrancos = 0;
    int contadorAmargo = 0;
    int contadorAoLeite = 0;
    int contadorComCastanhas = 0;
    char tipoChocolate[13];
    scanf("%d", &quantidadeChocolates);

    for (i = 0; i < quantidadeChocolates; i++) {
        scanf("%s", choco[i].nome);
        scanf("%f %f", &choco[i].peso, &choco[i].valor);
        scanf("%s", tipoChocolate);

        if (strcmp(tipoChocolate, "BRANCO") == 0) {
            choco[i].tipoChocolate = BRANCO;
            contadorBrancos++;
        } else if (strcmp(tipoChocolate, "AMARGO") == 0) {
            choco[i].tipoChocolate = AMARGO;
            contadorAmargo++;
        } else if (strcmp(tipoChocolate, "AO_LEITE") == 0) {
            choco[i].tipoChocolate = AO_LEITE;
            contadorAoLeite++;
        } else if (strcmp(tipoChocolate, "COM_CASTANHAS") == 0) {
            choco[i].tipoChocolate = COM_CASTANHAS;
            contadorComCastanhas++;
        }
    }
    for (j = 0; j < quantidadeChocolates; j++) {
        if (choco[j].valor > maior) {
            maior = choco[j].valor;
            indiceMaior = j;
        }
        if (choco[j].valor < menor) {
            menor = choco[j].valor;
            indiceMenor = j;
        }
    }
    printf("Total de chocolates BRANCO: %d\n", contadorBrancos);
    printf("Total de chocolates AMARGO: %d\n", contadorAmargo);
    printf("Total de chocolates AO_LEITE: %d\n", contadorAoLeite);
    printf("Total de chocolates COM_CASTANHAS: %d\n", contadorComCastanhas);
    printf("Chocolate mais caro: %s - R$%.2f\n", choco[indiceMaior].nome, choco[indiceMaior].valor);
    printf("Chocolate mais barato: %s - R$%.2f\n", choco[indiceMenor].nome, choco[indiceMenor].valor);
}
