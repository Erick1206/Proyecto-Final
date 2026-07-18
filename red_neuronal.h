#ifndef RED_NEURONAL_H
#define RED_NEURONAL_H

// Declaraciones de funciones base
float activacion(float x);
float prediccion(float w0, float b, float x);
float calcularerror(float x[], float y[], int n, float w0, float b);
void calculargradientes(float x[], float y[], int n, float w0, float b, float &grad_w0, float &grad_b);
void ejecutarRedNeuronal(float &w0_final, float &b_final);

// Única declaración de la función interactiva
void hacerPrediccionInteractiva(float w0, float b);

#endif // RED_NEURONAL_H
