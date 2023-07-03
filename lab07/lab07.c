#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "fila.h"
//#include "pilha.h"
#define max  500


typedef struct fila *p_fila;

struct fila {
    char *enfilerados;
    int ini, fim ,tamanho;
};



typedef struct pilha *p_pilha;

struct pilha {
    p_pilha proximo;
    char *caracteres;
    int quantidade_utilizada;
};






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




















int retira_enter(char insercao_atual[50], int *quantidade, int *qtdd_caracteres){
    int contador =0;
    while(insercao_atual[contador] != '\n'){
        contador++;
    }
    *qtdd_caracteres = contador;
    insercao_atual[*qtdd_caracteres] = '\0';
    char palavra[max];
    int aux = 0;
    for (int i = 0; insercao_atual[i] != '\0' && insercao_atual[i] != ' '; i++){
        palavra[i] = insercao_atual[i];
        aux ++;
    }
    palavra[aux] = '\0';
    if (strcmp(palavra, "EXEC") ==0){
        char *numero =calloc(1, sizeof(char) *3);
        for (int i= 0; insercao_atual[i+aux]!= '\0';i++){
            numero[i] = insercao_atual[aux+i];
        }
        *quantidade = atoi(numero);
        free(numero);
        return 1;

    }else if(strcmp(palavra, "DEL") ==0){
        char *numero =calloc(1, sizeof(char) *3);
        for (int i= 0; insercao_atual[i+aux] != '\0';i++){
            numero[i] = insercao_atual[aux+i];
        }
        *quantidade = atoi(numero);
        free(numero);
        return -1;

    }else if(strcmp(palavra, "EXIT") ==0){
        return 0;

    }else{
        int aux_2 = 0;
        for (int i = 0; insercao_atual[i] != '\0'; i++ ){
            aux_2 ++;
        }
        *qtdd_caracteres = aux_2;
        return 10; 
    }
}

void imprime_resultado(p_pilha apontador, p_fila fila, int *qtdd_pilhas){
//Imprime fila
    char *palavra;
    palavra = malloc(sizeof(char)*max);
    for (int i = 0; i < max; i++){
        palavra[i] = '\0';
    }
    for (int i=0; i<fila->tamanho; i++){
        if (fila->ini+i <500){
            palavra[i] = fila->enfilerados[fila->ini+i];
        }else{
            palavra[i] = fila->enfilerados[fila->ini+i-500];
        }
    } printf("FILA ATUAL: %s\n", palavra);
    free(palavra);

//Imprime pilha
    printf("PILHA ATUAL: ");
    int *aux;
    aux = malloc(sizeof(int));
    for (int i=*qtdd_pilhas; i>0; i--){
        *aux=1;
        imprime_pilha(i, apontador, aux);
    }
    printf("\n####\n");
}

void EXEC(int *qtdd_caracteres, int *quantidade, p_fila fila, p_pilha apontador, int* qtdd_pilhas){
    for (int i=0; i<*quantidade; i++){
        if (apontador->quantidade_utilizada==50){//ficar ligado com esses numeros
            p_pilha novo_topo;
            qtdd_pilhas ++;
            novo_topo = malloc(sizeof(struct pilha));
            inicializa_pilha(novo_topo);
            novo_topo->proximo = apontador;
            apontador = novo_topo;
        }
        apontador->caracteres[apontador->quantidade_utilizada]= fila->enfilerados[fila->ini];
        apontador->quantidade_utilizada++;
        fila->ini++;
    }
}

int main(){
    int ligado = 1, *qtdd_caracteres, *qtdd_pilhas, funcao, *quantidade;
    char insercao_atual[max];

    qtdd_caracteres = calloc(1, sizeof(int));
    quantidade = calloc(1, sizeof(int));
    qtdd_pilhas = calloc(1, sizeof(int));
    *qtdd_pilhas =1;

    p_pilha apontador, pilha;
    pilha = inicializa_pilha();

    apontador = calloc(1, sizeof(p_pilha));
    apontador = pilha;

    p_fila fila;
    fila = inicializa_fila();


    while (ligado){
        fgets(insercao_atual, max, stdin);
        funcao = retira_enter(insercao_atual, quantidade, qtdd_caracteres);

        switch (funcao){
            case 1:
                EXEC(qtdd_caracteres, quantidade, fila, apontador, qtdd_pilhas);
                break;

            case -1:
                DEL(quantidade, apontador);
                break;

            case 0:
                ligado = 0;

            default:
                adiciona_fila(fila, qtdd_caracteres, insercao_atual);
                break;
        }
        if (ligado){
            imprime_resultado(apontador, fila, qtdd_pilhas);
        }
    }
    free(qtdd_caracteres); free(quantidade);
    limpa_fila(fila);

    int *aux_limpeza;
    aux_limpeza = calloc(1, sizeof(int));

    for (int i=*qtdd_pilhas; i>0; i--){
        *aux_limpeza = 1;
        limpa_pilha(i, apontador, aux_limpeza);
    }
    free(aux_limpeza);
    free(qtdd_pilhas);
    return 0;       
}

