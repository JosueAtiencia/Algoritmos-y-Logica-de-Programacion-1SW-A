#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("estudiantes.txt");

    if (!archivo) {
        cout << "Error: archivo no existe\n";
        return 1;
    }

    string nombre;
    double n1, n2, n3, promedio;
    int total = 0, aprobados = 0;
    double suma = 0;

    while (archivo >> nombre >> n1 >> n2 >> n3) {

        promedio = (n1 + n2 + n3) / 3;

        cout << "Nombre: " << nombre << endl;
        cout << "Promedio: " << promedio << endl;

        //NUEVA CLASIFICACIÓN
        if (promedio >= 9) {
            cout << "Estado: Excelente\n";
            aprobados++;
        }
        else if (promedio >= 7) {
            cout << "Estado: Bueno\n";
            aprobados++;
        }
        else {
            cout << "Estado: Reprobado\n";
        }

        cout << "---------------------\n";

        suma += promedio;
        total++;
    }

    //RESULTADOS FINALES
    if (total > 0) {
        cout << "Total estudiantes: " << total << endl;
        cout << "Total aprobados: " << aprobados << endl;
        cout << "Promedio general: " << suma / total << endl;
    }

    archivo.close();
    return 0;
}
