#include <iostream>
using namespace std;

int main(){

    int estudiantes, dias, transporte, alimentacion, descuentoInst, coordinador;
    float costoHospedajeDia;
    float costoTransporte, costoHospedaje, costoAlimentacion;
    float total, descuento, totalFinal, costoPorEstudiante;

    cout<<"=====================================\n";
    cout<<"     PLANIFICADOR DE VIAJE\n";
    cout<<"=====================================\n\n";

    cout<<"Numero de estudiantes: ";
    cin>>estudiantes;

    cout<<"Tipo de transporte (1=Bus, 2=Avion): ";
    cin>>transporte;

    cout<<"Numero de dias: ";
    cin>>dias;

    cout<<"Costo de hospedaje por dia: ";
    cin>>costoHospedajeDia;

    cout<<"Incluye alimentacion? (1=SI, 0=NO): ";
    cin>>alimentacion;

    cout<<"Aplica descuento institucional? (1=SI, 0=NO): ";
    cin>>descuentoInst;

    cout<<"Hay coordinador gratis? (1=SI, 0=NO): ";
    cin>>coordinador;

    if(transporte == 1){
        costoTransporte = 50;
    } else {
        costoTransporte = 120;
    }

    if(estudiantes > 20){
        costoTransporte *= 0.80;
    }

    if(coordinador == 1){
        costoTransporte *= (estudiantes - 1);
    } else {
        costoTransporte *= estudiantes;
    }

    costoHospedaje = estudiantes * dias * costoHospedajeDia;

    if(dias > 3){
        costoHospedaje *= 0.90;
    }

    costoAlimentacion = 0;
    if(alimentacion == 1){
        costoAlimentacion = estudiantes * dias * 10;
    }

    total = costoTransporte + costoHospedaje + costoAlimentacion;

    descuento = 0;
    if(descuentoInst == 1 && total > 1000){
        descuento = total * 0.10;
    }

    totalFinal = total - descuento;

    costoPorEstudiante = totalFinal / estudiantes;

    cout<<"\n========== RESULTADOS ==========\n";
    cout<<"Costo transporte: "<<costoTransporte<<endl;
    cout<<"Costo hospedaje: "<<costoHospedaje<<endl;
    cout<<"Costo alimentacion: "<<costoAlimentacion<<endl;
    cout<<"Descuento: "<<descuento<<endl;
    cout<<"Total general: "<<totalFinal<<endl;
    cout<<"Costo por estudiante: "<<costoPorEstudiante<<endl;

    if(costoPorEstudiante > 200){
        cout<<"Recomendacion: Viaje no recomendable"<<endl;
    } else {
        cout<<"Recomendacion: Viaje recomendado"<<endl;
    }

    return 0;
}
