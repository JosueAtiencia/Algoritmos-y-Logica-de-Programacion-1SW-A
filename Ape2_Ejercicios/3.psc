Algoritmo GestionDeJean
    Definir codigo, color, talla, estadoTela Como Caracter
    Definir fueTenido Como Logico
    Definir cantTenidos, cantBotones, humedad, opcion Como Entero
    Definir precio Como Real
    
    Escribir "--- Registro de Nuevo Jean ---"
    Escribir "Ingrese Código:"
    Leer codigo
    Escribir "Ingrese Color:"
    Leer color
    Escribir "Ingrese Talla:"
    Leer talla
    Escribir "Ingrese Precio:"
    Leer precio
    Escribir "Ingrese Cantidad de Botones:"
    Leer cantBotones
    Escribir "Ingrese Cantidad de Teñidos iniciales:"
    Leer cantTenidos
    
    Si cantTenidos > 0 Entonces
        fueTenido <- Verdadero
    Sino
        fueTenido <- Falso
    FinSi
    
    humedad <- 0 
    estadoTela <- "Nuevo"
    
    Repetir
        Escribir ""
        Escribir "--- MENÚ DE GESTIÓN DE JEAN ---"
        Escribir "1. Mostrar Datos"
        Escribir "2. Lavar Jean (Disminuye teñido / Aumenta humedad)"
        Escribir "3. Secar Jean (Disminuye humedad)"
        Escribir "4. Salir"
        Escribir "Seleccione una opción:"
        Leer opcion
        
        Segun opcion Hacer
            1:
                Escribir ""
                Escribir "======= DATOS DEL JEAN ======="
                Escribir "Código: ", codigo
                Escribir "Color: ", color, " | Talla: ", talla
                Escribir "Precio: $", precio
                Escribir "Botones: ", cantBotones
                Escribir "Humedad: ", humedad, "%"
                Escribir "Estado: ", estadoTela
                Si fueTenido Entonces
                    Escribir "Teñidos restantes: ", cantTenidos
                Sino
                    Escribir "El jean no es teñido."
                FinSi
                Escribir "=============================="
            2:
                Si cantTenidos > 0 Entonces
                    cantTenidos <- cantTenidos - 1
                    humedad <- 100
                    estadoTela <- "Limpio y Húmedo"
                    Escribir "[PROCESO] Lavado completado. Se desgastó el teñido."
                Sino
                    humedad <- 100
                    estadoTela <- "Limpio y Húmedo"
                    Escribir "[AVISO] Lavado, pero ya no tiene teñido original."
                FinSi
            3:
                Si humedad > 0 Entonces
                    humedad <- 0
                    estadoTela <- "Seco / Listo"
                    Escribir "[PROCESO] El jean se ha secado."
                Sino
                    Escribir "[AVISO] El jean ya se encuentra seco."
                FinSi
            4:
                Escribir "Saliendo del sistema de fábrica..."
            De Otro Modo:
                Escribir "Opción no válida."
        FinSegun
        
    Hasta Que opcion = 4
 FinAlgoritmo
