Algoritmo ejercicio1
		Definir minutosTarde, faltas Como Entero
		Definir credencial, perteneceCurso Como Cadena
		Definir estado, motivo, prioridad Como Cadena
		
		Escribir "===== SISTEMA DE CONTROL DE ACCESO ====="
		
		Escribir "Ingrese los minutos de retraso (0 si llegó puntual): "
		Leer minutosTarde
		
		Escribir "Ingrese el número de faltas acumuladas: "
		Leer faltas
		
		Escribir "¿Tiene credencial? (SI o NO): "
		Leer credencial
		
		Escribir "¿Pertenece al curso? (SI o NO): "
		Leer perteneceCurso
		
		Si credencial = "NO" Entonces
			estado <- "No ingresa"
			motivo <- "No presenta credencial"
			prioridad <- "Alta"
		Sino
			Si perteneceCurso = "NO" Entonces
				estado <- "No ingresa"
				motivo <- "No pertenece al curso"
				prioridad <- "Alta"
			Sino
				Si faltas >= 5 Entonces
					estado <- "No ingresa"
					motivo <- "Demasiadas faltas"
					prioridad <- "Alta"
				Sino
					Si minutosTarde > 10 Entonces
						estado <- "No ingresa"
						motivo <- "Llegada muy tarde"
						prioridad <- "Media"
					Sino
						Si faltas >= 3 Entonces
							estado <- "Ingresa con advertencia"
							motivo <- "Muchas faltas"
							prioridad <- "Media"
						Sino
							Si minutosTarde > 0 Entonces
								estado <- "Ingresa con advertencia"
								motivo <- "Llegada tarde"
								prioridad <- "Baja"
							Sino
								estado <- "Ingresa sin problema"
								motivo <- "Cumple todas las condiciones"
								prioridad <- "Baja"
							FinSi
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
		
		Escribir ""
		Escribir "===== RESULTADO ====="
		Escribir "Estado: ", estado
		Escribir "Motivo: ", motivo
		Escribir "Prioridad: ", prioridad
FinAlgoritmo
