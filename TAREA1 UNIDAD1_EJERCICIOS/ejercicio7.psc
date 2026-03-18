Proceso ConsumoElectrico
	Definir lecturaAnterior, lecturaActual, consumo Como Real
	Definir tipoVivienda, habitantes, altoConsumo, deuda Como Entero
	Definir precio, costoBase, totalFinal, subsidio, recargo Como Real
	Definir consumoPorPersona Como Real
	Escribir "===== SISTEMA ELECTRICO ====="
	Escribir "Ingrese lectura anterior:"
	Leer lecturaAnterior
	Escribir "Ingrese lectura actual:"
	Leer lecturaActual
	Escribir "Tipo de vivienda (1=Social, 2=Normal):"
	Leer tipoVivienda
	Escribir "Numero de habitantes:"
	Leer habitantes
	Escribir "Tiene artefactos de alto consumo? (1=SI, 0=NO):"
	Leer altoConsumo
	Escribir "Tiene deuda anterior? (1=SI, 0=NO):"
	Leer deuda
	Si lecturaActual < lecturaAnterior Entonces
		Escribir "Error: lectura invalida"
	Sino
		consumo <- lecturaActual - lecturaAnterior
		Si consumo <= 100 Entonces
			precio <- 0.10
		Sino
			Si consumo <= 300 Entonces
				precio <- 0.15
			Sino
				precio <- 0.20
			FinSi
		FinSi
		costoBase <- consumo * precio
		subsidio <- 0
		recargo <- 0
		Si tipoVivienda = 1 Y consumo < 80 Entonces
			subsidio <- costoBase * 0.20
		FinSi
		Si deuda = 1 Entonces
			recargo <- costoBase * 0.10
		FinSi
		totalFinal <- costoBase - subsidio + recargo
		consumoPorPersona <- consumo / habitantes
		Escribir ""
		Escribir "===== RESULTADOS ====="
		Escribir "Consumo total: ", consumo
		Escribir "Costo base: ", costoBase
		Escribir "Subsidio: ", subsidio
		Escribir "Recargo: ", recargo
		Escribir "Total final: ", totalFinal
		Si consumoPorPersona > 100 Entonces
			Escribir "ALERTA: Consumo excesivo por habitante"
		FinSi
		Si altoConsumo = 1 Y consumo > 300 Entonces
			Escribir "RIESGO: Posible sobrefacturacion"
		FinSi
	FinSi	
FinProceso
