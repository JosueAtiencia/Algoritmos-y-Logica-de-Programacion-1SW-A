Algoritmo ejercicio3
		Definir a,b,c,h,angulo,area Como Real
		Definir tipoLados, tipoAngulo, mensaje Como Cadena
		Escribir "===== TRIANGULO INTELIGENTE ====="
		Escribir "Ingrese lado A:"
		Leer a
		Escribir "Ingrese lado B:"
		Leer b
		Escribir "Ingrese lado C:"
		Leer c
		Escribir "Ingrese la altura:"
		Leer h
		Escribir "Ingrese el ángulo principal:"
		Leer angulo
		Si a+b <= c O a+c <= b O b+c <= a Entonces
			Escribir "No forma triangulo"
		Sino
			Si a=b Y b=c Entonces
				tipoLados <- "Equilatero"
			Sino
				Si a=b O a=c O b=c Entonces
					tipoLados <- "Isosceles"
				Sino
					tipoLados <- "Escaleno"
				FinSi
			FinSi
			
			Si angulo < 90 Entonces
				tipoAngulo <- "Acutangulo"
			Sino
				Si angulo = 90 Entonces
					tipoAngulo <- "Rectangulo"
				Sino
					tipoAngulo <- "Obtusangulo"
				FinSi
			FinSi
			
			area <- (a * h) / 2
			
			Si h > a O h > b O h > c Entonces
				mensaje <- "Advertencia: altura inconsistente"
			Sino
				mensaje <- "Altura consistente"
			FinSi
			
			Escribir "Valido: SI"
			Escribir "Tipo por lados: ", tipoLados
			Escribir "Tipo por angulo: ", tipoAngulo
			Escribir "Area: ", area
			Escribir mensaje
		FinSi
FinAlgoritmo
