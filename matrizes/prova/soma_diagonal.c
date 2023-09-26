#include <stdio.h>

int main (){
    int ordem;

    scanf("%d", &ordem);

    int matriz[ordem][ordem];
    int i;
    int j;
    int entrada;
    int somaDiagonal = 0;

    for (i=0; i < ordem; i++){
        for (j=0; j < ordem; j++){
            scanf("%d", &entrada);
            
            matriz[i][j] = entrada;
            
            if (i == j){
                somaDiagonal += entrada;
            }
        }
    }

    printf("%d", somaDiagonal);
}