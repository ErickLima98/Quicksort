#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;
int divide(int v[], int i, int f)
{
    int izq, der, piv, temp;
    izq=i;
    der=f;
    piv=v[i];

    while (izq<der)
    {
        while(v[der]>piv)
        {
            der--;
        }
        while(izq<der && v[izq]<=piv)
         {
             izq++;
         }
        if (izq<der)
            {
                temp=v[izq];
                v[izq]=v[der];
                v[der]=temp;
            }

    }
    temp=v[der];
    v[der]=v[i];
    v[i]=temp;
    return der;
}
void Quicksort(int v[], int i, int f)
{
    int pospivote=0;
    if(i<f)
    {
        pospivote=divide(v, i, f);
        Quicksort(v, i, pospivote-1);//primera recursividad para ordenar los datos del lado izquierdo del vector
        Quicksort(v, pospivote+1, f);//segunda recursividad para ordenar los datos del lado derecho del vector
    }
}
void Mostrar (int v[])
{
    cout<<endl;
    for (int x=0; x<7; x++)
    cout<<v[x]<<" ";
}

int main()
{
    srand(time(NULL));
    int vectores[7];
    for (int x=0; x<7; x++)
    {
        vectores[x]= 10+rand()%(100-10);
        cout<<vectores[x]<<" ";
    }
    Quicksort(vectores, 0, 6);
    Mostrar(vectores);

}
