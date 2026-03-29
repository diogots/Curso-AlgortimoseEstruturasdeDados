#include <iostream>
#include "vetor.h"
#include <locale.h>
#include <ctime>   // Para a função time() e clock()
#include <cstdlib> // Para rand() e srand()

using namespace std;

int main()
{   //setlocale("",LC_ALL); //setar codificação de caracteres para pt-BR

    // Inicializa a semente do gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    int *ord, *nord; //ponteiro para vetor ordenado e não-ordenado
    double t_ini, t_fim, tempo_gasto;
    int nbuscas = 1000; //quantidade de buscas na amostra

    //criar vetores com tamanhos escalando de grandeza a cada interação
    for (int t=10; t<=10000000; t=t*10){

        //criar espaço na memória
        ord = criaVetor(t);
        nord = criaVetor(t);

        //EXERCÌCIO 1: inserção no final x inserção ordenada em vetor

 /*
        //inserir não ordenado X inserir ordenado


        t_ini = clock();

        //gerar amostra
        for (int i = 0; i < t; i++) {
            int num = rand();
            insereFim(num,i,nord); //complexidade O(1) => constante
        }

        t_fim = clock();

        // Calcula o tempo em segundos
        tempo_gasto = ((t_fim - t_ini)) / CLOCKS_PER_SEC;

        if(t==10){
            printVetor(t,nord);

        }

        cout << "NORD-"<<t <<" : " << tempo_gasto << "seg" << endl;

        t_ini = clock();

        //gerar amostra
        for (int i = 0; i < t; i++) {
            int num = rand();
            insereOrd(num,i,ord); //complexidade O(n^2) => (quadrática)
        }

        t_fim = clock();

        // Calcula o tempo em segundos
        tempo_gasto = ((t_fim - t_ini)) / CLOCKS_PER_SEC;

        if(t==10){
            printVetor(t,nord);

        }

        cout << "ORD-"<<t <<" : " << tempo_gasto << "seg" << endl;
        cout << "-------------------------------------------------------------\n";

 */

        // EXERCÍCIO 2: Busca sequencial contra Busca Binária + Ordenação

// /*
        //caso queira medir inserção, decomente a linha abaixo
        //t_ini = clock();

        //gerar amostra
        for (int i = 0; i < t; i++) {
            int num = rand();
            insereFim(num,i,nord); //complexidade O(1) = constante
        }

        //definir número buscado
        //int busca = rand(); //achar ou não elemento, aleatoriamente
        int busca = -1; //não achar nunca, gerar PIOR CASO O(n)

        //busca sequencial
        t_ini = clock();
        for(int i=0; i<nbuscas; i++)
            buscaSeq(busca,t,nord); //complexidade O(n) => linear
        t_fim = clock();
        // --- Fim da Medição ---

        // Calcula o tempo em segundos
        tempo_gasto = ((t_fim - t_ini)) / CLOCKS_PER_SEC;

        if(t==10){
            printVetor(t,nord);

        }

        cout << "NORD-"<<t <<" c/ busca seq: " << tempo_gasto << "seg" << endl;

        //busca binária (precisa estar ordenado pra funcionar)
        //quicksort(nord,0,t); //sem medir ordenação
        t_ini = clock();
        quicksort(nord,0,t-1); //complexidade O(n*log(n))
        for(int i=0; i< nbuscas; i++)
            buscabin(busca,t,nord); //complexidade O(log(n)) => logarítmica
        t_fim = clock();
        // --- Fim da Medição ---

        // Calcula o tempo em segundos
        tempo_gasto = ((t_fim - t_ini)) / CLOCKS_PER_SEC;

        if(t==10){
            printVetor(t,nord);

        }

        cout << "ORD-"<<t <<" c/ busca bin: " << tempo_gasto << "seg" << endl;
        cout << "-------------------------------------------------------------\n";

// */

        //libera a memória alocada
        delete[] nord;
        delete[] ord;


    }
}
