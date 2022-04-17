#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//Funciones usadas para este tp:
int GetNumero(int* pResultado, char mensaje[], char mensajeError[], int rangoMin, int rangoMax, int reintentos);
float IngresarNumero(char mensaje[]);
float ValidarNumMayorQueCero(float numero, char mensajeError[]);



void MostrarListado(int numeros[],int size);
void CantidadPositivoNegativo(int numero[],int size);
int VerificarSigno(int numero);
int VerificarParidad(int);
int SumarPares(int[],int);
void ListarPosicionImpar(int[],int);

#endif /* FUNCIONES_H_ */
