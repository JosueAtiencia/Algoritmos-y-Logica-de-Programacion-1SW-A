Proceso EvaluacionEstudiante
	Definir n1, n2, n3, promedio Como Real
	Definir asistencia Como Real
	Definir proyecto, plagio Como Entero
	Definir estado, obsDisciplinaria, obsRendimiento Como Cadena
	Escribir "===== SISTEMA DE EVALUACION ====="
	Escribir "Ingrese nota 1:"
	Leer n1
	Escribir "Ingrese nota 2:"
	Leer n2
	Escribir "Ingrese nota 3:"
	Leer n3
	Escribir "Ingrese porcentaje de asistencia:"
	Leer asistencia
	Escribir "Entrego proyecto final? (1=SI, 0=NO):"
	Leer proyecto
	Escribir "Cometio plagio? (1=SI, 0=NO):"
	Leer plagio
	promedio <- (n1 + n2 + n3) / 3
	estado <- ""
	obsDisciplinaria <- "Sin observaciones"
	obsRendimiento <- ""

	Si plagio = 1 Entonces
		estado <- "Reprobado"
		obsDisciplinaria <- "Sancion por plagio"
	Sino
		
		Si asistencia < 70 Entonces
			estado <- "Reprobado"
		Sino
			
			Si promedio >= 7 Y proyecto = 1 Entonces
				estado <- "Aprobado"
			Sino
				Si promedio >= 5 Entonces
					estado <- "Recuperacion"
				Sino
					estado <- "Reprobado"
				FinSi
			FinSi
			
			Si proyecto = 0 Y estado = "Aprobado" Entonces
				estado <- "Recuperacion"
			FinSi
		FinSi
	FinSi

	Si (n1 = 10 O n2 = 10 O n3 = 10) Y ((n1 < 4 Y n2 < 4) O (n1 < 4 Y n3 < 4) O (n2 < 4 Y n3 < 4)) Entonces
		obsRendimiento <- "Rendimiento irregular"
	FinSi

	Si n1 >= 9 Y n2 >= 9 Y n3 >= 9 Y asistencia >= 95 Entonces
		estado <- "Aprobado con felicitacion"
	FinSi
	Escribir ""
	Escribir "===== RESULTADOS ====="
	Escribir "Promedio: ", promedio
	Escribir "Estado academico: ", estado
	Escribir "Observacion disciplinaria: ", obsDisciplinaria
	Escribir "Observacion de rendimiento: ", obsRendimiento	
FinProceso