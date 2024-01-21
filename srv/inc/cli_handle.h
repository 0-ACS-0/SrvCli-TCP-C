/**
 * Fichero de cabecera para el control del manejo del cliente.
 *  Este fichero contiene los prototipos de las funciones del cliente.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#ifndef CLI_HANDLE
#define CLI_HANDLE

#include "server.h"

/* Estructura para el manejo del cliente */
struct cliente_t{
    int client_socket;                              //Identificador del socket del cliente.
    char msg_tx[1024];                              //Buffer con el mensaje a transmitir.
    char msg_rx[1024];                              //Buffer con el mensaje recibido.
    ssize_t send_bytes, read_bytes;                 //Tamaño de los mensajes enviados y recibidos.

    char * sh_cmd;                                  //Comando de la shell del servidor.
};

/* Prototipos */
void *handle_client(void *arg);

#endif