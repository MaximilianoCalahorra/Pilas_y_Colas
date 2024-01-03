#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola_void.h"

///Implementaciones

///Structs
//Nodo
struct NodoE
{
    void* item;
    NodoPtr proximoNodo;
};

//Cola
struct ColaE
{
    NodoPtr inicio;
    NodoPtr fin;
    int tamanio;
    int tamanioDelItemEnBytes;
};

///Constructores
//Cola
ColaPtr crearCola(int tamItemEnBytes)
{
    ColaPtr col = malloc(sizeof(struct ColaE)); //La nueva cola reservará la memoria suficiente para un struct ColaE.
    col->inicio = NULL; //El primer nodo de la cola es NULL.
    col->fin = NULL; //El último nodo de la cola es NULL.
    col->tamanio = 0; //El tamaño de la cola es 0.
    col->tamanioDelItemEnBytes = tamItemEnBytes; //Guardamos el tamaño en bytes del tipo de dato que tendrá el ítem de cada nodo.
    return col; //Retornamos la cola.
}

//Nodo
NodoPtr crearNodoCola(ColaPtr col, void* it)
{
    if (col == NULL) //Si la cola no existe...
    {
        printf("\nLa cola no existe.\n");
        return NULL; //Retornamos NULL.
    }
    if (it == NULL) //Si el puntero genérico no existe...
    {
        printf("\nEl puntero genérico no existe.\n");
        return NULL; //Retornamos NULL.
    }
    NodoPtr nod = malloc(sizeof(struct NodoE)); //El nuevo nodo reservará la memoria suficiente para un struct NodoE.
    nod->item = malloc(col->tamanioDelItemEnBytes); //El ítem del nodo reservará la memoria suficiente según el tipo de dato que sea.
    memcpy(nod->item, it, col->tamanioDelItemEnBytes); //Cargamos el ítem del nuevo nodo con el que llega por parámetro.
    return nod; //Retornamos el nodo.
}

///Destructor
int destruirCola(ColaPtr col)
{
    if (col == NULL) //Si la cola no existe...
    {
        printf("\nLa cola no existe.\n");
        return -1; //Error!
    }
    NodoPtr aux = col->inicio; //Un nodo auxiliar es el primer nodo de la cola.
    for (int i = 0; i < col->tamanio; i++)
    {
        aux = aux->proximoNodo; //El nodo auxiliar pasa a ser su siguiente en la cola.
    }
    //Al final del bucle, se liberó la memoria reservada por el ítem de cada nodo de la cola.
    free(col); //Liberamos la memoria reservada por la cola.
    return 1; //Cola destruída correctamente.
}

///Encolar
int encolar(ColaPtr col, void* itNuevo)
{
    if (col == NULL) //Si la cola no existe...
    {
        printf("\nLa cola no existe.\n");
        return -1; //Error!
    }
    if (itNuevo == NULL) //Si el puntero generico no existe...
    {
        printf("\nEl puntero generico no existe.\n");
        return -1; //Error!
    }
    NodoPtr nuevoNodo = crearNodoCola(col, itNuevo); //Creamos un nuevo nodo con el ítem que llega por parámetro.
    if (col->inicio == NULL) //Si la cola está vacía...
    {
        col->inicio = col->fin = nuevoNodo; //Tanto el primer como último nodo serán el nuevo nodo.
    }
    else //Si la cola tiene por lo menos un nodo...
    {
        col->fin->proximoNodo = nuevoNodo; //El siguiente al último nodo será el nuevo nodo.
        col->fin = nuevoNodo; //El último nodo será el nuevo nodo.
    }
    col->tamanio++; //Incrementamos el tamaño de la cola en una unidad.
    return 1; //Nodo encolado correctamente.
}

///Desencolar
int desencolar(ColaPtr col, void* itRemovido)
{
    if (col == NULL) //Si la cola no existe...
    {
        printf("\nLa cola no existe.\n");
        return -1; //Error!
    }
    if (col->tamanio == 0) //Si la cola está vacía...
    {
        printf("\nLa cola esta vacia.\n");
        return -1; //Error!
    }
    if (itRemovido != NULL)
    {
        memcpy(itRemovido, col->inicio->item, col->tamanioDelItemEnBytes); //Cargamos el puntero genérico con el ítem del primer
                                                                           //nodo.
    }
    NodoPtr aux = col->inicio->proximoNodo; //Un nodo auxiliar es el siguiente al primer nodo de la cola.
    free(col->inicio->item); //Liberamos la memoria reservada por el ítem del primer nodo de la cola.
    free(col->inicio); //Liberamos la memoria reservada por el primer nodo de la cola.
    col->inicio = aux; //Ahora, el primer nodo de la cola es el nodo auxiliar.
    col->tamanio--; //Decrementamos en una unidad el tamaño de la cola.
    if (col->tamanio == 0) //Si la cola está vacía...
    {
        col->inicio = col->fin = NULL; //Tanto el primer como último nodo de la cola son NULL.
    }
    if (col->tamanio == 1) //Si queda un nodo en la cola...
    {
        col->inicio = col->fin; //El primer nodo es el mismo que el último.
    }
    return 1; //Nodo desencolado e ítem recuperado correctamente.
}
