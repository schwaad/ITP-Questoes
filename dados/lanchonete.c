#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int codigo;
} Produto;

int main() {
    int quantidadeProdutos;
    int quantidadePedido;
    int i;
    int fazendoPedido = 1;
    float precoTotal = 0;

    scanf("%d", &quantidadeProdutos);

    Produto produto[100];
    Produto produtos[quantidadeProdutos];

    for (i = 0; i < quantidadeProdutos; i++) {
        scanf("%d", &produto[i].codigo);
        scanf(" %[^\n]", produto[i].nome);
        scanf("%f", &produto[i].preco);
        produtos[i] = produto[i];
    }

    while (fazendoPedido != 0) {
        scanf("%d %d", &fazendoPedido, &quantidadePedido);
        if (fazendoPedido == 0) {
            break;
        }
        for (i = 0; i < quantidadeProdutos; i++) {
            if (fazendoPedido == produtos[i].codigo) {
                precoTotal += produtos[i].preco * quantidadePedido;
            }
        }
    }

    printf("%.2f\n", precoTotal);
}
