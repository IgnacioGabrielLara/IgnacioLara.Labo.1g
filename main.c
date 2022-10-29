#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "menu.h"

#define TAM 15
#define TAMT 4
#define TAMM 4
#define TAMS 4
#define TAMTR 40
#define TAMC 4

int main()
{
    char salir ='n';
    int proxIdNotebook = 500;
    int proxIdTrabajo = 7000;
    int flagNotebook = 1;
    int flagTrab = 1;
    eNotebook Notebooks[TAM];
    eTrabajo trabajos[TAMTR];
    eTipo tipos[TAMT] =
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };
    eMarca marca[TAMM] =
    {
        {10000, "Compaq"},
        {10001, "Asus"},
        {10002, "Acer"},
        {10003, "HP"}
     };


    eServicio servicios[TAMS] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Teclado", 4400},
        {20003, "Fuente", 5600}
    };

    eCliente cliente;

    inicializarNotebook(Notebooks, TAM);
    inicializarTrabajo(trabajos, TAMTR);

    do
    {
         switch(menu())
        {
        case 'a':
            if(altaNotebook(Notebooks, TAM, tipos, TAMT, marca, TAMM, &proxIdNotebook, &flagNotebook, cliente,TAMC))
            {
                printf("Datos cargados con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar los datos\n");
            }
            break;
        case 'b':

            modificarNotebook(Notebooks, TAM, tipos, TAMT, marca, TAMM, flagNotebook,cliente, TAMC);
            break;

        case 'c':
            bajaNotebook(Notebooks, TAM, tipos, TAMT, marca, TAMM, flagNotebook, cliente,TAMC);
            break;
        case 'd':
             listarNotebook(Notebooks, TAM, tipos, TAMT, marca, TAMM, flagNotebook,cliente,TAMC);
            break;
        case 'e':
            listarMarca(marca,TAMM);
            system("pause");
            break;
        case 'f':
            listarTipos(tipos, TAMT);
            system("pause");
            break;
        case 'g':
            listarServicios(servicios,TAMS);
            system("pause");
            break;
        case 'h':
            if(altaTrabajo(trabajos, TAMTR, Notebooks, TAM, servicios, TAMS, tipos, TAMT, marca, TAMM, &proxIdTrabajo, &flagTrab, flagNotebook,cliente,TAMC))
            {
                printf("Trabajo cargado con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar trabajo\n");
            }
            break;
        case 'i':
             listarTrabajos(trabajos, TAMTR, servicios, TAMS, flagTrab);
             system("pause");
             break;
        case 'j':
            switch(menuInformes())
            {
                case 1:
                    informeUno(Notebooks,TAM,tipos,TAMT);
                    break;
                case 2:
                    informeDos(Notebooks,TAM,marca,TAMM);
                    break;
                case 3:
                    informeTres(Notebooks, TAM);
                    break;
                case 4:
                    informeCuatro(Notebooks,TAM,tipos,TAMT,marca,TAMM);
                    break;
                case 5:
                    informeCinco(Notebooks,TAM,tipos,TAMT,marca,TAMM);
                    break;
                default:
                    informeSeis(Notebooks,TAM,marca,TAMM);
                    break;
            }

            break;



        }
    }while(salir != 's');








    return 0;
}
