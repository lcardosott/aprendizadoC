#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultron.h" 
void cria_matriz(matriz matriz){//A funcao 'cria_matriz' cria a matriz dada pelo cliente
    scanf("%d ", &(matriz->qtdd_linhas));
    scanf ("%d ", &(matriz->qtdd_colunas));
    matriz -> linha = malloc (matriz-> qtdd_linhas *sizeof(int*));
    for (int i=0; i<matriz->qtdd_linhas; i++){
        matriz->linha[i] = malloc(matriz->qtdd_colunas *sizeof(int));
        for (int j=0; j<matriz->qtdd_colunas; j++){
            scanf("%d", &matriz->linha[i][j]);
        }
    }
    matriz->alocado_colunas = matriz->qtdd_colunas;
    matriz->alocado_linhas = matriz->qtdd_linhas;
}

void limpa_matriz(matriz matriz){//A funcao 'limpa_matriz' tem o obletivo de limpar a matriz a fim de previnir o vazamento de memoria 
    for (int i=0; i< matriz -> alocado_linhas; i++){
            free(matriz->linha[i]);
    }
    free(matriz->linha);
    free(matriz);
}
void imprime_matriz(matriz matriz){//A funcao 'imprime_matriz', imprime a matriz atual
    for (int i=0; i< matriz->qtdd_linhas; i++){
        for (int j=0; j<matriz-> qtdd_colunas; j++){
            printf("%d ", matriz->linha[i][j]);
        }
        printf("\n");
    }
    printf("###\n");
}

void tam_check(matriz matriz){/*A funcao 'tam_check' tem o objetivo de checar a quantidade de espaço 
alocado para linhas/colunas e se necessario, dobrar/dividir o espaco destinado*/
    if (matriz->alocado_colunas == matriz->qtdd_colunas){
        int *temp;
        temp = malloc(matriz->alocado_colunas*sizeof(int));
        for (int i=0; i< matriz->qtdd_linhas; i++){
            temp = matriz->linha[i];
            matriz->linha[i] = malloc(matriz->alocado_colunas *2 *sizeof(int));
            for(int j=0; j<matriz ->qtdd_colunas; j++ ){
                matriz->linha[i][j] = temp[j];
            }
            }
        free(temp);
        matriz ->alocado_colunas = matriz->qtdd_colunas*2;
    } else if((matriz->qtdd_colunas)<=matriz->alocado_colunas/4){
        int *temp;
        temp = malloc(matriz->alocado_colunas*sizeof(int));
        for (int i=0; i< matriz->qtdd_linhas; i++){
            temp = matriz->linha[i];
            matriz->linha[i] = malloc(matriz->alocado_colunas /2 *sizeof(int));
            for(int j=0; j<matriz->qtdd_colunas;j++){
                matriz->linha[i][j] = temp[j];
            }
            free (temp);
            matriz ->alocado_colunas = matriz->qtdd_colunas/2;
        }
    } if(matriz->alocado_linhas==matriz->qtdd_linhas){
        for(int i=matriz->qtdd_linhas; i<2*matriz->qtdd_linhas;i++){
            matriz->linha[i] = malloc(matriz->qtdd_colunas*sizeof(int));
        }
    } else if(matriz->qtdd_linhas<=matriz->alocado_linhas/4){
        for (int i=matriz->qtdd_linhas/2; i<matriz->qtdd_linhas; i++){
            free(matriz->linha[i]);
        }
    }
}

void IN_L(matriz matriz){//A funcao 'IN_L' insere uma linha na ultima posicao
    int aux;
    matriz->linha[matriz->qtdd_linhas]= malloc(matriz->alocado_colunas *sizeof(int));
    for (int i=0; i<matriz->qtdd_colunas; i++){
        scanf("%d", &aux);
        matriz->linha[matriz->qtdd_linhas][i]= aux;
    }
    matriz->qtdd_linhas =matriz->qtdd_linhas + 1;
}

void IN_C(matriz matriz){//A funcao'IN_C' insere uma coluna em ordem
    int aux;
    for (int i=0; i<matriz->qtdd_linhas;i++){
        scanf("%d",&aux);
        for(int j=0; j<matriz->qtdd_colunas;j++){
            if (aux<matriz->linha[i][j]){
                for (int k=matriz->qtdd_colunas;k>j;k--){
                    matriz->linha[i][k]=matriz->linha[i][k-1];
                }
                matriz->linha[i][j]= aux;
                break;
            }else if(j==matriz->qtdd_colunas-1){
                matriz->linha[i][j+1]= aux;
            }
        }
    }
    matriz->qtdd_colunas = matriz->qtdd_colunas +1;
}

void OUT_L(matriz matriz){//A funcao 'OUT_L' retira uma determinada linha
    int aux;
    scanf("%d", &aux);
    for (int i=aux; i<matriz->qtdd_linhas-1;i++){
        for(int j=0; j<matriz->qtdd_colunas; j++){
            matriz->linha[i][j]=matriz->linha[i+1][j];
        }
    }
    free(matriz->linha[matriz->qtdd_linhas-1]);
    matriz->qtdd_linhas --; 
}

void OUT_C(matriz matriz){//A funcao 'OUT_C' retira uma determinada coluna
    int aux;
    scanf("%d", &aux);
    for (int i=0; i<matriz->qtdd_linhas; i++){
        for (int j=aux;j<matriz->qtdd_colunas; j++){
            matriz->linha[i][j] = matriz->linha[i][j+1];
        }
    }
    matriz->qtdd_colunas--;
}