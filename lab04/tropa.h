typedef struct{
    int nome;
    int* ponteiro;
    int i;
    int j;
    int qtdd_elementos;
    int max;
} tropa;

int soma(int l, int m, tropa *estrutura);//'soma' tem a funcao de somar um determinado segmento de uma lista

void subtropa(tropa *estrutura, int n);//'subtropa' tem a funcao de calcular a subtropa de um 'pelotao'

void get_list(int *ponteiro, int n);//'get_list' tem a funcao de receber uma lista

void imprime_forte(tropa *estrutura, int *media, int *soma);//'imprime_forte' tem a funcao de imprimir uma subtropaforte

void normaliza(int *lista,int *lista_copia, int *media, int aux);//'normaliza' tem a funcao de normalizar uma lista

int reparticao_lista(tropa *estrutura, int aux, int *lista);//'reparticao_lista' tem a funcao de unir todas as subtropas_forte em uma unica lista

void subtropa_elite(tropa **estrutura, int n, int *media, int *soma, int*lista, int q);//'subtropa_elite' tem a funcao criar a subtropa de elite

void imprime_elite(tropa *lista_struct);//'imprime_elite' tem a funcao de imprimir a lista elite