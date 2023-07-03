typedef struct mapa *p_mapa;
struct mapa {
    char nome[100];
    int visitas;
    p_mapa esq, dir;
};

typedef struct visita *p_visita;
struct visita {
    int data;
    char nome[100];
    int pista;
    p_visita esq , dir;
};

void imprime_atualizao_mapa(char *nome_cidade);

void  imprime_atualizao_visita(char* nome_cidade, int *data);

void imprime_exclusao(int visitas, char* nome_remocao);

void limpa_mapa (p_mapa raiz);

void limpa_visita(p_visita raiz);

p_mapa insere_visita_mapa(p_mapa raiz, char* nome_cidade);

p_visita insere_visita_visita(p_visita raiz, char* nome_cidade, int *data, int *pista);

p_visita remover_visita(int* data, p_visita raiz, char* nome_remocao);

p_mapa remover_mapa(int* data, p_mapa raiz, char* nome_remocao);

void busca_recursiva_visita(p_visita raiz, int* data_inicio, int*data_fim);

void busca_recursiva_pista(p_visita raiz, int* data_inicio, int*data_fim);

void relatorio_data(p_visita raiz);

void relatorio_pistas(p_visita raiz);