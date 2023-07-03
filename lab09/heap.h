typedef struct {
    int numero_caso;
    int nivel_prioridade;
} Item;

typedef struct {
    Item *v; // vetor de Items alocado dinamicamente
    int n, tamanho; // n: qtde de elementos , tamanho: qtde alocada
} fp;

typedef fp * p_fp;

p_fp criar_filaprioridade(int tam);

void troca(int *a, int *b);

void sobe_no_heap(p_fp fila_prioridade, int atual);

void desce_no_heap(p_fp fila_prioridade , int atual); 

void insere(p_fp fila_prioridade , Item item);

Item remove_caso(p_fp fila_prioridade);

void muda_prioridade(p_fp fila_prioridade , int k, int valor);

int obtem_id(p_fp fila_prioridade, int caso);

void limpa_fila(p_fp fila);