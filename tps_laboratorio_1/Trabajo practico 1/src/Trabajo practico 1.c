/*
 ============================================================================
 Trabajo práctico número 1.
 Alumno: Inti Ledesma
 División: C

  Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
 para ofrecerlos a sus clientes.
 Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
  El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 Para ello el programa iniciará y contará con un menú de opciones:

 1. Ingresar Kilómetros: ( km=x)

 2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
 - Precio vuelo Aerolíneas:
 - Precio vuelo Latam:

 3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

 4. Informar Resultados:
 “Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r

 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r

 La diferencia de precio es : r “

 5. Carga forzada de datos
 6. Salir

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	int flagCase1;
	int flagCase2;
	int flagCase3;
	int flagCase5;
	int opciones;
	int respuesta;
	int x;
	int y;
	int z;
	float resultadosAerolineas[4];
	float resultadosLatam[4];
	int diferenciaPrecio;
	int xForzado;
	int yForzado;
	int zForzado;

	flagCase1 = 0;
	flagCase2 = 0;
	flagCase3 = 0;
	flagCase5 = 0;
	xForzado = 7090;
	yForzado = 162965;
	zForzado = 159339;

	do
	{
		respuesta = GetNumero(&opciones,"Seleccione una opción:\n1.Ingresar km\n2.Ingresar precio de vuelos\n3.Calcular todos los costos\n4.Informar resultados\n5.Carga forzada de datos\n6.Salir\n","La opción seleccionada no existe.\n",1,6,2);

		if (respuesta == 0)
		{
			switch(opciones)
			{
				case 1:
					x = IngresarNumero("Ingrese los km:\n");
					ValidarNumMayorQueCero(x, "Los km ingresados no pueden ser negativos.\n");
					flagCase1 = 1;
					break;
				case 2:
					y = IngresarNumero("Ingrese el precio de vuelos con Aerolineas:\n");
					ValidarNumMayorQueCero(y, "El precio ingresado no pueden ser negativos.\n");
					z = IngresarNumero("Ingrese el precio de vuelos con Latam:\n");
					ValidarNumMayorQueCero(z, "El precio ingresado no pueden ser negativos.\n");
					flagCase2 = 1;
					break;
				case 3:
					if(flagCase1 == 1 && flagCase2 == 1)
					{
						resultadosAerolineas[0] = y * 0.9;
						resultadosAerolineas[1] = y * 1.25;
						resultadosAerolineas[2] = y / 4606954.55;
						resultadosAerolineas[3] = y / x;

						resultadosLatam[0] = z * 0.9;
						resultadosLatam[1] = z * 1.25;
						resultadosLatam[2] = z / 4606954.55;
						resultadosLatam[3] = z / x;

						diferenciaPrecio = y - z;

						if(diferenciaPrecio < 0)
						{
							diferenciaPrecio *= -1;
						}
						flagCase3 = 1;
					}
					else
					{
						printf("Para calcular los costos necesita ingresar los kms y los precios de los vuelos.\n\n");
					}
					break;
				case 4:
					if(flagCase3 == 1 || flagCase5 == 1)
					{
						printf("\nAerolineas:\nPrecio con tarjeta de débito: $%.2f", resultadosAerolineas[0]);
						printf("\nPrecio con tarjeta de crédito: $%.2f", resultadosAerolineas[1]);
						printf("\nPrecio pagando con bitcoin: %f BTC", resultadosAerolineas[2]);
						printf("\nPrecio unitario: $%.2f\n", resultadosAerolineas[3]);

						printf("\nLatam:\nPrecio con tarjeta de débito: $%.2f", resultadosLatam[0]);
						printf("\nPrecio con tarjeta de crédito: $%.2f", resultadosLatam[1]);
						printf("\nPrecio pagando con bitcoin: %f BTC", resultadosLatam[2]);
						printf("\nPrecio unitario: $%.2f\n", resultadosLatam[3]);

						printf("\nLa diferencia de precio es de: $%d\n\n",diferenciaPrecio);
					}
					else
					{
						printf("Para informar los resultados necesita calcular los costos o bien hacer una carga forzada.\n\n");
					}
					break;
				case 5:
					resultadosAerolineas[0] = yForzado * 0.9;
					resultadosAerolineas[1] = yForzado * 1.25;
					resultadosAerolineas[2] = yForzado / 4606954.55;
					resultadosAerolineas[3] = yForzado / xForzado;

					resultadosLatam[0] = zForzado * 0.9;
					resultadosLatam[1] = zForzado * 1.25;
					resultadosLatam[2] = zForzado / 4606954.55;
					resultadosLatam[3] = zForzado / xForzado;

					diferenciaPrecio = yForzado - zForzado;
					if(diferenciaPrecio<0)
					{
						diferenciaPrecio *= -1;
					}
					flagCase5 = 1;
					break;
				case 6:
					printf("Gracias por usar la aplicación.\n");
					break;
			}
		}
		else
		{
			printf("Error, ninguna de las opciones fue seleccionada.\nFin del programa.");
			opciones = 6;
		}
	}while(opciones != 6);

	return 0;
}
