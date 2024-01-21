/**
 * Servidor TCP 
 * @author Antonio Carretero Sahuquillo
*/

#include "server.h"

/* Prototipo de funciones principales */
void srv_close(int signal);

/* Estructura del servidor como variable global*/
struct servidor_t serv;

/* Función principal */
int main()
{
    //Asignación de tamaño de la estructura de dirección del servidor.
    serv.addrlen = sizeof(serv.server_address); 

    //Configuración del manejador para la finalización del servidor.
    signal(SIGUSR1, srv_close);

    // Creación del servidor //
    //Creación del socket del servidor.
    if ((serv.server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        srv_log("[SERVIDOR-ERR]: Fallo en la creación del socket.");
        exit(EXIT_FAILURE);
    }

    //Configuración de la estructura de dirección del servidor.
    serv.server_address.sin_family = AF_INET;
    serv.server_address.sin_addr.s_addr = INADDR_ANY;
    serv.server_address.sin_port = htons(PORT);

    //Vinculación del socket al puerto.
    if (bind(serv.server_fd, (struct sockaddr *)&serv.server_address, sizeof(serv.server_address)) < 0)
    {
        srv_log("[SERVIDOR-ERR]: Fallo en la vinculación del socket.");
        exit(EXIT_FAILURE);
    } 

    //Socket en modo escucha.
    if(listen(serv.server_fd, 3) < 0)
    {
        srv_log("[SERVIDOR-ERR]: Error en la escucha del socket.");
        exit(EXIT_FAILURE);
    }

    srv_log("[SERVIDOR]: Servidor TCP esperando conexiones...");

    /* Bucle de funcionalidad del servidor*/
    server_loop(&serv);
    /* Fin del bucle de funcionalidad del servidor*/

    return 0;
}

/* Funciones principales del servidor */

/**
 * @brief Tras recibir la señal de salida, cierra el socket del servidor.
 * @param int signal: Señal recibida
 * 
 * @retval none
*/
void srv_close(int signal)
{
    //Cierre del socket del servidor (Solo ocurre tras indicarlo en la shell del servidor).
    close(serv.server_fd);

    srv_log("[SERVIDOR]: Socket del servidor cerrado!");

    //Finaliza el programa.
    exit(EXIT_SUCCESS);
}