#include <iostream>
#include "red_neuronal.h"
#include "sistema_ecuaciones.h"
#include "Ejercicio 5.h"

using namespace std;

int main() {
    cout << "EJERCICIO 1: RED NEURONAL" << endl;
    
    float w0 = 0.0;
    float b = 0.0;

    ejecutarRedNeuronal(w0, b);

    cout << endl;
    cout << "--- RESULTADOS FINALES DE LA NEURONA ---" << endl;
    cout << "Peso final w0: " << w0 << endl;
    cout << "Sesgo final b:  " << b << endl;
    cout << endl;

    float x[5] = {0, 1, 2, 3, 4};
    float y[5] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; i++) {
        float a = prediccion(w0, b, x[i]);
        cout << "x: " << x[i] << " | y real: " << y[i] << " | prediccion: " << a << endl;
    }

    cout << endl;
    cout << "EJERCICIO 2: SISTEMA DE ECUACIONES" << endl;
    
    int n_ecuaciones;
    float matriz[10][11];

    cout << "Ingrese el numero de incognitas: ";
    cin >> n_ecuaciones;

    if (n_ecuaciones < 1 || n_ecuaciones > 10) {
        cout << "Cantidad de incognitas no valida" << endl;
    } else {
        cout << endl;
        ingresarEcuaciones(matriz, n_ecuaciones);
        cout << endl;

        cout << "Sistema ingresado:" << endl;
        mostrarSistema(matriz, n_ecuaciones);
        cout << endl;

        gaussJordan(matriz, n_ecuaciones);

        int resultado = analizarSolucion(matriz, n_ecuaciones);

        if (resultado == 0) {
            cout << "El sistema no tiene solucion" << endl;
        } else if (resultado == 2) {
            cout << "El sistema tiene infinitas soluciones" << endl;
        } else {
            mostrarSolucion(matriz, n_ecuaciones);
        }
    }

    cout << endl;
    cout << "EJERCICIO 3: RESOLUCION DE LABERINTO" << endl;

    int laberinto[FILAS][COLUMNAS] = {
        {3, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 2},
        {1, 1, 1, 1, 1, 1}
    };

    cout << "--- Laberinto Original ---" << endl;
    mostrarLaberinto(laberinto);

    int inicioX = -1, inicioY = -1;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (laberinto[i][j] == INICIO) {
                inicioX = i;
                inicioY = j;
                break;
            }
        }
    }

    if (inicioX == -1 || inicioY == -1) {
        cout << "Error: No se encontro el punto de inicio (3)." << endl;
    } else {
        if (resolverLaberinto(laberinto, inicioX, inicioY)) {
            cout << "--- Laberinto Resuelto ---" << endl;
            mostrarLaberinto(laberinto);
            cout << "Solucion encontrada." << endl;
        } else {
            cout << "No existe ruta posible." << endl;
        }
    }

    return 0;
}
