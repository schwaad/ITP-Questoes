#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol){
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    if (mat == NULL){
        return NULL;
    }
    mat->nlin = nlin;
    mat->ncol = ncol;
    mat->mat = (int**)malloc(nlin * sizeof(int*));
    if(mat->mat == NULL){
        free(mat);
        return NULL;
    }

    for(int i = 0; i < nlin; i++){
        mat->mat[i] = (int*)malloc(ncol * sizeof(int));
        if (mat->mat == NULL){
           for (int j = 0; j < i; j++) {
                free(mat->mat[j]);
            }
            free(mat->mat);
            free(mat);
            return NULL;
        }
    }

    return mat;
}
void readMatrix(Matrix *m){
    for(int i = 0; i < m->nlin; i++){
        for(int j = 0; j < m->ncol; j++){
            scanf("%d", &m->mat[i][j]);
        }
    }
}

void printMatrix(Matrix *m){
    for(int i = 0; i < m->nlin; i++){
        for(int j = 0; j < m->ncol; j++){
            printf("%d ", m->mat[i][j]);
        }
        printf("\n");
    }
}

void destroyMatrix(Matrix **m){
    if (*m) {
        for (int i = 0; i < (*m)->nlin; i++){
            free((*m)->mat[i]);
        }
        free((*m)->mat);
        free(*m);
        *m = NULL;
    }
}

int main() {
    int lin, col;
    Matrix* mat;

    scanf("%i %i", &lin, &col);
    mat = createMatrix(lin, col);
    readMatrix(mat);
    printMatrix(mat);
    destroyMatrix(&mat);

    if (mat == NULL) {
        printf("OK\n");
    }
    
    return 0;
}
