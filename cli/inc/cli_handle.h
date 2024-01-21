/**
 * Fichero de cabecera para el control de la funcionalidad del cliente.
 *  Este fichero contiene únicamente los prototipos de las funciones del cliente.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#ifndef CLI_HANDLE 
#define CLI_HANDLE

#include "client.h"

/* Estructura de datos del cliente */
struct cliente_t{
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
};

/* Prototipos */
void env_rcv(struct cliente_t * cli);


#endif