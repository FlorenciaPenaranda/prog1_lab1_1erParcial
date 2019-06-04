#include <stdio.h>
#include <stdlib.h>
//#include <stdmus.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "musicos.h"
#include "instrumentos.h"
#include "orquestas.h"


static int generarId(void)
{
    static int idE=0;
    return idE++;
}

/** \brief Para indicar que todas las posiciones en la array están vacías
* esta función puso la bandera (isEmpty) en VERDADERO en todos
* posición de la matriz
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \return int Return (-1) si no encuentra un lugar vacio o Error  - (0) si encuentra una posicion vacia
*
*/
int mus_InicializarArray(Musicos* mMusicos, int limite)
{
    int ret;
    if(mMusicos != NULL && limite >0)
    {
        for (int i=0; i<limite; i++)
        {
            mMusicos[i].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}

/** \brief Busca el primer lugar vacio en un array
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \param devuelve int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error  - (0) si encuentra una posicion vacia
*
*/
int mus_buscarLibre(Musicos* mMusicos, int limite, int* devuelve)
{
    int ret;
    if(mMusicos != NULL && limite >0)
    {
        for (int i=0; i<limite; i++)
        {
            if (mMusicos[i].isEmpty==1)
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
* \param mMusicos Musicos Array de musicos
* \param oOrquestas Orquestas Array de orquestas
* \param iInstrumentos Instrumentos Array de instrumentos
* \param limiteMusicos Tamaño del array de musicos
* \param limiteOrquestas Tamaño del array de orquestas
* \param limiteInstrumentos Tamaño del array de instrumentos
* \param int posLibre int posicion del ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error  - (0) si se agrega un nuevo elemento exitosamente
*
*/
int mus_altaMusicos(Musicos* mMusicos, Orquestas* oOrquestas, Instrumentos* iInstrumentos, int limiteMusicos, int limiteOrquestas, int limiteInstrumentos, int posLibre)
{
    int ret=-1;
    int bufferIdInstrumento;
    int bufferIdOrquesta;

    if(mMusicos != NULL && oOrquestas!= NULL && iInstrumentos!= NULL && limiteMusicos>0 && limiteOrquestas>0 && limiteInstrumentos>0)
    {
        if (!getString(mMusicos[posLibre].nombre,"Ingrese nombre: ","error, vuelva a ingresar\n\n",1,30,2) &&
                !getString(mMusicos[posLibre].apellido,"Ingrese apellido: ","error, vuelva a ingresar\n\n",1,30,2) &&
                !getInt(&mMusicos[posLibre].edad, "Ingrese edad:", "Error, vuelva a ingresar", 15,105,2)
           )
        {
            printf("\n\n");
            orq_mostrarArray(oOrquestas, limiteOrquestas);
            printf("\n\n");
            if(!getInt(&bufferIdOrquesta, "Ingrese ID Orquesta:", "Error, vuelva a ingresar", 0,50,2 ))
            {
                if(orq_buscarPorId(oOrquestas, limiteOrquestas, bufferIdOrquesta))
                {
                    mMusicos[posLibre].idOrqesta = bufferIdOrquesta;
                }
            }
            printf("\n\n");
            ins_mostrarArray(iInstrumentos, limiteInstrumentos);
            printf("\n\n");
            if(!getInt(&bufferIdInstrumento, "Ingrese ID instrumento:", "Error, vuelva a ingresar", 0,20,2 ))
            {
                if(ins_buscarPorId(iInstrumentos, limiteInstrumentos, bufferIdInstrumento))
                {
                    mMusicos[posLibre].idInstrumento = bufferIdInstrumento;
                }
            }
            mMusicos[posLibre].idMusicos = generarId();
            mMusicos[posLibre].isEmpty=0;
            ret=0;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

/** \brief  Pide al usuario un ID, lo busca en un array y modifica sus campos
* \param mMusicos Musicos Array de musicos
* \param oOrquestas Orquestas Array de orquestas
* \param iInstrumentos Instrumentos Array de instrumentos
* \param limiteMusicos Tamaño del array de musicos
* \param limiteOrquestas Tamaño del array de orquestas
* \param limiteInstrumentos Tamaño del array de instrumentos
* \param intentos int cantidad  intentos para modiciar el campo en caso de hacerlo mal
* \return int Return (-1) si Error  - (0) si se modifica el elemento exitosamente
*
*/
int mus_modificar(Musicos* mMusicos, Orquestas* oOrquestas, Instrumentos* iInstrumentos, int limiteMusicos, int limiteInstrumentos, int limiteOrquestas,int intentos)
{
    int ret=-1;
    int auxId;
    int posIdEnc;
    int opcion;

    if(mMusicos != NULL && oOrquestas!= NULL && iInstrumentos!= NULL && limiteMusicos>0 && limiteOrquestas>0 && limiteInstrumentos>0)
    {
        mus_mostrarElementosArray(mMusicos, limiteMusicos);
        mus_buscarPosicionId(mMusicos, limiteMusicos, &posIdEnc);
        auxId = mMusicos[posIdEnc].idMusicos;//valor
        //printf("ID a modificar es: %d\n\n", auxId);
        if(auxId>=0 && posIdEnc!=-1)
        {
            do
            {
                system("cls");
                printf("1- Modificar edad\n");
                printf("2- Modificar orquesta\n");
                getInt(&opcion,"\n\nIngrese el campo a modificar: ", "Error. Ingrese una opcion valida",1,2,1);

            }
            while (opcion<1 || opcion>3);
            fflush( stdin ); //LIMPIA BUFFER WINDOWS
            //__fpurge(stdin); //LIMPIA BUFFER LINUX
            switch(opcion)
            {
            case 1:
                if(!getInt(&mMusicos[posIdEnc].edad, "\nIngrese edad:", "Error, vuelva a ingresar", 15,105,2))
                {
                    ret = 0;
                    printf("\nEdad modificada correctamente.\n\n");
                    break;
                }
                else
                {
                    printf("No se pudo modificar la edad\n\n");
                    break;
                }
            case 2:
                orq_mostrarArray(oOrquestas, limiteOrquestas);
                if(!getInt(&mMusicos[posIdEnc].idOrqesta, "\nIngrese ID de orquesta: ", "error, vuelva a intentar\n\n",0,3,2))
                {
                    ret = 0;
                    printf("\nOrquesta modificado correctamente.\n\n");
                    break;
                }
                else
                {
                    printf("No se pudo modificar la orquesta\n\n");
                    break;
                }
            }
        }
        else
        {
            printf("\n\nNo se encontro el codigo!\n");
        }

        return ret;
    }
    return ret;
}

/** \brief Muestralos elementos de un array
* \param mMusicos Musicos Array de musicos
* \param iInstrumentos Instrumentos Array de instrumentos
* \param limiteMusicos Tamaño del array de musicos
* \param limiteInstrumentos Tamaño del array de instrumentos
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
void mus_mostrarArray(Musicos* mMusicos,Instrumentos* iInstrumentos, int limiteInstrumentos, int limiteMusicos)
{
    int auxPos;

    if(mMusicos != NULL && iInstrumentos!= NULL && limiteMusicos>0 && limiteInstrumentos>0)
    {
        for (int i=0; i<limiteMusicos; i++)
        {
            if(mMusicos[i].isEmpty!=1)
            {
                fflush(stdin);
                printf("\n-ID del musico : %d\n", mMusicos[i].idMusicos);
                printf("Nombre: %s\n", mMusicos[i].nombre);
                printf("Apellido: %s\n", mMusicos[i].apellido);

                auxPos = ins_buscarPorId(iInstrumentos, limiteInstrumentos, mMusicos[i].idInstrumento);

                switch (iInstrumentos[auxPos].tipo)
                {
                case 1:
                    printf("Nombre del instrumento: %s\n", iInstrumentos[auxPos].nombre);
                    printf("Tipo: cuerdas\n");
                    break;
                case 2:
                    printf("Nombre del instrumento: %s\n", iInstrumentos[auxPos].nombre);
                    printf("Tipo: viento-madera\n");
                    break;
                case 3:
                    printf("Nombre del instrumento: %s\n", iInstrumentos[auxPos].nombre);
                    printf("Tipo: viento-metal\n");
                    break;
                case 4:
                    printf("Nombre del instrumento: %s\n", iInstrumentos[auxPos].nombre);
                    printf("Tipo: percusion\n");
                    break;
                }
            }
            //printf("Press 'Enter' to continue: ... ");
            //while ( getchar() != '\n');
        }
    }
}

/** \brief Muestralos elementos de un array
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
void mus_mostrarElementosArray(Musicos* mMusicos, int limiteMusicos)
{
    if(mMusicos != NULL && limiteMusicos>0)
    {
     for (int i=0; i<limiteMusicos; i++)
    {
        if(mMusicos[i].isEmpty!=1)
        {
            fflush(stdin);
            printf("\n-ID del musico : %d\n", mMusicos[i].idMusicos);
            printf("Nombre: %s\n", mMusicos[i].nombre);
            printf("Apellido: %s\n", mMusicos[i].apellido);

        }
        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }
    }
}

/** \brief Pide al usuario un ID, lo busca en un array y devuelve la posicion en que se encuentra
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \param musicoEncontrado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int mus_buscarPosicionId(Musicos* mMusicos, int limite, int* musicoEncontrado)
{
    int ret=1;
    Musicos auxMusicos;

    if(mMusicos != NULL && limite >0)
    {
     if (getInt(&auxMusicos.idMusicos,"\nIngrese el codigo del musico: ","Error en el codigo del musro ingresado",0,20,3)==0)
    {
        ret=-1;
        for(int i=0; i<limite; i++)
        {
            if (mMusicos[i].idMusicos == auxMusicos.idMusicos)
            {
                *musicoEncontrado=i;
                ret=0;
                break;
            }
        }
    }
    }
    return ret;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \param idE int La posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int mus_buscarPorId (Musicos* mMusicos, int limite, int idE)
{
    int ret=-1;

    if(mMusicos != NULL && limite >0)
    {
     for(int i=0; i<limite; i++)
    {
        if(mMusicos[i].idMusicos==idE)
        {
            ret=i;
            break;
        }
    }
    }
    return ret;
}

/** \brief Pide al usuario un ID, lo busca en un array y borra todos los elemento del array que contengan el valor buscado
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente
*
*/
int mus_bajaMusicos(Musicos* mMusicos, int limite)
{
    int posMusicos;
    mus_mostrarElementosArray(mMusicos, limite);

    if(mMusicos != NULL && limite >0)
    {
    switch (mus_buscarPosicionId(mMusicos, limite,&posMusicos))
    {
    case 0:

        if (mMusicos[posMusicos].isEmpty ==0)
        {
            printf("hubo coincidencia\n\n");
            mMusicos[posMusicos].isEmpty=1;
            printf("El musleado borrado es: %d\n\n",mMusicos[posMusicos].idMusicos);
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

/** \brief Se le pasa un ID, lo busca en un array y borra todos los elemento del array que contengan el valor buscado
* \param mMusicos Musicos Array de musicos
* \param limite Tamaño del array
* \param idOrquesta int Valor a borrar
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente
*
*/
int mus_bajaMusicosId(Musicos* mMusicos, int limite, int idOrquesta)
{
    int ret=-1;

    if(mMusicos != NULL && limite >0)
    {
    for(int i=0; i<limite; i++)
    {
        if(mMusicos[i].idOrqesta== idOrquesta)
        {
            mMusicos[i].isEmpty = 1;
            ret=0;
            break;
        }
    }
    }
    return ret;
}



