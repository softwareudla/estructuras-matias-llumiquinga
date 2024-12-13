#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(struct Libro libros[NUM_LIBROS], int i, int opc)
{
    imprimirSeparadores();
    printf("Ingrese:\n1.Registrar libros\n2.Mostrar la lista de libros\n3.Buscar un libro por titulo\n4.Buscar un libro por id\n5.Actualizar el estado de un libro\n6.Eliminar libro\n7.Salir\n>>\t");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        imprimirSeparadores();
        registrarLibros(libros, i);
        i++;
        break;
    case 2:
        imprimirSeparadores();
        mostrarLibros(libros, i);
        break;
    /*case 3:
        int id;
        printf("Ingrese el id del libro a buscar: ");
        scanf("%d", &id);
        buscarLibroId(libros, id);
        break;
    case 4:
        char titulo[100];
        printf("Ingrese el titulo del libro a buscar: ");
        scanf("%s", titulo);
        buscarLibroTitulo(libros, titulo);
        break;*/
    }
}

void registrarLibros(struct Libro libros[NUM_LIBROS], int i)
{
    int len = 0;
    printf("Ingrese el id del libro %d:\t", i + 1);
    scanf("%d", libros[i].id);

    printf("Ingrese el nombre del libro %d:\t", i + 1);
    fgets(libros[i].titulo, NUM_CARACTERES_TITULO, stdin);
    fflush(stdin);
    len = strlen(libros[i].titulo) - 1;
    libros[i].titulo[len] = '\0';

    printf("Ingrese el autor del libro %d:\t", i + 1);
    fflush(stdin);
    fgets(libros[i].autor, NUM_CARACTERES_TITULO, stdin);
    len = strlen(libros[i].autor) - 1;
    libros[i].autor[len] = '\0';

    printf("Ingrese el anio del libro %d:\t", i + 1);
    scanf("%d", libros[i].anio);

    strcpy(libros[i].estado, "Disponible");
}

void mostrarLibros(struct Libro libros[NUM_LIBROS], int n)
{
    printf("%-4s%-100s%-50s%-5s%-20s\n", "ID", "TITULO", "AUTOR", "ANIO", "ESTADO");
    for (int i = 0; i < n; i++)
    {
        printf("%-4d%-100s%-50s%-5d%-20s\n", libros[i].id,libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void imprimirSeparadores()
{
    for (int i = 0; i < 200; i++)
    {
        printf("-");
    }
    
    printf("\n");
}
