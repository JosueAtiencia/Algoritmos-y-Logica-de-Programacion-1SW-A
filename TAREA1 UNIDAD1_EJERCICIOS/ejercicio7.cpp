#include <iostream>
using namespace std;

int main(){

    float lecturaAnterior, lecturaActual, consumo;
    int tipoVivienda, habitantes, altoConsumo, deuda;
    float precio, costoBase, totalFinal, subsidio, recargo;
    float consumoPorPersona;

    cout<<"=====================================\n";
    cout<<"      SISTEMA ELECTRICO\n";
    cout<<"=====================================\n\n";

    cout<<"Ingrese lectura anterior: ";
    cin>>lecturaAnterior;

    cout<<"Ingrese lectura actual: ";
    cin>>lecturaActual;

    cout<<"Tipo de vivienda (1=Social, 2=Normal): ";
    cin>>tipoVivienda;

    cout<<"Numero de habitantes: ";
    cin>>habitantes;

    cout<<"Tiene artefactos de alto consumo? (1=SI, 0=NO): ";
    cin>>altoConsumo;

    cout<<"Tiene deuda anterior? (1=SI, 0=NO): ";
    cin>>deuda;

    if(lecturaActual < lecturaAnterior){
        cout<<"Error: lectura invalida"<<endl;
        return 0;
    }

    consumo = lecturaActual - lecturaAnterior;

    if(consumo <= 100){
        precio = 0.10;
    }
    else if(consumo <= 300){
        precio = 0.15;
    }
    else{
        precio = 0.20;
    }

    costoBase = consumo * precio;

    subsidio = 0;
    recargo = 0;

    if(tipoVivienda == 1 && consumo < 80){
        subsidio = costoBase * 0.20;
    }

    if(deuda == 1){
        recargo = costoBase * 0.10;
    }

    totalFinal = costoBase - subsidio + recargo;

    consumoPorPersona = consumo / habitantes;

    cout<<"\n========== RESULTADOS ==========\n";
    cout<<"Consumo total: "<<consumo<<endl;
    cout<<"Costo base: "<<costoBase<<endl;
    cout<<"Subsidio: "<<subsidio<<endl;
    cout<<"Recargo: "<<recargo<<endl;
    cout<<"Total final: "<<totalFinal<<endl;

    if(consumoPorPersona > 100){
        cout<<"ALERTA: Consumo excesivo por habitante"<<endl;
    }

    if(altoConsumo == 1 && consumo > 300){
        cout<<"RIESGO: Posible sobrefacturacion"<<endl;
    }

    return 0;
}
