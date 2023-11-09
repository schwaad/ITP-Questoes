#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char *nome, int idade, char sexo) {
    Pessoa novaPessoa;
    novaPessoa.nome = strdup(nome);
    novaPessoa.idade = idade;
    novaPessoa.sexo = sexo;
    return novaPessoa;
}

void inserir(Pessoa **vetor, int *tamanho) {
    char nome[100];
    int idade;
    char sexo;

    scanf(" %[^\n]s", nome);
    scanf("%d", &idade);
    scanf(" %c", &sexo);

    Pessoa novaPessoa = criar(nome, idade, sexo);

    *vetor = (Pessoa *)realloc(*vetor, (*tamanho + 1) * sizeof(Pessoa));
    if (*vetor == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }

    (*vetor)[*tamanho] = novaPessoa;
    (*tamanho)++;
}

void deletar(Pessoa **vetor, int *tamanho, char *nome, int idade, char sexo) {
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp((*vetor)[i].nome, nome) == 0 &&
            (*vetor)[i].idade == idade &&
            (*vetor)[i].sexo == sexo) {
            free((*vetor)[i].nome);
            for (int j = i; j < *tamanho - 1; j++) {
                (*vetor)[j] = (*vetor)[j + 1];
            }
            *vetor = (Pessoa *)realloc(*vetor, (*tamanho - 1) * sizeof(Pessoa));
            if (*vetor == NULL && *tamanho > 1) {
                printf("Erro de alocação\n");
                exit(1);
            }
            (*tamanho)--;
            i--;
        }
    }
}

void imprimir(Pessoa *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Idade: %d, Sexo: %c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
    }
}

int main() {
    Pessoa *vetor = NULL;
    int tamanho = 0;

    while (1) {
        char operacao;
        scanf(" %c", &operacao);

        if (operacao == 'i') {
            inserir(&vetor, &tamanho);
        } else if (operacao == 'd') {
            char nome[100];
            int idade;
            char sexo;

            scanf(" %[^\n]s", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);

            deletar(&vetor, &tamanho, nome, idade, sexo);
        } else if (operacao == 'p') {
            imprimir(vetor, tamanho);
            break;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        free(vetor[i].nome);
    }
    free(vetor);

    return 0;
}
