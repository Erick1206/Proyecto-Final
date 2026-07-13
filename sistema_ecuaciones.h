#ifndef SISTEMA_ECUACIONES_H
#define SISTEMA_ECUACIONES_H

void mostrarIncognita(int j, int n);
void ingresarEcuaciones(float matriz[][11], int n);
void mostrarSistema(float matriz[][11], int n);
void gaussJordan(float matriz[][11], int n);
int analizarSolucion(float matriz[][11], int n);
void mostrarSolucion(float matriz[][11], int n);

#endif
