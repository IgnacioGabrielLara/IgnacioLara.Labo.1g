#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include"validacionesDatos.h"

void altaCliente(eCliente cliente,int tam)
{
    int id = 100;
    eCliente aux;


        aux.id = id;



       pidoValidoLetras(aux.nombre, tam,"Nombre");

        fflush(stdin);

        printf("Ingrese sexo ( m / f ) : ");
        scanf("%c", &aux.sexo);
        aux.sexo = tolower(aux.sexo);
        while(aux.sexo != 'm' && aux.sexo != 'f')
        {
            fflush(stdin);
             printf("\nError. Ingrese sexo ( m / f ) : ");
            scanf("%c", &aux.sexo);
            aux.sexo = tolower(aux.sexo);
        }



       cliente = aux;


}



