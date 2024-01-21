/**
 * Servidor TCP 
 * @author Antonio Carretero Sahuquillo
*/

#include "server.h"

/* Función principal */
int main()
{
    // Estructura del servidor //
    struct servidor_t serv;
    serv.addrlen = sizeof(serv.server_address); 

    // Creación del servidor //
    //Creación del socket del servidor.
    if ((serv.server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("[SERVIDOR-ERR]: Fallo en la creación del socket.");
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
        perror("[SERVIDOR-ERR]: Fallo en la vinculación del socket.");
        srv_log("[SERVIDOR-ERR]: Fallo en la vinculación del socket.");
        exit(EXIT_FAILURE);
    } 

    //Socket en modo escucha.
    if(listen(serv.server_fd, 3) < 0)
    {
        perror("[SERVIDOR-ERR]: Error en la escucha del socket.");
        srv_log("[SERVIDOR-ERR]: Error en la escucha del socket.");
        exit(EXIT_FAILURE);
    }

    printf("[SERVIDOR]: Servidor TCP esperando conexiones en el puerto %d...\n", PORT);
    srv_log("[SERVIDOR]: Servidor TCP esperando conexiones...");

    /* Bucle de funcionalidad del servidor*/
    server_loop(&serv);
    /* Fin del bucle de funcionalidad del servidor*/

    //Cierre del socket del servidor (Solo ocurre una vez detenido el servidor).
    close(serv.server_fd);

    return 0;
}
