typedef struct No TNo;

struct No{
    int valor;
    struct No *esq;
    struct No *dir;
};

TNo *criar(int v);
void exibeNo(TNo *e);
int valorNo(TNo *e);
void preordem(TNo *e);
void simetrica(TNo *e);
void posordem(TNo *e);
int soma(TNo *e);
int altura(TNo *e);
int QtdNos(TNo *e);
TNo *busca(TNo *e, int v);
TNo *buscaB(TNo *e, int raiz);
TNo *BuscaNaoRec(TNo *e, int n);
int QtdBuscaDir(TNo *e, int valor);
int somaImpar(TNo *e);
TNo *inserir(TNo *e, int valor);
void liberaNo(TNo *e);
void liberaBin(TNo *e);
int busca_maior(TNo *e);
int busca_menor(TNo *e);
TNo *removerNo(TNo *e, int valor);
TNo *MaisDir(TNo *e);
TNo *MaisEsq(TNo *e);
int comparar(TNo *e1, TNo *e2);
