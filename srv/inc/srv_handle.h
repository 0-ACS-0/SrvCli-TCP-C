/**
 * Fichero de cabecera para el control de la funcionalidad del servidor.
 *  Este fichero contiene únicamente los prototipos de las funciones del servidor.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#ifndef SRV_HANDLE
#define SRV_HANDLE

/* Estructura de datos del servidor */
struct servidor_t{
    
    int server_fd, client_socket;                           //Descriptores de archivo para servidor y cliente.
    struct sockaddr_in server_address, client_address;      //Estructura de dirección para el servidor y el cliente.
    int addrlen;                                            //Longitud de las estructuras de los sockets.

    pthread_t thread_id;                                    //ID del hilo manejador del cliente.
};

/* Prototipos */
void server_loop(struct servidor_t * serv);

#endif