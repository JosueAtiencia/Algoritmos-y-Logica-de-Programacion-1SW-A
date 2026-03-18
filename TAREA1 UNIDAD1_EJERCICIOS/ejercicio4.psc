Algoritmo ejercicio4
		Definir hojas Como Entero
		Definir tipo, usuario, horario, anillado Como Entero
		Definir precioHoja, subtotal, descuento, recargo, total Como Real
		Definir costoAnillado Como Real
		
		Escribir "===== COPIADORA UNIVERSITARIA ====="
		
		Escribir "Ingrese numero de hojas:"
		Leer hojas
		
		Escribir "Tipo de impresion (1=Blanco/Negro, 2=Color):"
		Leer tipo
		
		Escribir "Tipo de usuario (1=Estudiante, 2=Docente):"
		Leer usuario
		
		Escribir "Horario (1=Normal, 2=Nocturno):"
		Leer horario
		
		Escribir "Desea anillado? (1=SI, 0=NO):"
		Leer anillado

		Si hojas <= 20 Entonces
			precioHoja <- 0.05
		Sino
			Si hojas <= 100 Entonces
				precioHoja <- 0.04
			Sino
				precioHoja <- 0.03
			FinSi
		FinSi
		
		Si tipo = 2 Entonces
			precioHoja <- precioHoja + 0.05
		FinSi
		
		subtotal <- hojas * precioHoja
		descuento <- 0
		
		Si usuario = 2 Entonces
			descuento <- subtotal * 0.05
		Sino
			Si usuario = 1 Y hojas > 50 Entonces
				descuento <- subtotal * 0.08
			FinSi
		FinSi
	
		recargo <- 0
		Si horario = 2 Entonces
			recargo <- subtotal * 0.10
		FinSi
	
		costoAnillado <- 0
		Si anillado = 1 Entonces
			costoAnillado <- hojas * 0.02
			Si hojas > 100 Entonces
				costoAnillado <- costoAnillado * 0.80
			FinSi
		FinSi

		total <- subtotal - descuento + recargo + costoAnillado
		
		Escribir ""
		Escribir "===== FACTURA ====="
		Escribir "Subtotal impresion: ", subtotal
		Escribir "Descuento aplicado: ", descuento
		Escribir "Recargo: ", recargo
		Escribir "Valor anillado: ", costoAnillado
		Escribir "TOTAL A PAGAR: ", total
FinAlgoritmo