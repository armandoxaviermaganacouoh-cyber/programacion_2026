#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ESTUDIANTES 100

// Definición de la estructura Estudiante
typedef struct {
    char nombre[50];
    char codigo[20];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

// Lista de estudiantes
Estudiante estudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;

// ---------------- Métodos de actualización ----------------
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

// ---------------- Métodos de visualización ----------------
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
    printf("Estado: %s\n", e.activo ? "Activo" : "Inactivo");
}

void mostrarInformacionCompleta(Estudiante e) {
    printf("----- Información del Estudiante -----\n");
    mostrarNombre(e);
    mostrarCodigo(e);
    mostrarEdad(e);
    mostrarPromedio(e);
    mostrarActivo(e);
    printf("--------------------------------------\n");
}

// ---------------- Funciones del menú ----------------
void agregarEstudiante() {
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes.\n");
        return;
    }

    Estudiante nuevo;
    printf("Ingrese nombre: ");
    getchar(); // limpiar buffer
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0; // quitar salto de línea

    printf("Ingrese código: ");
    fgets(nuevo.codigo, sizeof(nuevo.codigo), stdin);
    nuevo.codigo[strcspn(nuevo.codigo, "\n")] = 0;

    printf("Ingrese edad: ");
    scanf("%d", &nuevo.edad);

    printf("Ingrese promedio (0.0 - 10.0): ");
    scanf("%f", &nuevo.promedio);

    printf("¿Está activo? (1 = Sí, 0 = No): ");
    int estado;
    scanf("%d", &estado);
    nuevo.activo = (estado == 1);

    estudiantes[totalEstudiantes++] = nuevo;
    printf("Estudiante agregado exitosamente.\n");
}

void mostrarEstudianteEspecifico() {
    char codigo[20];
    printf("Ingrese el código del estudiante: ");
    getchar();
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    for (int i = 0; i < totalEstudiantes; i++) {
        if (strcmp(estudiantes[i].codigo, codigo) == 0) {
            mostrarInformacionCompleta(estudiantes[i]);
            return;
        }
    }
    printf("Estudiante con código %s no encontrado.\n", codigo);
}

void mostrarTodosEstudiantes() {
    if (totalEstudiantes == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    for (int i = 0; i < totalEstudiantes; i++) {
        mostrarInformacionCompleta(estudiantes[i]);
    }
}

// ---------------- Programa principal ----------------
int main() {
    int opcion;
    do {
        printf("\n===== Menú de Gestión Académica =====\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar un estudiante en específico\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudianteEspecifico(); break;
            case 3: mostrarTodosEstudiantes(); break;
            case 4: printf("Saliendo del programa...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}