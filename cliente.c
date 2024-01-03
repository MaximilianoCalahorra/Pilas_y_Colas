#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

///Implementaciones

///Struct
struct ClienteE
{
    char nombre[25];
    char apellido[25];
    int dni;
};

///Constructor
ClientePtr crearCliente(char nom[25], char ape[25], int dni)
{
    ClientePtr cli = malloc(sizeof(struct ClienteE)); //El nuevo cliente reservará la memoria suficiente para un struct ClienteE.
    strcpy(cli->nombre, nom); //Cargamos el nombre.
    strcpy(cli->apellido, ape); //Cargamos el apellido.
    cli->dni = dni; //Cargamos el DNI.
    return cli; //Retornamos el cliente.
}

ClientePtr crearClienteTeclado()
{
    printf("\nCreando cliente...\n");
    char nom[25]; //Acá guardaremos el nombre.
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(nom); //Nombre cargado.
    char ape[25]; //Acá guardaremos el apellido.
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(ape); //Apellido cargado.
    int dni; //Acá guardaremos el DNI.
    printf("Ingrese el DNI: #");
    scanf("%d", &dni); //DNI cargado.
    return crearCliente(nom, ape, dni); //Creamos un cliente con esos datos y lo retornamos.
}

///Destructor
void destruirCliente(ClientePtr cli)
{
    free(cli); //Liberamos la memoria reservada por el cliente.
}

///Mostrar
void mostrarCliente(ClientePtr cli)
{
    printf("\n--------------------- CLIENTE --------------------\n");
    printf("Nombre: %s\n", cli->nombre);
    printf("Apellido: %s\n", cli->apellido);
    printf("DNI: #%d", cli->dni);
    printf("\n--------------------------------------------------\n");
}

///Getters
char* getNombreCliente(ClientePtr cli)
{
    return cli->nombre; //Retornamos el nombre.
}

char* getApellidoCliente(ClientePtr cli)
{
    return cli->apellido; //Retornamos el apellido.
}

int getDniCliente(ClientePtr cli)
{
    return cli->dni; //Retornamos el DNI.
}

///Setters
void setNombreCliente(ClientePtr cli, char nueNombre[25])
{
    strcpy(cli->nombre, nueNombre); //Reemplazamos el nombre por el que llega por parámetro.
}

void setApellidoCliente(ClientePtr cli, char nueApellido[25])
{
    strcpy(cli->apellido, nueApellido); //Reemplazamos el apellido por el que llega por parámetro.
}

void setDniCliente(ClientePtr cli, int nueDni)
{
    cli->dni = nueDni; //Reemplazamos el DNI por el que llega por parámetro.
}
