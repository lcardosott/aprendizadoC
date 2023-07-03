#include <stdio.h>
#include "represa.h"

represa leitor(){ // a funcao leitor le os inputs dados pelo cliente
    represa generica;
    int media = 0;
    scanf("%s %f %d ",generica.nome, &generica.max, &generica.N);

    for (int i=0; i<generica.N; i++){
        scanf("%d ", &generica.valores[i]);
        media = media+ generica.valores[i];
    }
    media =media/generica.N;
    generica.media = media;
    return generica;
}

int alerta(represa nome_represa){// a funcao alerta checa se algum dos niveis ultrapassou 90% do limite
    for (int i=0; i<nome_represa.N; i++){
        if(nome_represa.valores[i]>=nome_represa.max*0.9){
            return 1;
        }
    }
    return 0;
    }

void imprime(represa nome_represa, int checker){// a funcao imprime imprime os dados apos o tratamento

    if (checker){
        printf("NOME: %s\nQTD NIVEIS: %d\nMEDIA: %d\nCAPACIDADE ACIMA DE 90%% DA MAXIMA!\n#####\n",nome_represa.nome,nome_represa.N, nome_represa.media);
    } else{
        printf("NOME: %s\nQTD NIVEIS: %d\nMEDIA: %d\n#####\n", nome_represa.nome,nome_represa.N, nome_represa.media);
    }
}

void minusculo(char nome_represa[100]){// a funcao minusculo troca todas as maiusculas por minusculas 
    int qtdd_carac;
    qtdd_carac = tamanho(nome_represa);
    for (int i = 0; i < qtdd_carac; i++){
        if(nome_represa[i] >='A' && nome_represa[i] <='Z'){
            nome_represa[i] = nome_represa[i]+ 32;
        }
    }
}

void espaco(char nome_represa[100]){// a funcao espaco troca "_" por " "
    int qtdd_carac;
    qtdd_carac = tamanho(nome_represa);
    for (int i = 0; i < qtdd_carac; i++){
        if(nome_represa[i] == '_'){
            nome_represa[i] = ' ';
        }
    }
}

void numero(char nome_represa[100]){// a funcao numero retira os numeros do fim dos nomes
    int qtdd_carac;
    qtdd_carac = tamanho(nome_represa);
    for(int i=0; i<qtdd_carac; i++){
        if(nome_represa[i] >='0' && nome_represa[i]<='9'){
            nome_represa[i]='\0';
            break;
        }
    }
}

int prefixo(char nome_represa[100]){// a funcao prefixo retira "represa_de_" dos nomes
    char padrao[12]="represa de ",novo_nome[100-11];
    int qtdd_caracter;

    for (int i=0; i<11;i++){
        if(nome_represa[i]!= padrao[i]){
            return 1;
        }
    }
    for(int i=11;nome_represa[i]!='\0'; i++){
        novo_nome[i-11]=nome_represa[i];
        novo_nome[i-10]= '\0';
    }
    qtdd_caracter=tamanho(novo_nome);
    for (int i=0;i<qtdd_caracter+1; i++){
        nome_represa[i]=novo_nome[i];
    }
    return 1;
} 

int tamanho(char nome_represa[100]){// a funcao tamanho descobre o tamanho de uma string
    int i;
    for (i=0; nome_represa[i] !='\0'; i++){        
    }
    return i;
}

void trata_string(char nome_represa[100]){/*a funcao trata_string realiza os processos necessario para tratar uma string
com o auxílio das funcoes minusculo; espaco; inteiro; numero; prefixo*/
    minusculo(nome_represa);
    espaco(nome_represa);
    numero(nome_represa);
    prefixo(nome_represa);
}


