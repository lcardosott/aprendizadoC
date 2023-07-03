#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"

int main(){
    p_no cabeca;
    cabeca = malloc(sizeof(struct no));
    cria_no(cabeca);
    
    p_mapa mapa;
    mapa = malloc(sizeof(struct mapa_jogo));
    cria_matriz(mapa);

    le_fruta(mapa);
    le_cobra(cabeca, mapa);
    imprime_mapa(mapa);

    int checker = 1, win_checker;
    char comando;

    while(checker){
        if (mapa->fruta=='N'){
            zera_mapa(mapa);
            le_fruta(mapa);
            atualiza_mapa(mapa, cabeca);
            imprime_mapa(mapa);
        }

        scanf(" %c", &comando);
        switch (comando){
        case 's':
            checker = atualiza_cobra(cabeca, mapa, 0, 1);
            break;
        
        case 'w':
            checker = atualiza_cobra(cabeca, mapa, 0, -1);
            break;

        case 'a':
            checker = atualiza_cobra(cabeca, mapa, -1, 0);
            break;

        case 'd':
            checker = atualiza_cobra(cabeca, mapa, 1, 0);
            break;
        }
        if(checker== 0){
            imprime_mapa(mapa);
            printf("GAME OVER");
            break;
        }
        zera_mapa(mapa);
        if (mapa->fruta =='S'){
            marca_fruta(mapa);
        }
        atualiza_mapa(mapa, cabeca);
        win_checker = imprime_mapa(mapa);//A funcao imprime mapa, além de imprimir, conta as ocorrencias de cobra e a devolve
        
        if ((win_checker == (mapa->M)*(mapa->N))){//caso tenha a quantidade de ocorrencias seja igual a quatindade de espacos, o jogador ganhou
            printf("YOU WIN");
            checker = 0;
        }
    }
    destruir_lista(cabeca);
    limpa_matriz(mapa);
    return 0;
}



















//Hashing pelo metodo da divisao (valor )
//Duvidas em relaao a alocacao
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 83 //Primeiro primo 


typedef struct caso *p_caso;

struct caso {
    int id;
    char nome[50];
    int tempo;
};

typedef struct hash *p_hash;

struct hash {
    p_caso vetor[MAX];
};


int hash(int id) {// Funcao hash, que retorna o index esperado do caso
    int index;
    index = id/MAX;
    return index;
}

void inserir(p_hash lista_hash){
    int id, tempo, index;
    char nome[50];
    scanf("%d %s %d ", &id, nome, &tempo);
    index = hash(id); 

    while (lista_hash ->vetor[index] != NULL){
        if (index == MAX){
            index = 0;
        }else{
            index++;
        }
    }
    lista_hash->vetor[index] = calloc(1, sizeof(struct caso));
    lista_hash->vetor[index]->id = id;
    strcpy(lista_hash->vetor[index]->nome, nome);
    lista_hash ->vetor[index]->tempo = tempo;
    printf("PROCESSO %d INSERIDO!", id);
}

void remover(p_hash lista_hash){
    int id, index;
    scanf("%d ", &id);
    index = hash(id);
    while(lista_hash->vetor[index]->id != id){
        if(index = MAX){
            index = 0;
        }else{
            index++;
        }
    }
    lista_hash->vetor[index]->id = 1;
    printf("PROCESSO %d REMOVIDO", id);
}

void consulta_nome(p_hash lista_hash){
    int index, id;
    scanf("%d ", &id);
    index = hash(id);
    while(lista_hash->vetor[index]->id != id && lista_hash->vetor[index]->id != 0){
        if (index == MAX){
            index++;
        } else{
            index = 0;
        }
    }
    if (lista_hash->vetor[index]->id == id){
        printf("PROCESSO %d: %s", id, lista_hash->vetor[index]->nome);
    } else{
        printf("PROCESSO %d NÃO ENCONTRADO", id);
    }
}

void consulta_tempo(p_hash lista_hash){
    int index, id;
    scanf("%d ", &id);
    index = hash(id);
    while(lista_hash->vetor[index]->id != id){
        if (index == MAX){
            index++;
        } else{
            index = 0;
        }
    }
    printf("TEMPO DO PROCESSO %d: %d", id, lista_hash->vetor[index]->tempo);
}

void limpa_hash(p_hash lista_hash){
    for(int i=0; i<MAX; i++){
        if(lista_hash->vetor[i]!=NULL){
            free(lista_hash->vetor[i]);
        }
    }
    free(lista_hash);
}

int main(){
    p_hash lista_hash;
    lista_hash = calloc(1, sizeof(struct hash));
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
    return 0;
}
