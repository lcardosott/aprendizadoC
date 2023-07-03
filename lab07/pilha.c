#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define max  500

p_pilha inicializa_pilha(){
    p_pilha pilha;
    pilha = calloc(1, sizeof(struct pilha));
    pilha->caracteres = calloc(1, sizeof(char)*51);
    return pilha;
}

void DEL(int *quantidade, p_pilha apontador){
    if ((apontador->quantidade_utilizada) - *quantidade>0){
        apontador->caracteres[(apontador->quantidade_utilizada) - *quantidade] = '\0';
        apontador->quantidade_utilizada = apontador->quantidade_utilizada -*quantidade;
    }else{
        int modulo = *quantidade-(apontador->quantidade_utilizada);
        apontador->proximo->caracteres[50 - modulo] = '\0';
        apontador = apontador->proximo;
        apontador->quantidade_utilizada = 50 - modulo;
    }
}

void imprime_pilha(int pilha_id, p_pilha apontador, int* aux){
    if (pilha_id == *aux){
        printf("%s",apontador->caracteres);
        return;
    } 
    *aux= *aux+1;
    return imprime_pilha(pilha_id,apontador->proximo,aux);
}

void limpa_pilha(int pilha_id, p_pilha apontador, int *aux){
    if (pilha_id == *aux){
        free(apontador->caracteres);
        free(apontador);
        return;
    }
    *aux= *aux+1;
    return limpa_pilha(pilha_id, apontador->proximo, aux);
}