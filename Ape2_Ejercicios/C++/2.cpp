#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cuenta {
    string tipo = "Ahorros";
    double saldo = 0.0;
};

struct Cliente {
    string dni;
    Cuenta cuentas[3];
};

void mostrarMenu() {
    cout << "\n--- MENU DE CUENTA ---" << endl;
    cout << "1. Ver atributos (Saldo y Tipo)" << endl;
    cout << "2. Recibir dinero (Deposito)" << endl;
    cout << "3. Enviar dinero (Retiro)" << endl;
    cout << "4. Transferir entre mis cuentas" << endl;
    cout << "5. Salir al menu de seleccion" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Cliente usuario;
    int opcion, numCuenta, destino;
    double monto;

    cout << "Registro de Cliente" << endl;
    cout << "Ingrese Cedula: ";
    cin >> usuario.dni;

    usuario.cuentas[0].tipo = "Sueldo";
    usuario.cuentas[1].tipo = "Ahorros";
    usuario.cuentas[2].tipo = "Inversión";

    while (true) {
        cout << "\nCuentas de Cedula: " << usuario.dni << endl;
        cout << "Seleccione cuenta (1, 2, 3) o 0 para salir del sistema: ";
        cin >> numCuenta;

        if (numCuenta == 0) break;
        if (numCuenta < 1 || numCuenta > 3) {
            cout << "Cuenta no válida." << endl;
            continue;
        }

        int idx = numCuenta - 1;
        bool enCuenta = true;

        while (enCuenta) {
            mostrarMenu();
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "\nTipo: " << usuario.cuentas[idx].tipo << endl;
                    cout << "Saldo: $" << usuario.cuentas[idx].saldo << endl;
                    break;
                case 2:
                    cout << "Monto a recibir: ";
                    cin >> monto;
                    usuario.cuentas[idx].saldo += monto;
                    cout << "Saldo actualizado." << endl;
                    break;
                case 3:
                    cout << "Monto a enviar: ";
                    cin >> monto;
                    if (monto <= usuario.cuentas[idx].saldo) {
                        usuario.cuentas[idx].saldo -= monto;
                        cout << "Envio exitoso." << endl;
                    } else {
                        cout << "Saldo insuficiente." << endl;
                    }
                    break;
                case 4:
                    cout << "Seleccione cuenta destino (1, 2, 3): ";
                    cin >> destino;
                    if (destino >= 1 && destino <= 3 && destino != numCuenta) {
                        cout << "Monto a transferir: ";
                        cin >> monto;
                        if (monto <= usuario.cuentas[idx].saldo) {
                            usuario.cuentas[idx].saldo -= monto;
                            usuario.cuentas[destino-1].saldo += monto;
                            cout << "Transferencia interna exitosa." << endl;
                        } else {
                            cout << "Saldo insuficiente." << endl;
                        }
                    } else {
                        cout << "Destino invalido." << endl;
                    }
                    break;
                case 5:
                    enCuenta = false;
                    break;
                default:
                    cout << "Opción invalida." << endl;
            }
        }
    }

    cout << "Gracias por usar el sistema bancario." << endl;
    return 0;
}
