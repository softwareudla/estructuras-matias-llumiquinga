#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(struct Libro libros[NUM_LIBROS], int *i, int opc)
{
    ingresarEntero(&opc, 1, 1, *i);

    switch (opc)
    {
    case 1:
        imprimirSeparadores();

        if (*i >= NUM_LIBROS)
        {
            *i = NUM_LIBROS;
            imprimirMensaje(27, 0);
        }
        else
        {
            registrarLibros(libros, *i);
            *i = *i + 1;
        }

        break;
    case 2:
        imprimirSeparadores();
        if (*i == 0)
        {
            imprimirMensaje(28, 0);
        }
        else
        {
            imprimirMensaje(10, *i);
            mostrarLibros(libros, *i);
        }
        break;
    case 3:
        imprimirSeparadores();
        buscarLibroId(libros, *i);
        break;
    case 4:
        imprimirSeparadores();
        buscarLibroTitulo(libros, *i);
        break;
    case 5:
        imprimirSeparadores();
        actualizarEstadoLibro(libros, *i);
        break;
    case 6:
        imprimirSeparadores();
        eliminarLibro(libros, i);
        break;
    }

    return opc;
}

void registrarLibros(struct Libro libros[NUM_LIBROS], int i)
{
    int len = 0, existencia = 0;

    do
    {
        ingresarEntero(&libros[i].id, 2, 2, i);
        existencia = verificarExistencia(libros, i, 1);
        if (existencia >= 1)
        {
            imprimirMensaje(24, 0);
        }
    } while (existencia >= 1);

    ingresarCadena(libros[i].titulo, NUM_CARACTERES_TITULO, 4, i);
    ingresarCadena(libros[i].autor, NUM_CARACTERES_AUTOR, 5, i);
    ingresarEntero(&libros[i].anio, 3, 3, i);

    strcpy(libros[i].estado, "Disponible");
}

