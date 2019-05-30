#ifndef ARRAYINSTRUMENTOS_H_INCLUDED
#define ARRAYINSTRUMENTOS_H_INCLUDED

typedef struct
{   int isEmpty; // lleno=0 ; vacio=1
    int idInstrumentos; //autoincremental
    char nombre[30];
    int tipo;//1-cuerdas/2-viento-madera/3-viento-metal/4-percusion
}Instrumentos;

#endif // ARRAYINSTRUMENTOS_H_INCLUDED

int ins_InicializarArray(Instrumentos* iInstrumentos, int limite);
int ins_buscarLibre(Instrumentos* iInstrumentos, int limite, int* devuelve);
int ins_altaInstrumentos(Instrumentos* iInstrumentos, int limite, int posLibre);
void ins_mostrarArray(Instrumentos* iInstrumentos, int limite);
int ins_buscarPosicionId(Instrumentos* iInstrumentos, int limite, int* insEncontrado);
int ins_buscarPorId (Instrumentos* iInstrumentos, int limite, int idE);



