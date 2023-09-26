#include <stdio.h>
#include <math.h>
int calcular_aposta(int largura, int altura, int numInicial, int bandeira[altura][largura], char cor){
    int i;
    int j;
    int sum = 0;

    for (i=0; i<altura;i++){
        printf("\n");
        for (j=0;j<largura;j++){
            if(j < largura/3){
                bandeira[i][j] = numInicial + 1;
                
                if (cor == 'G'){
                    sum += bandeira[i][j];
                }
            }
            else if(j >= largura/3 && j < ((largura/3) + (largura/3))){
                bandeira[i][j] = numInicial + 2;
                if (cor == 'Y'){
                    sum += bandeira[i][j];
                }
            }
            else if(j >= ((largura/3) + (largura/3))){
                bandeira[i][j] = numInicial + 3;
                if (cor == 'R'){
                    sum += bandeira[i][j];
                }
            }
            printf("%d", bandeira[i][j]);
        }
    }
    printf("\n");
    return sum;
    
}

int main (){
    int largura;
    int numInicial;
    char cor;
    int altura;

    scanf("%d %d %c", &largura, &numInicial, &cor);
    
    if (largura % 2 == 0){
        altura = 2 + ceil(largura / 2)-1;
    }
    else{
        altura = 2 + ceil(largura / 2);
    }
    
    int bandeira[altura][largura];

    int somaTotal = (calcular_aposta(largura, altura, numInicial, bandeira, cor));

    printf("%d", somaTotal);
}