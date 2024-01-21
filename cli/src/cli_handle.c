/**
 * Funcionalidad del cliente.
 *  En esta función se controlan las acciones del cliente.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#include "cli_handle.h"

/* Funciones */
void env_rcv(struct cliente_t * cli)
{
    //Envío de datos al servidor.
    send(cli->client_socket, cli->buffer, strlen(cli->buffer), 0);

    //Recepción de datos de respuesta del servidor.
    recv(cli->client_socket, cli->buffer, sizeof(cli->buffer), 0);

    printf("[CLIENTE]: Respuesta del servidor: %s\n", cli->buffer);
}