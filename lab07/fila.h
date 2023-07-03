typedef struct fila *p_fila;

struct fila {
    char *enfilerados;
    int ini, fim ,tamanho;
};

p_fila inicializa_fila();

void adiciona_fila(p_fila fila, int *qtdd_caracteres, char *insercao_atual);

void limpa_fila(p_fila fila);
