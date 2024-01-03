#ifndef COLA_VOID_H_INCLUDED
#define COLA_VOID_H_INCLUDED

///Declaraciones

///Structs
//Nodo
/*Axiomas:
1- 'item': puntero genérico.
2- 'proximoNodo': debe respetar los axiomas de struct NodoE.
*/
struct NodoE; //Declaración de la estructura.
typedef struct NodoE* NodoPtr; //Manejo de la estructura con un puntero.

//Cola
/*Axiomas:
1- 'inicio': debe respetar los axiomas de struct NodoE.
2- 'fin': debe respetar los axiomas de struct NodoE.
3- 'tamanio': entero mayor o igual a 0.
4- 'tamanioDelItemEnBytes': entero mayor a 0.
*/
struct ColaE; //Declaración de la estructura.
typedef struct ColaE* ColaPtr; //Manejo de la estructura con un puntero.

///Constructores
//Cola
//PRE: el tamaño que se envía por parámetro debe respetar el axioma 4 de struct ColaE.
//POST: crea una cola y la retorna.
ColaPtr crearCola(int tamanioDelItemEnBytes);

//Nodo
//PRE: la cola y el puntero genérico que se envían por parámetro deben existir. La cola debe, por lo menos, tener cargado el
//tamaño del tipo de dato del ítem en bytes. El puntero genérico debe estar cargado con el mismo tipo de dato que espera la cola.
//POST: crea un nodo, lo carga con el ítem que llega por parámetro y lo retorna.
NodoPtr crearNodoCola(ColaPtr cola, void* item);

///Destructor
//PRE: la cola que se envía por parámetro debe haber reservado memoria previamente.
//POST: devuelve -1 si hubo un error o -1 si pudo liberar la memoria reservada por la cola.
int destruirCola(ColaPtr cola);

///Encolar
//PRE: la cola y el puntero genérico que se envían por parámetro deben existir. El puntero genérico debe estar cargado con el mismo
//tipo de dato que espera la cola.
//POST: devuelve -1 si hubo un error o 1 si insertó un nodo al final de la cola que tiene como ítem el que llega por parámetro.
int encolar(ColaPtr cola, void* itemNuevo);

///Desencolar
//PRE: la cola que se envía por parámetro debe existir. La cola debe, por lo menos, tener un nodo.
//POST: devuelve -1 si hubo un error o 1 si se removió el primer nodo de la cola y se recuperó su ítem en el puntero genérico si
//corresponde.
int desencolar(ColaPtr cola, void* itemRemovido);

#endif // COLA_VOID_H_INCLUDED
