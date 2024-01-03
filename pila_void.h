#ifndef PILA_VOID_H_INCLUDED
#define PILA_VOID_H_INCLUDED

///Declaraciones

///Structs
//Nodo
/*Axiomas:
1- 'item': puntero genérico.
2- 'anteriorNodo': debe respetar los axiomas de struct NodoE.
*/
struct NodoE; //Declaración de la estructura.
typedef struct NodoE* NodoPtr; //Manejo de la estructura con un puntero.

//Pila
/*Axiomas:
1- 'fin': debe respetar los axiomas de struct NodoE.
2- 'tamanio': entero mayor o igual a 0.
3- 'tamanioDelItemEnBytes': entero mayor a 0.
*/
struct PilaE; //Declaración de la estructura.
typedef struct PilaE* PilaPtr; //Manejo de la estructura con un puntero.

///Constructores
//Pila
//PRE: el tamaño que se envía por parámetro debe respetar el axioma 3 de struct PilaE.
//POST: crea una pila y la retorna.
PilaPtr crearPila(int tamanioDelItemEnBytes);

//Nodo
//PRE: la pila y el puntero genérico que se envían por parámetro deben existir. La pila debe, por lo menos, tener cargado el
//tamaño del tipo de dato del ítem en bytes. El puntero genérico debe estar cargado con el mismo tipo de dato que espera la pila.
NodoPtr crearNodoPila(PilaPtr pila, void* item);

///Destructor
//PRE: la pila que se envía por parámetro debe haber reservado memoria previamente.
//POST: devuelve -1 si hubo un error o 1 si pudo liberar la memoria reservada por la pila.
int destruirPila(PilaPtr pila);

///Encolar
//PRE: la pila y el puntero genérico que se envían por parámetro deben existir. El puntero genérico debe estar cargado con el mismo
//tipo de dato que espera la pila.
//POST: devuelve -1 si hubo un error o 1 si insertó un nodo al final de la pila que tiene como ítem el que llega por parámetro.
int apilar(PilaPtr pila, void* itemNuevo);

///Desencolar
//PRE: la pila que se envía por parámetro debe existir. La pila debe, por lo menos, tener un nodo.
//POST: devuelve -1 si hubo un error o 1 si se removió el último nodo de la pila y se recuperó su ítem en el puntero genérico si
//corresponde.
int desapilar(PilaPtr pila, void* itemRecuperado);

#endif // PILA_VOID_H_INCLUDED
