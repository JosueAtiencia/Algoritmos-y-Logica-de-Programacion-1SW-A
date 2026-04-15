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

    
    }

    void mostrar(){
        cout << "Cedula: " << cedula << endl;
        cout << "Equipo: " << codigoEquipo << endl;
        cout << "Dias: " << dias << endl;
        cout << "Multa: $" << calcularMulta() << endl;
    }
};

//================= VARIABLES =================
vector<Equipo> equipos;
vector<Prestamo> prestamos;

//================= FUNCIONES GRUPO A =================
void registrarEquipo(){
    string c, n, e;
    cout << "Codigo: "; cin >> c;
    cout << "Nombre: "; cin >> n;
    cout << "Estado (disponible/mantenimiento): "; cin >> e;

    equipos.push_back(Equipo(c,n,e));
}

void mostrarEquipos(){
    for(int i = 0; i < equipos.size(); i++){
        equipos[i].mostrar();
        cout << "-------------------\n";
    }
}

void registrarPrestamo(){
    string ced, cod;
    int dias;

    cout << "Cedula: "; cin >> ced;
    cout << "Codigo equipo: "; cin >> cod;
    cout << "Dias: "; cin >> dias;

    // validacion simple
    bool encontrado = false;
    for(int i = 0; i < equipos.size(); i++){
        if(equipos[i].getCodigo() == cod && equipos[i].getEstado() == "disponible"){
            encontrado = true;
        }
    }

    if(encontrado){
        prestamos.push_back(Prestamo(ced,cod,dias));
        cout << "Prestamo registrado\n";
    } else {
        cout << "Equipo no disponible\n";
    }
}

void mostrarPrestamos(){
    for(int i = 0; i < prestamos.size(); i++){
        prestamos[i].mostrar();
        cout << "-------------------\n";
    }
}

//================= AHORCADO =================
void jugarAhorcado(){
    vector<string> palabras = {
        "laptop", "proyector", "tablet", "robotica",
        "mouse", "teclado", "cable", "disponible",
        "mantenimiento", "prestamo"
    };

    string palabra = palabras[rand() % palabras.size()];
    string progreso(palabra.length(), '_');

    int intentos = 6;
    string letrasUsadas = "";

    while(intentos > 0 && progreso != palabra){
        cout << "\nPalabra: " << progreso << endl;
        cout << "Intentos: " << intentos << endl;
        cout << "Usadas: " << letrasUsadas << endl;

        char letra;
        cout << "Ingrese una letra: ";
        cin >> letra;

        // validar repetidas
        if(letrasUsadas.find(letra) != string::npos){
            cout << "Letra repetida\n";
            continue;
        }

        letrasUsadas += letra;
        bool acierto = false;

        for(int i = 0; i < palabra.length(); i++){
            if(palabra[i] == letra){
                progreso[i] = letra;
                acierto = true;
            }
        }

        if(!acierto){
            intentos--;
        }
    }

    if(progreso == palabra){
        cout << "\nGANASTE! La palabra era: " << palabra << endl;
    } else {
        cout << "\nPERDISTE! Era: " << palabra << endl;
    }
}
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
