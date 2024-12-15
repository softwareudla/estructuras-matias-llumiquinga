#include <stdio.h>
#include <string.h>
#include "funciones.h"

void imprimirMensaje(int numMensaje, int i)
{
    switch (numMensaje)
    {
    case 1:
        printf("Ingrese:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n>>\t", "1.Registrar libros",
               "2.Mostrar la lista de libros",
               "3.Buscar un libro por titulo",
               "4.Buscar un libro por id",
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
        printf("-NUMERO INVALIDO-\n");
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
        printf("-NUMERO MAX DE CARACTERES EXCEDIDO-\n");
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

int menu(struct Libro libros[NUM_LIBROS], int *i, int opc)
{
    ingresarEntero(&opc, 1, 1, *i);

    switch (opc)
    {
    case 1:
        imprimirSeparadores();
        registrarLibros(libros, *i);
        *i = *i + 1;
        break;
    case 2:
        imprimirSeparadores();
        mostrarLibros(libros, *i);
        break;
    case 3:
        int id;
        imprimirSeparadores();
        ingresarEntero(&id, 2, 6, *i);
        buscarLibroId(libros, id);
        break;
        /*case 4:
            char titulo[100];
            printf("Ingrese el titulo del libro a buscar: ");
            scanf("%s", titulo);
            buscarLibroTitulo(libros, titulo);
            break;*/
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
        if (existencia > 1)
        {
            printf("-LA ID INGRESADO YA EXISTE-\n");
        }
    } while (existencia > 1);

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

void buscarLibroId(struct Libro libros[NUM_LIBROS], int id)
{
    int existencia = verificarExistencia(libros, id, 3);
    if (existencia==0)
    {
        printf("-NO SE ENCONTRARON RESULTADOS-\n");
    }    
}

int verificarExistencia(struct Libro libros[NUM_LIBROS], int n, int numInfo)
{
    int acumExistencia = 0, buscado=0;
    struct Libro libroEncontrado[20]={0};


    for (int i = 0; i < n + 1; i++)
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
        case 3:
                //printf("n=%d\ni=%d\nid copiado: %d\tid original: %d\n",n,i, libroEncontrado[0].id, libros[i].id);

            if (n == libros[i].id)
            {
                libroEncontrado[acumExistencia].id=libros[i].id;
                strcpy(libroEncontrado[acumExistencia].titulo, libros[i].titulo);
                strcpy(libroEncontrado[acumExistencia].autor, libros[i].autor);
                libroEncontrado[acumExistencia].anio=libros[i].anio;
                strcpy(libroEncontrado[acumExistencia].estado, libros[i].estado);

                //printf("n=%d\ni=%d\nid copiado: %d\tid original: %d\n",n,i, libroEncontrado[0].id, libros[i].id);
                acumExistencia++;
                buscado=1;
            }
            break;
        case 4:
            if (strcmp(libros[n].titulo, libros[i].titulo) == 0)
            {
                libroEncontrado[acumExistencia].id=libros[i].id;
                strcpy(libroEncontrado[acumExistencia].titulo, libros[i].titulo);
                strcpy(libroEncontrado[acumExistencia].autor, libros[i].autor);
                libroEncontrado[acumExistencia].anio=libros[i].anio;
                strcpy(libroEncontrado[acumExistencia].estado, libros[i].estado);
                acumExistencia++;
                buscado=1;
            }
            break;

        default:
            break;
        }
    }
    //printf("\texistencia= %d\n", acumExistencia);
    
    if (acumExistencia>0 && buscado==1)
    {
        mostrarLibros(libroEncontrado, acumExistencia);
    }
    
    return acumExistencia;
}

void imprimirSeparadores()
{
    for (int i = 0; i < 170; i++)
    {
        printf("-");
    }

    printf("\n");
}
