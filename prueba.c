#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;  
int Duracion; // entre 10 – 100
}typedef Tarea;

struct Nodo{
Tarea T;
struct Nodo *Siguiente;
}typedef Tnodo;


Tnodo *crearListaVacia();
Tnodo **insertarNodos(Tnodo * tareas,int nTareas);
void mostrar(Tnodo * tareas);
void liberarMemoria(Tnodo * tareas);
void enlazarNodo(Tnodo * tareas, Tnodo * nueva);

int main()
{
    srand(time(NULL));
    int nTareas,menu,nTareasR=0,tareaid;
    Tnodo * tareas;
    Tnodo * tareasR;
    puts("ingrese la cantidad de tareas a ralizar:");
    scanf("%d",&nTareas);
    tareas = crearListaVacia();
    tareasR = crearListaVacia();
    tareas = insertarNodos(tareas,nTareas);
    mostrar(tareas);
    

    
    
Tnodo *prev = NULL; // puntero al nodo anterior
while (tareas != NULL) {
    printf("Tarea id: %d\n", tareas->T.TareaID);
    printf("\tdescripcion: %s\n", tareas->T.Descripcion);
    printf("\tduracion: %d\n", tareas->T.Duracion);
    puts("Seleccione 1 si la tarea fue realizada, sino seleccione 0");
    scanf("%d",&menu);
    if (menu == 1) {
        // agregar el nodo actual a la lista de tareas realizadas
        if (tareasR == NULL) {
            // si la lista está vacía, crear el primer nodo
            tareasR = tareas;
            prev = tareas;
        } else {
            // agregar el nodo al final de la lista
            prev->Siguiente = tareas;
            prev = prev->Siguiente;
        }
        // eliminar el nodo actual de la lista de tareas pendientes
        Tnodo *temp = tareas;
        tareas = tareas->Siguiente;
        free(temp->T.Descripcion);
        free(temp);
    } else {
        // avanzar al siguiente nodo
        prev = tareas;
        tareas = tareas->Siguiente;
    }
}
    puts("/////tareas realizadas////////");
    mostrar(tareasR);

    puts("/////tareas pendientes////////");
    mostrar(tareas);

    
      
   

    
    liberarMemoria(tareas);
    liberarMemoria(tareasR);
    return 0;
}

void enlazarNodo(Tnodo * tareas, Tnodo * nueva){
     tareas->Siguiente = nueva;
     nueva = tareas;
     

}


Tnodo *crearListaVacia(){
    return NULL;
}

Tnodo **insertarNodos(Tnodo * tareas,int nTareas){
      Tarea tarea;
      Tnodo *insertar;
      
      for (int i = 0; i < nTareas; i++)
      {
        insertar = malloc(sizeof(Tnodo));
        tarea.TareaID = i+1;
        printf("ingrese la descripcion de la tarea:\n");
        fflush(stdin);
        tarea.Descripcion = malloc(sizeof(char)*60);
        gets(tarea.Descripcion);
        tarea.Duracion = rand() % 91 + 10;
        fflush(stdin);
        insertar->T = tarea;
        insertar->Siguiente = tareas;
        tareas = insertar;
      }
      return tareas;
}

void mostrar(Tnodo * tareas){
     while (tareas != NULL)
     {
        printf("\n\nTarea id: %d",tareas->T.TareaID);
        printf("\n\tdescripcion: %s\n", tareas->T.Descripcion);
        printf("\n\tduracion: %d\n", tareas->T.Duracion);
        tareas = tareas->Siguiente;
     }
     


}

void liberarMemoria(Tnodo * tareas){
    Tnodo *aux;
     while (tareas != NULL)
    {
        free(tareas->T.Descripcion);
        aux = tareas;
        free(aux);
        tareas = tareas->Siguiente;

        
    }
    
}
