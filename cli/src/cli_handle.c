/**
 * Funcionalidad del cliente.
 *  En esta función se controlan las acciones del cliente.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#include "cli_handle.h"

/* Funciones */

/**
 * @brief Función que controla el comprotamiento del cliente, una vez realizada la conexión.
 * @param struct cliente_t * cli: Estructura que contiene toda la información de la conexińo del cliente.
 * 
 * @retval None
*/
void env_rcv(struct cliente_t * cli)
{
    //Envío de datos al servidor.
    send(cli->client_socket, cli->buffer, strlen(cli->buffer), 0);

    //Recepción de datos de respuesta del servidor.
    recv(cli->client_socket, cli->buffer, sizeof(cli->buffer), 0);

    printf("[CLIENTE]: Respuesta del servidor: %s\n", cli->buffer);
}