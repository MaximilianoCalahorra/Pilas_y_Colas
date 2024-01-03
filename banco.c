#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "billete.h"
#include "banco.h"

///Implementaciones

///Struct
struct BancoE
{
    char nombre[30];
    char direccion[60];
    ColaPtr colaClientes;
    PilaPtr pilaBilletes;
};

///Constructor
BancoPtr crearBanco(char nom[30], char dir[60])
{
    BancoPtr ban = malloc(sizeof(struct BancoE)); //El nuevo banco reservará la memoria suficiente para un struct BancoE.
    strcpy(ban->nombre, nom); //Cargamos el nombre.
    strcpy(ban->direccion, dir); //Cargamos la dirección.
    ban->colaClientes = crearCola(sizeof(ClientePtr)); //Inicializamos la cola de clientes.
    ban->pilaBilletes = crearPila(sizeof(BilletePtr)); //Inicializamos la pila de billetes.
    return ban; //Retornamos el banco.
}

///Destructor
void destruirBanco(BancoPtr ban)
{
    destruirCola(ban->colaClientes); //Liberamos la memoria reservada por la cola de clientes.
    destruirPila(ban->pilaBilletes); //Liberamos la memoria reservada por la pila de billetes.
    free(ban); //Liberamos la memoria reservada por el banco.
}

///Mostrar
void mostrarBanco(BancoPtr ban)
{
    printf("\n---------------------- BANCO ---------------------\n");
    printf("Nombre: %s\n", ban->nombre);
    printf("Direccion: %s", ban->direccion);
    printf("\n--------------------------------------------------\n");
}

///Getters
char* getNombreBanco(BancoPtr ban)
{
    return ban->nombre; //Retornamos el nombre.
}

char* getDireccionBanco(BancoPtr ban)
{
    return ban->direccion; //Retornamos la dirección.
}

ColaPtr getColaClientesBanco(BancoPtr ban)
{
    return ban->colaClientes; //Retornamos la cola de clientes.
}

PilaPtr getPilaBilletesBanco(BancoPtr ban)
{
    return ban->pilaBilletes; //Retornamos la pila de billetes.
}

///Setters
void setNombreBanco(BancoPtr ban, char nueNombre[30])
{
    strcpy(ban->nombre, nueNombre);
}

void setDireccionBanco(BancoPtr ban, char nueDireccion[60])
{
    strcpy(ban->direccion, nueDireccion);
}
