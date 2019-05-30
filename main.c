#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "instrumentos.h"
#include "musicos.h"
#include "orquestas.h"
#include "informes.h"

#define CANT_INSTRUMENTOS 20
#define CANT_MUSICOS 1000
#define CANT_ORQUESTAS 50

int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int inicializarArrayinstrumentos;
    int inicializarArrayMusicos;
    int inicializarArrayOrquestas;

    int posLibre;
    int posBaja;
    int flagInstrumentos = 0;
    int flagMusicos = 0;
    int flagOrquestas = 0;

    Instrumentos instrumentos[CANT_INSTRUMENTOS];
    inicializarArrayinstrumentos = ins_InicializarArray(instrumentos,CANT_INSTRUMENTOS);
    Musicos musicos[CANT_MUSICOS];
    inicializarArrayMusicos = mus_InicializarArray(musicos, CANT_MUSICOS);
    Orquestas orquestas[CANT_ORQUESTAS];
    inicializarArrayOrquestas = orq_InicializarArray(orquestas, CANT_ORQUESTAS);


    instrumentos[1].isEmpty = 0;
    instrumentos[1].idInstrumentos = 1;
    instrumentos[1].tipo = 1;
    strncpy(instrumentos[1].nombre, "instuno", 30);

    instrumentos[2].isEmpty = 0;
    instrumentos[2].idInstrumentos = 2;
    instrumentos[2].tipo = 2;
    strncpy(instrumentos[2].nombre, "instdos", 30);

    instrumentos[3].isEmpty = 0;
    instrumentos[3].idInstrumentos = 3;
    instrumentos[3].tipo = 2;
    strncpy(instrumentos[3].nombre, "insttres", 30);

    instrumentos[4].isEmpty = 0;
    instrumentos[4].idInstrumentos = 4;
    instrumentos[4].tipo = 3;
    strncpy(instrumentos[4].nombre, "instcuatro", 30);

    instrumentos[5].isEmpty = 0;
    instrumentos[5].idInstrumentos = 5;
    instrumentos[5].tipo = 4;
    strncpy(instrumentos[5].nombre, "instcinco", 30);
    flagInstrumentos = 1;


    musicos[1].isEmpty = 0;
    musicos[1].idMusicos = 1;
    strncpy(musicos[1].nombre, "musuno", 30);
    strncpy(musicos[1].apellido, "Amusunos", 30);
    musicos[1].edad = 30;
    musicos[1].idInstrumento =  2;
    musicos[1].idOrqesta = 1;

    musicos[2].isEmpty = 0;
    musicos[2].idMusicos = 2;
    strncpy(musicos[2].nombre, "musdos", 30);
    strncpy(musicos[2].apellido, "Amusdos", 30);
    musicos[2].edad = 20;
    musicos[2].idInstrumento =  5;
    musicos[2].idOrqesta = 2;

    musicos[3].isEmpty = 0;
    musicos[3].idMusicos = 3;
    strncpy(musicos[3].nombre, "mustres", 30);
    strncpy(musicos[3].apellido, "Amustres", 30);
    musicos[3].edad = 25;
    musicos[3].idInstrumento =  2;
    musicos[3].idOrqesta = 4;

    musicos[4].isEmpty = 0;
    musicos[4].idMusicos = 4;
    strncpy(musicos[4].nombre, "muscuatro", 30);
    strncpy(musicos[4].apellido, "Amuscuatro", 30);
    musicos[4].edad = 27;
    musicos[4].idInstrumento =  1;
    musicos[4].idOrqesta = 4;

    musicos[5].isEmpty = 0;
    musicos[5].idMusicos = 5;
    strncpy(musicos[5].nombre, "muscinco", 30);
    strncpy(musicos[5].apellido, "Amuscinco", 30);
    musicos[5].edad = 22;
    musicos[5].idInstrumento =  3;
    musicos[5].idOrqesta = 1;

    musicos[6].isEmpty = 0;
    musicos[6].idMusicos = 7;
    strncpy(musicos[6].nombre, "musseis", 30);
    strncpy(musicos[6].apellido, "Amusseis", 30);
    musicos[6].edad = 35;
    musicos[6].idInstrumento =  4;
    musicos[6].idOrqesta = 3;

    /*musicos[7].isEmpty = 0;
    musicos[7].idMusicos = 8;
    strncpy(musicos[7].nombre, "mussiete", 30);
    strncpy(musicos[7].apellido, "Amussieste", 30);
    musicos[7].edad = 38;
    musicos[7].idInstrumento =  1;
    musicos[7].idOrqesta = 3;

    musicos[8].isEmpty = 0;
    musicos[8].idMusicos = 9;
    strncpy(musicos[8].nombre, "musocho", 30);
    strncpy(musicos[8].apellido, "Amusocho", 30);
    musicos[8].edad = 47;
    musicos[8].idInstrumento =  2;
    musicos[8].idOrqesta = 3;*/
    flagMusicos = 1;


    orquestas[1].isEmpty = 0;
    orquestas[1].idOrquestas= 1;
    strncpy(orquestas[1].nombre, "orquestauno", 30);
    strncpy(orquestas[1].lugar, "lugaruno", 30);
    orquestas[1].tipo = 1;

    orquestas[2].isEmpty = 0;
    orquestas[2].idOrquestas = 2;
    strncpy(orquestas[2].nombre, "orquestados", 30);
    strncpy(orquestas[2].lugar, "lugaruno", 30);
    orquestas[2].tipo = 2;

    orquestas[3].isEmpty = 0;
    orquestas[3].idOrquestas = 3;
    strncpy(orquestas[3].nombre, "orquestatres", 30);
    strncpy(orquestas[3].lugar, "lugardos", 30);
    orquestas[3].tipo = 3;

    orquestas[4].isEmpty = 0;
    orquestas[4].idOrquestas = 4;
    strncpy(orquestas[4].nombre, "orquestacuatro", 30);
    strncpy(orquestas[4].lugar, "lugartres", 30);
    orquestas[4].tipo = 2;
    flagOrquestas = 1;


    if (inicializarArrayinstrumentos ==0 && inicializarArrayMusicos==0 && inicializarArrayOrquestas==0)
    {
        printf("\tPantalla inicializadas correctamente\n");
    }
    while (seguir=='s')
    {
        printf("\t\t MENU DE ORQUESTAS");
        printf("\n1-AGREGAR ORQUESTA");
        printf("\n2-BORRAR ORQUESTA");
        printf("\n3-MOSTRAR ORQUESTAS\n");
        printf("\t---------------------------");
        printf("\n4-MENU INSTRUMENTOS\n");
        printf("5-MENU MUSICOS\n");
        printf("6- INFORMES DEL PROGRAMA\n");
        printf("\t---------------------------");
        printf("\n7-SALIR\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
            //system("cls"); //limpia la pantalla en windows
            //system("clear"); //limpia pantalla en linux
            //buffer[strlen(buffer)-1]= "\0" saca el enter que se toma como caracter

        }
        while (opcion<1 || opcion>7);

        switch (opcion)
        {
        case 1://AGREGAR ORQ
            if(orq_buscarLibre(orquestas, CANT_ORQUESTAS, &posLibre)!=0)
            {
                printf("COMPLETO, NO SE PUEDEN INGRESAR MAS ORQUESTAS\n\n");
            }
            else
            {
                switch(orq_altaOrquestas(orquestas, CANT_ORQUESTAS, posLibre))
                {
                case 0 :
                    flagOrquestas = 1;
                    printf("\nDato ingresado correctamente\n\n");
                    break;
                case 1:
                    printf("\nDato ingresado incorrectamente\n\n");
                    break;
                }
            }
            break;

        case 2://BORRAR ORQ
            if(flagOrquestas != 0 )
            {
                if(
                    orq_bajaOrquestas(orquestas, CANT_ORQUESTAS, &posBaja))
                {
                    mus_bajaMusicosId(musicos, CANT_MUSICOS, posBaja);
                }
            }
            else
            {
                printf("\nSe deben cargar orquestas para poder operar.\n\n");
            }
            break;

        case 3://MOSTRAR ORQ
            if(flagOrquestas != 0 )
            {
                orq_mostrarArray(orquestas, CANT_ORQUESTAS);
            }
            else
            {
                printf("\nNo hay orquestas para mostrar.\n\n");
            }
            break;

        case 4:
            do
            {
                getInt(&opcion, "\n\n-------MENU INSTRUMENTOS-------\n\n1) Agregar un instrumento \n2) Ver instrumentos \n3) Salir del menu de instrumentos\n\nIngrese la opcion: ","\nError",1,3,1);
                system("cls");
                switch(opcion)
                {
                case 1: //Alta
                    if(ins_buscarLibre(instrumentos, CANT_INSTRUMENTOS, &posLibre)!=0)
                    {
                        printf("COMPLETO, NO SE PUEDEN INGRESAR MAS instrumentos\n\n");
                    }
                    else
                    {
                        switch(ins_altaInstrumentos(instrumentos, CANT_INSTRUMENTOS, posLibre))
                        {
                        case 0 :
                            flagInstrumentos = 1;
                            printf("\nDato ingresado correctamente\n\n");
                            break;
                        case 1:
                            printf("\nDato ingresado incorrectamente\n\n");
                            break;
                        }
                    }
                    break;

                case 2: //mostrar ins
                    if(flagInstrumentos != 0 )
                    {
                        ins_mostrarArray(instrumentos, CANT_INSTRUMENTOS);
                    }
                    else
                    {
                        printf("\nNo hay instrumentos para mostrar.\n\n");
                    }
                    break;

                case 3:
                    break;
                }
            }
            while(opcion!=3);
            break;

        case 5:
            do
            {
                getInt(&opcion, "\n\n-------MENU MUSICOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Mostrar\n\n5)Salir del menu de Musicos\n\nIngrese la opcion: ","\nError",1,6,1);
                system("cls");
                switch(opcion)
                {

                case 1: //Alta
                    if(mus_buscarLibre(musicos, CANT_MUSICOS, &posLibre)!=0)
                    {
                        printf("COMPLETO, NO SE PUEDEN INGRESAR MAS MUSICOS\n\n");
                    }
                    else
                    {
                        switch(mus_altaMusicos(musicos, orquestas, instrumentos, CANT_MUSICOS, CANT_ORQUESTAS, CANT_INSTRUMENTOS, posLibre))
                        {
                        case 0 :
                            flagMusicos = 1;
                            printf("\nDato ingresado correctamente\n\n");
                            break;
                        case 1:
                            printf("\nDato ingresado incorrectamente\n\n");
                            break;
                        }
                    }
                    break;

                case 2: //Modificar
                    if(flagMusicos != 0)
                    {
                        mus_modificar(musicos, orquestas, instrumentos, CANT_MUSICOS, CANT_INSTRUMENTOS, CANT_ORQUESTAS, 2);
                    }
                    else
                    {
                        printf("\nNo hay musicos para modificar.\n\n");
                    }
                    break;

                case 3: //Baja
                    if(flagMusicos != 0 )
                    {
                        mus_bajaMusicos(musicos, CANT_MUSICOS);
                    }
                    else
                    {
                        printf("\nSe deben cargar libros para poder dar de baja.\n\n");
                    }
                    break;

                case 4://Ordenar
                    if(flagMusicos != 0 )
                    {
                        mus_mostrarArray(musicos,instrumentos,CANT_INSTRUMENTOS, CANT_MUSICOS);
                    }
                    else
                    {
                        printf("\nNo hay musicos para mostrar.\n\n");
                    }
                    break;
                case 5:
                    break;

                }
            }
            while(opcion!=5);
            break;

        case 6:
            do
            {
                getInt(&opcion, "\n\n-------MENU DE INFORMES-------\n\n1) Listar orquestas de un lugar. \n2) Listar musicos menores de 25 años. \n3) Orquesta con menos de 6 musicos.\n4) Listar instrumentos de una orquesta. \n5) Mostrar orquestas completas \n6) Orquestas con menos musicos \n7) Promedio de instrumentos por orquesta. \n8) Musicos que NO toquen instrumentos de viento(ordenados por apellido). \n9) Salir del menu de informes.\n\nIngrese la opcion: ","\nError",1,11,1);
                system("cls");
                switch(opcion)
                {

                case 1:
                    inf_OrquestaPorLugar(orquestas, CANT_ORQUESTAS);
                    break;

                case 2:
                    inf_edadesMenores25(musicos, instrumentos, orquestas, CANT_MUSICOS, CANT_INSTRUMENTOS, CANT_ORQUESTAS);
                    break;

                case 3:
                    inf_orquestaMenos6Musicos(musicos,orquestas,CANT_MUSICOS,CANT_ORQUESTAS);
                    break;

                case 4:
                    inf_instrumentoPorOrquesta(musicos, orquestas, instrumentos, CANT_INSTRUMENTOS, CANT_ORQUESTAS, CANT_MUSICOS);
                    break;

                case 5:
                    inf_orquestaCompleta(musicos, orquestas, instrumentos, CANT_INSTRUMENTOS, CANT_ORQUESTAS, CANT_MUSICOS);
                    break;

                case 6:
                    inf_orquestaConMenosMusicos(orquestas, musicos, CANT_ORQUESTAS, CANT_MUSICOS);
                    break;

                case 7:
                    inf_promedioInstrumentoPorOrquesta(musicos, orquestas, CANT_MUSICOS, CANT_ORQUESTAS);
                    break;

                case 8:
                    inf_musicosNoViento(musicos, instrumentos, CANT_MUSICOS, CANT_INSTRUMENTOS);
                    break;

                case 9:
                    break;

                }
            }
            while(opcion!=9);
            break;

        case 7:
            seguir='n';
            break;
        }
    }
    return 0;
}
