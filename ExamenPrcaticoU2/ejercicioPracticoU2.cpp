#include <iostream>
#include <vector>
#include <string>
using namespace std;

//================= CLASE EQUIPO =================
class Equipo {
private:
    string codigo, nombre, estado;

public:
    Equipo(string c, string n, string e){
        codigo = c;
        nombre = n;
        estado = e;
    }

    string getCodigo(){ return codigo; }
    string getNombre(){ return nombre; }
    string getEstado(){ return estado; }

    void mostrar(){
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Estado: " << estado << endl;
    }
};

//================= CLASE PRESTAMO =================
class Prestamo {
private:
    string cedula;
    string codigoEquipo;
    int dias;

public:
    Prestamo(string c, string cod, int d){
        cedula = c;
        codigoEquipo = cod;
        dias = d;
    }

    double calcularMulta(){
        double multa = 0;

        if(dias >= 1){
            multa = 1.25;
        }

        for(int i = 2; i <= dias; i++){
            multa += 0.75;
        }

        return multa;
    }

    void mostrar(){
        cout << "Cedula: " << cedula << endl;
        cout << "Equipo: " << codigoEquipo << endl;
        cout << "Dias: " << dias << endl;
        cout << "Multa: $" << calcularMulta() << endl;
    }
};


//================= MENU GRUPO A =================
void menuGrupoA(){
    int op;
    do{
        cout << "\n--- SISTEMA LABORATORIO ---\n";
        cout << "1. Registrar equipo\n";
        cout << "2. Mostrar equipos\n";
        cout << "3. Registrar prestamo\n";
        cout << "4. Mostrar prestamos\n";
        cout << "0. Volver\n";
        cin >> op;

        switch(op){
            case 1: registrarEquipo(); break;
            case 2: mostrarEquipos(); break;
            case 3: registrarPrestamo(); break;
            case 4: mostrarPrestamos(); break;
        }

    }while(op != 0);
}

//================= MENU PRINCIPAL =================
int main(){
    int op;

    do{
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Sistema Grupo A (Prestamos)\n";
        cout << "2. Jugar Ahorcado\n";
        cout << "0. Salir\n";
        cin >> op;

        switch(op){
            case 1: menuGrupoA(); break;
            case 2: jugarAhorcado(); break;
        }

    }while(op != 0);

    return 0;
}
