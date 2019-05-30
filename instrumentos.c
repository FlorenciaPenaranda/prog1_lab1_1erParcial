#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "instrumentos.h"
#

static int generarId(void)
{
    static int idE=0;
    return idE++;
}

/** \brief Para indicar que todas las posiciones en la array están vacías
* esta función puso la bandera (isEmpty) en VERDADERO en todos
* posición de la matriz
* \param iInstrumentos Instrumentos Array de instrumentos
* \param limite Tamaño del array
* \return int Return (-1) si no encuentra un lugar vacio o Error  - (0) si encuentra una posicion vacia
*
*/

int ins_InicializarArray(Instrumentos* iInstrumentos, int limite)
{
    int ret;
    for (int i=0; i<limite; i++)
    {
        iInstrumentos[i].isEmpty=1;
        ret=0;
    }
    return ret;
}

/** \brief Busca el primer lugar vacio en un array
* \param iInstrumentos Instrumentos Array de instrumentos
* \param limite Tamaño del array
* \param devuelve int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error  - (0) si encuentra una posicion vacia
*
*/
int ins_buscarLibre(Instrumentos* iInstrumentos, int limite, int* devuelve)
{
    int ret;
    for (int i=0; i<limite; i++)
    {
        if (iInstrumentos[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param iInstrumentos Instrumentos Array de instrumento
* \param limite int Tamaño del array
* \param int posLibre int posicion del ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error  - (0) si se agrega un nuevo elemento exitosamente
*
*/
int ins_altaInstrumentos(Instrumentos* iInstrumentos, int limite, int posLibre)
{
    int ret=-1;

    if (!getString(iInstrumentos[posLibre].nombre,"Ingrese un nombre: ","error, vuelva a ingresar\n\n",2,30,2))
    {
        printf("\n1-cuerdas\n2-viento-madera\n3-viento-metal\n4-percusion\n\n");
        if(!getInt(&iInstrumentos[posLibre].tipo,"Ingrese el tipo:","error, vuelva a intentar\n\n",0,3,2))
        {
            iInstrumentos[posLibre].idInstrumentos = generarId();
            iInstrumentos[posLibre].isEmpty=0;
            ret=0;
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}

/** \brief Muestra los elementos de un array
* \param iInstrumentos Instrumentos Array de instrumento
* \param limite Tamaño del array
* \return void
*
*/
void ins_mostrarArray(Instrumentos* iInstrumentos, int limite)
{


    for (int i=0; i<limite; i++)
    {
        if(iInstrumentos[i].isEmpty==0)
        {
            fflush(stdin);
            printf("\n\n-ID del instrumento : %d\n", iInstrumentos[i].idInstrumentos);
            printf("Nombre: %s\n", iInstrumentos[i].nombre);
            if(iInstrumentos[i].tipo ==1)
            {
                printf("tipo: cuerdas");
            }
            if(iInstrumentos[i].tipo ==2)
            {
                printf("tipo: viento-madera");
            }
            if(iInstrumentos[i].tipo ==3)
            {
                printf("tipo: viento-metal");
            }
            if(iInstrumentos[i].tipo ==4)
            {
                printf("tipo: percusion");
            }

        }
        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }
}

/** \brief Pide al usuario un ID, lo busca en un array y devuelve la posicion en que se encuentra
* \param iInstrumentos Instrumentos Array de instrumento
* \param limite Tamaño del array
* \param insEncontrado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int ins_buscarPosicionId(Instrumentos* iInstrumentos, int limite, int* insEncontrado)
{
    int ret=1;
    Instrumentos auxInstrumentos;


    if (getInt(&auxInstrumentos.idInstrumentos,"ingrese el ID del instrumento: ","Vuelva a ingresar",0,20,3)==0)
    {
        //auxInstrumentoss.nombre=tolower(auxInstrumentoss.nombre);
        ret=-1;
        for(int i=0; i<limite; i++)
        {
            if (iInstrumentos[i].idInstrumentos == auxInstrumentos.idInstrumentos)
            {
                *insEncontrado=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param iInstrumentos Instrumentos Array de instrumento
* \param limite Tamaño del array
* \param idE int la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int ins_buscarPorId (Instrumentos* iInstrumentos, int limite, int idE)
{
    int i;
    int ret=-1;
    for(i=0; i<limite; i++)
    {
        if(iInstrumentos[i].idInstrumentos==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief Lista un elementos especifico de un array
* \param iInstrumentos Instrumentos Array de instrumento
* \param limite int Tamaño del array
* \return int Return (-1) si Error - (0) si se lista exitosamente
*
*/
void ins_mostrarTipoInstrumento(Instrumentos* iInstrumentos, int limite)
{
    for (int i=0; i<limite; i++)
    {
        if(iInstrumentos[i].isEmpty==0)
        {
            fflush(stdin);
            printf("\n\n-ID del instrumento : %d\n", iInstrumentos[i].idInstrumentos);
            printf("Nombre: %s\n", iInstrumentos[i].nombre);
            if(iInstrumentos[i].tipo ==1)
            {
                printf("tipo: cuerdas\n");
            }
            if(iInstrumentos[i].tipo ==2)
            {
                printf("tipo: viento-madera\n");
            }
            if(iInstrumentos[i].tipo ==3)
            {
                printf("tipo: viento-metal\n");
            }
            if(iInstrumentos[i].tipo ==4)
            {
                printf("tipo: percusion\n");
            }

        }
        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }
}
