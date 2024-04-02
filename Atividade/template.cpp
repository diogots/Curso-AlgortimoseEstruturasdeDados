#include <iostream>
#include <locale.h>
using namespace std;

struct ponto{
    //..criar os campos para armazenar duas coordenadas x,y
};

typedef //... criar um tipo de dado Ponto a partir da struct ponto;

struct poligono{
    //criar os campos para armazenar o número de vertices e um ponteiro do tipo Ponto para alocar dinamicamente um vetor de pontos
};

typedef //... criar um tipo de dado Poligono a partir da struct poligono;

int main()
{   //setando o locale para pt-br
    setlocale(LC_ALL,"");
    cout << "Gerador de Polígono" << endl;

    Poligono p;

    //lendo o número de vértices
    cout << "Digite o número de vértices do polígono:" << endl;
    cin >> //... leia o número de vértices do polígono

    //lendo os vértices do polígono:

    // Passo 1: Alocar dinamicamente um vetor do ponto com n vértices e apontar o campo do ponteiro da struct poligono para ele
    // Passo 2: usar um 'for' para ler os campos x e y para cada ponto do vetor de pontos

    //imprimindo o polígono:
    cout << "\nPolígono gerado:" << endl;
    // usar novamente um 'for' para imprimir os campos x e y de cada ponto do vetor de pontos

    return 0; //encerrar programa
}
