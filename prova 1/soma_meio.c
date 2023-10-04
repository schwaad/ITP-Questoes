#include <stdio.h>
#include <math.h>

void somaLinhaMatrizMeio(int l,int c,int m[l][c]){
    int j;
    int i;
    int soma = 0;
    int somaLinha = 0;
    int somaColuna = 0;

    for (j=0; j < c; j++){
            somaLinha += m[l/2][j];
    }

    for (i=0; i < l; i++){
        somaColuna += m[i][c/2];
    }
    
    soma = somaLinha + somaColuna;

    printf("%d", soma);
}


int main (){
    int linhas;
    int colunas;

    scanf("%d %d", &linhas, &colunas);

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

    somaLinhaMatrizMeio(linhas,colunas,matriz);
}