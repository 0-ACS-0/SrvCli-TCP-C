/**
 * Implementación de ficheros lod del servidor.
 * 
 * @author Antonio Carretero Sahuquillo
 *  
*/

#include "server.h"
#include "srv_log.h"

/* Funciones */

/**
 * @brief Escribe el estado de servidor en un fichero .log
 * @param 
 * 
 * @retval int: Indica si ha habido algún error durante el almacenado en el log 
*/
int srv_log(const char * status)
{
    //Crea el archivo .log si no existe
    system("mkdir -p ./logs/ && touch ./logs/server.log");
    
    //Apertura del archivo en modo append.
    FILE * archivo = fopen("./logs/server.log", "a");

    //Verificación de que el archivo se ha abierto correctamente.
    if (archivo == NULL)
    {
        fprintf(stderr, "No se ha podido habrir el archivo <server.log>.\n");
        return 1;
    }

    //Escritura de la cadena en el archivo .log
    fprintf(archivo, "%s\n", status);

    //Cierre del archivo tras escritura.
    fclose(archivo);

    return 0;
}