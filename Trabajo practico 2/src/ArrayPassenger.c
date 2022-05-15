#include "ArrayPassenger.h"

static int idIncremental = 1000;
static int obtenerId();
static int obtenerId()
{
	return idIncremental++;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger list[], int len)
{
	int rtn;
	rtn = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for (int i = 0; i < len; i++)
			{
				list[i].isEmpty = TRUE;
			}
			rtn = 0;
		}
	}


	return rtn;
}

/** \brief add in a existing list of passengers the values received
* in the first empty position
* \param list passenger
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger list[], int len)
{
	int rtn = -1;
	int opcion;
	int resultado;
	int indiceLibre;
	Passenger auxiliar;

	if (list != NULL)
	{
		if (len >= 0)
		{
			indiceLibre = buscarEspacioLibre(list, len);
			if (indiceLibre >= 0)
			{
				auxiliar.id = obtenerId();
				ingresarString(auxiliar.name,"Ingrese el nombre del pasajero:\n", "El nombre no puede tener más de 50 carácteres.\n", 51);
				ingresarString(auxiliar.lastName,"Ingrese el apellido del pasajero:\n", "El apellido no puede tener más de 50 carácteres.\n", 51);
				auxiliar.price = ingresarNumero("Ingrese el precio de los pasajes:\n");
				ingresarString(auxiliar.flycode,"Ingrese el codigo de vuelo del pasajero:\n", "El código de vuelo no puede tener más de 9 carácteres.\n", 10);
				auxiliar.typePassenger = ingresarNumero("Ingrese el tipo de pasajero:\n");
				resultado = getNumero(&opcion, "Ingrese la opcion que indique el estado de su vuelo:\n"
									"1. Activo.\n"
									"2. Programado.\n"
									"3. Reprogramado.\n\n"
									, "No seleccionó ninguna de las opciones disponibles, inténtelo nuevamente.\n\n", 1, 3, 3);
				if(resultado == 0)
				{
					switch(opcion)
					{
					case 1:
						strcpy(auxiliar.flightState, "Activo");
						break;

					case 2:
						strcpy(auxiliar.flightState, "Programado");
						break;

					case 3:
						strcpy(auxiliar.flightState, "Reprogramado");
						break;
					}
				}
				auxiliar.isEmpty = FALSE;

				list[indiceLibre] = auxiliar;
				rtn = 0;
			}
		}
	}

	return rtn;
}

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger list[], int len)
{
	int rtn;
	int id;
	rtn = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			id = ingresarNumero("Ingrese el id del pasajero que busca:\n");

			for(int i=0;i<MAX;i++)
			{
				if(list[i].id == id && list[i].isEmpty == FALSE)
				{
					rtn = i;
					break;
				}
			}
		}
	}

	return rtn;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger list[], int len, int index)
{
	int rtn;
	rtn = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			list[index].isEmpty = TRUE;
			rtn = 0;
		}
	}

	return rtn;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger list[], int len, int order)
{
	int rtn;
	Passenger auxiliar;
	rtn = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for(int i=0; i<len-1; i++)
			{
				for(int j=i+1; j<len; j++)
				{
					if(order == UP)
					{
						if(strcmp(list[i].lastName, list[j].lastName)>0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}
						else
						{
							if(strcmp(list[i].lastName, list[j].lastName)==0)
							{
								if(list[i].typePassenger > list[j].typePassenger)
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
							}
						}
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName)<0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}
						else
						{
							if(strcmp(list[i].lastName, list[j].lastName)==0)
							{
								if(list[i].typePassenger < list[j].typePassenger)
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
							}
						}
					}
				}
			}
			rtn = 0;
		}
	}

	return rtn;
}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger list[], int lenght)
{
	int rtn;
	rtn = -1;

	if (list != NULL)
	{
		if (lenght >= 0)
		{
			printf("%4d %4s %4s %4.2f %4s %4d\n\n",list[lenght].id
											,list[lenght].name
											,list[lenght].lastName
											,list[lenght].price
											,list[lenght].flycode
											,list[lenght].typePassenger);
		}
	}
	return rtn;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger list[], int len, int order)
{
	int rtn;
	Passenger auxiliar;
	rtn = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for(int i=0; i<len-1; i++)
			{
				for(int j=i+1; j<len; j++)
				{
					if(order == UP)
					{
						if(strcmp(list[i].flycode, list[j].flycode)>0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}
					}
					else
					{
						if(strcmp(list[i].flycode, list[j].flycode)<0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}
					}
				}
			}
			rtn = 0;
		}
	}

	return rtn;
}

/**
 * \brief Solicita al usuario un numero, lo valida, verifica y devuelve un resultado.
 * @param pResultado Puntero al resultado, allí se dejara el numero ingresado por el usuario.
 * @param mensaje Es el mensaje que se muestra al pedir el ingreso.
 * @param mensajeError Es el mensaje que se muestra si hay un error.
 * @param rangoMin Es el rango minimo dispuesto por el usuario.
 * @param rangoMax Es el rango máximo dispuesto por el usuario.
 * @param reintentos es la cantidad de reintentos que tiene el usuario para ingresar un numero válido.
 * @return retorno Si funciona devuelve 0, en caso contrario devuelve 1.
 */
