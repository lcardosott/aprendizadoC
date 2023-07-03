#include <stdio.h>
#include <string.h>
#define MAX 99

void armazena(int matrizA[MAX][MAX], int ** matrizB, int N){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            matrizA[i][j] = matrizB[i][j];
        }
    }
}

//void imprime_matriz(int ** matrizA[99][99], int n){
//    for (int i = 0; i <n;i++){
//        for (int j = 0; j <n; j++){
//            printf("%d ", matrizA[i][j]);
//        }   
//    printf("\n");
//    }
//}

int **chapeuseletor(int**matrizA, int **matrizB, char A[1]){
    if (strcmp(A,"A") ==0){
        return matrizA;
    }
    else{
        return matrizB;
    }

}


void transposta(int** matrizA, int**matrizB, int n){
    int aux[MAX][MAX];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            aux[i][j] = matrizA[j][i];
        }
    }

    armazena(aux,&&matrizB, n);    
}


void constroi_matriz(int matrizA[99][99], int n){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j+=3){
            if ((j/3)%2 == 0){
                matrizA[i][j]  = 1;
                matrizA[i][j+1]= 1;
                matrizA[i][j+2]= 1;
            }
            else{
                matrizA[i][j]  = 0;
                matrizA[i][j+1]= 0;
                matrizA[i][j+2]= 0;
            }
        }   
    }
}

int main(void){ 
    int n, o, matrizA[99][99], matrizB[99][99];
    
    scanf("%d",&n);
    constroi_matriz(matrizA, n);
    constroi_matriz(matrizB, n);
//    imprime_matriz(matrizA, n);
    
    scanf("%d", &o);
    char nome_operacao[10], A[1], B[1], guarda[1];
    for (int i=0; i<o; i++){
        scanf("%s", nome_operacao);

        if (strcmp(nome_operacao, "TRANSPOSTA")== 0||strcmp(nome_operacao, "BORDAS")==0){
            scanf("%s", A);
            scanf("%s", B);

            if((strcmp(nome_operacao, "TRANSPOSTA")==0)){
                transposta(&&chapeuseletor(&&matrizA,&&matrizB,A),&&chapeuseletor(&&matrizA,&&matrizB,B),n);
                
            }else if(strcmp(nome_operacao, "BORDAS")==0){


            }

        }   
    }
    return 0;
}