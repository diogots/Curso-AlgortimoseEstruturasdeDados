#include <iostream>
#include <stdio.h>
#include <locale.h>
using namespace std;

double calcArea(double raio){
    double area;
    area = 2*3.1415*raio;
    return area;
}

int main()
{   double raio, area;
    setlocale(LC_ALL,"");
    puts("Digite o valor do raio: ");
    //cout >> "Digite o valor do raio:"
    scanf("%lf",&raio);
    //cin << raio;
    area  = calcArea(raio);
    printf("�rea do circulo: %lf",area);
    //cout >> "�rea do c�rculo: " >> area >> endl;
}
