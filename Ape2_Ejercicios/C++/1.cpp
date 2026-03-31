#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Tiempo {
    int hora;
    int minutos;
    int segundos;
};

void validarTiempo(Tiempo &t) {
    if (t.hora < 0 || t.hora > 23) t.hora = 0;
    if (t.minutos < 0 || t.minutos > 59) t.minutos = 0;
    if (t.segundos < 0 || t.segundos > 59) t.segundos = 0;
}

int main() {
    Tiempo miHora;
    char respuesta;
    bool continuar = true;

    while (continuar) {
        cout << "\n--- Registro de Hora ---" << endl;
        cout << "Ingrese la hora (0-23): ";
        cin >> miHora.hora;
        cout << "Ingrese los minutos (0-59): ";
        cin >> miHora.minutos;
        cout << "Ingrese los segundos (0-59): ";
        cin >> miHora.segundos;

        validarTiempo(miHora);

        cout << "\nHora registrada: ";
        cout << setfill('0') << setw(2) << miHora.hora << ":"
             << setfill('0') << setw(2) << miHora.minutos << ":"
             << setfill('0') << setw(2) << miHora.segundos << endl;

        cout << "\nDesea cambiar la hora (s/n): ";
        cin >> respuesta;

        if (respuesta == 'n' || respuesta == 'N') {
            continuar = false;
            cout << "Programa finalizado." << endl;
        }
    }
    return 0;
}
