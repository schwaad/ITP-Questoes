#include <stdio.h>

int main (){
    int linhas;
    int colunas;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];
    int transposta[colunas][linhas];
    int i;
    int j;
    int entrada;
    int aux = 1;

    for (i=0; i < linhas; i++){
        for (j=0; j < colunas; j++){
            scanf("%d", &entrada);
            matriz[i][j] = entrada;
            transposta[j][i] = entrada;
        }
    }

    for (i=0; i < linhas; i++){
        for (j=0; j < colunas; j++){
            if (matriz[i][j] != transposta[i][j]){
                aux = 0;
                break;
            }
        }
    }

    if (aux){
        printf("Matriz Simétrica");
    }
    else {
        printf("Matriz não Simétrica");
    }


}