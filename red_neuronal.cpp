#include <iostream>
#include "red_neuronal.h"
using namespace std;

float activacion(float x) {
    return x;
}

float prediccion(float w0, float b, float x) {
    return activacion(w0 * x + b);
}

float calcularerror(float x[], float y[], int n, float w0, float b) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        float a = prediccion(w0, b, x[i]);
        suma = suma + (a - y[i]) * (a - y[i]);
    }
    return suma / n;
}

void calculargradientes(float x[], float y[], int n, float w0, float b, float &grad_w0, float &grad_b) {
    float suma_w0 = 0;
    float suma_b = 0;
    for (int i = 0; i < n; i++) {
        float a = prediccion(w0, b, x[i]);
        suma_w0 = suma_w0 + (a - y[i]) * x[i];
        suma_b = suma_b + (a - y[i]);
    }
    grad_w0 = (2.0 / n) * suma_w0;
    grad_b = (2.0 / n) * suma_b;
}

void ejecutarRedNeuronal(float &w0_final, float &b_final) {
    float x[5] = {0, 1, 2, 3, 4};
    float y[5] = {1, 3, 5, 7, 9};
    int n = 5;

    float w0 = 1.0;
    float b = 0.0; 
    float tasaaprendizaje = 0.01;
    int epocas = 1000;

    for (int i = 0; i < epocas; i++) {
        float grad_w0 = 0, grad_b = 0;
        
        calculargradientes(x, y, n, w0, b, grad_w0, grad_b);
        
        w0 = w0 - tasaaprendizaje * grad_w0;
        b = b - tasaaprendizaje * grad_b;

        if (i % 100 == 0) {
            float error = calcularerror(x, y, n, w0, b);
            cout << "epoca: " << i << " w0: " << w0 << " b: " << b << " mse: " << error << endl;
        }
    }

    w0_final = w0;
    b_final = b;
    
}
