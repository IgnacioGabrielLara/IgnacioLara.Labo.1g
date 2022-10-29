#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

int cargarDescripcionMarca(eMarca marc[], int tam, int id, char desc[])
{
    int todoOk = 0;

    if(marc != NULL && desc != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(marc[i].id == id)
          {
              strcpy(desc, marc[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

int listarMarca(eMarca marc[], int tam)
{
    int todoOk = 0;

    if(marc != NULL && tam > 0)
    {
        printf("    *** MarcaES ***    \n");
        printf("    ID           DESCRIPCION\n");
        printf("-----------------------------\n");
      for(int i = 0; i < tam; i++)
      {
            printf("    %4d         %10s\n", marc[i].id, marc[i].descripcion);
      }
      todoOk = 1;
    }
    return todoOk;
}

int buscarMarca(eMarca marc[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if(marc && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(marc[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarMarca(eMarca marc[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarMarca(marc, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

