#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int monto, saldo;
    int b20, b10, b5, b1;
    int e20=0, e10=0, e5=0, e1=0;
    int restante, efectivoTotal;

    cout<<"=====================================\n";
    cout<<"        CAJERO AUTOMATICO\n";
    cout<<"=====================================\n\n";

    cout<<"Ingrese saldo disponible: ";
    cin>>saldo;

    cout<<"Cantidad de billetes de 20: ";
    cin>>b20;

    cout<<"Cantidad de billetes de 10: ";
    cin>>b10;

    cout<<"Cantidad de billetes de 5: ";
    cin>>b5;

    cout<<"Cantidad de billetes de 1: ";
    cin>>b1;

    cout<<"Ingrese monto a retirar: ";
    cin>>monto;

    if(monto <= 0){
        cout<<"Monto invalido"<<endl;
        return 0;
    }
    efectivoTotal = b20*20 + b10*10 + b5*5 + b1;
    if(monto > saldo || monto > efectivoTotal){
        cout<<"No se puede realizar la operacion"<<endl;
        return 0;
    }
    restante = monto;

    e20 = min(restante / 20, b20);
    restante -= e20 * 20;

    e10 = min(restante / 10, b10);
    restante -= e10 * 10;

    e5 = min(restante / 5, b5);
    restante -= e5 * 5;

    e1 = min(restante, b1);
    restante -= e1;

    if(restante != 0){
        cout<<"No es posible entregar el monto exacto"<<endl;
    }
    else{
        saldo -= monto;
        b20 -= e20;
        b10 -= e10;
        b5 -= e5;
        b1 -= e1;

        cout<<"\n========== ENTREGA ==========\n";
        cout<<"Billetes de 20: "<<e20<<endl;
        cout<<"Billetes de 10: "<<e10<<endl;
        cout<<"Billetes de 5: "<<e5<<endl;
        cout<<"Billetes de 1: "<<e1<<endl;

        cout<<"Saldo restante: "<<saldo<<endl;

        efectivoTotal = b20*20 + b10*10 + b5*5 + b1;
        cout<<"Efectivo restante en cajero: "<<efectivoTotal<<endl;
    }

    return 0;
}
