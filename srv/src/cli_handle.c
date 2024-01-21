/**
 * Bucle infinito del cliente.
 *  En este bucle se controla la interacción con el cliente.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#include "server.h"
#include "cli_handle.h"

/* Funciones */
void *handle_client(void *arg)
{
    // Variables locales del cliente.
    int client_socket = *((int *)arg);      //Socket del cliente.
    char buffer[BUFFER_SIZE];               //Tamaño del buffer.
    ssize_t read_bytes;                     //Bytes leídos del cliente.

    // Manejo de la comunicación con el cliente.
    while ((read_bytes = recv(client_socket, buffer, sizeof(buffer), 0)) > 0)
    {
        // PROCESAR LA SOLICITUD DEL CLIENTE //
            //En este caso solo se reenvía la misma información que envía el cliente.
        send(client_socket, buffer, read_bytes, 0);
    }

    // Cierre del socket del cliente.
    close(client_socket);

    //Finalización del hilo del cliente.
    pthread_exit(NULL);
}