#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ESTUDIANTES 100  // límite de estudiantes

// Definimos la estructura del estudiante
typedef struct {
    char nombre[50];
    char codigo[20];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

// Funciones para actualizar datos
void actualizarNombre(Estudiante *e, char nuevoNombre[]) {
    strcpy(e->nombre, nuevoNombre);
}

void actualizarCodigo(Estudiante *e, char nuevoCodigo[]) {
    strcpy(e->codigo, nuevoCodigo);
}

void actualizarEdad(Estudiante *e, int nuevaEdad) {
    e->edad = nuevaEdad;
}

void actualizarPromedio(Estudiante *e, float nuevoPromedio) {
    if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
        e->promedio = nuevoPromedio;
    } else {
        printf("Error: El promedio debe estar entre 0.0 y 10.0\n");
    }
}

void actualizarActivo(Estudiante *e, bool nuevoEstado) {
    e->activo = nuevoEstado;
}

// Funciones de visualización
void mostrarNombre(Estudiante e) {
    printf("Nombre: %s\n", e.nombre);
}

void mostrarCodigo(Estudiante e) {
    printf("Código: %s\n", e.codigo);
}

void mostrarEdad(Estudiante e) {
    printf("Edad: %d años\n", e.edad);
}

void mostrarPromedio(Estudiante e) {
    printf("Promedio: %.2f\n", e.promedio);
}

void mostrarActivo(Estudiante e) {
    if (e.activo)
        printf("Estado: Activo\n");
    else
        printf("Estado: Inactivo\n");
}

void mostrarInformacionCompleta(Estudiante e) {
    mostrarNombre(e);
    mostrarCodigo(e);
    mostrarEdad(e);
    mostrarPromedio(e);
    mostrarActivo(e);
    printf("-----------------------------\n");
}

// Programa principal con menú
int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n--- Sistema de Gestión de Estudiantes ---\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar un estudiante en específico\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        if (opcion == 1) {
            if (cantidad < MAX_ESTUDIANTES) {
                Estudiante nuevo;
                printf("Ingrese nombre: ");
                fgets(nuevo.nombre, 50, stdin);
                nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0; // quitar salto de línea

                printf("Ingrese código: ");
                fgets(nuevo.codigo, 20, stdin);
                nuevo.codigo[strcspn(nuevo.codigo, "\n")] = 0;

                printf("Ingrese edad: ");
                scanf("%d", &nuevo.edad);

                printf("Ingrese promedio: ");
                scanf("%f", &nuevo.promedio);

                printf("¿Está activo? (1=Sí, 0=No): ");
                int estado;
                scanf("%d", &estado);
                nuevo.activo = (estado == 1);

                estudiantes[cantidad++] = nuevo;
                printf("Estudiante agregado correctamente.\n");
            } else {
                printf("Error: No se pueden agregar más estudiantes.\n");
            }
        }
        else if (opcion == 2) {
            char codigoBuscado[20];
            printf("Ingrese el código del estudiante: ");
            getchar(); // limpiar buffer
            fgets(codigoBuscado, 20, stdin);
            codigoBuscado[strcspn(codigoBuscado, "\n")] = 0;

            int encontrado = 0;
            for (int i = 0; i < cantidad; i++) {
                if (strcmp(estudiantes[i].codigo, codigoBuscado) == 0) {
                    mostrarInformacionCompleta(estudiantes[i]);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Estudiante no encontrado.\n");
            }
        }
        else if (opcion == 3) {
            for (int i = 0; i < cantidad; i++) {
                mostrarInformacionCompleta(estudiantes[i]);
            }
        }

    } while (opcion != 4);

    printf("Saliendo del sistema...\n");
    return 0;
}

