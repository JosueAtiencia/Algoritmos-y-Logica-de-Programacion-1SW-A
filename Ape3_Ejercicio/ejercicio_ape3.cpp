#include <iostream>
using namespace std;

int main() {
    char repetir;

    do {
        int n;

        // Validar N
        do {
            cout << "Ingrese el numero de estudiantes: ";
            cin >> n;
        } while(n <= 0);

        // Variables acumuladoras
        int contA = 0, contB = 0, contC = 0;
        int excelente = 0, muyBueno = 0, bueno = 0, riesgo = 0, reprobado = 0;
        int reprobAsistencia = 0, reprobNota = 0;
        int estable = 0, inestable = 0, aprobados = 0;

        float sumaGeneral = 0;
        float sumaA = 0, sumaB = 0, sumaC = 0;

        float mayorProm = -1, menorProm = 11;
        string mejorEst, peorEst;

        for(int i = 0; i < n; i++) {
            string nombre;
            char paralelo;
            float n1, n2, practicas, asistencia;

            cout << "\nEstudiante " << i + 1 << endl;

            cout << "Nombre: ";
            cin >> nombre;

            // Validar paralelo
            do {
                cout << "Paralelo (A/B/C): ";
                cin >> paralelo;
            } while(paralelo != 'A' && paralelo != 'B' && paralelo != 'C');

            // Validar notas
            do {
                cout << "Nota 1: ";
                cin >> n1;
            } while(n1 < 0 || n1 > 10);

            do {
                cout << "Nota 2: ";
                cin >> n2;
            } while(n2 < 0 || n2 > 10);

            do {
                cout << "Practicas: ";
                cin >> practicas;
            } while(practicas < 0 || practicas > 10);

            // Validar asistencia
            do {
                cout << "Asistencia (%): ";
                cin >> asistencia;
            } while(asistencia < 0 || asistencia > 100);

            // Promedio
            float promedio = n1 * 0.3 + n2 * 0.3 + practicas * 0.4;
            sumaGeneral += promedio;

            // Contar por paralelo
            if(paralelo == 'A') { contA++; sumaA += promedio; }
            if(paralelo == 'B') { contB++; sumaB += promedio; }
            if(paralelo == 'C') { contC++; sumaC += promedio; }

            // Mayor y menor
            if(promedio > mayorProm) {
                mayorProm = promedio;
                mejorEst = nombre;
            }

            if(promedio < menorProm) {
                menorProm = promedio;
                peorEst = nombre;
            }

            // Clasificación
            string estado;

            if(asistencia < 70) {
                estado = "Reprobado por asistencia";
                reprobAsistencia++;
            } else {
                if(promedio >= 9) { excelente++; estado = "Excelente"; }
                else if(promedio >= 8) { muyBueno++; estado = "Muy bueno"; }
                else if(promedio >= 7) { bueno++; estado = "Bueno"; }
                else if(promedio >= 6) { riesgo++; estado = "En riesgo"; }
                else { reprobado++; estado = "Reprobado"; reprobNota++; }
            }

            // Aprobados
            if(promedio >= 7 && asistencia >= 70) {
                aprobados++;
            }

            // Estable / inestable
            float mayorNota = max(n1, max(n2, practicas));
            float menorNota = min(n1, min(n2, practicas));

            if(n1 == n2 && n2 == practicas) {
                estable++;
                cout << "Rendimiento: Estable\n";
            }

            if(mayorNota - menorNota > 4) {
                inestable++;
                cout << "Rendimiento: Inestable\n";
            }

            // Alerta
            if(promedio >= 9 && asistencia < 80) {
                cout << "Alerta: Alto promedio con baja asistencia\n";
            }

            cout << "Promedio: " << promedio << " -> " << estado << endl;
        }

        // Reporte
        cout << "\n===== REPORTE GENERAL =====\n";
        cout << "Total estudiantes: " << n << endl;
        cout << "Paralelo A: " << contA << " | B: " << contB << " | C: " << contC << endl;

        cout << "\nCategorias:\n";
        cout << "Excelente: " << excelente << endl;
        cout << "Muy bueno: " << muyBueno << endl;
        cout << "Bueno: " << bueno << endl;
        cout << "En riesgo: " << riesgo << endl;
        cout << "Reprobados: " << reprobado << endl;

        cout << "\nReprobados por nota: " << reprobNota << endl;
        cout << "Reprobados por asistencia: " << reprobAsistencia << endl;

        cout << "\nPromedio general: " << sumaGeneral / n << endl;

        if(contA > 0) cout << "Promedio A: " << sumaA / contA << endl;
        if(contB > 0) cout << "Promedio B: " << sumaB / contB << endl;
        if(contC > 0) cout << "Promedio C: " << sumaC / contC << endl;

        cout << "\nMejor estudiante: " << mejorEst << " (" << mayorProm << ")\n";
        cout << "Peor estudiante: " << peorEst << " (" << menorProm << ")\n";

        cout << "\n% Aprobados: " << (aprobados * 100.0 / n) << "%" << endl;
        cout << "% Estables: " << (estable * 100.0 / n) << "%" << endl;
        cout << "% Inestables: " << (inestable * 100.0 / n) << "%" << endl;

        // Repetir
        cout << "\nDesea repetir el proceso? (s/n): ";
        cin >> repetir;

    } while(repetir == 's' || repetir == 'S');

    return 0;
}
