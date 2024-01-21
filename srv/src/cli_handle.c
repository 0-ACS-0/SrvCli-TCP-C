/**
 * Bucle infinito del cliente.
 *  En este bucle se controla la interacción con el cliente.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#include "cli_handle.h"

/* Prototipos para las funciones "ocultas" */
static void * srv_tx(void * arg);
static void * srv_rx(void * arg);

/* Funciones */

/**
 * @brief Función que maneja la interacción con el cliente, una vez realizada la conexión.
 * @param void *arg: Descriptor de archvio del cliente recién conectado.
 * 
 * @retval None
*/
void *handle_client(void *arg)
{
    // Inicialización de la estructura del cliente conectado.
    struct cliente_t cli;
    cli.client_socket = *((int *)arg);


    // Manejo de la comunicación con el cliente.


    // Cierre del socket del cliente.
    close(cli.client_socket);

    //Finalización del hilo del cliente.
    pthread_exit(NULL);
}

/* Funciones "ocultas" */

/**
 * @brief Hilo de transmisión servidor-->cliente, de la conexión realizada.
 * @param void * arg: Estructura para el manejo de los datos del cliente.
 * 
 * @retval none
*/
static void * srv_tx(void * arg)
{
    //Estructura del cliente
    struct cliente_t cli = *((struct cliente_t *)arg);

    //Bucle infinito de transmisión
    while(1)
    {
        //send(cli.client_socket, cli.msg_tx, sizeof(cli.msg_tx), 0);
    }

    //Finalización del hilo
    pthread_exit(NULL);
}

/**
 * @brief Hilo de recepción servidor<--cliente, de la conexión realizada.
 * @param void * arg: Estructura para el manejo de los datos del cliente.
 * 
 * @retval none
*/
static void * srv_rx(void * arg)
{
    //Estructura del cliente
    struct cliente_t cli = *((struct cliente_t *)arg);

    //Bucle infinito de recepción.
    while(1)
    {
        //Lectura y almacenamiento de datos recividos por el cliente.
        while((cli.read_bytes = recv(cli.client_socket, cli.msg_rx, sizeof(cli.msg_rx), 0)) > 0);
    }

    //Finalización del hilo
    pthread_exit(NULL);
}