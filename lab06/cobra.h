typedef struct no *p_no;
typedef struct mapa_jogo *p_mapa;

struct no {
    int dados[2];
    p_no proximo;
    p_no anterior;
};

struct mapa_jogo {
    int **linha;
    int M;
    int N;
    char fruta;
    int posicao_fruta[2];
};

void cria_no (p_no cobra);

void cria_matriz(p_mapa mapa);

void destruir_lista(p_no cobra);

void limpa_matriz(p_mapa mapa);

void marca_fruta(p_mapa mapa);

void marca_cobra(p_mapa mapa, p_no cobra);

void le_fruta(p_mapa mapa);

void le_cobra(p_no cobra, p_mapa mapa);

int imprime_mapa(p_mapa mapa);

void zera_mapa(p_mapa mapa);

void atualiza_mapa(p_mapa mapa, p_no cobra);

void atualizacao_borda(p_no cobra, p_mapa mapa, int coluna, int linha, int* dados_aux);

int checa_fruta(p_mapa mapa, p_no cobra);

void recursao(p_no cobra, int* dados_aux);

void recursao_fruta(p_no cobra, p_no anterior, int* dados_aux);

int cobra_bate(p_mapa mapa, p_no cobra);

int atualiza_cobra(p_no cobra, p_mapa mapa, int coluna, int linha);