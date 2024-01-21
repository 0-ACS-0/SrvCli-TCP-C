/**
 * Bucle infinito del servidor.
 *  En este bucle se controla la funcionalidad del mismo.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#include "srv_handle.h"

/* Funciones */

void server_loop(struct servidor_t * serv)
{
    while (1)
    {
        //Aceptación de la conexión entrante
        if ((serv->client_socket = accept(serv->server_fd, (struct sockaddr *)&serv->client_address, (socklen_t*)&serv->addrlen)) < 0)
        {
            perror("[SERVIDOR-ERR]: Error al aceptar la conexión con el cliente.");
            exit(EXIT_FAILURE);
        }

        printf("[SERVIDOR]: Conexión aceptada.\n");

        //Creación de un hilo para el manejo del cliente.
        if (pthread_create(&serv->thread_id, NULL, handle_client, (void *)&serv->client_socket) < 0)
        {
            perror("[SERVIDOR-ERR]: Error en la creación del hilo para el manejo del cliente.");
            exit(EXIT_FAILURE);
        }

        //Permiso para que el hilo se ejecute de manera independiente
        pthread_detach(serv->thread_id);
    }
}