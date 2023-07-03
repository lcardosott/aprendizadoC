typedef struct dados *matriz;

struct dados{
    int qtdd_linhas, qtdd_colunas, alocado_colunas, alocado_linhas;
    int **linha;
};

void cria_matriz(matriz matriz);//A funcao 'cria_matriz' cria a matriz dada pelo cliente

void limpa_matriz(matriz matriz);//A funcao 'limpa_matriz' tem o obletivo de limpar a matriz a fim de previnir o vazamento de memoria 

void imprime_matriz(matriz matriz);//A funcao 'imprime_matriz', imprime a matriz atual

void tam_check(matriz matriz);/*A funcao 'tam_check' tem o objetivo de checar a quantidade de espaço 
alocado para linhas/colunas e se necessario, dobrar/dividir o espaco destinado*/

void IN_L(matriz matriz);//A funcao 'IN_L' insere uma linha na ultima posicao

void IN_C(matriz matriz);//A funcao'IN_C' insere uma coluna em ordem

void OUT_L(matriz matriz);//A funcao 'OUT_L' retira uma determinada linha

void OUT_C(matriz matriz);//A funcao 'OUT_C' retira uma determinada coluna