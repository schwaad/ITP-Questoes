#include <stdio.h>

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
    
    char ch;
    int x;

    scanf(" %c", &ch);

    if (ch == 'l'){
        scanf(" %d", &x);
        for (i=0;i < x;i++){
            if (matriz[0][x] < matriz[i][x]){
                matriz[0][x] = matriz[i][x];
            }
        }
        printf("%d", matriz[0][x]);
    }
    if (ch == 'c'){
        scanf(" %d", &x);
        for (i=0;i < x;i++){
            if (matriz[x][0] < matriz[x][i]){
                matriz[x][0] = matriz[x][i];
            }
        }
        printf("%d", matriz[x][0]);
    }
}
