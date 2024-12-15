#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[])
{

    struct Libro libros[NUM_LIBROS]={0};
    int opc;
    int i = 0;
    do
    {
        opc = menu(libros, &i, opc);

    } while (opc != 7);

    return 0;
}