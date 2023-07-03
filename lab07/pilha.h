typedef struct pilha *p_pilha;

struct pilha {
    p_pilha proximo;
    char *caracteres;
    int quantidade_utilizada;
};

p_pilha inicializa_pilha();

void DEL(int *quantidade, p_pilha apontador);

void imprime_pilha(int pilha_id, p_pilha apontador, int* aux);

void limpa_pilha(int pilha_id, p_pilha apontador, int *aux);

