#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Jean {
    string codigo;
    string color;
    string talla;
    bool fueTenido;
    int cantTenidos;
    double precio;
    int cantBotones;
    int humedad;
    string estadoTela;
};

void mostrarDatos(Jean j) {
    cout << "\n======= DATOS DEL JEAN =======" << endl;
    cout << "Codigo: " << j.codigo << endl;
    cout << "Color: " << j.color << " | Talla: " << j.talla << endl;
    cout << "Precio: $" << fixed << setprecision(2) << j.precio << endl;
    cout << "Botones: " << j.cantBotones << endl;
    cout << "Humedad: " << j.humedad << "%" << endl;
    cout << "Estado de tela: " << j.estadoTela << endl;
    cout << "Fue teñido: " << (j.fueTenido ? "S" : "N") << endl;
    cout << "Cant. teñidos restantes: " << j.cantTenidos << endl;
    cout << "==============================" << endl;
}

void lavar(Jean &j) {
    if (j.cantTenidos > 0) {
        j.cantTenidos--;
        j.humedad = 100;
        j.estadoTela = "Limpia / Humeda";
        cout << "\n[PROCESO] El jean ha sido lavado. El teñido se ha desgastado." << endl;
    } else {
        cout << "\n[AVISO] El jean ya no tiene teñido que perder." << endl;
    }
}

void secar(Jean &j) {
    if (j.humedad > 0) {
        j.humedad = 0;
        j.estadoTela = "Seca / Lista";
        cout << "\n[PROCESO] El jean se ha secado completamente." << endl;
    } else {
        cout << "\n[AVISO] El jean ya esta seco." << endl;
    }
}

int main() {
    Jean miJean;
    int opcion;

    cout << "--- Registro de Nuevo Jean ---" << endl;
    cout << "Código: "; cin >> miJean.codigo;
    cout << "Color: "; cin >> miJean.color;
    cout << "Talla: "; cin >> miJean.talla;
    cout << "Precio: "; cin >> miJean.precio;
    cout << "Cantidad de botones: "; cin >> miJean.cantBotones;
    cout << "Cantidad de teñidos iniciales: "; cin >> miJean.cantTenidos;

    miJean.fueTenido = (miJean.cantTenidos > 0);
    miJean.humedad = 0;
    miJean.estadoTela = "Nuevo";

    do {
        cout << "\n--- MENU DE GESTIÓN ---" << endl;
        cout << "1. Mostrar datos" << endl;
        cout << "2. Lavar jean" << endl;
        cout << "3. Secar jean" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: mostrarDatos(miJean); break;
            case 2: lavar(miJean); break;
            case 3: secar(miJean); break;
            case 4: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
