#include <stdio.h>

void flatten(int l, int c, int m[l][c], int vetor[], int ordem){
    int i;
    int j;
    if (ordem == 0){
        int indice = 0;
        for (i = 0; i < l; i++){
            for (j = 0; j < c; j++){
                vetor[indice] = m[i][j];
                printf("%d ", vetor[indice]);
                indice++;
            }
        }
        
    }
    else{
        int indice = 0;
        for (j = 0; j < c; j++){
            for (i = 0; i < l; i++){
                vetor[indice] = m[i][j];
                printf("%d ", vetor[indice]);
                indice++;
            }
        }
    }

    
    
}

int main (){
    int ordem;
    int linhas;
    int colunas;

    scanf("%d %d %d", &ordem, &linhas, &colunas);

    int vetor[linhas*colunas];
    int matriz[linhas][colunas];
    int i;
    int j;
    int entrada;

    for (i=0; i < linhas; i++){
        for (j=0; j < colunas; j++){
            scanf("%d", &entrada);
            matriz[i][j] = entrada;
        }
    }
    flatten(linhas,colunas,matriz,vetor,ordem);
}