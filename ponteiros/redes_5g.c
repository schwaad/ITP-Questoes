#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int obter_intervalo(int n, int celulas[n], int distancia, int usuario, int *indice_esquerda, int *indice_direita){
    int contador = 0;
    int esquerda = 0, direita = n - 1;
    int mais_proximo = -1;
    
    while (esquerda <= direita){
        int meio = (esquerda + direita) / 2;

        if (mais_proximo == -1 || abs(celulas[meio] - usuario) < abs(celulas[mais_proximo] - usuario))
            mais_proximo = meio;
        if (celulas[meio] < usuario)
            esquerda = meio + 1;
        else
            direita = meio - 1; 
    }

    *indice_esquerda = *indice_direita = mais_proximo;
    
    while (*indice_esquerda >= 0 && abs(celulas[*indice_esquerda] - usuario) <= distancia){
        contador++;
        (*indice_esquerda)--;
    }
    
    for (int i = mais_proximo + 1; i < n && abs(celulas[i] - usuario) <= distancia; i++){
        contador++;
        *indice_direita = i;
    }

    return contador;
}

int main(){
    int num_celulas, alcance_celulas, posicao_usuario;
    int indice_esquerda, indice_direita;
    
    scanf("%d %d %d", &num_celulas, &alcance_celulas, &posicao_usuario);

    int *celulas = (int*) malloc(num_celulas * sizeof(int));
    if (celulas == NULL){
        printf("Erro ao alocar memória");
        return 1;
    }

    for (int i = 0; i < num_celulas; i++) 
        scanf("%d", &celulas[i]);

    int contagem = obter_intervalo(num_celulas, celulas, alcance_celulas, posicao_usuario, &indice_esquerda, &indice_direita);

    if (contagem > 0){
        for (int i = indice_esquerda + 1; i <= indice_direita; i++)
            printf("%d ", celulas[i]);
            
        printf("\n");
    } else 
        printf("USUARIO DESCONECTADO\n");

    free(celulas);
    return 0;
}
