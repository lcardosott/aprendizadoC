typedef struct no *p_no;
struct no {
    int v;
    p_no prox;
};

typedef struct grafo *p_grafo;
struct grafo {
    p_no *adjacencia;
    int n;
};

#define MAX 40

p_grafo inicializa_grafo(int n);
p_no insere_na_lista(p_no lista , int v) ;
void insere_aresta(p_grafo grafo, int u, int v) ;
void busca_em_profundidade (p_grafo grafo, int *pai , int p, int v) ;
int* encontra_caminhos (p_grafo grafo, int s) ;
void conta_caminho(int v, int *pai, int* contador);
void insere_recursivamente(p_grafo grafo, int NOVO_CD, p_no PR);
int* gera_lista(p_no lista_ligada, int* lista, int* aux);
void troca(int *vetor, int index1, int index2);
void bubblesort_v2(int *v, int n) ;
void imprime_listaordenada(int* lista, int n);
void modo_operacaoD(p_grafo grafo);
p_no remove_da_lista(p_no lista , int v) ;
void remove_aresta(p_grafo grafo, int u, int v) ;
void modo_operacaoR(p_grafo grafo);
void libera_lista(p_no lista) ;
void destroi_grafo(p_grafo grafo) ;