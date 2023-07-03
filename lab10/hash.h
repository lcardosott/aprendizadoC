#define MAX 2003 //Primeiro primo após o N MAX

typedef struct caso *p_caso;

struct caso {
    int id;
    char nome[50];
    int tempo;
};

typedef struct hash *p_hash;

struct hash {
    p_caso vetor[MAX];
};

p_hash cria_hash();

int hash(int id);

void inserir(p_hash lista_hash);

void remover(p_hash lista_hash);

void consulta_nome(p_hash lista_hash);

void consulta_tempo(p_hash lista_hash);

void limpa_hash(p_hash lista_hash);