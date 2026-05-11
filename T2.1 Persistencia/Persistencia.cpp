#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int opcion;
    string nombre, carrera;
    int edad;
    float promedio;

    //Creacion de un menu

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {
                ofstream archivo("estudiantes.txt", ios::app);//Creacion del archivo .txt

                cin.ignore();

                // Ingreso y validación del nombre
                do {
                    cout << "Ingrese el nombre: ";
                    getline(cin, nombre);

                    if(nombre.empty()) {
                        cout << "Error: El nombre no puede estar vacio.\n";
                    }

                } while(nombre.empty());

                // Ingreso y validación de edad
                do {
                    cout << "Ingrese la edad: ";
                    cin >> edad;

                    if(edad <= 0) {
                        cout << "Error: Edad invalida.\n";
                    }

                } while(edad <= 0);

                cin.ignore();

                // Ingreso y validación de carrera
                do {
                    cout << "Ingrese la carrera: ";
                    getline(cin, carrera);

                    if(carrera.empty()) {
                        cout << "Error: La carrera no puede estar vacia.\n";
                    }

                } while(carrera.empty());

                // Ingreso y validación del promedio
                do {
                    cout << "Ingrese el promedio: ";
                    cin >> promedio;

                    if(promedio < 0 || promedio > 10) {
                        cout << "Error: El promedio debe estar entre 0 y 10.\n";
                    }

                } while(promedio < 0 || promedio > 10);

                // Guardar datos en archivo
                archivo << "Nombre: " << nombre << endl;
                archivo << "Edad: " << edad << endl;
                archivo << "Carrera: " << carrera << endl;
                archivo << "Promedio: " << promedio << endl;
                archivo << "------------------------" << endl;

                //Cierre del archivo

                archivo.close();

                cout << "\nDatos guardados correctamente.\n";
                break;
            }

            case 2:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 2);

    return 0;
}
