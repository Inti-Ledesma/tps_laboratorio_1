/*
 ============================================================================
 Tp 2 laboratorio
 Estudiante: Ledesma Godachevich Inti Ezequiel
 Año y división: 1C

 Enunciado: Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo.
  Se sabe que no puede tener más de 2000 pasajeros.

 El sistema deberá tener el siguiente menú de opciones:

 1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el número de Id.
  El resto de los campos se le pedirá al usuario.

 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar:
  o Nombre o Apellido o Precio o Tipo de pasajero o Código de vuelo.

 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

 4. INFORMAR:
  1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
  2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
  3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 ============================================================================
*/

#include "ArrayPassenger.h"

int main(void) {
	setbuf(stdout,NULL);
	Passenger arrayPassengers[MAX];
	int index;
	int rtn;
	int contador;
	int option;
	int result;
	int optionInf;
	int resultInf;
	int order;

	contador = 0;
	rtn = initPassengers(arrayPassengers, MAX);
	if(rtn < 0)
	{
		printf("Error");
	}

	do{
		result = getNumero(&option, "Ingrese una opción:\n"
						  "1. Altas.\n"
						  "2. Modificar.\n"
						  "3. Baja.\n"
						  "4. Informar.\n"
						  "5. Salir.\n\n"
						, "No seleccionó ninguna de las opciones disponibles, inténtelo nuevamente.\n\n", 1, 5, 3);
		if(result == 0)
		{
			switch(option)
			{
			case 1:
				addPassenger(arrayPassengers, MAX);
				if(rtn == 0)
				{
					printf("Se ha ingresado al pasajero con éxito.\n\n");
				}
				else
				{
					printf("Ha habido un error.\n\n");
				}
				contador++;
				break;

			case 2:
				if(contador > 0)
				{
					index = findPassengerById(arrayPassengers, MAX);
					modificarPasajero(arrayPassengers, MAX, index);
					if(rtn == 0)
					{
						printf("Se ha realizado la modificación con éxito.\n\n");
					}
					else
					{
						printf("Ha habido un error.\n\n");
					}
				}
				else
				{
					printf("Antes de poder modificar un pasajero necesita dar de alta como mínimo una vez.\n\n");
				}
				break;

			case 3:
				if(contador > 0)
				{
					index = findPassengerById(arrayPassengers, MAX);
					removePassenger(arrayPassengers, MAX, index);
					if(rtn == 0)
					{
						printf("Se ha removido al pasajero con éxito.\n\n");
					}
					else
					{
						printf("Ha habido un error.\n\n");
					}
				}
				else
				{
					printf("Antes de poder eliminar un pasajero necesita dar de alta como mínimo una vez.\n\n");
				}
				break;

			case 4:
				if(contador > 0)
				{
					resultInf = getNumero(&optionInf, "Ingrese una opción:\n"
											  "1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
											  "2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
											  "3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n"
											, "No seleccionó ninguna de las opciones disponibles, inténtelo nuevamente.\n\n", 1, 3, 3);

					if(resultInf == 0)
					{
						switch(optionInf)
						{
						case 1:
							order = ingresarNumero("Ingrese en que orden prefiere que se vea el listado:\n"
													"1. De menor a mayor\n"
													"2. De mayor a menor\n\n");
							sortPassengers(arrayPassengers, MAX, order);
							for(int i = 0;i<MAX;i++)
							{
								if(arrayPassengers[i].isEmpty == FALSE)
								{
									printPassenger(arrayPassengers, i);
								}
							}
							break;
						case 2:
							sumarPromediarEInformarPrecioPasajes(arrayPassengers, MAX);
							break;

						case 3:
							order = ingresarNumero("Ingrese en que orden prefiere que se vea el listado:\n"
													"1. De menor a mayor\n"
													"2. De mayor a menor\n\n");
							sortPassengersByCode(arrayPassengers, MAX, order);
							for(int i = 0;i<MAX;i++)
							{
								if(arrayPassengers[i].isEmpty == FALSE)
								{
									printPassenger(arrayPassengers, i);
								}
							}
							contadorEstadosDeVuelosActivos(arrayPassengers, MAX);
							break;
						}
					}
				}
				else
				{
					printf("Antes de poder dar un informe sobre los pasajeros necesita dar de alta como mínimo una vez.\n\n");
				}

				break;

			case 5:
				printf("Gracias por usar la app.");
				break;
			}
		}
	}while(option != 5);

	return EXIT_SUCCESS;
}
