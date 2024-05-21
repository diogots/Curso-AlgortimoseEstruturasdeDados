//arquivo com as defini��es de tipos abstratos de dados utilizados!

//cria��o de um n� de inteiros b�sico
struct node{
    int info;
    struct node *prox;
};

typedef struct node Node;

//cria��o de uma estrutura de pilha
struct pilha{
    Node *topo;
};

typedef struct pilha Pilha;

//cria��o de uma estrutura de fila
struct fila{
    Node *inicio;
    Node *fim;
};

typedef struct fila Fila;

//cria��o de uma estrutura de n� de �rvore de busca bin�ria b�sico
struct noArv{
    int info;
    struct noArv *esq;
    struct noArv *dir;
};

typedef struct noArv ArvBB;
