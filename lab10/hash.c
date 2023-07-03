#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"


p_hash cria_hash(){ // Funcao que alloca meu hash
    p_hash hash;
    hash = calloc(1, sizeof(struct hash));
    for (int i=0; i<MAX; i++){
        hash->vetor[i] = calloc(1, sizeof(struct caso));
    }
    return hash;
}

int hash(int id) {// Funcao hash, que retorna o index esperado do caso
    int index;
    index = id%MAX;
    return index;
}

void inserir(p_hash lista_hash){// Funcao que insere um caso no meu hash
    int id, tempo, index;
    char nome[50];
    scanf("%d %s %d ", &id, nome, &tempo);
    index = hash(id); 

    while (lista_hash ->vetor[index]->id != 0){
        if (index == MAX-1){
            index = 0;
        }else{
            index++;
        }
    }
    lista_hash->vetor[index]->id = id;
    strcpy(lista_hash->vetor[index]->nome, nome);
    lista_hash ->vetor[index]->tempo = tempo;
    printf("PROCESSO %d INSERIDO!\n", id);
}

void remover(p_hash lista_hash){// Funcao que remove um item do meu hash
    int id, index;
    scanf("%d ", &id);
    index = hash(id);
    while(lista_hash->vetor[index]->id != id){
        if(index == MAX-1){
            index = 0;
        }else{
            index++;
        }
    }
    lista_hash->vetor[index]->id = 1; //DUMMY VALUE
    printf("PROCESSO %d REMOVIDO!\n", id);
}

void consulta_nome(p_hash lista_hash){ // Funcao que consulta nome
    int index, id, count = 0;
    scanf("%d ", &id);
    index = hash(id);

    while(lista_hash->vetor[index]->id != 0 && count<MAX){/* count deve ser <MAX,
    caso contrario, se a lista esteja cheia e o caso nao existir, ocorrera um looping */
        if (lista_hash->vetor[index]->id != id){
            if (index == MAX-1){
                index = 0;
            } else{
                index ++;
            }
            count++;
        } else{
            printf("PROCESSO %d: %s\n", id, lista_hash->vetor[index]->nome);
            return;
        }
    }
    printf("PROCESSO %d NAO ENCONTRADO!\n", id);
}

void consulta_tempo(p_hash lista_hash){// Funcao que consulta o tempo de um caso
    int index, id;
    scanf("%d ", &id);
    index = hash(id);
    while(lista_hash->vetor[index]->id != id){
        if (index == MAX-1){
            index=0;
        } else{
            index ++;
        }
    }
    printf("TEMPO DO PROCESSO %d: %d DIAS.\n", id, lista_hash->vetor[index]->tempo);
}

void limpa_hash(p_hash lista_hash){// Funcao que da free em tudo que foi alocado
    for(int i=0; i<MAX; i++){
            free(lista_hash->vetor[i]);
    }
    free(lista_hash);
}
