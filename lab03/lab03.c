#include <stdio.h>
#include "represa.h"

int main(){
    int quantidade_testes, alerta_result;
    represa vetor_represas[1000];
    scanf("%d ", &quantidade_testes);

    for (int i=0; i< quantidade_testes; i++){ //realiza o processo para cada represa 
        vetor_represas[i] = leitor();
        alerta_result = alerta(vetor_represas[i]);
        trata_string(vetor_represas[i].nome);
        imprime(vetor_represas[i], alerta_result);
    }
    return 0;
}

