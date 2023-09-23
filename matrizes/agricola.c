#include <stdio.h>

int main() {
    int linhas;
    int colunas;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];
    int i;
    int j;
    int entrada;
    int ferteis = 0;
    int irrigados = 0;

    // Preenche a matriz e contabiliza quantos campos férteis ela possui
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &entrada);
            matriz[i][j] = entrada;
            if (entrada == 1) {
                ferteis++;
            }
        }
    }

    // Verifica os 4 espaços adjacentes de cada campo fértil
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] == 1) {
                if (matriz[i-1][j] == 2){
                    matriz[i][j] == 3;
                    irrigados++;
                }
                else if(matriz[i][j+1] == 2){
                    matriz[i][j] == 3;
                    irrigados++;
                }
                else if(matriz[i+1][j] == 2){
                    matriz[i][j] == 3;
                    irrigados++;
                }
                else if(matriz[i][j-1] == 2){
                    matriz[i][j] == 3;
                    irrigados++;
                }
                else{}
            }
        }
    }

    int naoIrrigados = ferteis - irrigados;

    printf("%d %d", irrigados, naoIrrigados);
    return 0;
}
