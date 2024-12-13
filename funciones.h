#define NUM_CARACTERES_TITULO 100
#define NUM_CARACTERES_AUTOR 50
#define NUM_CARACTERES_ESTADO 20
#define NUM_LIBROS 20

struct Libro{
    int id;
    char titulo[NUM_CARACTERES_TITULO];
    char autor[NUM_CARACTERES_AUTOR];
    int anio;
    char estado[NUM_CARACTERES_ESTADO];
};


int menu(struct Libro libro[20], int i, int opc);
void registrarLibros(struct Libro libros[NUM_LIBROS], int i);
void mostrarLibros(struct Libro libros[NUM_LIBROS], int n);


void imprimirSeparadores();

