#ifndef BILLETE_H_INCLUDED
#define BILLETE_H_INCLUDED
#include "pila_void.h"

///Declaraciones

///Struct
//Axiomas
/*
1- 'valor': entero mayor a 0.
2- 'color': menos de 20 caracteres que no sean especiales ni con tildes.
3- 'codigo': menos de 11 caracteres que no sean especiales ni con tildes.
*/
struct BilleteE; //Declaraci�n de la estructura.
typedef struct BilleteE* BilletePtr; //Manejo de la estructura con un puntero.

///Constructor
//PRE: los datos que se env�an por par�metro deben respetar los axiomas 1, 2 y 3, respectivamente, de struct BilleteE.
//POST: crea un billete, lo carga con esos datos y lo retorna.
BilletePtr crearBillete(int valor, char color[20], char codigo[11]);
//PRE: los datos que ingrese el usuario deben respetar los axiomas de struct BilleteE.
//POST: crea un billete, lo carga con esos datos y lo retorna.
BilletePtr crearBilleteTeclado();

///Destructor
//PRE: el billete que se env�a por par�metro debe haber reservado memoria previamente.
//POST: libera la memoria reservada por el billete.
void destruirBillete(BilletePtr billete);

///Mostrar
//PRE: el billete que se env�a por par�metro debe estar cargado.
//POST: muestra la informaci�n del billete.
void mostrarBillete(BilletePtr billete);

///Getters
//PRE: el billete que se env�a por par�metro debe, por lo menos, tener cargado el valor.
//POST: devuelve el valor del billete.
int getValorBillete(BilletePtr billete);
//PRE: el billete que se env�a por par�metro debe, por lo menos, tener cargado el color.
//POST: devuelve el color del billete.
char* getColorBillete(BilletePtr billete);
//PRE: el billete que se env�a por par�metro debe, por lo menos, tener cargado el c�digo.
//POST: devuelve el c�digo del billete.
char* getCodigoBillete(BilletePtr billete);

///Setters
//PRE: el billete que se env�a por par�metro debe existir y el nuevo valor respetar el axioma 1 de struct BilleteE.
//POST: reemplaza el valor del billete por el que llega por par�metro.
void setValorBillete(BilletePtr billete, int nuevoValor);
//PRE: el billete que se env�a por par�metro debe existir y el nuevo color respetar el axioma 2 de struct BilleteE.
//POST: reemplaza el color del billete por el que llega por par�metro.
void setColorBillete(BilletePtr billete, char nuevoColor[20]);
//PRE: el billete que se env�a por par�metro debe existir y el nuevo c�digo respetar el axioma 3 de struct BilleteE.
//POST: reemplaza el c�digo del billete por el que llega por par�metro.
void setCodigoBillete(BilletePtr billete, char nuevoCodigo[11]);

#endif // BILLETE_H_INCLUDED
