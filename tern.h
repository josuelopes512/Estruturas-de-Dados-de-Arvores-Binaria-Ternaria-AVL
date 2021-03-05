typedef struct NoN TNoN;

struct NoN{
    int valor;
    int qtde;
    struct Non **filhos;
};

TNoN *criarN(int v, int q);
void exibeNoN(TNoN *e);

void preordemN(TNoN *e);
void simetricaN(TNoN *e);
void posordemN(TNoN *e);

int somaN(TNoN *e);
void substituiValorVetorN(TNoN *e, int n);
int alturaN(TNoN *e);
void constroiBin(TNoN *e);