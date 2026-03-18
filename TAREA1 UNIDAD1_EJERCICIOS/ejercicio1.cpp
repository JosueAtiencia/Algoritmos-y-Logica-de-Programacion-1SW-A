#include<iostream>
using namespace std;

int main()
{
    int minutosTarde, faltas;
    string credencial, perteneceCurso;
    string estado, motivo, prioridad;

    cout << "===== SISTEMA DE CONTROL DE ACCESO =====" << endl;
    cout<<"Minutos tarde: " << endl;
    cin>>minutosTarde;

    cout<<"Faltas: " << endl;
    cin>>faltas;

    cout<<"Credencial (SI o NO): " << endl;
    cin>>credencial;

    cout<<"Pertenece (SI o NO): " << endl;
    cin>>perteneceCurso;

    if(credencial== "NO"){
        estado="No ingresa";
        motivo="Sin credencial";
        prioridad="Alta";
    }
    else if(perteneceCurso== "NO"){
        estado="No ingresa";
        motivo="No pertenece";
        prioridad="Alta";
    }
    else if(faltas>=5){
        estado="No ingresa";
        motivo="Faltas";
        prioridad="Alta";
    }
    else if(minutosTarde>10){
        estado="No ingresa";
        motivo="Tarde";
        prioridad="Media";
    }
    else if(faltas>=3){
        estado="Advertencia";
        motivo="Faltas";
        prioridad="Media";
    }
    else if(minutosTarde>0){
        estado="Advertencia";
        motivo="Retraso";
        prioridad="Baja";
    }
    else{
        estado="Correcto";
        motivo="OK";
    }

    cout<<"\nEstado: "<<estado;
    cout<< "\nMotivo: " << motivo;
    cout<<"\nPrioridad: "<<prioridad;

}
