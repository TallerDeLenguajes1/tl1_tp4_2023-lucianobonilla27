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
Tnodo *insertarNodos(Tnodo * tareas,int nTareas);
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
    

   //listar tareas 
    while (tareas != NULL)
    {
        printf("Tarea id: %d\n", tareas->T.TareaID);
        printf("\tdescripcion: %s\n", tareas->T.Descripcion);
        printf("\tduracion: %d\n", tareas->T.Duracion);
        puts("Seleccione 1 si la tarea fue realizada, sino seleccione 0");
        scanf("%d",&menu);
        if (menu == 1)
        {
            tareas->Siguiente = tareasR;
            tareasR = tareas;
            tareas = tareas->Siguiente;
     
        }else
        {
             tareas = tareas->Siguiente;
        }
        
        
       
    }
    puts("/////tareas realizadas////////");
    mostrar(tareasR);

    puts("/////tareas pendientes////////");
    mostrar(tareas);

    
      
   

    //listar tareas
    /* for (int i = 0; i < nTareas; i++) {
        printf("Tarea id: %d\n", tareas[i]->TareaID);
        printf("\tdescripcion: %s\n", tareas[i]->Descripcion);
        printf("\tduracion: %d\n", tareas[i]->Duracion);
        puts("Seleccione 1 si la tarea fue realizada, sino seleccione 0");
        fflush(stdin);
        scanf("%d", &menu);
        if (menu == 1) {
            tareasR[nTareasR] = tareas[i];
            tareas[i] = NULL;
            nTareasR++;
        } 
    }

    puts("/////tareas realizadas////////");
    for (int i = 0; i < nTareasR; i++) {
        printf("id: %d\n", tareasR[i]->TareaID);
        printf("\tdescripcion: %s\n", tareasR[i]->Descripcion);
        printf("\tduracion: %d\n", tareasR[i]->Duracion);
    }
   
    puts("/////tareas pendientes////////");
    for (int i = 0; i < nTareas; i++) {
        if (tareas[i] != NULL) {
            printf("id: %d\n", tareas[i]->TareaID);
            printf("\tdescripcion: %s\n", tareas[i]->Descripcion);
            printf("\tduracion: %d\n", tareas[i]->Duracion);
        }
    }
    fflush(stdin);
   
   puts("ingrese el id de la tarea realizada que desea buscar:");
   scanf("%d",&tareaid);

   buscada = BuscaTareaPorId(tareasR,nTareasR,tareaid);
   printf("\n\nTarea id: %d",tareaid);
   printf("\tdescripcion: %s\n", buscada.Descripcion);
   printf("\tduracion: %d\n", buscada.Duracion);


    for (int i = 0; i < nTareas; i++)
    {
        free(tareas[i]->Descripcion);
        free(tareas[i]); 
        free(tareasR[i]->Descripcion);
        free(tareasR[i]); 
    }
    free(tareas);
    free(tareasR);
    */
    liberarMemoria(tareas);
    return 0;
}

void enlazarNodo(Tnodo * tareas, Tnodo * nueva){
     tareas->Siguiente = nueva;
     nueva = tareas;
     

}


Tnodo *crearListaVacia(){
    return NULL;
}

Tnodo *insertarNodos(Tnodo * tareas,int nTareas){
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
