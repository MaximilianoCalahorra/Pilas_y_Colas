# Descripción del programa
Consiste en un **menú de opciones que se aplica en una struct Banco para operar con sus principales atributos que son una pila de structs Billete y una cola de structs Cliente**. Tanto **la pila como la cola son \*void**, por lo que en realidad pueden adaptarse a cualquier tipo de dato. **Está implementado totalmente en C aplicando los conceptos de pilas y colas \*void, structs, TDA y manejo dinámico de la memoria**.

*Aclaración: en el siguiente apartado menciono 'funcionalidades básicas', con ello me refiero a un constructor, un destructor, los getters, los setters y un mostrar*.

El programa **incluye**:
- Una struct Cliente con sus funcionalidades básicas, nombre, apellido y DNI.
- Una struct Billete con sus funcionalidades básicas, valor, color y código.
- Una struct Banco con sus funcionalidades básicas, nombre, dirección, cola de clientes (cola *void con structs Cliente) y pila de billetes (pila *void con structs Billete).
- Un código de cola *void que permite crearla, encolar un nodo, desencolar un nodo y destruir la cola.
- Un código de pila *void que permite crearla, apilar un nodo, desapilar un nodo y destruir la pila.
- **Menú de opciones**:
  - **De la 1 a la 3 refieren al manejo de la cola de clientes del banco**:
    - #1: Agrega un cliente con las características indicadas al final de la cola.
    - #2: Quita el primer cliente de la cola.
    - #3: Quita el primer cliente de la cola e imprime sus datos por consola.
  - **De la 4 a la 6 refieren al manejo de la pila de billetes del banco**:
    - #4: Agrega un billete con las características indicadas al final de la pila.
    - #5: Quita el último billete de la pila.
    - #6: Quita el último billete de la pila e imprime sus datos por consola.
  - **La opción #0 es para finalizar el programa**.

*Gracias por interesarte en visitar este repositorio y leer acerca de él*.

¡Saludos!

Maximiliano Calahorra.
