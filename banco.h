#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "cola_void.h"
#include "pila_void.h"

///Declaraciones

///Struct
//Axiomas:
/*
1- 'nombre': menos de 30 caracteres que no sean especiales ni con tildes.
2- 'direccion': menos de 60 caracteres que no sean especiales ni con tildes.
3- 'colaClientes': debe respetar los axiomas de struct ColaE.
4- 'pilaBilletes': debe respetar los axiomas de struct PilaE.
*/
struct BancoE; //Declaración de la estructura.
typedef struct BancoE* BancoPtr; //Manejo de la estructura con un puntero.

///Constructor
//PRE: los datos que se envían por parámetro deben respetar, respectivamente, los axiomas 1 y 2 de struct BancoE.
//POST: crea un banco, lo carga con esos datos y lo retorna.
BancoPtr crearBanco(char nombre[30], char direccion[60]);

///Destructor
//PRE: el banco que se envía por parámetro debe haber reservado memoria previamente.
//POST: libera la memoria reservada por el banco.
void destruirBanco(BancoPtr banco);

///Mostrar
//PRE: el banco que se envía por parámetro debe estar cargado.
//POST: muestra la información del banco.
void mostrarBanco(BancoPtr banco);

///Getters
//PRE: el banco que se envía por parámetro debe, por lo menos, tener cargado el nombre.
//POST: devuelve el nombre del banco.
char* getNombreBanco(BancoPtr banco);
//PRE: el banco que se envía por parámetro debe, por lo menos, tener cargada la dirección.
//POST: devuelve la dirección del banco.
char* getDireccionBanco(BancoPtr banco);
//PRE: el banco que se envía por parámetro debe, por lo menos, tener cargada la cola de clientes.
//POST: devuelve la cola de clientes del banco.
ColaPtr getColaClientesBanco(BancoPtr banco);
//PRE: el banco que se envía por parámetro debe, por lo menos, tener cargada la pila de billetes.
//POST: devuelve la pila de billetes del banco.
PilaPtr getPilaBilletesBanco(BancoPtr banco);

///Setters
//PRE: el banco que se envía por parámetro debe existir y el nuevo nombre respetar el axioma 1 de struct BancoE.
//POST: reemplaza el nombre del banco por el que llega por parámetro.
void setNombreBanco(BancoPtr banco, char nuevoNombre[30]);
//PRE: el banco que se envía por parámetro debe existir y la nueva dirección respetar el axioma 2 de struct BancoE.
//POST: reemplaza la dirección del banco por la que llega por parámetro.
void setDireccionBanco(BancoPtr banco, char nuevaDireccion[60]);

#endif // BANCO_H_INCLUDED
