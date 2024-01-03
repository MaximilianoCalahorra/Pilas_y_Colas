#ifndef COLA_VOID_H_INCLUDED
#define COLA_VOID_H_INCLUDED

///Declaraciones

///Structs
//Nodo
/*Axiomas:
1- 'item': puntero gen�rico.
2- 'proximoNodo': debe respetar los axiomas de struct NodoE.
*/
struct NodoE; //Declaraci�n de la estructura.
typedef struct NodoE* NodoPtr; //Manejo de la estructura con un puntero.

//Cola
/*Axiomas:
1- 'inicio': debe respetar los axiomas de struct NodoE.
2- 'fin': debe respetar los axiomas de struct NodoE.
3- 'tamanio': entero mayor o igual a 0.
4- 'tamanioDelItemEnBytes': entero mayor a 0.
*/
struct ColaE; //Declaraci�n de la estructura.
typedef struct ColaE* ColaPtr; //Manejo de la estructura con un puntero.

///Constructores
//Cola
//PRE: el tama�o que se env�a por par�metro debe respetar el axioma 4 de struct ColaE.
//POST: crea una cola y la retorna.
ColaPtr crearCola(int tamanioDelItemEnBytes);

//Nodo
//PRE: la cola y el puntero gen�rico que se env�an por par�metro deben existir. La cola debe, por lo menos, tener cargado el
//tama�o del tipo de dato del �tem en bytes. El puntero gen�rico debe estar cargado con el mismo tipo de dato que espera la cola.
//POST: crea un nodo, lo carga con el �tem que llega por par�metro y lo retorna.
NodoPtr crearNodoCola(ColaPtr cola, void* item);

///Destructor
//PRE: la cola que se env�a por par�metro debe haber reservado memoria previamente.
//POST: devuelve -1 si hubo un error o -1 si pudo liberar la memoria reservada por la cola.
int destruirCola(ColaPtr cola);

///Encolar
//PRE: la cola y el puntero gen�rico que se env�an por par�metro deben existir. El puntero gen�rico debe estar cargado con el mismo
//tipo de dato que espera la cola.
//POST: devuelve -1 si hubo un error o 1 si insert� un nodo al final de la cola que tiene como �tem el que llega por par�metro.
int encolar(ColaPtr cola, void* itemNuevo);

///Desencolar
//PRE: la cola que se env�a por par�metro debe existir. La cola debe, por lo menos, tener un nodo.
//POST: devuelve -1 si hubo un error o 1 si se removi� el primer nodo de la cola y se recuper� su �tem en el puntero gen�rico si
//corresponde.
int desencolar(ColaPtr cola, void* itemRemovido);

#endif // COLA_VOID_H_INCLUDED
