#ifndef ARRAYMUSICOS_H_INCLUDED
#define ARRAYMUSICOS_H_INCLUDED

#include "instrumentos.h"
#include "orquestas.h"


typedef struct
{   int isEmpty; // lleno=0 ; vacio=1
    int idMusicos; //autoincremental
    char nombre[30];
    char apellido[30];
    int edad;
    int idInstrumento;
    int idOrqesta;
}Musicos;

#endif // ARRAYMUSICOS_H_INCLUDED

int mus_InicializarArray(Musicos* mMusicos, int limite);
int mus_buscarLibre(Musicos* mMusicos, int limite, int* devuelve);
int mus_altaMusicos(Musicos* mMusicos, Orquestas* oOrquesta, Instrumentos* iInstrumentos, int limiteMusicos, int limiteOrquestas, int limiteInstrumentos, int posLibre);
void mus_mostrarArray(Musicos* mMusicos,Instrumentos* iInstrumentos, int limiteInstrumentos, int limiteMusicos);
void mus_mostrarElementosArray(Musicos* mMusicos, int limiteMusicos);
int mus_buscarPosicionId(Musicos* mMusicos, int limite, int* musicoEncontrado);
int mus_buscarPorId (Musicos* mMusicos, int limite, int idE);
int mus_bajaMusicos(Musicos* mMusicos, int limite);
int mus_modificar(Musicos* mMusicos, Orquestas* oOrquestas, Instrumentos* iInstrumentos, int limiteMusicos, int limiteInstrumentos, int limiteOrquesta,int intentos);
void mus_mostrarIntTipo(Musicos* mMusicos, int limiteMusicos);
int mus_bajaMusicosId(Musicos* mMusicos, int limite, int idOrquesta);

