Proceso PlanificadorViaje
	Definir estudiantes, dias, transporte, alimentacion, descuentoInst, coordinador Como Entero
	Definir costoHospedajeDia Como Real
	Definir costoTransporte, costoHospedaje, costoAlimentacion Como Real
	Definir total, descuento, totalFinal, costoPorEstudiante Como Real
	Escribir "===== PLANIFICADOR DE VIAJE ====="
	Escribir "Numero de estudiantes:"
	Leer estudiantes
	Escribir "Tipo de transporte (1=Bus, 2=Avion):"
	Leer transporte
	Escribir "Numero de dias:"
	Leer dias
	Escribir "Costo de hospedaje por dia:"
	Leer costoHospedajeDia
	Escribir "Incluye alimentacion? (1=SI, 0=NO):"
	Leer alimentacion
	Escribir "Aplica descuento institucional? (1=SI, 0=NO):"
	Leer descuentoInst
	Escribir "Hay coordinador que viaja gratis? (1=SI, 0=NO):"
	Leer coordinador

	Si transporte = 1 Entonces
		costoTransporte <- 50
	Sino
		costoTransporte <- 120
	FinSi

	Si estudiantes > 20 Entonces
		costoTransporte <- costoTransporte * 0.80
	FinSi

	Si coordinador = 1 Entonces
		costoTransporte <- costoTransporte * (estudiantes - 1)
	Sino
		costoTransporte <- costoTransporte * estudiantes
	FinSi

	costoHospedaje <- estudiantes * dias * costoHospedajeDia
	
	Si dias > 3 Entonces
		costoHospedaje <- costoHospedaje * 0.90
	FinSi

	costoAlimentacion <- 0
	Si alimentacion = 1 Entonces
		costoAlimentacion <- estudiantes * dias * 10
	FinSi

	total <- costoTransporte + costoHospedaje + costoAlimentacion

	descuento <- 0
	Si descuentoInst = 1 Y total > 1000 Entonces
		descuento <- total * 0.10
	FinSi

	totalFinal <- total - descuento
	
	costoPorEstudiante <- totalFinal / estudiantes

	Si costoPorEstudiante > 200 Entonces
		Escribir "Viaje no recomendable"
	Sino
		Escribir "Viaje recomendado"
	FinSi
	
	Escribir ""
	Escribir "===== RESULTADOS ====="
	Escribir "Costo transporte: ", costoTransporte
	Escribir "Costo hospedaje: ", costoHospedaje
	Escribir "Costo alimentacion: ", costoAlimentacion
	Escribir "Descuento: ", descuento
	Escribir "Total general: ", totalFinal
	Escribir "Costo por estudiante: ", costoPorEstudiante
	
FinProceso