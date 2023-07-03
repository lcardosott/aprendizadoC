#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"

p_grafo inicializa_grafo(int n){// aloca a memoria necessaria para o grafo 
    p_grafo grafo = malloc(sizeof(struct grafo));
    grafo->n = n;
    grafo->adjacencia = malloc(MAX * sizeof(p_no));
    for (int i = 0; i < MAX; i++){
        grafo->adjacencia[i] = NULL;
    }return grafo;
}

p_no insere_na_lista(p_no lista , int v) {// A função insere um vertice que esta ligado a outro determinado vertice
    p_no novo = malloc(sizeof(struct no));
    novo ->v = v;
    novo ->prox = lista;
    return novo;
}

void insere_aresta(p_grafo grafo, int u, int v) {//Insere uma nova aresta na lista ligada
    grafo->adjacencia[v] = insere_na_lista(grafo->adjacencia[v], u);
    grafo->adjacencia[u] = insere_na_lista(grafo->adjacencia[u], v);
}

void busca_em_profundidade (p_grafo grafo, int *pai , int p, int v) {//auxilia a encontrar caminhos
    p_no t;
    pai[v] = p;
    for(t = grafo->adjacencia[v]; t != NULL; t = t->prox){
        if (pai[t->v] == -1){
            busca_em_profundidade (grafo, pai , v, t->v);
        }
    }
}

int* encontra_caminhos (p_grafo grafo, int s) {// encontra todos os caminhos de s para qualquer vertice
    int *pai = malloc(grafo->n * sizeof(int));

    for (int i = 0; i < grafo->n; i++){
        pai[i] = -1;
    }
    busca_em_profundidade (grafo, pai , s, s);
    return pai;
}

void conta_caminho(int v, int *pai, int* contador){// conta a distancia de um CD a um PR
    if(pai[v] != v){
        conta_caminho(pai[v], pai, contador);
    }
    *contador= *contador +1;
}

void insere_recursivamente(p_grafo grafo, int NOVO_CD, p_no PR){// insere arestas a um CD
    if (PR != NULL){
        insere_recursivamente(grafo, NOVO_CD, PR->prox );
        insere_aresta(grafo, NOVO_CD, PR->v);
    }
}

int* gera_lista(p_no lista_ligada, int* lista, int* aux){// gera uma lista (nao necessariamente ordenada), de todas as PR ligadas a um determinado CD
    lista[*aux] = lista_ligada->v;
    if (lista_ligada ->prox != NULL){
        *aux = *aux +1;
        gera_lista(lista_ligada->prox, lista, aux);
    }
    return lista;
}

void troca(int *vetor, int index1, int index2){// Troca dois valores de uma lista
    int aux;
    aux = vetor[index1];
    vetor[index1] = vetor[index2];
    vetor[index2] = aux;

}

void bubblesort_v2(int *v, int n) {// Ordena uma lista através do bubblesort
    int trocou = 1;
    for (int i = 0; i < n-1 && trocou; i++){
        trocou = 0;
        for (int j = n-1; j > i; j--){
            if (v[j] < v[j -1]) {
                troca (v, j-1, j);
                trocou = 1;
            }
        }
    }
}

void imprime_listaordenada(int* lista, int n){// Imprime uma lista de tamanho 'n'
    for(int i=0; i<n; i++){
        printf(" %d", lista[i]);
    }printf("\n");    
}

void modo_operacaoD(p_grafo grafo){// Chama todas as funcoes necessarias para realizar a operacao 'D'
    int CD, PR, dist_max, *caminhos;
    int *contador = calloc(1, sizeof(int)), *aux = calloc(1, sizeof(int)); //CD -> Centro de Distribuicao PR -> Ponto de Recebimento
    int *lista = calloc(1, 40*sizeof(int));
    scanf("%d %d %d ", &CD, &PR, &dist_max);

    caminhos = encontra_caminhos(grafo, CD);
    conta_caminho(PR, caminhos, contador);
    printf("DISTANCIA %d -> %d = %d\n", CD, PR, (*contador)-1);

    if (*contador -1  > dist_max){
        grafo->n ++;
        printf("%d ADICIONADO E CONECTADO A", (grafo->n)-1);

        insere_recursivamente(grafo, grafo->n-1, grafo->adjacencia[PR]);
        insere_aresta(grafo, grafo->n-1, PR);
        lista = gera_lista(grafo->adjacencia[grafo->n-1], lista, aux);
        bubblesort_v2(lista, *aux+1);
        imprime_listaordenada(lista, *aux+1);
    }

    free(caminhos); free(contador); free(aux); free(lista);
    
}

p_no remove_da_lista(p_no lista , int v) {// Remove um valor da lista ligada
    p_no proximo;
    if (lista == NULL){
        return NULL;
    }else if (lista ->v == v) {
        proximo = lista ->prox;
        free(lista);
        return proximo;
    }else {
        lista ->prox = remove_da_lista(lista ->prox , v);
        return lista;
    }

}

void remove_aresta(p_grafo grafo, int u, int v) {// Remove uma aresta do grafo
    grafo->adjacencia[u] = remove_da_lista(grafo->adjacencia[u], v);
    grafo->adjacencia[v] = remove_da_lista(grafo->adjacencia[v], u);
}

void modo_operacaoR(p_grafo grafo){// Chama todas as funcoes necessarias para realizar a operacao 'R'
    int CD, PR; //CD -> Centro de Distribuicao PR -> Ponto de Recebimento
    scanf("%d %d ", &CD, &PR);
    remove_aresta(grafo, CD, PR);
    printf("ARESTA %d -> %d REMOVIDO\n", CD, PR);
}

void libera_lista(p_no lista) {// Libera a memoria alocada para a lista ligada
    if (lista != NULL) {
        libera_lista(lista ->prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo grafo) {// Destroi o grafo
    for (int i = 0; i < grafo->n; i++)
        libera_lista(grafo->adjacencia[i]);
    free(grafo->adjacencia);
    free(grafo);
} 