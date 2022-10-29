#include "fecha.h"
#include "notebook.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief carga en 1 los campos isEmpty de las estructuras del array de trabajos
 *
 * \param vec[] eTrabajo array de structuras de trabajos
 * \param tam int tamaño del array de trabajos
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarTrabajo(eTrabajo vec[], int tam);

/** \brief busca la estructura vacia mas proxima
 *
 * \param vec[] eTrabajo array de structuras de trabajos
 * \param tam int tamaño del array de trabajos
 * \param pIndex int* carga aqui el indice de la estructura encontrada
 * \return int devuelve 1 si pudo encontrar la estructura
 *
 */
int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex);

/** \brief permite cargar los datos de un alta de un nuevo trabajo
 *
 * \param trab[] eTrabajo array de structuras de trabajos
 * \param tamT int tamaño del array de trabajos
 * \param vec[] eNotebook array de Notebooks
 * \param tam int tamaño array de Notebooks
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \param tip[] eTipo array de tipos
 * \param tamTi int tamaño del array de tipos
 * \param marc[] eMarca array de marcores
 * \param tamM int tamaño del array de marcores
 * \param pNextId int* proximo numero de id
 * \return int devuelve 1 si pudo dar de lata el nuevo trabajo
 *
 */
int altaTrabajo(eTrabajo trab[], int tamT, eNotebook vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eMarca marc[], int tamM, int* pNextId, int* pFlagT, int flagM, eCliente cliente, int tamC);

/** \brief muestra en forma de tabla los trabajos guardados
 *
 * \param trab[] eTrabajo  array de structuras de trabajos
 * \param tamTr int tamaño del array de trabajos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \return int retorna 1 si pudo mostrar
 *
 */
int listarTrabajos(eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagT);

/** \brief muestra los datos guardados en una estructura de trabajos
 *
 * \param trab eTrabajo estructuras de trabajos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \return void
 *
 */
void mostrarTrabajoFila(eTrabajo trab, eServicio serv[], int tamS);

/** \brief muestra los datos guardados en una estructura de trabajos
 *
 * \param trab eTrabajo estructuras de trabajos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamS);

/** \brief alta forzada para estructuras de trabajos
 *
 * \param vec[] eTrabajo array de estructuras de trabajos
 * \param tam int int tamaño del array de trabajos
 * \param cant int cantidad de estructuras a dar de alta
 * \param pNextId int* direccion de memoria del siguiente id
 * \return int devuelve 1 si pudo dar de alta las estructuras solicitadas
 *
 */
int harcodearTrabajos(eTrabajo vec[], int tam, int* pNextId, int* pFlagT, int flagM);


/** \brief imprime en pantalla las opciones de informes de trabajos y permite al usuario ingresadr una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuInformesTrabajos();



