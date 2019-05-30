#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "instrumentos.h"
#include "musicos.h"
#include "orquestas.h"
#include "informes.h"

/** \brief Pide al usuario un lugar, lo busca en el array de orquestas y devuelve las que lo contienen
* \param oOrquesta Orquestas Array de orquesta
* \param limite Tamaño del array
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente
*
*/
int inf_OrquestaPorLugar(Orquestas* oOrquesta, int limite)
{
    int ret=-1;
    Orquestas auxOrquestas;

    if (getString(auxOrquestas.lugar,"\nIngrese lugar: ","Error en el lugar ingresado. ",2,30,1)==0)
    {
        ret=-1;
        for(int i=0; i<limite; i++)
        {
            if(strncmp(oOrquesta[i].lugar, auxOrquestas.lugar,30)==0)
            {

                printf("\n-ID de la orquesta : %d\n", oOrquesta[i].idOrquestas);
                printf("Nombre de la orquesta: %s\n", oOrquesta[i].nombre);
                printf("Lugar de la orquesta: %s\n", oOrquesta[i].lugar);
                if(oOrquesta[i].tipo ==1)
                {
                    printf("tipo: sinfonica\n");
                }
                if(oOrquesta[i].tipo ==2)
                {
                    printf("tipo: filarmonica\n");
                }
                if(oOrquesta[i].tipo ==3)
                {
                    printf("tipo: camara\n");
                }
                ret=0;
            }
        }
    }
    if(ret==-1)
    {
        printf("No se encontro orquesta en ese lugar");
    }
    return ret;
}

/** \brief Busca en el array de musicos los menores a 25 años y los muestra.
* \param mMusicos Musicos Array de musicos.
* \param iInstrumentos Instrumentos Array de instrumentos.
* \param oOrquesta Orquestas Array de orquesta.
* \param limiteMusicos Tamaño del array de musicos.
* \param limiteIntrumentos Tamaño del array de instrumentos.
* \param limiteOrquestas Tamaño del array de orquesta.
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente.
*
*/
int inf_edadesMenores25 (Musicos* mMusicos, Instrumentos* iInstrumentos,Orquestas* oOrquestas, int limiteMusicos, int limiteIntrumentos, int limiteOrquestas)
{
    int ret = 1;
    int auxInst;
    int auxOrq;

    if(mMusicos != NULL && limiteMusicos>0 )
    {
        for(int i =0; i<limiteMusicos ; i++)
        {
            if(mMusicos[i].isEmpty==0 && mMusicos[i].edad < 25)
            {
                printf("\n-ID del musico : %d\n", mMusicos[i].idMusicos);
                printf("Nombre: %s\n", mMusicos[i].nombre);
                printf("Apellido: %s\n", mMusicos[i].apellido);
                printf("Edad : %d\n", mMusicos[i].edad);
                auxInst = ins_buscarPorId(iInstrumentos,limiteIntrumentos,mMusicos[i].idInstrumento);
                printf("Instrumento: %s\n", iInstrumentos[auxInst].nombre);
                auxOrq = orq_buscarPorId(oOrquestas,limiteOrquestas, mMusicos[i].idOrqesta);
                printf("Orquesta: %s\n", oOrquestas[auxOrq].nombre);
            }
        }
        ret = 0;
    }
    return ret;
}

