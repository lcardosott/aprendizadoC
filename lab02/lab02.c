#include <stdio.h>
#include <string.h>
#define MAX 99

void armazena(int matrizAcopiar[MAX][MAX], int matrizFinal[MAX][MAX], int n){
//A funcao tem a finalidade de copiar uma matriz 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrizFinal[i][j] = matrizAcopiar[i][j];
        }
    }
}

void imprime_matriz(int matrizA[99][99], int n){
//A funcao tem a finalidade de dada uma matriz, imprimir a mesma
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }
}

void transposta(int matrizA[MAX][MAX], int matrizB[MAX][MAX], int n){
//A funcao tem a finalidade de transpor uma matrizA e inserir o resultado em uma matrizB
    int aux[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux[i][j] = matrizA[j][i];
        }
    }
    armazena(aux, matrizB, n);
}

void soma(int matrizA[MAX][MAX], int matrizB[MAX][MAX], int matrizC[MAX][MAX], int n){
//A funcao tem a finalidade de somar uma matrizA e uma matrizB e inserir o resultado em uma matrizC
    int matrizD[MAX][MAX];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizD[i][j] = matrizA[i][j] || matrizB[i][j];
        }
    }
    armazena(matrizD, matrizC, n);
}

void multi_elemento(int matrizA[MAX][MAX], int matrizB[MAX][MAX], int matrizC[MAX][MAX], int n){
/*A funcao tem a finalidade de multiplicar uma matrizA por uma matrizB(elemento a elemento)
 e inserir o resultado em uma matrizC*/
    int matrizD[MAX][MAX];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizD[i][j] = matrizA[i][j] && matrizB[i][j];
        }
    }
    armazena(matrizD, matrizC, n);
}

void multi_mat(int matrizA[MAX][MAX], int matrizB[MAX][MAX], int matrizC[MAX][MAX], int n){
//A funcao tem a finalidade de multiplicar uma matrizA por uma MatrizB e inserir o resultado em uma matrizC
    int matrizD[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            matrizD[i][j] = 0;
            for (int k = 0; k < n; k++)
                matrizD[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (matrizD[i][j]){
                matrizD[i][j] = 1;
            }
        }
    }
    armazena(matrizD, matrizC, n);
}

void bordas(int matrizA[MAX][MAX], int matrizB[MAX][MAX], int n){
//A funcao tem a finalidade de definir as bordas de uma matrizA e inserir o resultado em uma matrizB
    int matrizD[MAX][MAX];
    armazena(matrizA, matrizD, n);//salva as linhas e colunas mais periféricas da matriz
    for (int i=1; i<n-1; i++){
        for (int j=1; j<n-1; j++){
            if (matrizA[i][j-1] && matrizA[i][j+1] && matrizA[i+1][j] && matrizA[i-1][j]
            && matrizA[i+1][j+1] && matrizA[i+1][j-1] && matrizA[i-1][j+1] && matrizA[i-1][j-1]){
                matrizD[i][j]=0;
            }
        }
    }
    armazena(matrizD, matrizB, n);
}

void constroi_matriz(int matrizA[99][99], int n){
//A funcao tem a finalidade de contruir uma matriz N*N, cujas colunas variam de 1 a 0 a cada 3
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j += 3)
        {
            if ((j / 3) % 2 == 0)
            {
                matrizA[i][j] = 1;
                matrizA[i][j + 1] = 1;
                matrizA[i][j + 2] = 1;
            }
            else
            {
                matrizA[i][j] = 0;
                matrizA[i][j + 1] = 0;
                matrizA[i][j + 2] = 0;
            }
        }
    }
}

