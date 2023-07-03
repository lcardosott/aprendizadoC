//Hashing pelo metodo da divisao (valor )
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

int main(){
    p_hash lista_hash;
    lista_hash = cria_hash();

    int N;
    char funcao;
    scanf("%d ", &N);
    for (int i=0; i<N; i++){
        scanf("%c", &funcao);
        switch (funcao){
            case 'I':
                inserir(lista_hash);
                break;
            case 'R':
                remover(lista_hash);
                break;
            case 'C':
                consulta_nome(lista_hash);
                break;
            case 'T':
                consulta_tempo(lista_hash);
        }
    }
    limpa_hash(lista_hash);
    printf("FINALIZADO!");
    return 0;
}
