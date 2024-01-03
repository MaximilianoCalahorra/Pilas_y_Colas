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
    PilaPtr pil = malloc(sizeof(struct PilaE)); //La nueva pila reservar� la memoria suficiente para un struct PilaE.
    pil->fin = NULL; //El �ltimo nodo de la pila es NULL.
    pil->tamanio = 0; //El tama�o de la pila es 0.
    pil->tamanioDelItemEnBytes = tamItemEnBytes; //Guardamos el tama�o en bytes del tipo de dato que tendr� el �tem de cada nodo.
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
    if (it == NULL) //Si el puntero gen�rico no existe...
    {
        printf("\nEl puntero generico no existe.\n");
        return NULL; //Retornamos NULL.
    }
    NodoPtr nod = malloc(sizeof(struct NodoE)); //El nuevo nodo reservar� la memoria suficiente para un struct NodoE.
    nod->item = malloc(pil->tamanioDelItemEnBytes); //El �tem del nodo reservar� la memoria suficiente seg�n el tipo de dato que sea.
    memcpy(nod->item, it, pil->tamanioDelItemEnBytes); //Cargamos el �tem del nuevo nodo con el que llega por par�metro.
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
    NodoPtr aux = pil->fin; //Un nodo auxiliar es el �ltimo nodo de la pila.
    for (int i = 0; i < pil->tamanio; i++)
    {
        aux = aux->anteriorNodo; //El nodo auxiliar pasa a ser su anterior en la lista.
    }
    //Al final del bucle, se liber� la memoria reservada por el �tem de cada nodo de la pila.
    free(pil); //Liberamos la memoria reservada por la pila.
    return 1; //Cola destru�da correctamente.
}

///Apilar
int apilar(PilaPtr pil, void* itNuevo)
{
    if (pil == NULL) //Si la pila no existe...
    {
        printf("\nLa pila no existe.\n");
        return -1; //Error!
    }
    if (itNuevo == NULL) //Si el puntero gen�rico no existe...
    {
        printf("\nEl puntero generico no existe.\n");
        return -1; //Error!
    }
    NodoPtr nuevoNodo = crearNodoPila(pil, itNuevo); //Creamos un nuevo nodo con el �tem que llega por par�metro.
    nuevoNodo->anteriorNodo = pil->fin; //El nodo anterior al nuevo nodo es el �ltimo de la pila.
    pil->fin = nuevoNodo; //Ahora, el �ltimo nodo de la pila es el nuevo nodo.
    pil->tamanio++; //Incrementamos en una unidad el tama�o de la pila.
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
    if (pil->tamanio == 0) //Si la pila est� vac�a...
    {
        printf("\nLa pila esta vacia.\n");
        return -1; //Error!
    }
    if (itRecuperado != NULL)
    {
        memcpy(itRecuperado, pil->fin->item, pil->tamanioDelItemEnBytes); //Cargamos el puntero gen�rico con el �tem del �ltimo
                                                                          //nodo.
    }
    NodoPtr aux = pil->fin->anteriorNodo; //Un nodo auxiliar es el anterior al �ltimo nodo de la pila.
    free(pil->fin->item); //Liberamos la memoria reservada por el �tem del �ltimo nodo de la pila.
    free(pil->fin); //Liberamos la memoria reservada por el �ltimo nodo de la pila.
    pil->fin = aux; //Ahora, el �ltimo nodo de la pila es el nodo auxiliar.
    pil->tamanio--; //Decrementamos en una unidad el tama�o de la pila.
    return 1; //Nodo desapilado correctamente e �tem recuperado correctamente.
}
