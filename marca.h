#ifndef Marca_H_INCLUDED
#define Marca_H_INCLUDED

typedef struct
{
   int id;
   char descripcion[20];
}eMarca;

#endif // Marca_H_INCLUDED
/** \brief recibe el id de un Marca y devuelve la descripcion
 *
 * \param eMarca vector de la estructura Marca
 * \param int tamaño del vector Marca
 * \param int id de la descripcion a copiar
 * \param char cadena de caracteres donde se copiara la descripcion
 * \return retorna 1 si pudo copiar la descripcion
 *
 */
int cargarDescripcionMarca(eMarca marc[], int tam, int id, char desc[]);

/** \brief muestra en forma de tabla todas las esctructuras de Marca guardadas en el vector de Marcaes
 *
 * \param eMarca vector de la estructura Marca
 * \param int tamaño del vector Marca
 * \return retorna 1 si pudo mostrar con exito
 *
 */
int listarMarca(eMarca marc[], int tam);

/** \brief recibe un id de tipo Marca y busca ese id en el vector de Marcaes
 *
 * \param eMarca vector de la estructura Marca
 * \param int tamaño del vector Marca
 * \param int id a buscar
 * \param  int* donde cargara el indice del id encontrado
 * \return retorna 1 si pudo encontar el id
 *
 */
int buscarMarca(eMarca marc[], int tam, int id, int* pIndex);


/** \brief recibe un id y valida si ese id existe en el vector de Marcaes
 *
 * \param marc[] eMarca vector de la estructura Marca
 * \param tam int tamaño del vector Marca
 * \param id int id a validar
 * \return int retorna 1 si el id es valido, 0 en caso de que no lo fuera
 *
 */
int validarMarca(eMarca marc[], int tam, int id);
