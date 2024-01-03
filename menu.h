#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

///Declaraciones

///Opción
//PRE: ninguna.
//POST: la opción que se elige debe ser mayor o igual a 0 y menor o igual a 6.
int pedirOpcion();

///Menú
//PRE: ninguna.
//POST: se ejecutará mientras la opción que ingrese el usuario sea distinta de 0.
void menu();

#endif // MENU_H_INCLUDED
