Algoritmo SistemaBancario
    Definir dni Como Caracter
    Definir saldos Como Real
    Definir tipos Como Caracter
    Definir opcion, numCuenta, destino Como Entero
    Definir monto Como Real
    Definir continuarSistema, enCuenta Como Logico
    
    Dimension saldos[3]
    Dimension tipos[3]
    tipos[1] <- "Sueldo"
    tipos[2] <- "Ahorros"
    tipos[3] <- "Inversion"
    saldos[1] <- 0.0
    saldos[2] <- 0.0
    saldos[3] <- 0.0
    
    Escribir "--- Registro de Cliente ---"
    Escribir "Ingrese DNI del cliente:"
    Leer dni
    
    continuarSistema <- Verdadero
    
    Mientras continuarSistema Hacer
        Escribir ""
        Escribir "Cliente DNI: ", dni
        Escribir "Seleccione una cuenta (1, 2, 3) o 0 para salir:"
        Leer numCuenta
        
        Si numCuenta = 0 Entonces
            continuarSistema <- Falso
        Sino
            Si numCuenta < 1 O numCuenta > 3 Entonces
                Escribir "Error: Cuenta no válida."
            Sino
                enCuenta <- Verdadero
                Mientras enCuenta Hacer
                    Escribir ""
                    Escribir "--- MENÚ CUENTA ", tipos[numCuenta], " ---"
                    Escribir "1. Ver atributos (Saldo y Tipo)"
                    Escribir "2. Recibir dinero (Depósito)"
                    Escribir "3. Enviar dinero (Retiro)"
                    Escribir "4. Transferir entre mis cuentas"
                    Escribir "5. Volver al menú principal"
                    Escribir "Seleccione opción:"
                    Leer opcion
                    
                    Segun opcion Hacer
                        1:
                            Escribir "Tipo de cuenta: ", tipos[numCuenta]
                            Escribir "Saldo actual: $", saldos[numCuenta]
                        2:
                            Escribir "Ingrese monto a depositar:"
                            Leer monto
                            saldos[numCuenta] <- saldos[numCuenta] + monto
                            Escribir "Depósito exitoso."
                        3:
                            Escribir "Ingrese monto a retirar:"
                            Leer monto
                            Si monto <= saldos[numCuenta] Entonces
                                saldos[numCuenta] <- saldos[numCuenta] - monto
                                Escribir "Retiro exitoso."
                            Sino
                                Escribir "Error: Saldo insuficiente."
                            FinSi
                        4:
                            Escribir "Seleccione cuenta destino (1, 2, 3):"
                            Leer destino
                            Si destino >= 1 Y destino <= 3 Y destino <> numCuenta Entonces
                                Escribir "Monto a transferir:"
                                Leer monto
                                Si monto <= saldos[numCuenta] Entonces
                                    saldos[numCuenta] <- saldos[numCuenta] - monto
                                    saldos[destino] <- saldos[destino] + monto
                                    Escribir "Transferencia interna completada."
                                Sino
                                    Escribir "Error: Saldo insuficiente."
                                FinSi
                            Sino
                                Escribir "Error: Destino inválido."
                            FinSi
                        5:
                            enCuenta <- Falso
                        De Otro Modo:
                            Escribir "Opción no válida."
                    FinSegun
                FinMientras
            FinSi
        FinSi
    FinMientras
    
    Escribir "Sistema cerrado. Que tenga un buen día."
FinAlgoritmo