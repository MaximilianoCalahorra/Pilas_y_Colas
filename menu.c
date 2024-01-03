#include <stdio.h>
#include <stdlib.h>
#include "billete.h"
#include "cliente.h"
#include "banco.h"
#include "cola_void.h"
#include "pila_void.h"

///Implementaciones

///Opción
int pedirOpcion()
{
    int op; //Variable donde se guardará la opción que ingrese el usuario.
    do
    {
        printf("\nIngrese una de las siguientes opciones:\n");
        printf("Opcion #1: encolar un cliente en la cola de clientes del banco.\n");
        printf("Opcion #2: desencolar un cliente de la cola de clientes del banco.\n");
        printf("Opcion #3: desencolar un cliente de la cola de clientes del banco y mostrar sus datos.\n");
        printf("Opcion #4: apilar un billete en la pila de billetes del banco.\n");
        printf("Opcion #5: desapilar un billete de la pila de billetes del banco.\n");
        printf("Opcion #6: desapilar un billete de la pila de billetes del banco y mostrar sus datos.\n");
        printf("Opcion #0: salir del menu.\n");
        printf("\nSu opcion: #");
        scanf("%d", &op);
    }
    while ((op < 0) || (op > 6)); //Se repite el bucle de instrucciones mientras la opción sea menor a 0 o mayor a 6
    return op; //Retornamos la opción elegida.
}

///Menú
void menu()
{
    BancoPtr bancoSantander = crearBanco("Santander", "Av. 9 de Julio 2982, CABA."); //Creamos un banco con esos datos.
    printf("\nBienvenido al sistema del banco:\n");
    mostrarBanco(bancoSantander); //Mostramos el banco.
    int opcionElegida; //Acá guardaremos la opción que elija el usuario.
    do
    {
        opcionElegida = pedirOpcion(); //Pedimos una opción.
        switch (opcionElegida)
        {
            case 1:
            {
                ClientePtr clienteNuevo = crearClienteTeclado(); //Creamos un cliente con los datos que ingresa el usuario.
                int resultado = encolar(getColaClientesBanco(bancoSantander), &clienteNuevo); //Encolamos el cliente nuevo.
                if (resultado == 1) //Si resultado es 1 significa que lo encoló, si es -1 que hubo un error...
                {
                    printf("\nCliente encolado correctamente.\n");
                }
            }
            break;
            case 2:
            {
                int aux; //Una variable auxiliar para no enviar NULL al desencolar y poder realizar la función sin recuperar el cliente.
                int resultado = desencolar(getColaClientesBanco(bancoSantander), &aux); //Desencolamos un cliente y "no lo recuperamos".
                if (resultado == 1) //Si resultado es 1 significa que lo desencoló, si es -1 que hubo un error...
                {
                    printf("\nCliente desencolado correctamente.\n");
                }
            }
            break;
            case 3:
            {
                ClientePtr clienteDesencolado; //Un cliente auxiliar donde se guardará el cliente desencolado.
                int resultado = desencolar(getColaClientesBanco(bancoSantander), &clienteDesencolado); //Desencolamos un cliente y
                                                                                                       //lo recuperamos en el cliente
                                                                                                       //auxiliar.
                if (resultado == 1) //Si resultado es 1 significa que lo desencoló, si es -1 que hubo un error...
                {
                    printf("\nCliente desencolado:\n");
                    mostrarCliente(clienteDesencolado); //Mostramos el cliente desencolado mediante el cliente auxiliar.
                }
            }
            break;
            case 4:
            {
                BilletePtr billeteNuevo = crearBilleteTeclado(); //Creamos un billete con los datos que ingresa el usuario.
                int resultado = apilar(getPilaBilletesBanco(bancoSantander), &billeteNuevo); //Encolamos el billete nuevo.
                if (resultado == 1) //Si el resultado es 1 significa que lo apiló, si es -1 que hubo un error...
                {
                    printf("\nBillete apilado correctamente.\n");
                }
            }
            break;
            case 5:
            {
                int aux; //Una variable auxiliar para no enviar NULL al desapilar y poder realizar la función sin recuperar el billete.
                int resultado = desapilar(getPilaBilletesBanco(bancoSantander), &aux); //Desapilamos un billete y "no lo recuperamos".
                if (resultado == 1) //Si es 1 significa que lo desapiló, si es -1 que hubo un error...
                {
                    printf("\nBillete desapilado correctamente.\n");
                }
            }
            break;
            case 6:
            {
                BilletePtr billeteDesapilado; //Un billete auxiliar donde se guardará el billete desapilado.
                int resultado = desapilar(getPilaBilletesBanco(bancoSantander), &billeteDesapilado); //Desapilamos un billete y
                                                                                                     //lo recuperamos en el
                                                                                                     //billete auxiliar.
                if (resultado == 1) //Si es 1 significa que lo desapiló, si es -1 que hubo un error...
                {
                    printf("\nBillete desapilado:\n");
                    mostrarBillete(billeteDesapilado); //Mostramos el billete desapilado mediante el billete auxiliar.
                }
            }
            break;
            case 0:
            {
                printf("\nMuchas gracias por usar el sistema!\n");
            }
        }
    }
    while(opcionElegida != 0); //El bloque de instrucciones se repite mientras la opción elegida sea distinta de 0...
    destruirBanco(bancoSantander); //Liberamos la memoria reservada por el banco.
}
