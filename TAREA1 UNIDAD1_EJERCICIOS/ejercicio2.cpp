#include <iostream>
using namespace std;

int main(){

    float promedio, asistencia, ingresos;
    int materias, proyectos;
    string ayuda, razonA, razonE, observacion;

    cout<<"=====================================\n";
    cout<<"        SISTEMA DE BECAS\n";
    cout<<"=====================================\n\n";

    cout<<"Ingrese promedio (0-10): ";
    cin>>promedio;

    cout<<"Ingrese numero de materias perdidas: ";
    cin>>materias;

    cout<<"Ingrese porcentaje de asistencia: ";
    cin>>asistencia;

    cout<<"Ingrese ingresos familiares: ";
    cin>>ingresos;

    cout<<"Participa en proyectos? (1=SI, 0=NO): ";
    cin>>proyectos;
    if(asistencia < 80){
        ayuda="Sin beneficio";
        razonA="Baja asistencia";
    }
    else if(promedio < 7){
        ayuda="Sin beneficio";
        razonA="Promedio bajo";
    }
    else if(promedio >= 9 && asistencia >= 90 && materias == 0){
        ayuda="Beca completa";
        razonA="Alto rendimiento";
    }
    else if(promedio >= 8 && asistencia >= 85){
        ayuda="Beca parcial";
        razonA="Buen rendimiento";
    }
    else{
        ayuda="Ayuda de materiales";
        razonA="Cumple requisitos minimos";
    }
    if(materias > 1 && ayuda == "Beca completa"){
        ayuda="Beca parcial";
    }

    if(proyectos == 1 && ingresos < 500){
        if(ayuda == "Ayuda de materiales"){
            ayuda="Beca parcial";
        }
        else if(ayuda == "Beca parcial" && materias <= 1){
            ayuda="Beca completa";
        }
        razonE="Apoyo por condicion economica y proyectos";
    }
    else{
        razonE="Sin beneficio adicional";
    }

    observacion="Evaluacion completada";

    cout<<"\n========== RESULTADO ==========\n";
    cout<<"Tipo de ayuda: "<<ayuda<<endl;
    cout<<"Razon academica: "<<razonA<<endl;
    cout<<"Razon economica: "<<razonE<<endl;
    cout<<"Observacion: "<<observacion<<endl;

    return 0;
}
