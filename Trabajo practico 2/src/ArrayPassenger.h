#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 2

typedef struct {
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
char flightState[20];
int isEmpty;
} Passenger;

int initPassengers(Passenger list[], int len);
int addPassenger(Passenger list[], int len);
int findPassengerById(Passenger list[], int len);
int removePassenger(Passenger list[], int len, int index);
int sortPassengers(Passenger list[], int len, int order);
int printPassenger(Passenger list[], int len);
int sortPassengersByCode(Passenger list[], int len, int order);

int getNumero(int* pResultado, char mensaje[], char mensajeError[], int rangoMin, int rangoMax, int reintentos);
int buscarEspacioLibre(Passenger list[], int len);
float ingresarNumero(char mensaje[]);
int ingresarString(char array[], char mensaje[], char mensajeError[], int len);
int modificarPasajero(Passenger list[], int len,int index);
int sumarPromediarEInformarPrecioPasajes(Passenger list[],int len);
int contadorEstadosDeVuelosActivos(Passenger list[], int len);

#endif /* ARRAYPASSENGER_H_ */
