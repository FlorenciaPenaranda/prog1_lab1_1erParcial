#include <stdio.h>
//#include <stdorq.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "orquestas.h"
#include "musicos.h"


static int generarId(void)
{
    static int idE=0;
    return idE++;
}

/** \brief Para indicar que todas las posiciones en la array están vacías
* esta función puso la bandera (isEmpty) en VERDADERO en todos
* posición de la matriz
* \param oOrquestas Orquestas Array de orquestas
* \param limite Tamaño del array
* \return int Return (-1) si no encuentra un lugar vacio o Error  - (0) si encuentra una posicion vacia
*
*/
int orq_InicializarArray(Orquestas* oOrquestas, int limite)
{
    int ret;
    if(oOrquestas != NULL && limite >0)
    {
     for (int i=0; i<limite; i++)
    {
        oOrquestas[i].isEmpty=1;
        ret=0;
    }
    }
    return ret;
}

/** \brief Busca el primer lugar vacio en un array
* \param oOrquestas Orquestas Array de orquestas
* \param limite Tamaño del array
* \param devuelve int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error  - (0) si encuentra una posicion vacia
*
*/
int orq_buscarLibre(Orquestas* oOrquestas, int limite, int* devuelve)
{
    int ret;

    if(oOrquestas != NULL && limite >0)
    {
    for (int i=0; i<limite; i++)
    {
        if (oOrquestas[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }
        ret=1;
    }
    }
    return ret;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param oOrquestas Orquestas Array de orquestas
* \param limite int Tamaño del array
* \param int posLibre int posicion del ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error  - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orq_altaOrquestas(Orquestas* oOrquestas, int limite, int posLibre)
{
    int ret=-1;

    if(oOrquestas != NULL && limite >0)
    {
    if (!getString(oOrquestas[posLibre].nombre,"Ingrese nombre: ","error, vuelva a ingresar\n\n",1,60,2) &&
            !getString(oOrquestas[posLibre].lugar,"Ingrese lugar: ","error, vuelva a ingresar\n\n",1,30,2) &&
            !getInt(&oOrquestas[posLibre].tipo, "tipo: ","error, vuelva a ingresar\n\n",1,3,2))
    {

        oOrquestas[posLibre].idOrquestas = generarId();
        oOrquestas[posLibre].isEmpty=0;
        ret=0;

    }
    else
    {
        ret=1;
    }
    }
    return ret;
}

/** \brief Muestra los elementos de un array
* \param oOrquestas Orquestas Array de orquestas
* \param limiteOrquestas Tamaño del array
* \return void
*
*/
void orq_mostrarArray(Orquestas* oOrquestas, int limite)
{
    if(oOrquestas != NULL && limite >0)
    {
    for (int i=0; i<limite; i++)
    {
        if(oOrquestas[i].isEmpty!=1)
        {
            fflush(stdin);
            printf("\n-ID del orquesta : %d\n", oOrquestas[i].idOrquestas);
            printf("Nombre del orquesta: %s\n", oOrquestas[i].nombre);
            printf("Lugar del orquesta: %s\n", oOrquestas[i].lugar);
            if(oOrquestas[i].tipo ==1)
            {
               printf("tipo: sinfonica\n");
            }
            if(oOrquestas[i].tipo ==2)
            {
               printf("tipo: filarmonica\n");
            }
            if(oOrquestas[i].tipo ==3)
            {
               printf("tipo: camara\n");
            }
            //printf("musicos: %d\n", oOrquestas[i].idMusicos);
        }
        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }
    }
}

/** \brief Pide al usuario un ID, lo busca en un array y devuelve la posicion en que se encuentra
* \param oOrquestas Orquestas Array de orquestas
* \param limite Tamaño del array
* \param orqleadoEncontrado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int orq_buscarPosicionId(Orquestas* oOrquestas, int limite, int* orqleadoEncontrado)
{
    int ret=1;
    Orquestas auxOrquestas;

    if(oOrquestas != NULL && limite >0)
    {
    //orq_mostrarArray(oOrquestas, limite);
    if (getInt(&auxOrquestas.idOrquestas,"\nIngrese el ID de la orquesta: ","Error en el ID ingresado",0,20,3)==0)
    {
        //auxOrquestass.nombre=tolower(auxOrquestass.nombre);
        ret=-1;
        for(int i=0; i<limite; i++)
        {
            //orqleados[i].nombre=tolower(orqleados[i].nombre);
            if (oOrquestas[i].idOrquestas == auxOrquestas.idOrquestas)
            {
                *orqleadoEncontrado=i;
                ret=0;
                break;
            }
        }
    }
    }
    return ret;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param oOrquestas Orquestas Array de orquestas
* \param limite Tamaño del array
* \param idE int la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int orq_buscarPorId (Orquestas* oOrquestas, int limite, int idE)
{
    int i;
    int ret=-1;

    if(oOrquestas != NULL && limite >0)
    {
    for(i=0; i<limite; i++)
    {
        if(oOrquestas[i].idOrquestas==idE)
        {
            ret=i;
            break;
        }
    }
    }
    return ret;
}

/** \brief Se le pasa un ID, lo busca en un array y borra todos los elemento del array que contengan el valor buscado
* \param oOrquestas Orquestas Array de orquestas
* \param limite Tamaño del array
* \param idBaja int* Puntero a la posicion del array a dar de abaja
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente
*
*/
int orq_bajaOrquestas(Orquestas* oOrquestas, int limite, int* idBaja)
{
    int posOrquestas;
    orq_mostrarArray(oOrquestas, limite);

    if(oOrquestas != NULL && limite >0)
    {
    switch (orq_buscarPosicionId(oOrquestas, limite,&posOrquestas))
    {
    case 0:

        if (oOrquestas[posOrquestas].isEmpty ==0)
        {
            printf("hubo coincidencia\n\n");
            *idBaja = oOrquestas[posOrquestas].idOrquestas; //AGREGADO
            oOrquestas[posOrquestas].isEmpty=1;
            printf("La orquesta borrada es: %d\n\n",oOrquestas[posOrquestas].idOrquestas);
        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    }
    return 1;
}


