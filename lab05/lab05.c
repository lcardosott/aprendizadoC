#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultron.h"

int main(){
    matriz matriz;
    int quantidade_operacoes;
    char operacao[4], posicao;
    matriz = malloc(sizeof(struct dados));
    cria_matriz(matriz);
    scanf("%d",&quantidade_operacoes);
    for (int i=0; i<quantidade_operacoes; i++){

        tam_check(matriz);
        scanf("%s ", operacao);
        if (strcmp(operacao, "IN") == 0){
            scanf("%c ", &posicao);
            if (posicao == 'L'){
                IN_L(matriz);
            }else{
                IN_C(matriz);
            }
        }else{
            scanf("%c", &posicao);
            if (posicao=='L'){
                OUT_L(matriz);
            }else{
                OUT_C(matriz);
            }
        }
    imprime_matriz(matriz);
    }
    limpa_matriz(matriz);
    printf("COMBINACAO MATRICIAL FINALIZADA!");
    return 0;
}