int main(void){
    int n, o, matrizA[99][99], matrizB[99][99];

    scanf("%d ", &n);
    constroi_matriz(matrizA, n);
    constroi_matriz(matrizB, n);

    scanf("%d ", &o);
    char nome_operacao[10], A, B, guarda;
    for (int i = 0; i < o; i++)
    {
        scanf("%s ", nome_operacao);

        if (strcmp(nome_operacao, "TRANSPOSTA") == 0){//separa todos os casos possíveis para a operação "TRANSPOSTA"
            scanf("%c ", &A);
            scanf("%c ", &guarda);

            if (guarda == 'A'){

                if (A==guarda){
                    transposta(matrizA, matrizA, n);
                }
                else{
                    transposta(matrizB, matrizA, n);
                }
                imprime_matriz(matrizA,n);
            } else {
                if (A== guarda){
                    transposta(matrizB, matrizB, n);
                } else {
                    transposta(matrizA, matrizB, n);
                }
                imprime_matriz(matrizB,n);
            }

        } else if (strcmp(nome_operacao, "SOMA") == 0){//separa todos os casos possíveis para a operação "SOMA"
            scanf("%c ", &A);
            scanf("%c ", &B);
            scanf("%c ", &guarda);
            if (guarda=='A'){
                if(A==B){
                    if(A=='A'){
                        soma(matrizA,matrizA,matrizA,n);
                    }else{
                        soma(matrizB,matrizB,matrizA,n);
                    }
                }else{
                    if(A=='A'){
                        soma(matrizA,matrizB,matrizA,n);
                    }else{
                        soma(matrizB,matrizA,matrizA,n);
                    }      
                }
                imprime_matriz(matrizA, n);
            }else{
                if(A==B){
                    if(A=='A'){
                        soma(matrizA,matrizA,matrizB,n);
                    }else{
                        soma(matrizB,matrizB,matrizB,n);
                    }
                }else{
                    if(A=='A'){
                        soma(matrizA,matrizB,matrizB,n);
                    }else{
                        soma(matrizB,matrizA,matrizB,n);
                    }   
                }
                imprime_matriz(matrizB, n);
            }
        } else if(strcmp(nome_operacao, "MULTI_ELEM")==0){//s  epara todos os casos possíveis para a operação "MULTI_ELEM"
            scanf("%c ", &A);
            scanf("%c ", &B);
            scanf("%c ", &guarda);
            if (guarda=='A'){
                if(A==B){
                    if(A=='A'){
                        multi_elemento(matrizA,matrizA,matrizA,n);
                    }else{
                        multi_elemento(matrizB,matrizB,matrizA,n);
                    }
                }else{
                    if(A=='A'){
                        multi_elemento(matrizA,matrizB,matrizA,n);
                    }else{
                        multi_elemento(matrizB,matrizA,matrizA,n);
                    }      
                }
                imprime_matriz(matrizA, n);
            }else{
                if(A==B){
                    if(A=='A'){
                        multi_elemento(matrizA,matrizA,matrizB,n);
                    }else{
                        multi_elemento(matrizB,matrizB,matrizB,n);
                    }
                }else{
                    if(A=='A'){
                        multi_elemento(matrizA,matrizB,matrizB,n);
                    }else{
                        multi_elemento(matrizB,matrizA,matrizB,n);
                    }   
                }
                imprime_matriz(matrizB, n);
            }
        }else if(strcmp(nome_operacao, "MULTI_MAT")==0){//separa todos os casos possíveis para a operação "MULTI_MAT"
            scanf("%c ", &A);
            scanf("%c ", &B);
            scanf("%c ", &guarda);
            if (guarda== 'A'){
                if(A==B){
                    if(A== 'A'){
                        multi_mat(matrizA,matrizA,matrizA,n);
                    }else{
                        multi_mat(matrizB,matrizB,matrizA,n);
                    }
                }else{
                    if(A=='A'){
                        multi_mat(matrizA,matrizB,matrizA,n);
                    }else{
                        multi_mat(matrizB,matrizA,matrizA,n);
                    }      
                }
                imprime_matriz(matrizA, n);
            }else{
                if(A==B){
                    if(A=='A'){
                        multi_mat(matrizA,matrizA,matrizB,n);
                    }else{
                        multi_mat(matrizB,matrizB,matrizB,n);
                    }
                }else{
                    if(A=='A'){
                        multi_mat(matrizA,matrizB,matrizB,n);
                    }else{
                        multi_mat(matrizB,matrizA,matrizB,n);
                    }   
                }
                imprime_matriz(matrizB, n);
            }           
        }else{
            scanf("%c ", &A);
            scanf("%c ", &guarda);

            if (guarda=='A'){

                if (A==guarda){
                    bordas(matrizA, matrizA, n);
                }
                else{
                    bordas(matrizB, matrizA, n);
                }
                imprime_matriz(matrizA,n);
            } else {    
                if (A==guarda){
                    bordas(matrizB, matrizB, n);
                } else {
                    bordas(matrizA, matrizB, n);
                }
                imprime_matriz(matrizB,n);
            }
    }
    }
    return 0;
    
    }