#define NUM_CARACTERES_TITULO 100
#define NUM_CARACTERES_AUTOR 50
#define NUM_CARACTERES_ESTADO 20
#define NUM_LIBROS 20
#define NUM_OPCIONES 7

struct Libro{
    int id;
    char titulo[NUM_CARACTERES_TITULO];
    char autor[NUM_CARACTERES_AUTOR];
    int anio;
    char estado[NUM_CARACTERES_ESTADO];
};


void imprimirMensaje(int numMensaje, int i);




void ingresarEntero(int *numAValidar, int opcEntero, int numMensaje, int i);
void validarEntero(int *continuar, int *numAValidar, int opcEntero);
int validarRangos(int continuar, int numAValidar, int opcEntero);

void ingresarCadena(char cadenaAValidar[], int numCaracteres, int numMensaje, int i);
void validarNumCaracteres(int *continuar, char cadenaAValidar[], int numCaracteres);





int menu(struct Libro libros[NUM_LIBROS], int *i, int opc);
void registrarLibros(struct Libro libros[NUM_LIBROS], int i);
void mostrarLibros(struct Libro libros[NUM_LIBROS], int n);


void imprimirSeparadores();

