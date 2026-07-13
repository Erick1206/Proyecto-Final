#ifndef EJERCICIO_5_H
#define EJERCICIO_5_H

#include <iostream>

using namespace std;

const int FILAS = 6;
const int COLUMNAS = 6;

const int PARED = 1;
const int CAMINO = 0;
const int SALIDA = 2;
const int INICIO = 3;

void mostrarLaberinto(int laberinto[FILAS][COLUMNAS]);
bool resolverLaberinto(int laberinto[FILAS][COLUMNAS], int x, int y);

#endif
