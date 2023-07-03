#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define max  500

p_fila inicializa_fila(){
    p_fila fila;
    fila = calloc(1, sizeof(struct fila));
    fila->enfilerados = calloc(1, 50 * sizeof(char));
    return fila;
}

void adiciona_fila(p_fila fila, int *qtdd_caracteres, char *insercao_atual){
    for (int i=0; i<*qtdd_caracteres; i++){
        if (fila->fim+i<500){
            fila->enfilerados[fila->fim+i]=insercao_atual[i];
        }else{
            fila->enfilerados[fila->fim+i-500]=insercao_atual[i];
        }
    }
    if (fila->fim + *qtdd_caracteres >500){
        fila->fim = fila->fim+*qtdd_caracteres-500;
    }else{
        fila->fim = fila->fim+*qtdd_caracteres;
    }
    fila->tamanho += *qtdd_caracteres;
}

void limpa_fila(p_fila fila){
    free(fila->enfilerados);
    free(fila);
}
