/**
 * Implementación de la shell del servidor.
 *  Incluye todo tipo de funcionalidad para comprobar el estado del servidor.
 * 
 * @author Antonio Carretero Sahuquillo
*/

#include "server.h"
#include "srv_shell.h"

/* Prototipos de las funciones "ocultas" */
static void * srv_shell();
static void srv_prompt(char * cmd);
static void srv_interpreter(char * cmd);


/* Funciones */

/**
 * @brief Inicia en un hilo la shell del servidor.
 * @param none
 * 
 * @retval none
*/
void srv_init_shell()
{
    //Creación del hilo de shell.
    pthread_t sh_th;

    if ((pthread_create(&sh_th, NULL, srv_shell, NULL)) < 0)
    {
        perror("[SRV-SHELL-ERR]: Error en la creación del hilo de la shell del servidor.");
        exit(EXIT_FAILURE);
    }

    //Permiso para que el hilo se ejecute de manera independiente.
    pthread_detach(sh_th);
}


/* Funciones "Ocultars" */

/**
 * @brief Implementacioón de la shell del servidor.
 * @param void * running: Condición de finalización del servidor.
 * 
 * @retval none
*/
static void * srv_shell()
{
    char cmd[SHELL_BUFFER_SIZE];    //Buffer donde se almacenará el comando introducido.

    //Bucle infinito de la shell
    while(1)
    {
        //Prompt y lectura del comando.
        srv_prompt(cmd);

        //Opción <exit>
        if (!strcmp(cmd, "exit"))
        {
            raise(SIGUSR1);     //Señal de salida del servidor.
            
            pthread_exit(NULL);
            exit(EXIT_SUCCESS);
        }

        //Intérprete del comando (realiza la acción).
        srv_interpreter(cmd);
    }

}

/**
 * @brief Función que imprime el prompt del servidor y lee la entrada del administrador.
 * @param char * cmd: Lugar donde se almacenará la entrada por consola.
 * 
 * @retval none
*/
static void srv_prompt(char * cmd)
{
    //Impresión del prompt que indica la entrada del administrador.
    printf("[SRV-SHELL](type <help> for a list of commands)$ ");

    //Lectura de entrada del administrador.
    scanf(" %s", cmd);
}


/**
 * @brief Intérprete de comandos de lal shell.
 * @param char * cmd: Cadena de carácteres introducido por el usuario.
 * 
 * @retval none
*/
static void srv_interpreter(char * cmd)
{

    //Opción <help>
    if(!strcmp(cmd, "help"))
    {
        printf("\n______________________________________________________\n");
        printf("\n Por el momento esta shell está en desarrollo, por \n lo que cualquier comando introducido\n será devuelto a la consola. \n\n Lista de comandos implementados: \n\t <exit>: Finaliza la ejecución del servidor.\n\n");
        printf("\n______________________________________________________\n");
    }

    printf("\n Comando introducido: %s\n\n", cmd);
}