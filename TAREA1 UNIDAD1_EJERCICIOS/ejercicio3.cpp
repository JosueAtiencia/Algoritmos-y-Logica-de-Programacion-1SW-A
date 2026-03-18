#include <iostream>
using namespace std;
int main() {
    float a, b, c, h, angulo, area;
    string tipoLados, tipoAngulo, mensaje;
    cout<<"=====================================\n";
    cout<<"      TRIANGULO INTELIGENTE\n";
    cout<<"=====================================\n\n";
    cout<<"Ingrese lado A: ";
    cin>>a;
    cout<<"Ingrese lado B: ";
    cin>>b;
    cout<<"Ingrese lado C: ";
    cin>>c;
    cout<<"Ingrese la altura: ";
    cin>>h;
    cout<<"Ingrese el angulo principal (en grados): ";
    cin>>angulo;
    if(a + b <= c || a + c <= b || b + c <= a){
        cout<<"\nNo forma un triangulo"<<endl;
        return 0;
    }
    if(a == b && b == c){
        tipoLados = "Equilatero";
    }
    else if(a == b || a == c || b == c){
        tipoLados = "Isosceles";
    }
    else{
        tipoLados = "Escaleno";
    }
    if(angulo < 90){
        tipoAngulo = "Acutangulo";
    }
    else if(angulo == 90){
        tipoAngulo = "Rectangulo";
    }
    else{
        tipoAngulo = "Obtusangulo";
    }
    area = (a * h) / 2;

    if(h > a || h > b || h > c){
        mensaje = "Advertencia: altura inconsistente";
    }
    else{
        mensaje = "Altura consistente";
    }
    cout<<"\n========== RESULTADO ==========\n";
    cout<<"Valido: SI"<<endl;
    cout<<"Tipo por lados: "<<tipoLados<<endl;
    cout<<"Tipo por angulo: "<<tipoAngulo<<endl;
    cout<<"Area: "<<area<<endl;
    cout<<mensaje<<endl;
    return 0;
}
