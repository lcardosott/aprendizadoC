typedef struct{
    char nome[100];
    float max;
    int N;
    int valores[1000];
    int media;
} represa;

represa leitor(void); // a funcao leitor le os inputs dados pelo cliente

int alerta(represa nome_represa); // a funcao alerta checa se algum dos niveis ultrapassou 90% do limite

void imprime(represa nome_represa, int checker); // a funcao imprime imprime os dados apos o tratamento

void trata_string(char nome_represa[100]); /*a funcao trata_string realiza os processos necessario para tratar uma string
com o auxílio das funcoes minusculo; espaco; inteiro; numero; prefixo*/

void minusculo(char nome_represa[100]); // a funcao minusculo troca todas as maiusculas por minusculas 

void espaco(char nome_represa[100]); // a funcao espaco troca "_" por " "

void numero(char nome_represa[100]);// a funcao numero retira os numeros do fim dos nomes

int prefixo(char nome_represa[100]);// a funcao prefixo retira "represa_de_" dos nomes

int tamanho(char nome_represa[100]);// a funcao tamanho descobre o tamanho de uma string