int getNumero(int* pResultado, char mensaje[], char mensajeError[], int rangoMin, int rangoMax, int reintentos){
	int numeroIngresado;
	int rtn;

	rtn = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && rangoMin <= rangoMax && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&numeroIngresado);
			printf("\n");
			if(numeroIngresado >= rangoMin && numeroIngresado <= rangoMax)
			{
				*pResultado = numeroIngresado;
				rtn = 0;
				break;
			}
			else
			{
				printf("%sReintentos restantes: %d\n\n",mensajeError,reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return rtn;
}

int buscarEspacioLibre(Passenger list[], int len)
{
	int rtn = -1;
	int indice;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for (indice = 0; indice < len; indice++)
			{
				if(list[indice].isEmpty == TRUE)
				{
					rtn = indice;
					break;
				}
			}
		}
	}

	return rtn;
}

/**
 * \brief Solicita al usuario un numero y devuelve un resultado.
 * @param mensaje Es el mensaje que se muestra al pedir el ingreso.
 * @return retorno Devuelve el numero que ingresó el usuario.
 */
float ingresarNumero(char mensaje[])
{
	float numeroIngresado;

	printf("%s",mensaje);
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}

int ingresarString(char array[],char mensaje[],char mensajeError[], int len)
{
	int rtn;
	char stringIngresado[len];

	rtn = -1;

	if (array != NULL)
	{
		if (len > 0)
		{
			while(rtn == -1)
			{
				printf("%s",mensaje);
				fflush(stdin);
				gets(stringIngresado);
				if(strlen(stringIngresado)<len)
				{
					strcpy(array, stringIngresado);
					rtn = 0;
				}
				else
				{
					printf("%s", mensajeError);
				}
			}
		}
	}

	return rtn;
}

int modificarPasajero(Passenger list[], int len,int index)
{
	int rtn;
	int result;
	int option;
	rtn = -1;

	if (list != NULL)
	{
		if (len >= 0)
		{
			result = getNumero(&option, "Elija que dato desea modificar:\n"
										"1. Nombre.\n"
										"2. Apellido.\n"
										"3. Precio.\n"
										"4. Código de vuelo.\n"
										"5. Tipo de pasajero.\n"
										, "No seleccionó ninguna de las opciones disponibles, inténtelo nuevamente.\n\n", 1, 5, 3);

			if(result == 0)
			{
				switch(option)
				{
					case 1:
						ingresarString(list[index].name,"Ingrese el nuevo nombre del pasajero:\n", "El nombre no puede tener más de 50 carácteres.\n", 51);
						printf("%s\n", list[index].name);
						break;
					case 2:
						ingresarString(list[index].lastName,"Ingrese el nuevo apellido del pasajero:\n", "El apellido no puede tener más de 50 carácteres.\n", 51);
						break;
					case 3:
						list[index].price = ingresarNumero("Ingrese el precio de los pasajes:\n");
						break;
					case 4:
						ingresarString(list[index].flycode,"Ingrese el codigo de vuelo del pasajero:\n", "El código de vuelo no puede tener más de 9 carácteres.\n", 10);
						break;
					case 5:
						list[index].typePassenger = ingresarNumero("Ingrese el tipo de pasajero:\n");
						printf("%d\n",list[index].typePassenger);
						break;
				}
				rtn = 0;
			}
		}
	}

	return rtn;
}

int sumarPromediarEInformarPrecioPasajes(Passenger list[],int len)
{
	int rtn;
	int precioTotal;
	int promedio;
	int contador;
	int contadorP;
	rtn = -1;

	contador = 0;
	precioTotal = 0;
	contadorP = 0;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for(int i = 0; i<len;i++)
			{
				if(list[i].isEmpty == FALSE)
				{
					precioTotal += list[i].price;
					contador++;
				}
			}
			rtn = 0;
		}
	}

	promedio = precioTotal / contador;

	for(int i = 0;i<MAX;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			if(list[i].price>promedio)
			{
				contadorP++;
			}
		}
	}
	printf("El precio total de los pasajes es de: $%d\n"
		"El precio promedio es de: $%d\n"
		"Y %d pasajeros superan el precio promedio.\n\n", precioTotal, promedio, contadorP);

	return rtn;
}

int contadorEstadosDeVuelosActivos(Passenger list[], int len)
{
	int rtn;
	int contador;

	rtn = -1;
	contador = 0;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for(int i=0; i<len;i++)
			{
				if(strcmp(list[i].flightState, "Activo")==0)
				{
					contador++;
				}
			}
			rtn = 0;
		}
	}

	printf("Hay %d vuelos activos.\n\n", contador);

	return rtn;
}
