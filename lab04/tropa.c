#include <stdio.h>
#include <stdlib.h>
#include "tropa.h"

typedef struct{
    int nome;
    int* ponteiro;
    int i;
    int j;
    int qtdd_elementos;
    int max;
} tropa;

int soma(int l, int m, tropa *estrutura){//'soma' tem a funcao de somar um determinado segmento de uma lista
    int soma=0;
    for (int i=l; i<m+1; i++){
        soma = soma+ estrutura->ponteiro[i];
    }
    return soma;
}

void subtropa(tropa *estrutura, int n){//'subtropa' tem a funcao de calcular a subtropa de um 'pelotao'
    int valor;
    estrutura->max=-101; //valor setado para que a primeira subtropa seja maior que -101
    for (int i=0; i<n; i++){ // calcula a soma de todos os possiveis segmentos
        for (int j=i; j<n; j++){
            valor = soma(i, j, estrutura);
            if(valor>estrutura->max){ //se a soma for a maior encontrada, um novo conjunto e setado
                estrutura->max = valor;
                estrutura->i = i;
                estrutura->j = j;
            }
        }
    }
}

void get_list(int *ponteiro, int n){//'get_list' tem a funcao de receber uma lista
    for (int i=0; i<n; i++){
        scanf("%d", &ponteiro[i]);
    }
}

void imprime_forte(tropa *estrutura, int *media, int *soma){//'imprime_forte' tem a funcao de imprimir uma subtropaforte
    printf("Sub-tropa Forte %d: ", estrutura->nome+1);
    estrutura->qtdd_elementos = (estrutura->j-estrutura->i) +1;
    for (int i= estrutura->i; i <estrutura->j+1; i++){
        *soma = *soma+ estrutura->ponteiro[i];//linha 47 e 48 tem o objetivo de recolher dados para possibilitar o calulo da media futuramente

        *media = *media+1;

        printf("%d ", estrutura->ponteiro[i]);
    }
    printf("\n");
}

void normaliza(int *lista,int *lista_copia, int *media, int aux){//'normaliza' tem a funcao de normalizar uma lista
    for (int i=0; i<aux; i++){
        lista_copia[i] = lista[i]-*media;
    }
    
}

int reparticao_lista(tropa *estrutura, int aux, int *lista){//'reparticao_lista' tem a funcao de unir todas as subtropas_forte em uma unica lista
    for (int i=estrutura->i; i<(estrutura->j+1); i++){
        lista[aux] = estrutura->ponteiro[i];
        aux = aux +1;
    }
    return aux;
}

void subtropa_elite(tropa **estrutura, int n, int *media, int *soma, int*lista, int q){//'subtropa_elite' tem a funcao criar a subtropa de elite
    int aux = 0, *lista_copia;
    *media = *soma/(*media);
    estrutura[q]=malloc(sizeof(tropa));
    for (int i=0; i<n; i++){
        aux = reparticao_lista(estrutura[i], aux, lista);
    }

    lista_copia = malloc(aux *sizeof(int));
    normaliza(lista, lista_copia, media, aux);

    estrutura[q]->nome = q;
    estrutura[q]->ponteiro = lista_copia;
    subtropa(estrutura[q], aux);
    estrutura[q]->ponteiro = lista;

    free(lista_copia);
    
}

void imprime_elite(tropa *lista_struct){//'imprime_elite' tem a funcao de imprimir a lista elite
    printf("Sub-tropa Elite: ");
        for (int i= lista_struct->i; i <lista_struct->j+1; i++){
            printf("%d ", lista_struct->ponteiro[i]);
        }
        printf("\n");
}