#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "validacionesDatos.h"
#include "tipo.h"
#include "marca.h"
#include "menu.h"
#include "cliente.h"



int inicializarNotebook(eNotebook vec[], int tam)
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

int menuNotebook()
{
    int opcion;
    int opcionIngresada;

    system("cls");
    printf("   *** Service de Notebook ***\n\n");
    printf("1. Alta Notebook\n");
    printf("2. Modificar Notebook\n");
    printf("3. Baja Notebook\n");
    printf("4. Listar Notebook\n");
    printf("5. Listar tipos\n");
    printf("6. Listar marca\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajo\n");
    printf("10. Informes\n");
    printf("11. Informes de trabajos\n");
    printf("12. Alta forzada/ Harcodear Notebook\n");
    printf("13. Alta forzada/ Harcodear Trabajos\n");
    printf("14. salir\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);

    opcionIngresada = (scanf("%d", &opcion));

    if(opcionIngresada == 0)
    {
        opcion = 100;
    }
    return opcion;

}

int buscarLibre(eNotebook vec[], int tam, int* pIndex)
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


int altaNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int* pNextId, int* pFlag, eCliente cliente,int tamC)
{
    int todoOk = 0;
    int indice;
    eNotebook nuevaNotebook;
    int bufferTipo;
    int buffermarca;

    int bufferprecio;

    if(vec != NULL && pNextId != NULL && tip != NULL && pFlag != NULL && tam > 0 && tamT > 0)
    {
        system("cls");
        printf("*** Alta Notebook ***\n\n");
        buscarLibre(vec, tam, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            nuevaNotebook.id = *pNextId;

            pidoValidoLetras(nuevaNotebook.modelo, tam, "Modelo");

            fflush(stdin);
            system("cls");
            listarTipos(tip, tamT);
            printf("\nIngrese Id Tipo: ");
            scanf("%d", &bufferTipo);

            while(validarTipo(tip, tamT, bufferTipo) == 0)
            {
                 fflush(stdin);
                system("cls");
                listarTipos(tip, tamT);
                printf("\nIngrese Id Tipo Valido: ");
                scanf("%d", &bufferTipo);
            }
            nuevaNotebook.idTipo = bufferTipo;

             fflush(stdin);
            system("cls");
            listarMarca(marc, tamM);
            printf("\nIngrese Id marca: ");
            scanf("%d", &buffermarca);

            while(validarMarca(marc, tamM, buffermarca) == 0)
            {
                fflush(stdin);
                system("cls");
                listarMarca(marc, tamM);
                printf("\nIngrese Id marca Valido: ");
                scanf("%d", &buffermarca);
            }
            nuevaNotebook.idMarca = buffermarca;

            fflush(stdin);
            system("cls");
            printf("\nIngrese precio: ");
            scanf("%d", &bufferprecio);
            while(bufferprecio < 1 )
            {
                 fflush(stdin);
                system("cls");
                printf("\nIngrese precio: ");
                scanf("%d", &bufferprecio);
            }
            nuevaNotebook.precio = bufferprecio;

           altaCliente(cliente, tamC);

          strcpy(nuevaNotebook.nombrecliente,cliente.nombre);

            nuevaNotebook.isEmpty = 0;

            vec[indice] = nuevaNotebook;

            (*pNextId)++;
            *pFlag = 0;
            todoOk = 1;
        }

    }
    return todoOk;
}



