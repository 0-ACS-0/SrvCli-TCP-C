/**
 * Fichero de cabecer del servidor
 *  Este fichero contiene todos las librerías necesarias para la ejecución del servidor.
 *  Este fichero contiene todas las definiciones necesarias para la ejecución del servidor.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#ifndef SERVER
#define SERVER

/* Librerías */
#include <stdio.h>          //Librerías del sistema
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#include "cli_handle.h"     //Librerías del proyecto
#include "srv_handle.h"     
#include "srv_shell.h"
#include "srv_log.h"

/* Definición de características del servidor*/
#define PORT 8080
#define BUFFER_SIZE 1024

#endif