void mostrarLibros(struct Libro libros[NUM_LIBROS], int n)
{
    printf("%-4s%-100s%-50s%-6s%-11s\n", "ID", "TITULO", "AUTOR", "ANIO", "ESTADO");
    for (int i = 0; i < n; i++)
    {
        printf("%-4d%-100s%-50s%-6d%-11s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibroId(struct Libro libros[NUM_LIBROS], int n)
{
    int id = 0, acumExistencia = 0;
    struct Libro libroEncontrado[20] = {0};

    ingresarEntero(&id, 2, 6, n);

    for (int i = 0; i < n; i++)
    {
        if (id == libros[i].id)
        {
            libroEncontrado[acumExistencia] = libros[i];
            acumExistencia++;
        }
    }

    imprimirResultadosBusqueda(libroEncontrado, acumExistencia);
}
void buscarLibroTitulo(struct Libro libros[NUM_LIBROS], int n)
{
    char tituloBuscado[NUM_CARACTERES_TITULO] = {0};
    int acumExistencia = 0;
    struct Libro libroEncontrado[20] = {0};

    ingresarCadena(tituloBuscado, NUM_CARACTERES_TITULO, 7, n);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(tituloBuscado, libros[i].titulo) == 0)
        {
            libroEncontrado[acumExistencia] = libros[i];
            acumExistencia++;
        }
    }

    imprimirResultadosBusqueda(libroEncontrado, acumExistencia);
}

void actualizarEstadoLibro(struct Libro libros[NUM_LIBROS], int n)
{
    int id = 0, acumExistencia = 0;
    struct Libro libroEncontrado[20] = {0};

    ingresarEntero(&id, 2, 8, n);

    for (int i = 0; i < n; i++)
    {
        if (id == libros[i].id)
        {
            if (strcmp(libros[i].estado, "Disponible") == 0)
            {
                strcpy(libros[i].estado, "Prestado");
            }
            else if (strcmp(libros[i].estado, "Prestado") == 0)
            {
                strcpy(libros[i].estado, "Disponible");
            }
            imprimirMensaje(25, 0);
            libroEncontrado[acumExistencia] = libros[i];
            acumExistencia++;
        }
    }
    imprimirResultadosBusqueda(libroEncontrado, acumExistencia);
}

void eliminarLibro(struct Libro libros[NUM_LIBROS], int *n)
{
    int id = 0, elimninado = 0;
    struct Libro libroCero = {0};

    ingresarEntero(&id, 2, 9, *n);

    for (int i = 0; i < *n; i++)
    {
        if (id == libros[i].id)
        {
            for (int j = i; j < *n; j++)
            {
                if (j == NUM_LIBROS - 1)
                {
                    libros[j] = libroCero;
                    elimninado = 1;
                }
                else
                {
                    libros[j] = libros[j + 1];
                    elimninado = 1;
                }
            }
        }
    }
    if (elimninado == 0)
    {
        imprimirMensaje(23., 0);
    }
    else
    {
        imprimirMensaje(26, 0);
        *n = *n - 1;
    }
}

void imprimirMensaje(int numMensaje, int i)
{
    switch (numMensaje)
    {
    case 1:
        printf("Ingrese:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n>>\t", "1.Registrar libros",
               "2.Mostrar la lista de libros",
               "3.Buscar un libro por id",
               "4.Buscar un libro por titulo",
               "5.Actualizar el estado de un libro",
               "6.Eliminar libro",
               "7.Salir");
        break;
    case 2:
        printf("Ingrese la id del libro %d:\t", i + 1);
        break;
    case 3:
        printf("Ingrese el anio del libro %d:\t", i + 1);
        break;
    case 4:
        printf("Ingrese el titulo del libro %d:\t", i + 1);
        break;
    case 5:
        printf("Ingrese el autor del libro %d:\t", i + 1);
        break;
    case 6:
        printf("Ingrese la id del libro a buscar:\t");
        break;
    case 7:
        printf("Ingrese el titulo del libro a buscar:\t");
        break;
    case 8:
        printf("Ingrese la id del libro a actualizar su estado:\t");
        break;
    case 9:
        printf("Ingrese la id del libro a eliminar:\t");
        break;
    case 10:
        printf("-%d/%d LIBROS REGISTRADOS-\n", i, NUM_LIBROS);
        break;
    case 21:
        printf("-NUMERO INVALIDO-\n");
        break;
    case 22:
        printf("-NUMERO MAX DE CARACTERES EXCEDIDO-\n");
        break;
    case 23:
        printf("-NO SE ENCONTRARON RESULTADOS-\n");
        break;
    case 24:
        printf("-LA ID INGRESADA YA EXISTE-\n");
        break;
    case 25:
        printf("-ESTADO ACTUALIZADO-\n");
        break;
    case 26:
        printf("-SE HA ELIMINADO UN LIBRO-\n");
        break;
    case 27:
        printf("-YA SE HAN REGISTRADO EL MAX DE %d LIBROS-\n", NUM_LIBROS);
        break;
    case 28:
        printf("-NO EXISTEN LIBROS REGISTRADOS-\n");
        break;

    default:
        break;
    }
}

void ingresarEntero(int *numAValidar, int opcEntero, int numMensaje, int i)
{
    int continuar;
    do
    {
        if (numMensaje == 1)
        {
            imprimirSeparadores();
        }

        imprimirMensaje(numMensaje, i);
        validarEntero(&continuar, numAValidar, opcEntero);
    } while (continuar == 0);
}

void validarEntero(int *continuar, int *numAValidar, int opcEntero)
{
    float numF = 0;
    *numAValidar = 0;
    *continuar = 0;

    scanf("%f", &numF);
    *numAValidar = (int)(numF);

    if (*numAValidar != numF)
    {
        *continuar = 0;
    }
    else
    {
        *continuar = validarRangos(*continuar, *numAValidar, opcEntero);
    }

    if (*continuar == 0)
    {
        imprimirMensaje(21, 0);
    }
}

int validarRangos(int continuar, int numAValidar, int opcEntero)
{
    switch (opcEntero)
    {
    case 1:
        for (int i = 0; i < NUM_OPCIONES; i++)
        {
            if (numAValidar == i + 1)
            {
                continuar = 1;
                break;
            }
            else
            {
                continuar = 0;
            }
        }
        break;

    case 2:
        if (numAValidar > 0 && numAValidar <= 20)
        {
            continuar = 1;
        }
        break;
    case 3:
        if (numAValidar >= 1455 && numAValidar <= 2024)
        {
            continuar = 1;
        }
        break;

    default:
        break;
    }

    return continuar;
}

void ingresarCadena(char cadenaAValidar[], int numCaracteres, int numMensaje, int i)
{
    int continuar;
    do
    {
        strcpy(cadenaAValidar, "");
        imprimirMensaje(numMensaje, i);
        validarNumCaracteres(&continuar, cadenaAValidar, numCaracteres);
    } while (continuar == 0);
}

void validarNumCaracteres(int *continuar, char cadenaAValidar[], int numCaracteres)
{
    int len = 0;
    *continuar = 0;
    while (cadenaAValidar[0] == '\n' || cadenaAValidar[0] == '\0')
    {
        fgets(cadenaAValidar, numCaracteres, stdin);
    }

    len = strlen(cadenaAValidar) - 1;

    if (cadenaAValidar[len] != '\n')
    {
        imprimirMensaje(22, 0);
        while (getchar() != '\n')
            ;
        *continuar = 0;
    }
    else
    {
        cadenaAValidar[len] = '\0';
        *continuar = 1;
    }
}

int verificarExistencia(struct Libro libros[NUM_LIBROS], int n, int numInfo)
{
    int acumExistencia = 0, buscado = 0;
    struct Libro libroEncontrado[20] = {0};

    for (int i = 0; i < n; i++)
    {
        switch (numInfo)
        {
        case 1:
            if (libros[n].id == libros[i].id)
            {
                acumExistencia++;
            }
            break;
        case 2:
            if (strcmp(libros[n].titulo, libros[i].titulo) == 0)
            {
                acumExistencia++;
            }
            break;
        default:
            break;
        }
    }

    return acumExistencia;
}

void imprimirResultadosBusqueda(struct Libro libroEncontrado[20], int acumExistencia)
{
    if (acumExistencia > 0)
    {
        mostrarLibros(libroEncontrado, acumExistencia);
    }
    else
    {
        imprimirMensaje(23, 0);
    }
}

void imprimirSeparadores()
{
    for (int i = 0; i < 170; i++)
    {
        printf("-");
    }

    printf("\n");
}