int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if(vec && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarNotebook(eNotebook vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarNotebook(vec, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

void mostrarNotebook (eNotebook vec, int tam, eTipo tip[], int tamT, eMarca marc[], int tamM)
{
    char descTip[20];
    char descmarc[20];

    printf("\nId: %d\n", vec.id);
    printf("Modelo: %s\n", vec.modelo);
    cargarDescripcionTipo(tip, tamT, vec.idTipo, descTip);
    printf("Tipo: %s\n", descTip);
    cargarDescripcionMarca(marc, tamM, vec.idMarca, descmarc);
    printf("marca: %s\n", descmarc);
    printf("precio: %.2f\n", vec.precio);

}

int listarNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int flagM, eCliente cliente, int tamC)
{
    int todoOk = 0;

    if(vec != NULL && tip != NULL && marc != NULL && tam > 0 && tamT > 0 && tamM > 0 && flagM != 1)
    {
        system("cls");
        printf("*************************************** Notebook **************************************\n\n");
        printf(" ID           MARCA            TIPO            marca            precio        nombre\n");
        printf("-------------------------------------------------------------------------------------\n\n");

        for(int i = 0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                mostrarNotebookFila(vec[i], tam, tip, tamT, marc, tamM,cliente,tamC);
            }
        }
        todoOk = 1;
        system("pause");
    }
    else
    {
        printf("Primero debe cargar Notebook en el sistema\n");
        system("pause");
    }
    return todoOk;
}

void mostrarNotebookFila(eNotebook vec, int tam, eTipo tip[], int tamT, eMarca marc[], int tamM,eCliente cliente, int tamC)
{
    char descTip[20];
    char descmarc[20];

    cargarDescripcionTipo(tip, tamT, vec.idTipo, descTip);
    cargarDescripcionMarca(marc, tamM, vec.idMarca, descmarc);

    printf("%4d     %10s       %10s      %10s     %.2f  %s \n",
           vec.id,
           vec.modelo,
           descTip,
           descmarc,
           vec.precio,
           vec.nombrecliente);
}

int bajaNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int flag,eCliente cliente, int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(vec != NULL && tip != NULL && marc != NULL && tam > 0 && tamT > 0 && tamM > 0 && flag != 1)
    {
        listarNotebook(vec, tam, tip, tamT, marc, tamM, flag,cliente,tamC);
        printf("Ingrese Id: ");
        scanf("%d",&id);

        if(buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe notebook con id %d en el sistema.\n", id);
                system("pause");
            }
            else
            {
                mostrarNotebook(vec[indice], tam, tip, tamT, marc, tamM);
                printf("\nPresione 's' para confirmar baja: ");
                fflush(stdin);
                scanf("%c",&confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!\n");
                    system("pause");
                }
                else
                {
                    printf("Baja cancelada por el usuario!\n");
                    system("pause");
                }
            }
            todoOk = 1;
        }
    }
    else
    {
        printf("Primero debe cargar Notebook en el sistema\n");
    }
    return todoOk;
}



int menuModificarNotebook()
{
    int opcion;

    printf("\n   *** Campo a modificar ***\n\n");
    printf("1. marca\n");
    printf("2. precio\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarNotebook(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM, int flag, eCliente cliente, int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int idMarca;
    int precio;

    if(vec && tip && marc && tam > 0 && tamT > 0 && tamM > 0 && flag != 1)
    {
        listarNotebook(vec, tam, tip, tamT, marc, tamM, flag,cliente,tamC);
        printf("Ingrese Id: ");
        scanf("%d",&id);

        if(buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe Notebook con id %d en el sistema.\n", id);
                system("pause");
            }
            else
            {
                mostrarNotebook(vec[indice], tam, tip, tamT, marc, tamM);

                switch(menuModificarNotebook())
                {
                case 1:
                    listarMarca(marc, tamM);

                    printf("Ingrese nuevo Id marca: ");
                    scanf("%d", &idMarca);

                    while(validarMarca(marc, tamM, idMarca) == 0)
                    {
                        listarMarca(marc, tamM);
                        printf("Ingrese Id marca Valido: ");
                        scanf("%d", &idMarca);
                    }
                    vec[indice].idMarca = idMarca;
                    printf("marca modificado!\n");
                    break;

                case 2:
                    printf("Ingrese precio: ");
                    int validoModPrecio = scanf("%d", &precio);
                    while(precio < 1 || validoModPrecio == 0)
                    {
                        printf("Ingrese precio: ");
                        scanf("%d", &precio);
                    }
                    vec[indice].precio = precio;
                    break;

                    printf("precio modificado!\n");
                    break;
                }
            }
            todoOk = 1;
        }
    }
    else
    {
        printf("Primero debe cargar Notebook en el sistema\n");
    }
    return todoOk;
}

int mostrarNotebookPormarca(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM)
{
    int todoOk = 0;



    if(vec != NULL && tip != NULL && marc != NULL && tam > 0 && tamT > 0 && tamM > 0)
    {
        todoOk = 0;
        eNotebook auxVec;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j = i +1; j < tam ; j++)
            {
               if(((vec[i].idMarca == vec[j].idMarca) && (vec[i].precio > vec[j].precio))
                   ||((vec[i].idMarca != vec[j].idMarca) && (vec[i].precio > vec[j].precio)))
                   {
                       auxVec = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxVec;
                   }
            }
        }





}
}
 return todoOk;
}

