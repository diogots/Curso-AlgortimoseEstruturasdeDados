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

