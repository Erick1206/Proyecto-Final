#include <iostream>
#include "sistema_ecuaciones.h"
using namespace std;

void mostrarIncognita(int j, int n)
{
    if(n <= 3)
    {
        if(j == 0)
            cout << "x";
        else if(j == 1)
            cout << "y";
        else
            cout << "z";
    }
    else
    {
        cout << "x" << j + 1;
    }
}

void ingresarEcuaciones(float matriz[][11], int n)
{

    for(int i = 0; i < n; i++)
    {
        cout << "Ecuacion " << i + 1 << endl;

        for(int j = 0; j < n; j++)
        {
            cout << "Coeficiente de ";
            mostrarIncognita(j, n);
            cout << ": ";

            cin >> matriz[i][j];
        }

        cout << "Resultado: ";
        cin >> matriz[i][n];
        
        cout <<endl; 
    }
}

void mostrarSistema(float matriz[][11], int n)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // Mostrar signo
            if(j > 0)
            {
                if(matriz[i][j] >= 0)
                    cout << " + ";
                else
                    cout << " - ";
            }

            // Mostrar valor absoluto si es negativo
            if(matriz[i][j] < 0)
                cout << -matriz[i][j];
            else
                cout << matriz[i][j];

            // Mostrar la incógnita
            mostrarIncognita(j, n);
        }

        cout << " = " << matriz[i][n] << endl;
    }
}

void gaussJordan(float matriz[][11], int n)
{
    for(int i = 0; i < n; i++)
    {
        // Si el pivote es cero, buscamos una fila para intercambiar
        if(matriz[i][i] == 0)
        {
            for(int k = i + 1; k < n; k++)
            {
                if(matriz[k][i] != 0)
                {
                    for(int j = 0; j <= n; j++)
                    {
                        float aux = matriz[i][j];
                        matriz[i][j] = matriz[k][j];
                        matriz[k][j] = aux;
                    }

                    break;
                }
            }
        }


        // Convertir el pivote en 1
        float pivote = matriz[i][i];

        if(pivote != 0)
        {
            for(int j = 0; j <= n; j++)
            {
                matriz[i][j] /= pivote;
            }
        }


        // Hacer ceros en la columna del pivote
        for(int k = 0; k < n; k++)
        {
            if(k != i)
            {
                float factor = matriz[k][i];

                for(int j = 0; j <= n; j++)
                {
                    matriz[k][j] -= factor * matriz[i][j];
                }
            }
        }
    }
}

int analizarSolucion(float matriz[][11], int n)
{
    int pivotes = 0;


    for(int i = 0; i < n; i++)
    {
        bool filaCeros = true;


        // Revisamos los coeficientes
        for(int j = 0; j < n; j++)
        {
            if(matriz[i][j] != 0)
            {
                filaCeros = false;
            }
        }


        // Caso: 0 0 0 | numero sin solución
        if(filaCeros && matriz[i][n] != 0)
        {
            return 0; // Sin solución
        }


        // Contamos filas con pivote
        if(!filaCeros)
        {
            pivotes++;
        }
    }


    if(pivotes < n)
    {
        return 2; // Infinitas soluciones
    }


    return 1; // Solución única
}

void mostrarSolucion(float matriz[][11], int n)
{
    cout << "Soluciones:"<<endl;

    for(int i = 0; i < n; i++)
    {
        mostrarIncognita(i,n);
        cout << " = " << matriz[i][n] << endl;
    }
}

