#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;  
int Duracion; // entre 10 – 100
}typedef Tarea;

Tarea BuscarTarea(Tarea **tareas,int nTareas,int TareaID);

int main()
{
    srand(time(NULL));
    int nTareas,menu,nTareasR=0,tareaid;
    Tarea buscada;
    Tarea ** tareas;
    Tarea ** tareasR;
    puts("ingrese la cantidad de tareas a ralizar:");
    scanf("%d",&nTareas);


    tareas = malloc(sizeof(Tarea*)*nTareas);
    tareasR = malloc(sizeof(Tarea*)*nTareas);



    for (int i = 0; i < nTareas; i++)
    {
        tareas[i] = malloc(sizeof(Tarea));
        tareas[i]->TareaID = i+1;
        printf("ingrese la descripcion de la tarea:\n");
        fflush(stdin);
        tareas[i]->Descripcion = malloc(sizeof(char)*60);
        gets(tareas[i]->Descripcion);
        tareas[i]->Duracion = rand() % 91 + 10;
        tareasR[i] = NULL;
        fflush(stdin);
    }
      
    printf("\n\n");

    //listar tareas
     for (int i = 0; i < nTareas; i++) {
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

   buscada = BuscarTarea(tareasR,nTareasR,tareaid);
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
    return 0;
}

Tarea BuscarTarea(Tarea **tareas,int nTareas,int TareaID){
     Tarea tarea_no_encontrada = {0, "Tarea no encontrada", 0};
     for (int i = 0; i < nTareas; i++)
     {
        if (tareas[i]->TareaID == TareaID)
        {
            return *(tareas[i]);
        }
        
     }
     printf("No se encontro la tarea de id= %d",TareaID);
     return tarea_no_encontrada;
}