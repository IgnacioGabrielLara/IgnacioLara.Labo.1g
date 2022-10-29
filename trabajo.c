#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "servicio.h"
#include "notebook.h"


int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex)
{
    int todoOk = 0;


    if(vec && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trab[], int tamT, eNotebook vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eMarca marc[], int tamM, int* pNextId, int* pFlagT, int flagM, eCliente cliente, int tamC)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    int bufferNotebook;
    int bufferServicio;
    eFecha bufferFecha;


    if(trab != NULL && vec != NULL && pNextId != NULL && serv != NULL && tip != NULL && marc != NULL && tamTi > 0 && tamM > 0 && tam > 0 && tamS > 0 && tamT > 0 && flagM != 1)
    {
        system("cls");
        printf("*** Alta Trabajo ***\n\n");
        buscarLibreTrabajo(trab, tamT, &indice);
        if(indice == -1)
        {

            printf("No hay lugar en el sistema.\n");
            fflush(stdin);
            system("pause");
        }
        else
        {
            nuevoTrabajo.id = *pNextId;


            listarNotebook(vec, tam, tip, tamTi, marc, tamM, flagM,cliente, tamC);
            printf("Ingrese Id de Notebook: ");
            scanf("%d",&bufferNotebook);
            while(validarNotebook(vec, tam, bufferNotebook) == 0)
            {
                listarNotebook(vec, tam, tip, tamTi, marc, tamM, flagM,cliente,tamC);
                printf("Ingrese Id de Notebook: ");
                scanf("%d",&bufferNotebook);
                validarNotebook(vec, tam, bufferNotebook);
            }
            nuevoTrabajo.idNotebook = bufferNotebook;

            listarServicios(serv, tamS);
            printf("Ingrese Id de Servicio: ");
            scanf("%d",&bufferServicio);
            while(validarServicio(serv, tamS, bufferServicio) == 0)
            {
                listarServicios(serv, tamS);
                printf("Ingrese Id de Servicio: ");
                scanf("%d",&bufferServicio);
                validarServicio(serv, tamS, bufferServicio);
            }
            nuevoTrabajo.idServicio = bufferServicio;


            while(pidoValidoFecha(&bufferFecha)== 0)
            {
                if(pidoValidoFecha(&bufferFecha))
                {
                   break;
                }
            }
            nuevoTrabajo.fecha = bufferFecha;

            nuevoTrabajo.isEmpty = 0;

            trab[indice] = nuevoTrabajo;

            (*pNextId)++;
            *pFlagT = 0;
            todoOk = 1;
        }

    }
    else
    {
        printf("No hay Notebooks cargadas en el sistema\n");
         fflush(stdin);
            system("pause");
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagT)
{
    int todoOk = 0;

    if(trab != NULL && serv != NULL && tamTr > 0 && tamS > 0 && flagT != 1)
    {
         system("cls");
        printf("******************  TRABAJOS  ********************\n\n");
        printf(" ID     ID Notebook       SERVICIO              FECHA \n");
        printf("---------------------------------------------------\n\n");

        for(int i = 0; i < tamTr; i++)
        {
            if( !trab[i].isEmpty)
            {
                mostrarTrabajoFila(trab[i], serv, tamS);
            }
        }
        todoOk = 1;
    }
    else
    {
        printf("No hay trabajos cargados en el sistema\n");
    }
    return todoOk;
}

void mostrarTrabajoFila(eTrabajo trab, eServicio serv[], int tamS)
{
    char descServ[20];

    cargarDescripcionServicio(serv, tamS, trab.idServicio, descServ);

    printf("%4d     %4d       %10s           %2d/%2d/%d\n",
           trab.id,
           trab.idNotebook,
           descServ,
           trab.fecha.dia,
           trab.fecha.mes,
           trab.fecha.anio);
}

void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamS)
{
    char descServ[20];


    printf("\nId: %d\n", trab.id);
    printf("Notebook: %d\n", trab.idNotebook);
    cargarDescripcionServicio(serv, tamS, trab.idServicio, descServ);
    printf("Tipo: %s\n", descServ);
    printf("Fecha: %d/%d/%d\n", trab.fecha.dia, trab.fecha.mes, trab.fecha.anio);

}

int harcodearTrabajos(eTrabajo vec[], int tam, int* pNextId, int* pFlagT, int flagM)
{
    int todoOk = 0;
    int cant;

    eTrabajo trabajo[10] =
    {
        {0, 500, 20000 ,{29,3,2019},0},
        {0, 508, 20002 ,{2,9,2021},0},
        {0, 505, 20001 ,{9,12,2020},0},
        {0, 507, 20002 ,{14,8,2019},0},
        {0, 506, 20003 ,{12,5,2022},0},
        {0, 505, 20001 ,{5,11,2019},0},
        {0, 502, 20002 ,{23,6,2020},0},
        {0, 501, 20001 ,{16,1,2021},0},
        {0, 503, 20003 ,{31,3,2022},0},
        {0, 504, 20000 ,{2,7,2021},0},

    };
    printf("Que cantidad de trabajos desea dar de alta? 'MAXIMO 10': ");
    scanf("%d", &cant);
    while(cant < 0 || cant > 10)
    {
        printf("Que cantidad de trabajos desea dar de alta? 'MAXIMO 10': ");
        scanf("%d", &cant);
    }

    if(vec != NULL && pNextId != NULL && tam >= 0 && cant >= 0 && cant < 11 && flagM != 1)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = trabajo[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        *pFlagT = 0;
        todoOk = 1;
    }
    else
    {
        printf("No hay Notebooks cargadas en el sistema\n");
    }
    return todoOk;
}



