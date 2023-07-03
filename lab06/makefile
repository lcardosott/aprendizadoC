#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
//***************FUNCOES AUXILIARES*************
void imprime_atualizao_mapa(char *nome_cidade){
    printf("ARVORE: MAPA\nCIDADE: %s\nINSERIDO COM SUCESSO!\n####\n",nome_cidade);
}

void  imprime_atualizao_visita(char* nome_cidade, int *data){
    printf("ARVORE: VISITA\nDATA: %d\nCIDADE./configure: %s\nINSERIDO COM SUCESSO!\n####\n", *data, nome_cidade);
}

void imprime_exclusao(int visitas, char* nome_remocao){
    printf("CIDADE: %s\nQUANTIDADE DE VISITAS RESTANTES: %d\n####\n", nome_remocao , visitas);
}

void limpa_mapa (p_mapa raiz){
    if (raiz == NULL){
        return;
    }
    limpa_mapa(raiz->esq);
    limpa_mapa(raiz->dir);
    free(raiz);
}

void limpa_visita(p_visita raiz){
    if (raiz == NULL){
        return;
    }
    limpa_visita(raiz->esq);
    limpa_visita(raiz->dir);
    free(raiz);
}
//***************FUNCOES ESPECIFICAS*************
p_mapa insere_visita_mapa(p_mapa raiz, char* nome_cidade){
    p_mapa novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(struct mapa));
        novo->nome[0] = '\0';
        novo->esq = novo->dir = NULL;
        novo-> visitas = 1;
        strcpy(novo ->nome, nome_cidade);//// SE LIGAAAA

        imprime_atualizao_mapa(nome_cidade);
        return novo;
    } 
    if (strcmp(raiz->nome,nome_cidade)== 0){
        raiz->visitas ++;
        return raiz;
    }
    if ((strcmp(nome_cidade, raiz ->nome)>0)){
        raiz ->esq = insere_visita_mapa(raiz ->esq , nome_cidade);
    }else{
        raiz ->dir = insere_visita_mapa(raiz ->dir , nome_cidade);
    } return raiz;
}

p_visita insere_visita_visita(p_visita raiz, char* nome_cidade, int *data, int *pista){
    p_visita novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(struct visita));
        novo ->esq = novo ->dir = NULL;
        novo->nome[0] = '\0';
        strcpy(novo ->nome, nome_cidade);
        novo->data = *data;
        novo-> pista = *pista;
        imprime_atualizao_visita(nome_cidade, data);
        return novo;
    } 
    if (*data < raiz ->data){
        raiz ->esq = insere_visita_visita(raiz ->esq , nome_cidade, data, pista);
    }else{
        raiz ->dir = insere_visita_visita(raiz ->dir , nome_cidade, data, pista);
    } 
    return raiz;
}

p_visita remover_visita(int* data, p_visita raiz, char* nome_remocao){
    if (*data < raiz ->data){
        raiz ->esq = remover_visita(data, raiz ->esq, nome_remocao);
    }
    else if (*data > raiz ->data){
        raiz ->dir = remover_visita(data, raiz ->dir, nome_remocao);
    }
    else{
        strcpy(nome_remocao, raiz -> nome);
        if (raiz->esq ==NULL && raiz->dir ==NULL) {//caso esteja retirando uma folha
            raiz = NULL;
        }
        else if ((raiz->esq ==NULL && raiz->dir !=NULL)){//caso esteja retirando folha com no direito
            raiz->data = raiz->dir->data;
            raiz->pista = raiz->dir->pista;
            raiz->dir = raiz->dir->dir;
            raiz->esq = raiz->dir->esq;
            free()
            strcpy(raiz->nome, raiz->direita->nome);

        }
        else if ((raiz->esq !=NULL && raiz->dir ==NULL)){//caso esteja retirando folha com no esquerdo
            raiz = raiz->esq;
        }
        else{//caso esteja retirando folha com 2 nos
            p_visita min = raiz ->dir;

            while (min ->esq != NULL) {
                min = min ->esq;
            }

            raiz ->data = min ->data;
            raiz-> pista = min->pista;
            strcpy(raiz->nome, min->nome);
            free(min);
        }
    }
    return raiz;
}

