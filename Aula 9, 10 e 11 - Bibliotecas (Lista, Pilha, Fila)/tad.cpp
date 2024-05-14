//arquivo com as definições de tipos abstratos de dados utilizados!

//criação de um nó de inteiros básico
struct node{
    int info;
    struct node *prox;
};

typedef struct node Node;

//criação de uma estrutura de pilha
struct pilha{
    Node *topo;
};

typedef struct pilha Pilha;

//criação de uma estrutura de fila
struct fila{
    Node *inicio;
    Node *fim;
};

typedef struct fila Fila;

