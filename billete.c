#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "billete.h"

///Implementaciones

///Struct
struct BilleteE
{
    int valor;
    char color[20];
    char codigo[11];
};

///Constructor
BilletePtr crearBillete(int val, char col[20], char cod[11])
{
    BilletePtr bil = malloc(sizeof(struct BilleteE)); //El nuevo billete reservar� la memoria suficiente para un struct BilleteE.
    bil->valor = val; //Cargamos el valor.
    strcpy(bil->color, col); //Cargamos el color.
    strcpy(bil->codigo, cod); //Cargamos el c�digo.
    return bil; //Retornamos el billete.
}

BilletePtr crearBilleteTeclado()
{
    printf("\nCreando billete...\n");
    int val; //Ac� guardaremos el valor.
    printf("Ingrese el valor: $");
    scanf("%d", &val); //Valor cargado.
    char col[20]; //Ac� guardaremos el color.
    printf("Ingrese el color: ");
    fflush(stdin);
    gets(col); //Color cargado.
    char cod[11]; //Ac� guardaremos el c�digo.
    printf("Ingrese el codigo: ");
    fflush(stdin);
    gets(cod); //C�digo cargado.
    return crearBillete(val, col, cod); //Creamos un billete con esos datos y lo retornamos.
}

///Destructor
void destruirBillete(BilletePtr bil)
{
    free(bil); //Liberamos la memoria reservada por el billete.
}

///Mostrar
void mostrarBillete(BilletePtr bil)
{
    printf("\n--------------------- BILLETE --------------------\n");
    printf("Valor: $%d\n", bil->valor); //Mostramos el valor del billete.
    printf("Color: %s\n", bil->color); //Mostramos el color del billete.
    printf("Codigo: %s", bil->codigo); //Mostramos el c�digo del billete.
    printf("\n--------------------------------------------------\n");
}

///Getters
int getValorBillete(BilletePtr bil)
{
    return bil->valor; //Retornamos el valor del billete.
}

char* getColorBillete(BilletePtr bil)
{
    return bil->color; //Retornamos el color del billete.
}

char* getCodigoBillete(BilletePtr bil)
{
    return bil->codigo; //Retornamos el c�digo del billete.
}

///Setters
void setValorBillete(BilletePtr bil, int nueValor)
{
    bil->valor = nueValor; //Valor del billete reemplazado por el que llega por par�metro.
}

void setColorBillete(BilletePtr bil, char nueColor[20])
{
    strcpy(bil->color, nueColor); //Color del billete reemplazado por el que llega por par�metro.
}

void setCodigoBillete(BilletePtr bil, char nueCodigo[11])
{
    strcpy(bil->codigo, nueCodigo); //C�digo del billete reemplazado por el que llega por par�metro.
}
