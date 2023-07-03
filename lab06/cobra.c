#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"

void cria_no (p_no cobra) {//A funcao 'cria_no' e responsavel por criar uma unidade da cobra
    cobra->anterior = NULL;
    cobra->proximo = NULL;
}

void cria_matriz(p_mapa mapa){ //A funcao 'cria_matriz' cria uma matriz m*n uma matriz m*n composta por '_' 
    scanf("%d", &(mapa->M));//É MMMMM
    scanf("%d", &(mapa->N));
    mapa->linha = malloc ((mapa->M)*sizeof(int*));
    for (int i=0; i<mapa->M; i++){
        mapa->linha[i] = malloc((mapa->N)*sizeof(int));
        for (int j=0; j<mapa->N; j++){
            mapa->linha[i][j] =0;
        }
    }
}

void destruir_lista(p_no cobra){//A funcao 'destruir_lista' limpa a memoria selecionada para a cobra ao fim do jogo
    if (cobra != NULL) {
        destruir_lista(cobra ->proximo);
        free(cobra);
    }
}

void limpa_matriz(p_mapa mapa){//A funcao 'limpa_matriz' tem o obletivo de limpar a matriz a fim de previnir o vazamento de memoria 
    for (int i=0; i< mapa -> M; i++){
            free(mapa->linha[i]);
    }
    free(mapa->linha);
    free(mapa);
}

void marca_fruta(p_mapa mapa){//A funcao 'marca_fruta' marca a fruta no mapa
    mapa->linha[mapa->posicao_fruta[0]][mapa->posicao_fruta[1]] = -1;
}

void marca_cobra(p_mapa mapa, p_no cobra){// A funcao 'marca_cobra' marca a primerira posicao da cobra no mapa
    mapa->linha[cobra->dados[0]][cobra->dados[1]] = 1;   
}

void le_fruta(p_mapa mapa){//A funcao 'le_fruta' le onde a fruta esta sendo inserida e a marca no mapa
    char lixo[6];
    scanf("%s ", lixo );
    scanf("%d ", &mapa->posicao_fruta[0]);
    scanf("%d ", &mapa->posicao_fruta[1]);
    marca_fruta(mapa);
    mapa-> fruta='S';
}

void le_cobra(p_no cobra, p_mapa mapa){//A funcao 'le_cobra' le a posicao da cobra e a marca no mapa
    char lixo[6];
    scanf("%s ", lixo);
    scanf("%d ", &cobra->dados[0]);
    scanf("%d", &cobra->dados[1]);
    marca_cobra(mapa, cobra);
}

int imprime_mapa(p_mapa mapa){//A funcao 'imprime_mapa' traduz -1 para '*', 0 para '_' e ' para '#', em seguida, imprime 
    int win_checker;
    win_checker = 0;
    for (int i=0; i<mapa->M; i++){
        for (int j=0; j<mapa->N;j++){
            if(mapa->linha[i][j]==-1){
                printf("%c ", '*');
            }else if(mapa->linha[i][j]==0){
                printf("%c ", '_');
            }else if(mapa->linha[i][j]==1){
                printf("%c ", '#');
                win_checker ++;
            }
        }
        printf("\n");
    }
    printf("\n");
    return win_checker;
}

void zera_mapa(p_mapa mapa){//A funcao 'zera_mapa' deixa todas a posicoes do mapa com o valor 0
    for (int i=0; i<mapa->M; i++){
        for (int j=0; j<mapa->N; j++){
            mapa->linha[i][j] =0;
        }
    }
}

void atualiza_mapa(p_mapa mapa, p_no cobra){//A funcao 'atualiza_mapa' insere a nova cobra no mapa
    mapa->linha[cobra->dados[0]][cobra->dados[1]] = 1;
    if (cobra->proximo !=NULL) {
        atualiza_mapa(mapa, cobra->proximo);
    }
    return;
}

void atualizacao_borda(p_no cobra, p_mapa mapa, int coluna, int linha, int* dados_aux){/*Caso o jogador se dirija a parede, a funcao 'atualizacao_borda' 
a desloca para o lado oposto*/
    dados_aux[0] = cobra->dados[0];
    dados_aux[1] = cobra->dados[1];

    if(coluna){
        if(coluna>0){
            cobra-> dados[1] = 0;   
        }else{
            cobra-> dados[1] = mapa->N-1;  
        }
    }else{
        if(linha>0){
            cobra-> dados[0] = 0;   
        }else{
            cobra-> dados[0] = mapa->M -1;  
        }
    }
}

int checa_fruta(p_mapa mapa, p_no cobra){//A funcao 'checa_fruta' confere se o jogador comeu a fruta
    if (cobra->dados[0]==mapa->posicao_fruta[0] && cobra->dados[1]==mapa->posicao_fruta[1]){
        return 1;
    } else{
        return 0;
    }
}

void recursao(p_no cobra, int* dados_aux){//A funcao 'recursao'atualiza a posicao da cobra caso a mesma tenha se deslocado sem comer nada
    if(cobra==NULL){
        return;
    } else if (cobra->proximo !=NULL){
        int aux[2];
        aux[0]=cobra->dados[0];
        aux[1]=cobra->dados[1];
        cobra->dados[0] = dados_aux[0];
        cobra->dados[1] = dados_aux[1];
        return recursao(cobra->proximo, aux);
    }
    cobra->dados[0] = dados_aux[0];
    cobra->dados[1] = dados_aux[1];
    return;
}

void recursao_fruta(p_no cobra, p_no anterior, int* dados_aux){//A funcao 'recursao_fruta' atualiza a posicao da cobra caso ela tenha comido uma fruta
    if (cobra != NULL){
        int aux[2];
        aux[0]=cobra->dados[0];
        aux[1]=cobra->dados[1];
        cobra->dados[0] = dados_aux[0];
        cobra->dados[1] = dados_aux[1];
        return recursao_fruta(cobra->proximo, cobra, aux);
    }
    p_no rabo;
    rabo = malloc(sizeof(struct no));
    cria_no(rabo);
    anterior->proximo = rabo;
    rabo->anterior = anterior,
    rabo->dados[0]=dados_aux[0];
    rabo->dados[1]=dados_aux[1];
    return;
}

int atualiza_cobra(p_no cobra, p_mapa mapa, int coluna, int linha){//A funcao 'atualiza_cobra', chama as funcoes necessarias para fazer a cobra andar
    int dados_aux[2];

    if (cobra->dados[0]+linha == mapa->M ||cobra->dados[1]+coluna == mapa->N || cobra->dados[0]+linha <0 ||cobra->dados[1]+coluna < 0){
    //se a cobra se dirigir a borda
        atualizacao_borda(cobra, mapa, coluna, linha, dados_aux);
    }else{ //caso contrario, segue atualizando a posicao da cabeca 
        dados_aux[0] = cobra->dados[0];
        dados_aux[1] = cobra->dados[1];
        cobra->dados[0]= cobra->dados[0]+linha;
        cobra->dados[1] = cobra->dados[1]+coluna;
    }

    if ((mapa->linha[cobra->dados[0]][cobra->dados[1]]==1)){// se a cobra bate nela mesma
        return 0;
    }

    if(checa_fruta(mapa, cobra)){// checa se a posicao em que a cabeca se encontra Ã© a mesma de uma fruta
        mapa->fruta = 'N';
        recursao_fruta(cobra->proximo, cobra, dados_aux); //se sim, adiciona uma unidade de comprimento para a cobra
    }else {// caso a cobra nao coma fruta, atualiza suas posicoes normalmente
        recursao(cobra->proximo, dados_aux);
    }

    return 1;
}