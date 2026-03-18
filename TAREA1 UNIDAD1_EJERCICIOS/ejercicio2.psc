Algoritmo ejercicio2
		Definir promedio, asistencia, ingresos Como Real
		Definir materias Como Entero
		Definir proyectos Como Entero
		Definir ayuda, razonA, razonE, observacion Como Cadena
		
		Escribir "===== SISTEMA DE BECAS ====="
		
		Escribir "Ingrese promedio (0-10):"
		Leer promedio
		
		Escribir "Ingrese numero de materias perdidas:"
		Leer materias
		
		Escribir "Ingrese porcentaje de asistencia:"
		Leer asistencia
		
		Escribir "Ingrese ingresos familiares:"
		Leer ingresos
		
		Escribir "Participa en proyectos? (1=SI, 0=NO):"
		Leer proyectos
		Si asistencia < 80 Entonces
			ayuda <- "Sin beneficio"
			razonA <- "Baja asistencia"
		Sino
			Si promedio < 7 Entonces
				ayuda <- "Sin beneficio"
				razonA <- "Promedio bajo"
			Sino
				Si promedio >= 9 Y asistencia >= 90 Y materias = 0 Entonces
					ayuda <- "Beca completa"
					razonA <- "Alto rendimiento"
				Sino
					Si promedio >= 8 Y asistencia >= 85 Entonces
						ayuda <- "Beca parcial"
						razonA <- "Buen rendimiento"
					Sino
						ayuda <- "Ayuda de materiales"
						razonA <- "Cumple requisitos minimos"
					FinSi
				FinSi
			FinSi
		FinSi
		
		Si materias > 1 Y ayuda = "Beca completa" Entonces
			ayuda <- "Beca parcial"
		FinSi
		
		Si proyectos = 1 Y ingresos < 500 Entonces
			Si ayuda = "Ayuda de materiales" Entonces
				ayuda <- "Beca parcial"
			Sino
				Si ayuda = "Beca parcial" Y materias <= 1 Entonces
					ayuda <- "Beca completa"
				FinSi
			FinSi
			razonE <- "Apoyo por condicion economica y proyectos"
		Sino
			razonE <- "Sin beneficio adicional"
		FinSi
		
		observacion <- "Evaluacion completada"
		
		Escribir ""
		Escribir "===== RESULTADO ====="
		Escribir "Tipo de ayuda: ", ayuda
		Escribir "Razon academica: ", razonA
		Escribir "Razon economica: ", razonE
		Escribir "Observacion: ", observacion
FinAlgoritmo
