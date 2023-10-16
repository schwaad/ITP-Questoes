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

int main (){
    struct Chocolate choco[100];
    int i;
    int j;
    int maior = 0;
    int menor = INFINITY;
    int indiceMaior;
    int indiceMenor;
    int quantidadeChocolates;
    int contadorBrancos = 0;
    int contadorAmargo = 0;
    int contadorAoLeite = 0;
    int contadorComCastanhas = 0;
    char tipoChocolate[13];
    scanf("%d", &quantidadeChocolates);
    int precos[quantidadeChocolates];

    for (i=0;i<quantidadeChocolates;i++){
        scanf("%s %f %f %s", &choco[i].nome, &choco[i].peso, &choco[i].valor, &tipoChocolate);

        if (strcmp(tipoChocolate, "BRANCO") == 0){
            choco[i].tipoChocolate = BRANCO;
            contadorBrancos++;
        }
        else if (strcmp(tipoChocolate, "AMARGO") == 0){
            choco[i].tipoChocolate = AMARGO;
            contadorAmargo++;
        }
        else if (strcmp(tipoChocolate, "AO_LEITE") == 0){
            choco[i].tipoChocolate = AO_LEITE;
            contadorAoLeite++;
        }
        else if (strcmp(tipoChocolate, "COM_CASTANHAS") == 0){
            choco[i].tipoChocolate = COM_CASTANHAS;
            contadorComCastanhas++;
        }
        else{}
    }
    for (j=0;j<quantidadeChocolates;j++){
        if(choco[j].valor > maior){
            indiceMaior = j;
        }
        if(choco[j].valor < menor){
            indiceMenor = j;
        }
    }
    printf("Total de chocolates BRANCO: %d", contadorBrancos);
    printf("Total de chocolates AMARGO: %d", contadorAmargo);
    printf("Total de chocolates AO_LEITE: %d", contadorAoLeite);
    printf("Total de chocolates COM_CASTANHAS: %d", contadorComCastanhas);
    printf("Chocolate mais caro: %s - %d", choco[indiceMaior].nome, choco[indiceMaior].valor);
    printf("Chocolate mais caro: %s - %d", choco[indiceMenor].nome, choco[indiceMenor].valor);
}