#include <iostream>
#include <locale.h>
using namespace std;

struct ponto{
    //..criar os campos para armazenar duas coordenadas x,y
};

typedef //... criar um tipo de dado Ponto a partir da struct ponto;

struct poligono{
    //criar os campos para armazenar o n�mero de vertices e um ponteiro do tipo Ponto para alocar dinamicamente um vetor de pontos
};

typedef //... criar um tipo de dado Poligono a partir da struct poligono;

int main()
{   //setando o locale para pt-br
    setlocale(LC_ALL,"");
    cout << "Gerador de Pol�gono" << endl;

    Poligono p;

    //lendo o n�mero de v�rtices
    cout << "Digite o n�mero de v�rtices do pol�gono:" << endl;
    cin >> //... leia o n�mero de v�rtices do pol�gono

    //lendo os v�rtices do pol�gono:

    // Passo 1: Alocar dinamicamente um vetor do ponto com n v�rtices e apontar o campo do ponteiro da struct poligono para ele
    // Passo 2: usar um 'for' para ler os campos x e y para cada ponto do vetor de pontos

    //imprimindo o pol�gono:
    cout << "\nPol�gono gerado:" << endl;
    // usar novamente um 'for' para imprimir os campos x e y de cada ponto do vetor de pontos

    return 0; //encerrar programa
}
