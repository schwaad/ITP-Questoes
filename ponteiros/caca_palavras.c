#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimePalavra(char *c, int salto, int tam) {
    if (c == NULL) {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i = 0; i < tam; i++) {
        printf("%c", *c);
        c += salto;
    }
    printf(", salto:%d\n", salto);
}

char* encontraPalavra(char *grade, int n, int m, char *palavra, int *salto) {
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    char *min_ptr = NULL;

    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
            for (int dir = 0; dir < 8; ++dir){
                int len, xx, yy;
                char *ptr = grade + x * m + y;

                for (len = 0, xx = x, yy = y; palavra[len] != '\0'; ++len, xx += dx[dir], yy += dy[dir]){
                    char *cur_ptr = grade + xx * m + yy;
                    
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m || tolower(*cur_ptr) != tolower(palavra[len]))
                        break;
                }
                if (palavra[len] == '\0')
                    if (min_ptr == NULL || ptr < min_ptr){
                        min_ptr = ptr;
                        *salto = dx[dir] * m + dy[dir];
                    }
            }

    return min_ptr;
}

int main(){
    int n, m, q;

    scanf("%d", &q);

    char palavras[5][20];

    for (int i = 0; i < q; ++i)
        scanf("%s", palavras[i]);

    n = 10; m = 10;
    char grade[10][10];

    for (int i = 0; i < n; ++i)
        scanf("%s", grade[i]);

    for (int i = 0; i < q; ++i){
        int salto;
        char *ptr = encontraPalavra((char *)grade, n, m, palavras[i], &salto);
        imprimePalavra(ptr, salto, strlen(palavras[i]));
    }
    
    return 0;
}