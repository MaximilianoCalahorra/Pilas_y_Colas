#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila_void.h"

///Structs
//Nodo
struct NodoE
{
    void* item;
    NodoPtr anteriorNodo;
};

//Pila
struct PilaE
{
    NodoPtr fin;
    int tamanio;
    int tamanioDelItemEnBytes;
};

///Constructores
//Pila
PilaPtr crearPila(int tamItemEnBytes)
{
    PilaPtr pil = malloc(sizeof(struct PilaE)); //La nueva pila reservará la memoria suficiente para un struct PilaE.
    pil->fin = NULL; //El último nodo de la pila es NULL.
    pil->tamanio = 0; //El tamaño de la pila es 0.
    pil->tamanioDelItemEnBytes = tamItemEnBytes; //Guardamos el tamaño en bytes del tipo de dato que tendrá el ítem de cada nodo.
    return pil; //Retornamos la pila.
}

//Nodo
NodoPtr crearNodoPila(PilaPtr pil, void* it)
{
    if (pil == NULL) //Si la pila no existe...
    {
        printf("\nLa pila no existe.\n");
        return NULL; //Retornamos NULL.
    }
    if (it == NULL) //Si el puntero genérico no existe...
    {
        printf("\nEl puntero generico no existe.\n");
        return NULL; //Retornamos NULL.
    }
    NodoPtr nod = malloc(sizeof(struct NodoE)); //El nuevo nodo reservará la memoria suficiente para un struct NodoE.
    nod->item = malloc(pil->tamanioDelItemEnBytes); //El ítem del nodo reservará la memoria suficiente según el tipo de dato que sea.
    memcpy(nod->item, it, pil->tamanioDelItemEnBytes); //Cargamos el ítem del nuevo nodo con el que llega por parámetro.
    return nod; //Retornamos el nodo.
}

///Destructor
int destruirPila(PilaPtr pil)
{
    if (pil == NULL) //Si la pila no existe...
    {
        printf("\nLa pila no existe.\n");
        return -1; //Error!
    }
    NodoPtr aux = pil->fin; //Un nodo auxiliar es el último nodo de la pila.
    for (int i = 0; i < pil->tamanio; i++)
    {
        aux = aux->anteriorNodo; //El nodo auxiliar pasa a ser su anterior en la lista.
    }
    //Al final del bucle, se liberó la memoria reservada por el ítem de cada nodo de la pila.
    free(pil); //Liberamos la memoria reservada por la pila.
    return 1; //Cola destruída correctamente.
}

///Apilar
int apilar(PilaPtr pil, void* itNuevo)
{
    if (pil == NULL) //Si la pila no existe...
    {
        printf("\nLa pila no existe.\n");
        return -1; //Error!
    }
    if (itNuevo == NULL) //Si el puntero genérico no existe...
    {
        printf("\nEl puntero generico no existe.\n");
        return -1; //Error!
    }
    NodoPtr nuevoNodo = crearNodoPila(pil, itNuevo); //Creamos un nuevo nodo con el ítem que llega por parámetro.
    nuevoNodo->anteriorNodo = pil->fin; //El nodo anterior al nuevo nodo es el último de la pila.
    pil->fin = nuevoNodo; //Ahora, el último nodo de la pila es el nuevo nodo.
    pil->tamanio++; //Incrementamos en una unidad el tamaño de la pila.
    return 1; //Nodo apilado correctamente.
}

///Desapilar
int desapilar(PilaPtr pil, void* itRecuperado)
{
    if (pil == NULL) //Si la pila no existe...
    {
        printf("\nLa pila no existe.\n");
        return -1; //Error!
    }
    if (pil->tamanio == 0) //Si la pila está vacía...
    {
        printf("\nLa pila esta vacia.\n");
        return -1; //Error!
    }
    if (itRecuperado != NULL)
    {
        memcpy(itRecuperado, pil->fin->item, pil->tamanioDelItemEnBytes); //Cargamos el puntero genérico con el ítem del último
                                                                          //nodo.
    }
    NodoPtr aux = pil->fin->anteriorNodo; //Un nodo auxiliar es el anterior al último nodo de la pila.
    free(pil->fin->item); //Liberamos la memoria reservada por el ítem del último nodo de la pila.
    free(pil->fin); //Liberamos la memoria reservada por el último nodo de la pila.
    pil->fin = aux; //Ahora, el último nodo de la pila es el nodo auxiliar.
    pil->tamanio--; //Decrementamos en una unidad el tamaño de la pila.
    return 1; //Nodo desapilado correctamente e ítem recuperado correctamente.
}
