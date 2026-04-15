Algoritmo SistemaLaboratorio

    Dimension codigosEq[100], nombresEq[100], estadosEq[100]
    Dimension cedulasP[100], codigosP[100], diasP[100]
    
    numEquipos <- 0
    numPrestamos <- 0
    opcionPrincipal <- -1
    
    Repetir
        Escribir ""
        Escribir "===== MENU PRINCIPAL ====="
        Escribir "1. Sistema Grupo A (Prestamos)"
        Escribir "2. Jugar Ahorcado"
        Escribir "0. Salir"
        Escribir "Seleccione una opcion:"
        Leer opcionPrincipal
        
        Segun opcionPrincipal Hacer
            1: 
                MenuGrupoA(codigosEq, nombresEq, estadosEq, numEquipos, cedulasP, codigosP, diasP, numPrestamos)
            2: 
                EjecutarAhorcado
            0:
                Escribir "Saliendo del sistema..."
        FinSegun
    Hasta Que opcionPrincipal = 0
FinAlgoritmo

SubProceso MenuGrupoA(cEq, nEq, eEq, numEq POR REFERENCIA, cP, codP, dP, numP POR REFERENCIA)
    Definir opSub, i, d, j Como Entero
    Definir ced, cod Como Caracter
    Definir encontrado Como Logico
    Definir multa Como Real
    
    Repetir
        Escribir ""
        Escribir "--- SISTEMA LABORATORIO ---"
        Escribir "1. Registrar equipo"
        Escribir "2. Mostrar equipos"
        Escribir "3. Registrar prestamo"
        Escribir "4. Mostrar prestamos"
        Escribir "0. Volver"
        Leer opSub
        
        Segun opSub Hacer
            1: 
                numEq <- numEq + 1
                Escribir "Codigo: "; Leer cEq[numEq]
                Escribir "Nombre: "; Leer nEq[numEq]
                Escribir "Estado (disponible/mantenimiento): "; Leer eEq[numEq]
            2:
                Si numEq = 0 Entonces
                    Escribir "No hay equipos registrados."
                SiNo
                    Para i <- 1 Hasta numEq Hacer
                        Escribir "Equipo ", i, ":"
                        Escribir "  Codigo: ", cEq[i]
                        Escribir "  Nombre: ", nEq[i]
                        Escribir "  Estado: ", eEq[i]
                    FinPara
                FinSi
            3:
                Escribir "Cedula: "; Leer ced
                Escribir "Codigo equipo: "; Leer cod
                Escribir "Dias: "; Leer d
                
                encontrado <- Falso
                Para i <- 1 Hasta numEq Hacer
                    Si cEq[i] = cod Y eEq[i] = "disponible" Entonces
                        encontrado <- Verdadero
                    FinSi
                FinPara
                
                Si encontrado Entonces
                    numP <- numP + 1
                    cP[numP] <- ced
                    codP[numP] <- cod
                    dP[numP] <- d
                    Escribir "Prestamo registrado con exito."
                SiNo
                    Escribir "Error: Equipo no encontrado o no disponible."
                FinSi
            4:
                Para i <- 1 Hasta numP Hacer
                    multa <- 0
                    Si dP[i] >= 1 Entonces
                        multa <- 1.25
                        Para j <- 2 Hasta dP[i] Hacer
                            multa <- multa + 0.75
                        FinPara
                    FinSi
                    Escribir "Cedula: ", cP[i], " | Equipo: ", codP[i], " | Dias: ", dP[i], " | Multa: $", multa
                FinPara
        FinSegun
    Hasta Que opSub = 0
FinSubProceso

SubProceso EjecutarAhorcado
    Dimension palabras[10]
    palabras[1]<-"laptop"; palabras[2]<-"proyector"; palabras[3]<-"tablet"
    palabras[4]<-"robotica"; palabras[5]<-"mouse"; palabras[6]<-"teclado"
    palabras[7]<-"cable"; palabras[8]<-"disponible"; palabras[9]<-"mantenimiento"
    palabras[10]<-"prestamo"
    
    palabraElegida <- palabras[Azar(10)+1]
    progreso <- ""
    Para i<-1 Hasta Longitud(palabraElegida) Hacer
        progreso <- progreso + "_"
    FinPara
    
    intentos <- 6
    letrasUsadas <- ""
    
    Mientras intentos > 0 Y progreso <> palabraElegida Hacer
        Escribir "Palabra: ", progreso
        Escribir "Intentos restantes: ", intentos
        Escribir "Letras usadas: ", letrasUsadas
        Escribir "Ingrese una letra:"
        Leer l
        
        acierto <- Falso
        Para i<-1 Hasta Longitud(palabraElegida) Hacer
            Si Subcadena(palabraElegida,i,i) = l Entonces

                nueva_cadena <- ""
                Para k<-1 Hasta Longitud(palabraElegida) Hacer
                    Si k = i Entonces
                        nueva_cadena <- nueva_cadena + l
                    SiNo
                        nueva_cadena <- nueva_cadena + Subcadena(progreso,k,k)
                    FinSi
                FinPara
                progreso <- nueva_cadena
                acierto <- Verdadero
            FinSi
        FinPara
        
        Si No acierto Entonces
            intentos <- intentos - 1
        FinSi
        letrasUsadas <- letrasUsadas + l + " "
    FinMientras
    
    Si progreso = palabraElegida Entonces
        Escribir "¡GANASTE! La palabra era: ", palabraElegida
    SiNo
        Escribir "PERDISTE. La palabra era: ", palabraElegida
    FinSi
FinSubProceso