#include <iostream>
#include "sistema_ecuaciones.h"
using namespace std;

int main()
{
    int n;
    float matriz[10][11];


    cout << "Ingrese el numero de incognitas: ";
    cin >> n;


    if(n < 1 || n > 10)
    {
        cout << "Cantidad de incognitas no valida";
        return 0;
    }
	
	cout << endl;

    ingresarEcuaciones(matriz,n);
	cout << endl;

    cout << "Sistema ingresado:"<<endl;
    mostrarSistema(matriz,n);
	cout << endl;

    gaussJordan(matriz,n);


    int resultado = analizarSolucion(matriz,n);


    if(resultado == 0)
    {
        cout << "El sistema no tiene solucion";
    }
    else if(resultado == 2)
    {
        cout << "El sistema tiene infinitas soluciones";
    }
    else
    {
        mostrarSolucion(matriz,n);
    }


    return 0;
}

