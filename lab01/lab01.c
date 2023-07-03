#include <stdio.h>

void conjuntobanner(int lista[], int aux[], int T) {
  int quantidade, j, k, l, test_number;
  scanf("%d", &quantidade);
  int conjunto[quantidade];

  
  for (j = 0; j < quantidade; j++) { /*Tem o objetivo de scanear o conjunto banner*/
    scanf("%d", &conjunto[j]);
    }
  
  for (k = 0; k < T; k++) {
    test_number = 2;
    for (l = 0; l < quantidade; l++) {
      if (lista[k] == conjunto[l]) {
        test_number = 1;
        break;
      }
    }
    if (test_number != 1) {
      lista[k] = 0;
    }
  }
}


void multiplicacaomorbius(int lista[], int T){
  int M, i;
  scanf("%d",&M);
  for (i=1; i<T; i=i+2){
    lista[i] = lista[i]*M;
  }
  
}

void movimentociclico(int lista[], int T, int aux[]){
  int P, i, j;
  scanf("%d", &P);
  for (i=0; i!=P; i++){
    aux[0] = lista[T-1];
    for (j=1; j!=T; j++){	
      aux[j] = lista[j-1] ;     
    }
    for (j=0;j!=T; j++){
      lista[j] = aux[j];
    }
  }
}


void inversao(int lista[], int aux[], int T){
  int i;
  
  for (i=0; i!=T; i++){
    aux[T-i-1] = lista[i];
  }
  for (i=0;i!=T;i++){
    lista[i]=aux[i];
  }
}

void imprimelista(int lista[], int T){
  int i;

  for (i=0; i<T; i++){
    printf("%d ", lista[i]);
  }
  printf("\n");
} 

int main(void) {
  int T;
  scanf("%d", &T);
  int lista[T], aux[T], i;

  for (i = 0; i < T; i++) {
    scanf("%d", &lista[i]);
  }

  int quantidade, operation;
  scanf("%d", &quantidade);
  for (i = 0; i < quantidade; i++) {
    scanf("%d", &operation);
    
    switch (operation) {
    	case 1:
      		conjuntobanner(lista, aux, T);
      		break;
    	case 2:
      		multiplicacaomorbius(lista, T);
      		break;
    	case 3:
      		movimentociclico(lista, T, aux);
      		break;
    	case 4:
      		inversao(lista, aux, T);
      		break;
      }
     imprimelista(lista, T);
  }
  return 0;
}

