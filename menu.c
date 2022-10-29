#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "notebook.h"


char menu()
{
    char opcion;

    system("cls");
    printf("-----------------------------------------------------\n"
           "                    ABM NOTEBOOKS                    \n"
           "------------------------------------------------------\n\n");

    printf("A.Alta notebook\n"
           "B.Modificar notebook\n"
           "C.Baja notebook\n"
           "D.Listar notebooks\n"
           "E.Listar marcas\n"
           "F.Listar tipos\n"
           "G.Listar servicios\n"
           "H.Alta trabajo\n"
           "I.Listar trabajos\n"
           "J.Listado de informes\n");

        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        while(opcion != 'a'&& opcion != 'b'&&
              opcion != 'c'&& opcion != 'd'&& opcion != 'e'&&
              opcion != 'f'&& opcion != 'g'&& opcion != 'h'&& opcion != 'i' && opcion != 'j')
        {
            fflush(stdin);
            printf("Error. Ingrese una opcion valida: ");
            scanf("%c", &opcion);
            opcion = tolower(opcion);
        }
        fflush(stdin);
        return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");

    printf("\n   *** INFORMES ***\n\n");
    printf("1. Mostrar Notebooks del tipo seleccionado por el usuario\n");
    printf("2. Mostrar Notebooks de una marca seleccionada\n");
    printf("3. Informar la o las notebooks mas baratas\n");
    printf("4. Listar Notebook separadas por marca\n");
    printf("5. Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca\n");
    printf("6. Mostrar la o las marcas mas elegidas por los clientes\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    while(opcion < 1 && opcion >6)
    {
         fflush(stdin);
         printf("Error.Selecciona una opcion valida");
        scanf("%d", &opcion);
    }



    return opcion;
}
