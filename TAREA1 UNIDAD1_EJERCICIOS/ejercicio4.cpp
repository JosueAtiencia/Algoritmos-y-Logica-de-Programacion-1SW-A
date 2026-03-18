#include <iostream>
using namespace std;

int main(){

    int hojas, tipo, usuario, horario, anillado;
    float precioHoja, subtotal, descuento, recargo, total, costoAnillado;

    cout<<"=====================================\n";
    cout<<"     COPIADORA UNIVERSITARIA\n";
    cout<<"=====================================\n\n";

    cout<<"Ingrese numero de hojas: ";
    cin>>hojas;

    cout<<"Tipo de impresion (1=Blanco/Negro, 2=Color): ";
    cin>>tipo;

    cout<<"Tipo de usuario (1=Estudiante, 2=Docente): ";
    cin>>usuario;

    cout<<"Horario (1=Normal, 2=Nocturno): ";
    cin>>horario;

    cout<<"Desea anillado? (1=SI, 0=NO): ";
    cin>>anillado;

    if(hojas <= 20){
        precioHoja = 0.05;
    }
    else if(hojas <= 100){
        precioHoja = 0.04;
    }
    else{
        precioHoja = 0.03;
    }

    if(tipo == 2){
        precioHoja += 0.05;
    }
    subtotal = hojas * precioHoja;
    descuento = 0;
    if(usuario == 2){
        descuento = subtotal * 0.05;
    }
    else if(usuario == 1 && hojas > 50){
        descuento = subtotal * 0.08;
    }

    recargo = 0;
    if(horario == 2){
        recargo = subtotal * 0.10;
    }

    costoAnillado = 0;
    if(anillado == 1){
        costoAnillado = hojas * 0.02;
        if(hojas > 100){
            costoAnillado *= 0.80;
        }
    }

    total = subtotal - descuento + recargo + costoAnillado;

    cout<<"\n=========== FACTURA ===========\n";
    cout<<"Subtotal impresion: "<<subtotal<<endl;
    cout<<"Descuento aplicado: "<<descuento<<endl;
    cout<<"Recargo: "<<recargo<<endl;
    cout<<"Valor anillado: "<<costoAnillado<<endl;
    cout<<"TOTAL A PAGAR: "<<total<<endl;

    return 0;
}
