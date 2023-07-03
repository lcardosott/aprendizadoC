#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"


#define PAI(i) ((i-1) /2)
#define F_ESQ(i) (2*i+1) /* Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /* Filho direito de i*/

p_fp criar_filaprioridade(int tam) {//A funcao criar_filaprioridade alloca memoria para a fila
    p_fp fila_prioridade = malloc(sizeof(fp));
    fila_prioridade ->v = malloc(tam * sizeof(Item));
    fila_prioridade ->n = 0;
    fila_prioridade ->tamanho = tam;
    return fila_prioridade;
}

void troca(int *a, int *b) {//A funcao troca troca dois valores
    int t = *a;
    *a = *b;
    *b = t;
}

void sobe_no_heap(p_fp fila_prioridade, int atual){//Caso seja necessário, sobe o elemento no nível de importancia 
    if (atual > 0 && fila_prioridade ->v[PAI(atual)].nivel_prioridade > fila_prioridade ->v[atual].nivel_prioridade){
        troca (&fila_prioridade ->v[atual].nivel_prioridade, &fila_prioridade ->v[PAI(atual)].nivel_prioridade);
        troca (&fila_prioridade ->v[atual].numero_caso, &fila_prioridade ->v[PAI(atual)].numero_caso);
        sobe_no_heap(fila_prioridade , PAI(atual));
        return;
    }
    if (atual>0 &&fila_prioridade ->v[PAI(atual)].nivel_prioridade == fila_prioridade ->v[atual].nivel_prioridade){
        if(fila_prioridade ->v[PAI(atual)].numero_caso < fila_prioridade ->v[atual].numero_caso){
                troca (&fila_prioridade ->v[atual].nivel_prioridade, &fila_prioridade ->v[PAI(atual)].nivel_prioridade);
                troca (&fila_prioridade ->v[atual].numero_caso, &fila_prioridade ->v[PAI(atual)].numero_caso);
                sobe_no_heap(fila_prioridade , PAI(atual));
        return;
        }
    }
}

void desce_no_heap(p_fp fila_prioridade , int atual){//Caso seja necessário, desce o elemento no nível de importancia
    int maior_filho;
    if (F_ESQ(atual) < fila_prioridade ->n) {
        maior_filho = F_ESQ(atual);
        if (F_DIR(atual) < fila_prioridade ->n && fila_prioridade ->v[F_ESQ(atual)].nivel_prioridade > fila_prioridade ->v[F_DIR(atual)].nivel_prioridade){
            maior_filho = F_DIR(atual);
        }
        if (F_DIR(atual) < fila_prioridade ->n && fila_prioridade ->v[F_ESQ(atual)].nivel_prioridade == fila_prioridade ->v[F_DIR(atual)].nivel_prioridade && fila_prioridade ->v[F_ESQ(atual)].numero_caso < fila_prioridade ->v[F_DIR(atual)].numero_caso)
            maior_filho = F_DIR(atual);

        if (fila_prioridade ->v[atual].nivel_prioridade > fila_prioridade ->v[maior_filho].nivel_prioridade) {
            troca (&fila_prioridade ->v[atual].nivel_prioridade, &fila_prioridade ->v[maior_filho].nivel_prioridade);
            troca (&fila_prioridade ->v[atual].numero_caso, &fila_prioridade ->v[maior_filho].numero_caso);
            desce_no_heap(fila_prioridade , maior_filho);
            return;
        }
        if (fila_prioridade ->v[atual].nivel_prioridade == fila_prioridade ->v[maior_filho].nivel_prioridade && fila_prioridade ->v[atual].numero_caso < fila_prioridade ->v[maior_filho].numero_caso){
            troca (&fila_prioridade ->v[atual].nivel_prioridade, &fila_prioridade ->v[maior_filho].nivel_prioridade);
            troca (&fila_prioridade ->v[atual].numero_caso, &fila_prioridade ->v[maior_filho].numero_caso);
            desce_no_heap(fila_prioridade , maior_filho);
            return;     
        }
    }
}

void insere(p_fp fila_prioridade , Item item){// Insere um novo elemento na nossa fila de prioridade
    fila_prioridade ->v[fila_prioridade ->n] = item;
    fila_prioridade ->n++;
    sobe_no_heap(fila_prioridade, fila_prioridade ->n - 1);
}

Item remove_caso(p_fp fila_prioridade){//Remove o caso com maior importancia
    Item item = fila_prioridade ->v[0];
    troca (&fila_prioridade ->v[0].nivel_prioridade, &fila_prioridade ->v[fila_prioridade ->n - 1].nivel_prioridade);
    troca (&fila_prioridade ->v[0].numero_caso, &fila_prioridade ->v[fila_prioridade ->n - 1].numero_caso);
    fila_prioridade ->n--;
    desce_no_heap(fila_prioridade , 0);
    return item;
    }

void muda_prioridade(p_fp fila_prioridade , int k, int valor){//Muda a prioridade de um processo
    if (fila_prioridade ->v[k]. nivel_prioridade > valor) {
        fila_prioridade ->v[k]. nivel_prioridade= valor;
        sobe_no_heap(fila_prioridade , k);
    } else {
        fila_prioridade ->v[k]. nivel_prioridade = valor;
        desce_no_heap(fila_prioridade , k);
    }
}

int obtem_id(p_fp fila_prioridade, int caso){//Obtem o id de um processo
    int i=0;
    while (fila_prioridade->v[i].numero_caso != caso){
        i++;
    }
    return i;
}

void limpa_fila(p_fp fila){//Limpa a fila de prioridade
    free(fila->v);
    free(fila);
}