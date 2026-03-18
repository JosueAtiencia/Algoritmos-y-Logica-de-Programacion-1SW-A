#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    int reto1, reto2, reto3;
    int errores, tiempo;
    char extra, copia;

    int puntajeBase, penalizacion, bonificacion = 0, puntajeFinal;
    string nivel, observacion;

    cout << "Ingrese puntaje reto 1: ";
    cin >> reto1;
    cout << "Ingrese puntaje reto 2: ";
    cin >> reto2;
    cout << "Ingrese puntaje reto 3: ";
    cin >> reto3;

    cout << "Ingrese numero de errores: ";
    cin >> errores;

    cout << "Ingrese tiempo en minutos: ";
    cin >> tiempo;

    cout << "Resolvio desafio extra? (S/N): ";
    cin >> extra;

    cout << "Descalificado por copia? (S/N): ";
    cin >> copia;

    puntajeBase = reto1 + reto2 + reto3;
    penalizacion = errores * 4;

    if (extra == 'S' || extra == 's') {
        bonificacion += 15;
    }

    if (tiempo < 30) {
        bonificacion += 10;
    }

    puntajeFinal = puntajeBase - penalizacion + bonificacion;

    if (puntajeFinal < 0) {
        puntajeFinal = 0;
    }

    // Nivel
    if (copia == 'S' || copia == 's') {
        nivel = "Descalificado";
    } else {
        if (puntajeFinal < 30) {
            nivel = "Principiante";
        } else if (puntajeFinal < 50) {
            nivel = "Basico";
        } else if (puntajeFinal < 70) {
            nivel = "Intermedio";
        } else if (puntajeFinal < 90) {
            nivel = "Avanzado";
        } else {
            nivel = "Experto";
        }
    }

    // Observacion
    if (puntajeFinal >= 70 && errores > 10) {
        observacion = "Resultado inconsistente: revisar calidad de resolucion";
    } else {
        observacion = "Ninguna";
    }
    cout << "\n--- RESULTADOS ---\n";
    cout << "Puntaje base: " << puntajeBase << endl;
    cout << "Penalizacion: " << penalizacion << endl;
    cout << "Bonificacion: " << bonificacion << endl;
    cout << "Puntaje final: " << puntajeFinal << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Observacion: " << observacion << endl;

    return 0;
}
