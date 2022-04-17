#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

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
int GetNumero(int* pResultado, char mensaje[], char mensajeError[], int rangoMin, int rangoMax, int reintentos)
{
	int numeroIngresado;
	int retorno;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && rangoMin <= rangoMax && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&numeroIngresado);
			if(numeroIngresado >= rangoMin && numeroIngresado <= rangoMax)
			{
				*pResultado = numeroIngresado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%sReintentos restantes: %d\n\n",mensajeError,reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/**
 * \brief Solicita al usuario un numero y devuelve un resultado.
 * @param mensaje Es el mensaje que se muestra al pedir el ingreso.
 * @return retorno Devuelve el numero que ingresó el usuario.
 */
float IngresarNumero(char mensaje[])
{
	float numeroIngresado;

	printf("%s",mensaje);
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}

/**
 * \brief Valida que el numero que ingrese el usuario sea mayor a 0.
 * @param numero Lo usa para poder validar.
 * @param mensajeError Es el mensaje que será devuelto en caso de que el numero ingresado fuese menor que 0.
 * @return retorno Devuelve el numero que ingresó el usuario una vez que lo validó.
 */
float ValidarNumMayorQueCero(float numero, char mensajeError[])
{
	while(numero <= 0)
	{
		printf("%s",mensajeError);
		scanf("%f",&numero);
	}

	return numero;
}

void MostrarListado(int numeros[],int size)
{
	int i;

	printf("Los numeros son: \n");

	for(i=0;i<size;i++)
	{
		printf("%d\n",numeros[i]);
	}
}

void CantidadPositivoNegativo(int numero[],int size)
{
	int positivos;
	int negativos;
	int i;


	positivos = 0;
	negativos = 0;

	for(i=0;i<size;i++)
	{

		switch(VerificarSigno(numero[i]))
		{
		case 1:

			positivos++;
			break;

		case 0:

			negativos++;
		    break;
		}

//		if(numero[i]<0)
//		{
//			negativos++;
//		}
//		else
//		{
//			if(numero[i]>0)
//			{
//				positivos++;
//			}
//		}
	}

	printf("Numeros negativos: %d\n",negativos);
	printf("Numeros positivos: %d\n",positivos);

}
/// \brief Verifica si es positivo y negativo.
/// \param numero
/// \param size
/// \return retorna 1 si es positivo,0 si es negativo y -1 por default.

int VerificarSigno(int numero)
{
	int respuesta;

	respuesta = -1;

	if(numero<0)
			{
				respuesta=0;
			}
			else
			{
				if(numero>0)
				{
					respuesta=1;
				}
			}

	return respuesta;

}

int VerificarParidad(int numero)
{
	int resultado;

	resultado = 0;

	if(numero%2 == 0)
	{
		resultado = 1;
	}

	return resultado;
}

int SumarPares(int numeros[],int size)
{
	int i;
	int acumulador;

	acumulador = 0;

	for(i=0;i<size;i++)
	{
		if(VerificarParidad(numeros[i]) == 1)
		{
			acumulador += numeros[i];
		}
	}

	return acumulador;
}

void ListarPosicionImpar(int numeros[],int size)
{
	int i;
	int par;

	for(i=0;i<size;i++)
	{
		par = VerificarParidad(i);

		if(par == 0)
		{
			printf("%d\n",numeros[i]);
		}
	}
}
