Proceso CajeroAutomatico
	Definir monto, saldo Como Entero
	Definir b20, b10, b5, b1 Como Entero
	Definir e20, e10, e5, e1 Como Entero
	Definir restante, efectivoTotal Como Entero
	Escribir "===== CAJERO AUTOMATICO ====="
	Escribir "Ingrese saldo disponible:"
	Leer saldo
	Escribir "Cantidad de billetes de 20:"
	Leer b20
	Escribir "Cantidad de billetes de 10:"
	Leer b10
	Escribir "Cantidad de billetes de 5:"
	Leer b5
	Escribir "Cantidad de billetes de 1:"
	Leer b1
	Escribir "Ingrese monto a retirar:"
	Leer monto
	Si monto <= 0 Entonces
		Escribir "Monto invalido"
	Sino
		efectivoTotal <- b20*20 + b10*10 + b5*5 + b1
		Si monto > saldo O monto > efectivoTotal Entonces
			Escribir "No se puede realizar la operacion"
		Sino
			restante <- monto
			e20 <- 0
			e10 <- 0
			e5 <- 0
			e1 <- 0
			Si restante / 20 < b20 Entonces
				e20 <- restante / 20
			Sino
				e20 <- b20
			FinSi
			restante <- restante - (e20 * 20)
			Si restante / 10 < b10 Entonces
				e10 <- restante / 10
			Sino
				e10 <- b10
			FinSi
			restante <- restante - (e10 * 10)
			Si restante / 5 < b5 Entonces
				e5 <- restante / 5
			Sino
				e5 <- b5
			FinSi
			restante <- restante - (e5 * 5)
			Si restante < b1 Entonces
				e1 <- restante
			Sino
				e1 <- b1
			FinSi
			restante <- restante - e1
			Si restante <> 0 Entonces
				Escribir "No es posible entregar el monto exacto"
			Sino
				saldo <- saldo - monto
				b20 <- b20 - e20
				b10 <- b10 - e10
				b5 <- b5 - e5
				b1 <- b1 - e1
				Escribir "===== ENTREGA ====="
				Escribir "Billetes de 20: ", e20
				Escribir "Billetes de 10: ", e10
				Escribir "Billetes de 5: ", e5
				Escribir "Billetes de 1: ", e1
				Escribir "Saldo restante: ", saldo
				efectivoTotal <- b20*20 + b10*10 + b5*5 + b1
				Escribir "Efectivo restante: ", efectivoTotal
			FinSi
		FinSi
	FinSi
FinProceso