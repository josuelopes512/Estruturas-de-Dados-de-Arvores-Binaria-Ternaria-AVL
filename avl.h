typedef struct NoAvl TNoAvl;

struct NoAvl{
    int valor;
    int altura;
    struct NoAvl *esq;
    struct NoAvl *dir;
};

TNoAvl *criar(int v);