/** \brief Busca en el array de musicos los que pertenecen a la misma orquesta, los acumula y muestra las orquestas con menos de 6 musicos.
* \param mMusicos Musicos Array de musicos.
* \param oOrquesta Orquestas Array de orquesta.
* \param limiteMusicos Tamaño del array de musicos.
* \param limiteOrquestas Tamaño del array de orquesta.
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente.
*
*/
int inf_orquestaMenos6Musicos (Musicos* mMusicos,Orquestas* oOrquestas, int limiteMusicos, int limiteOrquestas)
{
    int i;
    int j;
    int retorno=-1;
    int contador=0;

    if (mMusicos!=NULL && oOrquestas!=NULL && limiteMusicos>0 && limiteOrquestas>0)
    {
        for (i=0; i<limiteOrquestas; i++)
        {
            if (oOrquestas[i].isEmpty==0)
            {
                for(j=0; j<limiteMusicos; j++)
                {
                    if (mMusicos[j].isEmpty==0)
                    {
                        if(oOrquestas[i].idOrquestas == mMusicos[j].idOrqesta)
                        {
                            contador++;
                        }
                    }
                }
                if (contador<6)
                {
                    printf ("\nId de orquesta: %d. \n",oOrquestas[i].idOrquestas);
                    printf ("Nombre de orquesta: %s. \n",oOrquestas[i].nombre);
                    printf ("Lugar de orquesta: %s.\n",oOrquestas[i].lugar);
                    switch (oOrquestas[i].tipo)
                    {
                    case 1:
                        printf ("Tipo de orquesta : Sinfonica.\n");
                        break;
                    case 2:
                        printf ("Tipo de orquesta: Filarmonica.\n");
                        break;
                    case 3:
                        printf ("Tipo de orquesta: Camara.\n");
                        break;
                    }
                }
                contador=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Pide al usuario un ID de orquesta, y muestra el nombre del musico que pertece a esa orquesta con el instrumento que toca
* \param mMusicos Musicos Array de musicos.
* \param oOrquesta Orquestas Array de orquesta.
* \param iInstrumentos Instrumentos Array de instrumentos.
* \param limiteIntrumentos Tamaño del array de instrumentos.
* \param limiteOrquestas Tamaño del array de orquesta.
* \param limiteMusicos Tamaño del array de musicos.
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int inf_instrumentoPorOrquesta(Musicos* mMusicos,Orquestas* oOrquestas, Instrumentos* iInstrumentos, int limiteInstrumentos,int limiteOrquestas, int limiteMusicos)
{
    int ret=-1;
    Orquestas auxIns;
    int auxId;
    //int contador=0;

    orq_mostrarArray(oOrquestas, limiteOrquestas);

    if (getInt(&auxIns.idOrquestas,"\n\nIngrese ID de la orquesta: ","Error en el ID de a orquesta",0,limiteOrquestas,1)==0)
    {
        system("cls"); //limpia la pantalla en windows
        //system("clear"); //limpia pantalla en linux
        ret=-1;
        for(int i=0; i<limiteMusicos; i++)
        {
            if (mMusicos[i].isEmpty==0)
            {
                if(mMusicos[i].idOrqesta == auxIns.idOrquestas)
                {
                    printf("\nNombre musico: %s\n", mMusicos[i].nombre);
                    auxId = mMusicos[i].idInstrumento;
                    printf("Nombre instrumento: %s\n", iInstrumentos[auxId].nombre);
                    if(iInstrumentos[auxId].tipo ==1)
                    {
                        printf("tipo: cuerdas\n\n");
                    }
                    if(iInstrumentos[auxId].tipo ==2)
                    {
                        printf("tipo: viento-madera\n\n");
                    }
                    if(iInstrumentos[auxId].tipo ==3)
                    {
                        printf("tipo: viento-metal\n\n");
                    }
                    if(iInstrumentos[auxId].tipo ==4)
                    {
                        printf("tipo: percusion\n\n");
                    }

                    ret=0;
                }
            }
        }
    }
    if(ret==-1)
    {
        printf("No se encontro esa orquesta");
    }
    return ret;
}

/** \brief  Muestra las orquestas completas.
* \param mMusicos Musicos Array de musicos.
* \param oOrquesta Orquestas Array de orquesta.
* \param iInstrumentos Instrumentos Array de instrumentos.
* \param limiteIntrumentos Tamaño del array de instrumentos.
* \param limiteOrquestas Tamaño del array de orquesta.
* \param limiteMusicos Tamaño del array de musicos.
* \return int Return (-1) si no encuentra el valor buscado o Error  - (0) si encuentra el valor buscado
*
*/
int inf_orquestaCompleta(Musicos* mMusicos,Orquestas* oOrquestas, Instrumentos* iInstrumentos, int limiteInstrumentos,int limiteOrquestas, int limiteMusicos)
{
    int retorno=-1;
    int posInst;
    int contadorCuerda=0;
    int contadorViento=0;
    int contadorPercusion=0;

    if (mMusicos!=NULL && oOrquestas!=NULL && iInstrumentos!=NULL && limiteMusicos>0 && limiteOrquestas>0 && limiteInstrumentos>0)
    {

        for (int i=0; i<limiteOrquestas; i++)
        {
            if (oOrquestas[i].isEmpty==0)
            {
                for(int j = 0 ; j < limiteMusicos ; j++)
                {
                    if(mMusicos[j].isEmpty == 0 && mMusicos[j].idOrqesta == oOrquestas[i].idOrquestas)
                    {
                        posInst = ins_buscarPorId(iInstrumentos,limiteInstrumentos,mMusicos[j].idInstrumento);
                        {
                            switch (iInstrumentos[posInst].tipo)
                            {
                            case 1:
                                contadorCuerda++;
                                break;
                            case 2:
                                contadorViento++;
                                break;
                            case 3:
                                contadorViento++;
                                break;
                            case 4:
                                contadorPercusion++;
                                break;
                            }
                        }
                    }
                }
                if (contadorCuerda>=4 && contadorViento>=4 && contadorPercusion>=4)
                {
                    printf ("\nOrquesta completa id: %d.\n",oOrquestas[i].idOrquestas);
                    printf ("Orquesta completa nombre: %s.\n",oOrquestas[i].nombre);
                    printf ("Orquesta completa lugar: %s.\n",oOrquestas[i].lugar);
                }
                else
                    printf ("\nNinguna orquesta esta completa.\n");
                    retorno=0;
                    break;
            }
        }
    }
    return retorno;
}

/** \brief Busca musicos en el array de orquestas, los cuenta y muestra las orquestas con la menor cantidad musicos.
* \param oOrquesta Orquestas Array de orquesta.
* \param mMusicos Musicos Array de musicos.
* \param limiteOrquestas Tamaño del array de orquesta.
* \param limiteMusicos Tamaño del array de musicos.
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente.
*
*/
int inf_orquestaConMenosMusicos (Orquestas* oOrquestas, Musicos* mMusicos, int limiteOrquestas, int limiteMusicos)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int indiceMaximo=0;
    int indiceMinimo=1000;

    if (mMusicos!=NULL && oOrquestas!=NULL && limiteMusicos>0 && limiteOrquestas>0)
    {
        for (i=0; i<limiteOrquestas; i++)
        {
            if (oOrquestas[i].isEmpty==0)
            {
                for (j=0; j<limiteMusicos; j++)
                {
                    if (mMusicos[j].isEmpty==0)
                    {
                        if (oOrquestas[i].idOrquestas== mMusicos[j].idOrqesta)
                        {
                            contador++;
                        }
                    }
                }

                if (contador>indiceMaximo)
                {
                    indiceMaximo=contador;
                }
                else if (contador<=indiceMinimo)
                {
                    indiceMinimo=contador;
                    printf ("\nID de la orquesta: %d. \n",oOrquestas[i].idOrquestas);
                    printf ("Nombre de la orquesta: %s. \n",oOrquestas[i].nombre);
                    printf ("Lugar de la orquesta: %s.\n",oOrquestas[i].lugar);
                    printf ("Cantidad de musicos: %d\n",contador);
                    switch (oOrquestas[i].tipo)
                    {
                    case 1:
                        printf ("Tipo: Sinfonica.\n");
                        break;
                    case 2:
                        printf ("Tipo: Filarmonica.\n");
                        break;
                    case 3:
                        printf ("Tipo: Camara.\n");
                        break;
                    }
                }

                contador=0;
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Cuenta los instrumentos, cuenta las orqeustas y calcula el promedio de instrumentos por orquesta.
* \param mMusicos Musicos Array de musicos.
* \param oOrquesta Orquestas Array de orquesta.
* \param limiteMusicos Tamaño del array de musicos.
* \param limiteOrquestas Tamaño del array de orquesta.
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente.
*
*/
int inf_promedioInstrumentoPorOrquesta (Musicos* mMusicos, Orquestas* oOrquestas, int limiteMusicos, int limiteOrquestas)
{
    int retorno=-1;
    int contIntrumento=0;
    int contOrquesta=0;
    float promedio=0;

    if (mMusicos!=NULL && oOrquestas!=NULL && limiteMusicos>0 && limiteOrquestas>0)
    {
        for (int i=0; i<=limiteMusicos; i++)
        {
            if (mMusicos[i].isEmpty==0)
            {
                contIntrumento++;
            }
        }

        for (int i=0; i<=limiteOrquestas; i++)
        {
            if (oOrquestas[i].isEmpty==0)
            {
                contOrquesta++;
            }
        }
        promedio=contIntrumento/(float)contOrquesta;
        printf("\nEl promedio de instrumentos por orquesta es: %.2f",promedio);
        retorno=0;
    }
    return retorno;
}

/** \brief Recorre el array de musicos y los ordena por apellido.
* \param mMusicos Musicos Array de musicos.
* \param limiteMusicos Tamaño del array de musicos.
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente.
*
*/
int inf_ordenarPorapellido(Musicos* mMusicos,int limite)
{
    int ret= -1;
    Musicos aux;
    int flagSwap;
    do
    {
        for(int i=0; i<limite-1; i++)
        {
            if(mMusicos[i].isEmpty ==0)
            {
                flagSwap =0;
                ret = 1;
                if(strncmp(mMusicos[i].apellido, mMusicos[i+1].apellido,30)>0)
                {
                    aux = mMusicos[i];
                    mMusicos[i] = mMusicos[i+1];
                    mMusicos[i+1] = aux;
                    flagSwap = 1;
                    ret =0;
                }
            }
        }


    }
    while(flagSwap);
    return ret;
}

/** \brief Recorre el array de musicos y muestra solo los que tocan instrumentos del tipo cuerdas o percusion.
* \param mMusicos Musicos Array de musicos.
* \param iInstrumentos Instrumentos Array de instrumentos.
* \param limiteMusicos Tamaño del array de musicos.
* \param limiteIntrumentos Tamaño del array de instrumentos.
* \return int Return (-1) si Error - (0) si se elimina el elemento exitosamente.
*
*/
int inf_musicosNoViento(Musicos* mMusicos, Instrumentos* iInstrumentos, int limiteMusicos, int limiteInstrumentos)
{
    int retorno=-1;
    int auxIdInst;
    int posInst;

    inf_ordenarPorapellido(mMusicos, limiteMusicos);
    if (mMusicos!= NULL && iInstrumentos!= NULL && limiteMusicos >0 && limiteInstrumentos>0)
    {
        for (int i=0; i<limiteMusicos; i++)
        {
            if (mMusicos[i].isEmpty==0)
            {
                auxIdInst = mMusicos[i].idInstrumento;
                posInst = ins_buscarPorId(iInstrumentos, limiteInstrumentos, auxIdInst);

                if (iInstrumentos[posInst].tipo!=2 && iInstrumentos[posInst].tipo!=3)
                {
                    printf ("\nNombre del musico: %s.\n",mMusicos[i].nombre);
                    printf ("Apellido del musico: %s.\n",mMusicos[i].apellido);
                    printf ("Edad: %d.\n",mMusicos[i].edad);
                    printf ("Nombre del instrumento: %s.\n",iInstrumentos[posInst].nombre);
                    switch (iInstrumentos[posInst].tipo)
                    {
                    case 1:
                        printf ("Tipo de instrumento: cuerdas.\n");
                        break;
                    case 4:
                        printf ("Tipo de instrumento: percusion.\n");
                        break;
                    }
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

