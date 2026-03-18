#include <iostream>
using namespace std;

int main(){

    float n1, n2, n3, promedio, asistencia;
    int proyecto, plagio;
    string estado, obsDisciplinaria, obsRendimiento;

    cout<<"=====================================\n";
    cout<<"    SISTEMA DE EVALUACION\n";
    cout<<"=====================================\n\n";

    cout<<"Ingrese nota 1: ";
    cin>>n1;

    cout<<"Ingrese nota 2: ";
    cin>>n2;

    cout<<"Ingrese nota 3: ";
    cin>>n3;

    cout<<"Ingrese porcentaje de asistencia: ";
    cin>>asistencia;

    cout<<"Entrego proyecto final? (1=SI, 0=NO): ";
    cin>>proyecto;

    cout<<"Cometio plagio? (1=SI, 0=NO): ";
    cin>>plagio;

    promedio = (n1 + n2 + n3) / 3;

    estado = "";
    obsDisciplinaria = "Sin observaciones";
    obsRendimiento = "";

    if(plagio == 1){
        estado = "Reprobado";
        obsDisciplinaria = "Sancion por plagio";
    }
    else{

        if(asistencia < 70){
            estado = "Reprobado";
        }
        else{

            if(promedio >= 7 && proyecto == 1){
                estado = "Aprobado";
            }
            else if(promedio >= 5){
                estado = "Recuperacion";
            }
            else{
                estado = "Reprobado";
            }

            if(proyecto == 0 && estado == "Aprobado"){
                estado = "Recuperacion";
            }
        }
    }

    if((n1 == 10 || n2 == 10 || n3 == 10) &&
       ((n1 < 4 && n2 < 4) || (n1 < 4 && n3 < 4) || (n2 < 4 && n3 < 4))){
        obsRendimiento = "Rendimiento irregular";
    }

    if(n1 >= 9 && n2 >= 9 && n3 >= 9 && asistencia >= 95){
        estado = "Aprobado con felicitacion";
    }

    cout<<"\n========== RESULTADOS ==========\n";
    cout<<"Promedio: "<<promedio<<endl;
    cout<<"Estado academico: "<<estado<<endl;
    cout<<"Observacion disciplinaria: "<<obsDisciplinaria<<endl;
    cout<<"Observacion de rendimiento: "<<obsRendimiento<<endl;

    return 0;
}
