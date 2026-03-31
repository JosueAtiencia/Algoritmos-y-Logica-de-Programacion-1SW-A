Algoritmo ControlDeHora
    Definir horas, minutos, segundos Como Entero
    Definir respuesta Como Caracter
    
    Repetir
        Escribir "--- Registro de Hora ---"
        Escribir "Ingrese las horas (0-23):"
        Leer horas
        Escribir "Ingrese los minutos (0-59):"
        Leer minutos
        Escribir "Ingrese los segundos (0-59):"
        Leer segundos
	
        Escribir ""
        Escribir "Hora registrada: ", horas, ":", minutos, ":", segundos
        
        Escribir ""
        Escribir "Desea cambiar la hora (s/n):"
        Leer respuesta
        
    Hasta Que respuesta = "n" O respuesta = "N"
    
    Escribir "Programa finalizado. ¡Hasta luego!"
FinAlgoritmo