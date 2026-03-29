#include <iostream>
using namespace std;

// Criação do vetor dinâmico
int* criaVetor(int tam) {
    int *v;
    v = new int[tam];
    //cout << "Vetor de " << tam << " posições criado"<< endl;
    return v;
}

// Percurso e impressão
void printVetor(int t, int vet[]) {
    for (int i = 0; i < t; i++) {
        cout << "Valor da pos [" << i << "]: ";
        cout << vet[i] << endl;
    }
}

// Inserção no final
int insereFim(int elem, int t, int vet[]) {
    //cout << "Inserindo " << elem << " na posição " << t << endl;
    vet[t] = elem;
    t++;
    return t;
}

// Inserção ordenada (crescente)
int insereOrd(int elem, int t, int vet[]) {
    //cout << "inserindo " << elem << "..." << endl << "t = " << t << endl;
    int pos = -1; //pos que vamos inserir

    // sit 1: vetor vazio
    if (t == 0) {
        vet[t] = elem;
    } else {
        // sit 2 e 4: elem no inicio ou meio
        for (int i = 0; i < t; i++) {
            if (elem < vet[i]) {
                //cout << elem << " < " << vet[i] << "..." << endl;
                pos = i; // posição a inserir

                // percorre de trás pra frente pra não precisar de auxiliar
                for (int j = t; j > pos; j--) {
                    vet[j] = vet[j-1];
                }
                vet[pos] = elem;
                break;
            }
        }
        // sit 3: elem no final
        if (pos == -1) {
            vet[t] = elem;
        }
    }
    t++; // atualiza o tamanho
    return t;
}

// Busca sequencial
int buscaSeq(int elem, int t, int vet[]) {
    int pos = -1;
    for (int i = 0; i < t; i++) {
        if (elem == vet[i]) {
            pos = i;
            cout << "encontrado na posição " << i << endl;
            break;
        }
    }
    //cout << "Não encontrado!" << endl;
    return pos;
}

// Função de Busca Binária
// Retorna o índice do elemento se encontrado, ou -1 caso contrário
int buscabin(int elem, int tam, int vet[]) {
    int ini = 0;
    int fim = tam - 1;

    while (ini <= fim) {
        // Calcula o meio
        int meio = ini + (fim - ini) / 2;

        // Verifica se o elem está no meio
        if (vet[meio] == elem) {
            cout << "encontrado na posição " << meio << endl;
            return meio;
        }

        // Se o elem for maior, ignore a metade esquerda
        if (vet[meio] < elem) {
            ini = meio + 1;
        }
        // Se o elem for menor, ignore a metade direita
        else {
            fim = meio - 1;
        }
    }

    // Elemento não está presente
    //cout << "Não encontrado!";
    return -1;
}

// Remoção a partir de um índice (pos)
int removeElem(int pos, int t, int vet[]) {
    for (int i = pos + 1; i < t; i++) {
        vet[i-1] = vet[i];
    }
    t--;
    return t;
}

// Função auxiliar para trocar dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de Partição: Organiza os elementos em relação ao pivô
int particionar(int vet[], int baixo, int alto) {
    int pivo = vet[alto]; // Escolhe o último elemento como pivô
    int i = (baixo - 1);  // Índice do menor elemento

    for (int j = baixo; j <= alto - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (vet[j] <= pivo) {
            i++;
            trocar(&vet[i], &vet[j]);
        }
    }
    trocar(&vet[i + 1], &vet[alto]);
    return (i + 1);
}

// Função Principal do Quicksort
void quicksort(int vet[], int baixo, int alto) {
    if (baixo < alto) {
        // pi é o índice de partição, arr[pi] está no lugar certo
        int pi = particionar(vet, baixo, alto);

        // Ordena separadamente os elementos antes e depois da partição
        quicksort(vet, baixo, pi - 1);
        quicksort(vet, pi + 1, alto);
    }
}
