#include "Ejercicio 5.h"

void mostrarLaberinto(int laberinto[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool resolverLaberinto(int laberinto[FILAS][COLUMNAS], int x, int y) {

    if (x < 0 || x >= FILAS || y < 0 || y >= COLUMNAS) {
        return false;
    }

    if (laberinto[x][y] == SALIDA) {
        return true;
    }

    if (laberinto[x][y] != CAMINO && laberinto[x][y] != INICIO) {
        return false;
    }

    int estadoOriginal = laberinto[x][y];

    laberinto[x][y] = INICIO;

    if (resolverLaberinto(laberinto, x + 1, y)) return true; 
    if (resolverLaberinto(laberinto, x, y + 1)) return true; 
    if (resolverLaberinto(laberinto, x - 1, y)) return true; 
    if (resolverLaberinto(laberinto, x, y - 1)) return true; 

    laberinto[x][y] = estadoOriginal; 
    return false;
}