void informeUno(eNotebook vec[], int tam, eTipo tipo[], int tamTip)
{
    int id;
    char descTip[20];

    if(vec != NULL && tam>0 && tipo != NULL && tamTip>0)
    listarTipos(tipo,tamTip);
    printf("Ingrese Id: ");
    scanf("%d",&id );
    if(validarTipo(tipo,tamTip,id))
    {
        for(int i = 0;i<tam;i++)
        {
            if(tipo[i].id == id)
            {
                cargarDescripcionTipo(tipo, tamTip, vec[i].idTipo, descTip);

                printf("%4d     %10s       %10s      %.2f\n",
               vec[i].id,
               vec[i].modelo,
               descTip,
               vec[i].precio);
            }
        }
    }
    else
    {
        printf("Id inexistente");
    }

}

void informeDos(eNotebook vec[], int tam, eMarca marca[], int tamM)
{

    int id;
    char descMarc[20];

    if(vec != NULL && tam>0 && marca != NULL && tamM>0)
    listarMarca(marca,tamM);
    printf("Ingrese Id: ");
    scanf("%d",&id );
    if(validarMarca(marca,tamM,id))
    {
        for(int i = 0;i<tam;i++)
        {
            if(marca[i].id == id)
            {
                cargarDescripcionMarca(marca, tamM, vec[i].idMarca, descMarc);

                printf("%4d     %10s       %10s      %.2f\n",
               vec[i].id,
               vec[i].modelo,
               descMarc,
               vec[i].precio);
            }
        }
    }
    else
    {
        printf("Id inexistente");
    }

}

void informeTres(eNotebook vec[],int tam)
{
    eNotebook masBarata;

    int flag = 1;

    for(int i = 0;i<tam;i++)
    {
        if(vec[i].precio < masBarata.precio || flag == 1)
        {
            masBarata = vec[i];
            flag = 0;
        }
    }


}

void informeCuatro(eNotebook vec[], int tam, eTipo tip[], int tamT, eMarca marc[], int tamM)
{

    if(vec != NULL && tip != NULL && marc != NULL && tam > 0 && tamT > 0 && tamM > 0)
    {

        eNotebook auxVec;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j = i +1; j < tam ; j++)
            {
               if((vec[i].idMarca == vec[j].idMarca )
                   ||(vec[i].idMarca != vec[j].idMarca))
                   {
                       auxVec = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxVec;
                   }
            }
        }





}
}
}

void informeCinco(eNotebook vec[], int tam, eTipo tipo[], int tamTip, eMarca marca[], int tamM)
{
    int idMarca;
    int idTipo;

    int contadorMarca = 0;
    int contadorTipo = 0;

    if(vec != NULL && tam>0 && tipo != NULL && tamTip>0 && marca != NULL && tamM>0)
    {
        fflush(stdin);
        listarMarca(marca,tamM);
        printf("Ingrese id marca: ");
        scanf("%d",&idMarca);
        while(!validarMarca(marca,tamM,idMarca))
        {
            fflush(stdin);
            printf("Error. Ingrese id marca: ");
            scanf("%d",&idMarca);

        }

         fflush(stdin);
        listarTipos(tipo,tamTip);
        printf("Ingrese id tipo: ");
        scanf("%d",&idTipo);
        while(!validarTipo(tipo,tamTip,idTipo))
        {
            fflush(stdin);
            printf("Error. Ingrese id tipo: ");
            scanf("%d",&idTipo);
        }


        for(int i = 0;i<tam;i++)
        {
            if(vec[i].idMarca == idMarca)
            {
                contadorMarca++;
            }

            if(vec[i].idTipo == idTipo)
            {

                contadorTipo++;
            }
        }
    }
}

void informeSeis(eNotebook vec[], int tam, eMarca marca[], int tamM)
{

    eMarca marcaMasElegida;

    int contador[4] = {0,0,0,0};


    if(vec != NULL && tam>0 && marca != NULL && tamM>0)
    {
        for(int i=0;i<tam;i++)
        {
            switch(marca[i].id)
            {
            case 0:
                contador[0]++;
                break;

            case 1:
                contador[1]++;
                break;

            case 2:
                contador[2]++;
                break;

            case 3:
                contador[3]++;
                break;
            }
        }
        if(contador[0] > contador[1] && contador[0] > contador[2] &&contador[0] > contador[3])
        {
            marcaMasElegida = marca[0];
        }
        else if(contador[1] > contador[0] && contador[1] > contador[2] &&contador[1] > contador[3])
        {
            marcaMasElegida = marca[1];
        }

        else if(contador[2] > contador[0] && contador[2] > contador[1] &&contador[2] > contador[3])
        {
            marcaMasElegida = marca[2];
        }
        else{
            marcaMasElegida = marca[3];
        }
    }

    printf("La marca mas elegida es %s", marcaMasElegida.descripcion);
}




