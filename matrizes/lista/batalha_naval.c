#include <stdio.h>


int main (){
    int i;
    int j;
    int pos1;
    int pos2;
    int pos3;
    int pos4;
    int pos5;
    int pos6;
    int pos7;
    int pos8;
    
    //Cria o tabuleiro
    int tabuleiro[10][10];
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j] = '~';
        }
    }

    //Posiciona os barcos
    for(i=0;i<4;i++){

        //Canoa
        if (i==0){
            scanf("%d %d", &pos1, &pos2);
            tabuleiro[pos1][pos2] = '*';
        }
        
        //Barco
        else if (i==1){
            scanf("%d %d %d %d", &pos1, &pos2, &pos3, &pos4);
            if (pos3 > pos1){
                tabuleiro[pos1][pos2] = '^';
                tabuleiro[pos3][pos4] = 'v';
            }
            else{
                tabuleiro[pos1][pos2] = '<';
                tabuleiro[pos3][pos4] = '>';
            }
        }
        
        //Fragata
        else if (i==2){
            scanf("%d %d %d %d %d %d", &pos1, &pos2, &pos3, &pos4, &pos5, &pos6);
            if (pos3 > pos1){
                tabuleiro[pos1][pos2] = '^';
                tabuleiro[pos3][pos4] = '|';
                tabuleiro[pos5][pos6] = 'v';
            }
            else{
                tabuleiro[pos1][pos2] = '<';
                tabuleiro[pos3][pos4] = '=';
                tabuleiro[pos5][pos6] = '>';
            }
        }
        
        //Destroier
        else{
            scanf("%d %d %d %d %d %d %d %d", &pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7, &pos8);
            if (pos3 > pos1){
                tabuleiro[pos1][pos2] = '^';
                tabuleiro[pos3][pos4] = '|';
                tabuleiro[pos5][pos6] = '|';
                tabuleiro[pos7][pos8] = 'v';
            }
            else{
                tabuleiro[pos1][pos2] = '<';
                tabuleiro[pos3][pos4] = '=';
                tabuleiro[pos5][pos6] = '=';
                tabuleiro[pos7][pos8] = '>';
            }
        }

    }

    //Imprime o tabuleiro
    for(i=0;i<10;i++){
        printf("\n");
        for(j=0;j<10;j++){
            printf("%c", tabuleiro[i][j]);
        }
    }
        
}