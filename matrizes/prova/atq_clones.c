#include <stdio.h>

int main (){
    int linhas;
    int colunas;
    int coordJediY;
    int coordJediX;
    int locaisBomba;
    int resgate = 1;
    int contadorLocais = 0;

    scanf("%d %d %d %d", &linhas, &colunas, &coordJediY, &coordJediX);

    int matrizOriginal[linhas][colunas];
    char matrizBombas[linhas][colunas]; //Vai ser utilizada para checar onde tem bombas de forma mais fácil
    int i;
    int j;
    int entrada;

    for (i=0; i < linhas; i++){
        for (j=0; j < colunas; j++){
            scanf("%d", &entrada);
            matrizOriginal[i][j] = entrada;
            matrizBombas[i][j] = '~';
        }
    }

    for (i=0; i < linhas; i++){
        for (j=0; j < colunas; j++){
            //Verifica todos os 8 espaços em volta do local
            if (matrizOriginal[i-1][j] < matrizOriginal[i][j] && matrizOriginal[i-1][j+1] < matrizOriginal[i][j]
                && matrizOriginal[i][j+1] < matrizOriginal[i][j] && matrizOriginal[i+1][j+1] < matrizOriginal[i][j]
                && matrizOriginal[i+1][j] < matrizOriginal[i][j] && matrizOriginal[i+1][j-1] < matrizOriginal[i][j]
                && matrizOriginal[i][j-1] < matrizOriginal[i][j] && matrizOriginal[i-1][j-1] < matrizOriginal[i][j]){
                matrizBombas[i][j] = '*';
            }

        }
    }

    for (i=0; i < linhas; i++){
        for (j=0; j < colunas; j++){
            if (matrizBombas[i][j] == '*'){
                contadorLocais++;
                printf("Local %d: %d %d\n", contadorLocais, i, j);
                if(i == coordJediY && j == coordJediX){
                    resgate = 0;
                }
            }
        }
    
    }
    if (resgate){
        printf("Ao resgate!");
    }
    else{
        printf("Descanse na força...");
    }
}