p_mapa remover_mapa(int* data, p_mapa raiz, char* nome_remocao){
    if (raiz == NULL){
        return NULL;
    }
    if (strcmp(nome_remocao, raiz->nome)<0){
        raiz ->esq = remover_mapa(data, raiz ->esq, nome_remocao);
    }
    else if (strcmp(nome_remocao, raiz->nome)<0){
        raiz ->dir = remover_mapa(data, raiz ->dir, nome_remocao);
    }
    else{
        raiz->visitas --;
        imprime_exclusao(raiz->visitas, nome_remocao);
        if (raiz->visitas == 0){
            if (raiz->esq ==NULL && raiz->dir ==NULL) {//caso esteja retirando uma folha
                raiz = NULL;
            }
            else if ((raiz->esq ==NULL && raiz->dir !=NULL)){//caso esteja retirando folha com no direito
                raiz =raiz->dir;
            }
            else if ((raiz->esq !=NULL && raiz->dir ==NULL)){//caso esteja retirando folha com no esquerdo
                raiz = raiz->esq;
            }
            else{//caso esteja retirando folha com 2 nos
                p_mapa min = raiz ->dir;

                while (min ->esq != NULL) {
                    min = min ->esq;
                }

                raiz->visitas = min ->visitas;
                strcpy(raiz->nome, min->nome);
                free(min);
            }
        }
    }
    return raiz;
}

void busca_recursiva_visita(p_visita raiz, int* data_inicio, int*data_fim){
    if (raiz->esq != NULL){
        busca_recursiva_visita(raiz->esq, data_inicio, data_fim);
    }else if(raiz->dir != NULL){
        if(raiz->data >*data_inicio && raiz->data<*data_fim){
            printf("DATA: %d\nCIDADE: %s\n####\n", raiz->data, raiz->nome);
        }
        busca_recursiva_visita(raiz->dir, data_inicio, data_fim);
        return;
    }    
    if(raiz->data >*data_inicio && raiz->data<*data_fim){
        printf("DATA: %d\nCIDADE: %s\n####\n", raiz->data, raiz->nome);
    }
    return;
}

void busca_recursiva_pista(p_visita raiz, int* data_inicio, int*data_fim){
    if (raiz->dir != NULL){
        busca_recursiva_pista(raiz->dir, data_inicio, data_fim);
    }else if(raiz->esq != NULL){
        if (raiz->data >*data_inicio && raiz->data<*data_fim && raiz->pista >0){
            printf("DATA: %d\nCIDADE: %s\n####\n", raiz->data, raiz->nome);
        }
        busca_recursiva_pista(raiz->esq, data_inicio, data_fim);
        return;
    }
    if(raiz->data >*data_inicio && raiz->data<*data_fim && raiz->pista >0){
        printf("DATA: %d\nCIDADE: %s\n####\n", raiz->data, raiz->nome);
        return;
    }
}
//**************FUNCOES GENERICAS****************
void relatorio_data(p_visita raiz){
    int *data_inicio = malloc(sizeof(int));
    int *data_fim = malloc(sizeof(int));
    scanf("%d %d", data_inicio, data_fim);
    printf("--VISITAS--\n");
    busca_recursiva_visita(raiz, data_inicio, data_fim);
    free(data_inicio);
    free(data_fim);
}

void relatorio_pistas(p_visita raiz){
    int *data_inicio = malloc(sizeof(int));
    int *data_fim = malloc(sizeof(int));
    scanf("%d %d", data_inicio, data_fim);
    printf("--PISTAS--\n");
    busca_recursiva_pista(raiz, data_inicio, data_fim);
    free(data_inicio);
    free(data_fim);  
}
