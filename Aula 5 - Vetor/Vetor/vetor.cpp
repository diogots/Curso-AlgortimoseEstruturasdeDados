#include <iostream>
using namespace std;

int* criarVetor(int tam){
    int *vet;
    vet = new int[tam];
    cout << "vetor criado com sucesso!" << endl;
    return vet;

}


