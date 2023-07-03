#include <stdio.h>
#include <stdlib.h>
#include "tropa.h"

int main(){
    int q, n, *lista_elite, *soma, *media;
    tropa **lista_struct;

    scanf("%d", &q);
    lista_struct = malloc(q*sizeof(tropa));
    soma= malloc(sizeof(int));
    media=malloc(sizeof(int));

    for(int i=0; i<q; i++ ){
        lista_struct[i] = malloc(sizeof(tropa));
        lista_struct[i]->nome = i;
        scanf("%d", &n);
        lista_struct[i]->ponteiro = malloc(n*sizeof(int));
        get_list(lista_struct[i]->ponteiro, n);
        subtropa(lista_struct[i] ,n);
        imprime_forte(lista_struct[i], media, soma);
    }
    lista_elite= malloc(*media * sizeof(int));
    subtropa_elite(lista_struct, q, media, soma, lista_elite, q);
    imprime_elite(lista_struct[q]);
    free(lista_struct);
    free(lista_elite);
    free(soma);
    free(media);

    return 0;
}