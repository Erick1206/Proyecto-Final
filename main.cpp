#include <iostream>
#include "red_neuronal.h"
#include "sistema_ecuaciones.h"
#include "Ejercicio 5.h"

using namespace std;

int main() {
    int opcion;
    
    // Variables para el Ejercicio 1 (Red Neuronal)
    float w0 = 0.0;
    float b = 0.0;
    bool redEntrenada = false;

    // Variables para el Ejercicio 2 (Sistemas de Ecuaciones)
    int n_ecuaciones;
    float matriz[10][11];

    // Variables para el Ejercicio 3 (Laberinto)
    int laberinto[FILAS][COLUMNAS];

    do {
        cout << "====================================================" << endl;
        cout << "            MENU PRINCIPAL DE EXPOSICION            " << endl;
        cout << "====================================================" << endl;
        cout << "1. EJERCICIO 1: Red Neuronal (Entrenamiento)" << endl;
        cout << "2. EJERCICIO 1: Probar Neurona con dato personalizado" << endl;
        cout << "3. EJERCICIO 2: Sistema de Ecuaciones (Gauss-Jordan)" << endl;
        cout << "4. EJERCICIO 3: Resolucion de Laberinto (Recursividad)" << endl;
        cout << "5. Salir del Programa" << endl;
        cout << "====================================================" << endl;
        cout << "Seleccione una opcion (1-5): ";
        cin >> opcion;

        switch (opcion) {
            case 1: { 
                cout << "\n>>> INICIANDO EJERCICIO 1: ENTRENAMIENTO DE RED NEURONAL" << endl;
                w0 = 0.0; 
                b = 0.0;
                ejecutarRedNeuronal(w0, b);

                cout << endl;
                cout << "--- RESULTADOS FINALES DE LA NEURONA ---" << endl;
                cout << "Peso final w0 (pendiente): " << w0 << endl;
                cout << "Sesgo final b (interseccion): " << b << endl;
                cout << "----------------------------------------" << endl << endl;

                float x[5] = {0, 1, 2, 3, 4};
                float y[5] = {1, 3, 5, 7, 9};
                
                cout << "Evaluando datos de entrenamiento fijos:" << endl;
                for (int i = 0; i < 5; i++) {
                    float a = prediccion(w0, b, x[i]);
                    cout << "x: " << x[i] << " | y real: " << y[i] << " | prediccion: " << a << endl;
                }
                redEntrenada = true;
                cout << endl;
                break;
            } 

            case 2:
                if (!redEntrenada) {
                    cout << "\n[ALERTA] Primero debe entrenar la neurona con la opcion 1." << endl << endl;
                } else {
                    // Llama directamente a la función que está en red_neuronal.cpp
                    hacerPrediccionInteractiva(w0, b);
                }
                break;

            case 3:
                cout << "\n>>> INICIANDO EJERCICIO 2: SISTEMA DE ECUACIONES" << endl;
                cout << "Ingrese el numero de incognitas (1 a 10): ";
                cin >> n_ecuaciones;

                if (n_ecuaciones < 1 || n_ecuaciones > 10) {
                    cout << "[ERROR] Cantidad de incognitas no valida." << endl << endl;
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
                        cout << "El sistema no tiene solucion (Incompatible)." << endl << endl;
                    } else if (resultado == 2) {
                        cout << "El sistema tiene infinitas soluciones (Compatible Indeterminado)." << endl << endl;
                    } else {
                        mostrarSolucion(matriz, n_ecuaciones);
                        cout << endl;
                    }
                }
                break;

            case 4: {
                cout << "\n>>> INICIANDO EJERCICIO 3: RESOLUCION DE LABERINTO" << endl;

                int plantillaLaberinto[FILAS][COLUMNAS] = {
                    {3, 0, 1, 1, 1, 1},
                    {1, 0, 0, 0, 1, 1},
                    {1, 1, 1, 0, 1, 1},
                    {1, 0, 0, 0, 0, 1},
                    {1, 0, 1, 1, 0, 2},
                    {1, 1, 1, 1, 1, 1}
                };

                for (int i = 0; i < FILAS; i++) {
                    for (int j = 0; j < COLUMNAS; j++) {
                        laberinto[i][j] = plantillaLaberinto[i][j];
                    }
                }

                cout << "--- Laberinto Original ---" << endl;
                mostrarLaberinto(laberinto);
                cout << "*(Leyenda: 3 = Inicio, 0 = Camino libre, 1 = Pared, 2 = Salida)*" << endl << endl;

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
                    cout << "Error: No se encontro el punto de inicio (3)." << endl << endl;
                } else {
                    cout << "Buscando ruta de escape desde la posicion [" << inicioX << "][" << inicioY << "]..." << endl;
                    
                    if (resolverLaberinto(laberinto, inicioX, inicioY)) {
                        cout << "\n--- Laberinto Resuelto ---" << endl;
                        mostrarLaberinto(laberinto);
                        cout << "[EXITO] El algoritmo encontro una ruta de escape." << endl << endl;
                    } else {
                        cout << "[FALLO] No existe ninguna ruta posible para salir del laberinto." << endl << endl;
                    }
                }
                break;
            }

            case 5:
                cout << "\nSaliendo del programa. ¡Muchos exitos en la defensa de tu proyecto, Erick!" << endl;
                break;

            default:
                cout << "\n[ERROR] Opcion no valida. Intente nuevamente." << endl << endl;
                break;
        }

    } while (opcion != 5);

    return 0;
}
