#ifndef PILA_VOID_H_INCLUDED
#define PILA_VOID_H_INCLUDED

///Declaraciones

///Structs
//Nodo
/*Axiomas:
1- 'item': puntero gen�rico.
2- 'anteriorNodo': debe respetar los axiomas de struct NodoE.
*/
struct NodoE; //Declaraci�n de la estructura.
typedef struct NodoE* NodoPtr; //Manejo de la estructura con un puntero.

//Pila
/*Axiomas:
1- 'fin': debe respetar los axiomas de struct NodoE.
2- 'tamanio': entero mayor o igual a 0.
3- 'tamanioDelItemEnBytes': entero mayor a 0.
*/
struct PilaE; //Declaraci�n de la estructura.
typedef struct PilaE* PilaPtr; //Manejo de la estructura con un puntero.

///Constructores
//Pila
//PRE: el tama�o que se env�a por par�metro debe respetar el axioma 3 de struct PilaE.
//POST: crea una pila y la retorna.
PilaPtr crearPila(int tamanioDelItemEnBytes);

//Nodo
//PRE: la pila y el puntero gen�rico que se env�an por par�metro deben existir. La pila debe, por lo menos, tener cargado el
//tama�o del tipo de dato del �tem en bytes. El puntero gen�rico debe estar cargado con el mismo tipo de dato que espera la pila.
NodoPtr crearNodoPila(PilaPtr pila, void* item);

///Destructor
//PRE: la pila que se env�a por par�metro debe haber reservado memoria previamente.
//POST: devuelve -1 si hubo un error o 1 si pudo liberar la memoria reservada por la pila.
int destruirPila(PilaPtr pila);

///Encolar
//PRE: la pila y el puntero gen�rico que se env�an por par�metro deben existir. El puntero gen�rico debe estar cargado con el mismo
//tipo de dato que espera la pila.
//POST: devuelve -1 si hubo un error o 1 si insert� un nodo al final de la pila que tiene como �tem el que llega por par�metro.
int apilar(PilaPtr pila, void* itemNuevo);

///Desencolar
//PRE: la pila que se env�a por par�metro debe existir. La pila debe, por lo menos, tener un nodo.
//POST: devuelve -1 si hubo un error o 1 si se removi� el �ltimo nodo de la pila y se recuper� su �tem en el puntero gen�rico si
//corresponde.
int desapilar(PilaPtr pila, void* itemRecuperado);

#endif // PILA_VOID_H_INCLUDED
