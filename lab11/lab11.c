#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"

int main(){
    int c, p, arestas, vertice1, vertice2, qtdd_operacoes;
    char operacao;
    scanf("%d %d ",&c, &p);

//BLOCO RESPONSAVEL POR INCIALIZAR O GRAFO E INSERIR SUAS ARESTAS INICIAIS

    p_grafo grafo;
    grafo = inicializa_grafo(c+p);

    scanf("%d ", &arestas);
    for (int i=0; i<arestas; i++){
        scanf("%d %d", &vertice1, &vertice2);
        insere_aresta(grafo, vertice1, vertice2);
    }
    printf("GRAFO AMZ CONSTRUIDO!\n");

//BLOCO RESPONSAVEL POR REALIZAR AS OPERACOES

    scanf("%d ", &qtdd_operacoes);
    for (int i = 0; i < qtdd_operacoes; i++){
        scanf("%c ", &operacao);
        switch (operacao){
            case 'D':
                modo_operacaoD(grafo);
                break;
            case 'R':
                modo_operacaoR(grafo);
                break;
        }
    }
    destroi_grafo(grafo);
    return 0;
}