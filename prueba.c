#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tarea {
    int id;
    char descripcion[60];
    int duracion;
} Tarea;

typedef struct nodo {
    Tarea tarea;
    struct nodo* siguiente;
} Nodo;

void insertar(Nodo** cabeza, Tarea nueva_tarea) {
    Nodo* nuevo_nodo = malloc(sizeof(Nodo));
    nuevo_nodo->tarea = nueva_tarea;
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

void mostrar(Nodo* cabeza) {
    printf("Tareas:\n");
    while (cabeza != NULL) {
        printf("ID: %d\n", cabeza->tarea.id);
        printf("Descripcion: %s\n", cabeza->tarea.descripcion);
        printf("Duracion: %d\n\n", cabeza->tarea.duracion);
        cabeza = cabeza->siguiente;
    }
}

void realizar_tarea(Nodo** pendientes, Nodo** realizadas, int tarea_id) {
    Nodo* actual = *pendientes;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->tarea.id != tarea_id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("La tarea con ID %d no existe.\n", tarea_id);
        return;
    }

    if (anterior == NULL) {
        *pendientes = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    actual->siguiente = *realizadas;
    *realizadas = actual;

    printf("La tarea con ID %d ha sido realizada.\n", tarea_id);
}

int main() {
    srand(time(NULL));

    Nodo* pendientes = NULL;
    Nodo* realizadas = NULL;

    int n_tareas;
    printf("Ingrese el numero de tareas: ");
    scanf("%d", &n_tareas);

    for (int i = 1; i <= n_tareas; i++) {
        Tarea nueva_tarea;
        nueva_tarea.id = i;

        printf("Ingrese la descripcion de la tarea %d: ", i);
        scanf("%s", nueva_tarea.descripcion);
        fflush(stdin);

        nueva_tarea.duracion = rand() % 91 + 10;

        insertar(&pendientes, nueva_tarea);
    }

    printf("\n");

    int opcion;
    do {
        printf("Seleccione una opcion:\n");
        printf("1. Mostrar tareas pendientes.\n");
        printf("2. Mostrar tareas realizadas.\n");
        printf("3. Realizar una tarea.\n");
        printf("4. Salir.\n");

        scanf("%d", &opcion);

        switch(opcion) {
        case 1:
        printf("TAREAS PENDIENTES\n");
        mostrar(pendientes);
        break;

    case 2:
        printf("TAREAS REALIZADAS\n");
        mostrar(realizadas);
        break;

    case 3:
        printf("Ingrese el ID de la tarea a realizar: ");
        int tarea_id;
        scanf("%d", &tarea_id);
        realizar_tarea(&pendientes, &realizadas, tarea_id);
        break;

    case 4:
        printf("Adios!\n");
        break;

    default:
        printf("Opcion no valida.\n");
        break;
    }
} while (opcion != 4);

// Liberar memoria de las listas
Nodo* actual = pendientes;
while (actual != NULL) {
    Nodo* siguiente = actual->siguiente;
    free(actual);
    actual = siguiente;
}

actual = realizadas;
while (actual != NULL) {
    Nodo* siguiente = actual->siguiente;
    free(actual);
    actual = siguiente;
}

return 0;
}

           
