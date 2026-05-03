#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("productos.txt");

    if (!archivo) {
        cout << "Error: archivo no existe\n";
        return 1;
    }

    string nombre, mayorProducto;
    double precio, subtotal, total = 0, mayor = 0;
    int cantidad;

    while (archivo >> nombre >> precio >> cantidad) {
        subtotal = precio * cantidad;

        cout << "Producto: " << nombre << endl;
        cout << "Subtotal: " << subtotal << endl;
        cout << "----------------------\n";

        total += subtotal;

        if (subtotal > mayor) {
            mayor = subtotal;
            mayorProducto = nombre;
        }
    }

    cout << "TOTAL: " << total << endl;
    cout << "Producto mayor: " << mayorProducto << " (" << mayor << ")" << endl;

    archivo.close();
    return 0;
}
