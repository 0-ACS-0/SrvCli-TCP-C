/** 
 * Cliente TCP
 * @author Antonio Carretero Sahuquillo
*/

#include "client.h"

/* Función principal */
int main()
{
    // Estructura del cliente //
    struct cliente_t cli;
    strcpy(cli.buffer, "[CLIENTE]: Hola desde el cliente.");

    // Creación del cliente //
    //Creación del socket del cliente.
    if ((cli.client_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("[CLIENTE-ERR]: Fallo en la creación del socket.");
        exit(EXIT_FAILURE);
    }

    //Configuración de la estructura de dirección del servidor.
    cli.server_address.sin_family = AF_INET;
    cli.server_address.sin_port = htons(PORT);

    //Conversión de la dirección IP de texto a binario.
    if (inet_pton(AF_INET, "127.0.0.1", &cli.server_address.sin_addr) <= 0)
    {
        perror("[CLIENTE-ERR]: Error en la conversión de la dirección IP del servidor.");
        exit(EXIT_FAILURE);
    }

    //Conexión con el servidor.
    if (connect(cli.client_socket, (struct sockaddr*)&cli.server_address, sizeof(cli.server_address)) < 0)
    {
        perror("[CLIENTE-ERR]: Error al realizar la conexión con el servidor.");
        exit(EXIT_FAILURE);
    }

    printf("[CLIENTE]: Conectado al servidor!\n");

    /* Funcionalidad del cliente */
    env_rcv(&cli);
    /*Fin de funcionalidad del cliente */

    //Cierre del socket del cliente
    close(cli.client_socket);

    return 0;
}

