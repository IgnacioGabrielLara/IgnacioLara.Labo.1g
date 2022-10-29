#include "tipo.h"
#include "marca.h"
#include "cliente.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idTipo;
    int idMarca;
    float precio;
    char nombrecliente[20];
    int isEmpty;

}eNotebook;

#endif // Notebook_H_INCLUDED

/** \brief coloca todos los campos isEmpty del vector de Notebook en 1
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarNotebook(eNotebook vec[], int tam);



/** \brief imprime en pantalla el menu con las opciones y permite al usuario el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuNotebook();

/** \brief busca la primer estructura del array de Notebook q este vacia
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibre(eNotebook vec[], int tam, int* pIndex);

/** \brief permite el ingreso de datos para dar de alta una Notebook en el sistema
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param marc[] eMarca vector de estructuras de marca
 * \param tamM int tamaño del vector de marca
 * \param pNextId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de Notebook vacia
 *
 */
int altaNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int* pNextId, int* pFlag, eCliente cliente, int tamC);



/** \brief recibe un id y busca en q posicion del vector de Notebook se encuentra
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param id int id ingresado por el usuario
 * \param pIndex int* direccion de memoria donde volcara el valor del indicce donde se encuentra
 * \return int devuelve 1 si encontro el id
 *
 */
int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex);

/** \brief recibe un id y valida si es un id presente en el vector de Notebook
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param id int id ingresado por el usuario
 * \return int devuelve 1 si es valido, -1 si es invalido
 *
 */
int validarNotebook(eNotebook vec[], int tam, int id);


/** \brief muestra la esctructura del indice pedido del vector de Notebook
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param marc[] eMarca vector de estructuras de marca
 * \param tamM int tamaño del vector de marca
 * \return void
 *
 */
void mostrarNotebook (eNotebook vec, int tam, eTipo tip[], int tamT, eMarca marc[], int tamM);


/** \brief muestra en forma de tabla las estructuras q no estan vacias del vector de Notebook
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param marc[] eMarca vector de estructuras de marca
 * \param tamM int tamaño del vector de marca
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int flagM, eCliente cliente, int tamC);

/** \brief muestra la esctructura del indice pedido del vector de Notebook
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param marc[] eMarca vector de estructuras de colores
 * \param tamM int tamaño del vector de colores
 * \return void
 *
 */
void mostrarNotebookFila(eNotebook vec, int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, eCliente cliente, int tamC);

/** \brief permite ingresar un id y dar de baja a ese id
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param marc[] eMarca vector de estructuras de marca
 * \param tamM int tamaño del vector de marca
 * \return int retorna 1 si pudo realizar la baja
 *
 */
int bajaNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int flag, eCliente cliente, int tamC);

/** \brief muestra las opciones del menu modificar y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuModificarNotebook();

/** \brief perimte realizar un alta forzada de datos en el array de Notebook
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param cant int cantidad de Notebook q se desean dar de alta
 * \param pNextId int* direccion de memoria del siguiente id a usar
 * \return int devuelve 1 si pudo realizar las altas solicitadas
 *
 */
int harcodearNotebook(eNotebook vec[], int tam, int* pNextId, int* pFlag);

/** \brief realiza las opciones de modificacion deseadas
 *
 * \param vec[] eNotebook vector de estructuras de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param marc[] eMarca vector de estructuras de marca
 * \param tamM int tamaño del vector de marca
 * \return int devuelve 1 si pudo realizar las modificaciones
 *
 */
int modificarNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int flag,eCliente cliente, int tamC);


/** \brief permite al usuario ingresar un id de color y muestra todas las Notebook cargadas en el sistema de ese color
 *
 * \param vec[] eNotebook array de estructura de Notebook
 * \param tam int tamaño del vector de Notebook
 * \param tip[] eTipo array de estructura de tipos
 * \param tamT int tamaño del array de tipos
 * \param marc[] eMarca array de estructura de marca
 * \param tamM int tamaño del array de marca
 * \return int retorna 1 si pudo mostrar
 *
 */
int mostrarNotebookPorColor(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM);



