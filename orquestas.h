#ifndef ARRAYORQUESTAS_H_INCLUDED
#define ARRAYORQUESTAS_H_INCLUDED



typedef struct
{   int isEmpty; // lleno=0 ; vacio=1
    int idOrquestas; //orqoincremental
    char nombre[60];
    char lugar[30];
    int tipo; //1- sinfonica/2-filarmonica/3-camara
}Orquestas;

#endif // ARRAYORQUESTAS_H_INCLUDED

int orq_InicializarArray(Orquestas* oOrquestas, int limite);
int orq_buscarLibre(Orquestas* oOrquestas, int limite, int* devuelve);
int orq_altaOrquestas(Orquestas* oOrquestas, int limiteOrquestas, int posLibre);
void orq_mostrarArray(Orquestas* oOrquestas, int limiteOrquestas);
int orq_buscarPosicionId(Orquestas* oOrquestas, int limite, int* orqleadoEncontrado);
int orq_buscarPorId (Orquestas* oOrquestas, int limite, int idE);
int orq_bajaOrquestas(Orquestas* oOrquestas, int limite, int* idBaja);
