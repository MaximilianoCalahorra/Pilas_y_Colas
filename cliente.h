#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "cola_void.h"

///Declaraciones

///Struct
//Axiomas
/*
1- 'nombre': menos de 25 caracteres que no sean especiales ni con tildes.
2- 'apellido': menos de 25 caracteres que no sean especiales ni con tildes.
3- 'dni': entero mayor a 0 de 7 u 8 dígitos.
*/
struct ClienteE; //Declaración de la estructura.
typedef struct ClienteE* ClientePtr; //Manejo de la estructura con un puntero.

///Constructor
//PRE: los datos envíados por parámetro deben, respectivamente, respetar los axiomas 1, 2 y 3 de struct ClienteE.
//POST: crea un cliente, lo carga con esos datos y lo retorna.
ClientePtr crearCliente(char nombre[25], char apellido[25], int dni);
//PRE: los datos que ingrese el usuario deben respetar los axiomas de struct ClienteE.
//POST: crea un cliente, lo carga con esos datos y lo retorna.
ClientePtr crearClienteTeclado();

///Destructor
//PRE: el cliente que se envía por parámetro debe haber reservado memoria previamente.
//POST: libera la memoria reservada por el cliente.
void destruirCliente(ClientePtr cliente);

///Mostrar
//PRE: el cliente que se envía por parámetro debe estar cargado.
//POST: muestra la información del cliente.
void mostrarCliente(ClientePtr cliente);

///Getters
//PRE: el cliente que se envía por parámetro debe, por lo menos, tener cargado el nombre.
//POST: devuelve el nombre del cliente.
char* getNombreCliente(ClientePtr cliente);
//PRE: el cliente que se envía por parámetro debe, por lo menos, tener cargado el apellido.
//POST: devuelve el apellido del cliente.
char* getApellidoCliente(ClientePtr cliente);
//PRE: el cliente que se envía por parámetro debe, por lo menos, tener cargado el DNI.
//POST: devuelve el DNI del cliente.
int getDniCliente(ClientePtr cliente);

///Setters
//PRE: el cliente que se envía por parámetro debe existir y el nuevo nombre respetar el axioma 1 de struct ClienteE.
//POST: reemplaza el nombre del cliente por el que llega por parámetro.
void setNombreCliente(ClientePtr cliente, char nuevoNombre[25]);
//PRE: el cliente que se envía por parámetro debe existir y el nuevo apellido respetar el axioma 2 de struct ClienteE.
//POST: reemplaza el apellido del cliente por el que llega por parámetro.
void setApellidoCliente(ClientePtr cliente, char nuevoApellido[25]);
//PRE: el cliente que se envía por parámetro debe existir y el nuevo DNI respetar el axioma 3 de struct ClienteE.
//POST: reemplaza el DNI del cliente por el que llega por parámetro.
void setDniCliente(ClientePtr cliente, int nuevoDni);

#endif // CLIENTE_H_INCLUDED
