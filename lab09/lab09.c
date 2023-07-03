#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main(){

    int quantidade_casos;
    scanf("%d", &quantidade_casos);

    p_fp fila;
    fila = criar_filaprioridade(quantidade_casos);

    int caso, prioridade;
    for (int i = 0; i < quantidade_casos; i++){
        scanf("%d %d", &caso, &prioridade);
        Item processo;
        processo.numero_caso = caso ;
        processo.nivel_prioridade = prioridade;
        insere(fila, processo);
    }

    int quantidade_operacoes;
    char operacao[2];
    scanf("%d", &quantidade_operacoes);
    for(int i = 0; i<quantidade_operacoes; i++){
        scanf("%s ", operacao);
        if (strcmp(operacao, "R")==0){
            int a_remover;
            scanf("%d ", &a_remover);
            Item removido;
            printf("PROCESSOS REMOVIDOS:");
            for (int j = 0; j < a_remover; j++){
                removido = remove_caso(fila);
                printf(" %d", removido.numero_caso);
            }printf("\n");
        }else{
            int nova_prioridade, caso_id, caso_a_alterar;
            scanf("%d %d ", &caso_a_alterar, &nova_prioridade);
            caso_id = obtem_id(fila, caso_a_alterar);
            muda_prioridade(fila, caso_id, nova_prioridade);////encontrar id
        }
    } 
    printf("FINALIZADO!");
    limpa_fila(fila);
    return 0;
}