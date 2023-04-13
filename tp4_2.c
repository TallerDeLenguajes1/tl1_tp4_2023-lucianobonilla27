#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;  
int Duracion; // entre 10 – 100
}typedef Tarea;


int main()
{
    srand(time(NULL));
    int nTareas,menu;
    Tarea ** tareas;
    Tarea ** tareasR;
    Tarea ** tareasP;
    puts("ingrese la cantidad de tareas a ralizar:");
    scanf("%d",&nTareas);


    tareas = malloc(sizeof(Tarea*)*nTareas);
    tareasR = malloc(sizeof(Tarea*)*nTareas);



    for (int i = 0; i < nTareas; i++)
    {
        tareas[i] = malloc(sizeof(Tarea));
        tareas[i]->TareaID = i+1;
        printf("ingrese la descripcion de la tarea:\n");
        tareas[i]->Descripcion = malloc(sizeof(char)*60);
        scanf("%s",tareas[i]->Descripcion);
        tareas[i]->Duracion = rand() % 91 + 10;
        tareasR[i] = NULL;
    }
      
    

    //listar tareas
    for (int i = 0; i < nTareas; i++)
    {

        printf("id: %d\n",tareas[i]->TareaID);
        printf("descripcion: %s\n",tareas[i]->Descripcion);
        printf("duracion: %d\n",tareas[i]->Duracion);
        puts("Seleccione 1 si la tarea fue realizada sino seleccione 0");
        fflush(stdin);
        scanf("%d",&menu);
        if (menu == 1)
        {
            tareasR[i] = tareas[i];
        } 
    }

    puts("tareas realizadas: ");
    for (int i = 0; tareasR[i] != NULL; i++)
    {
        printf("id: %d\n",tareasR[i]->TareaID);
        printf("descripcion: %s\n",tareasR[i]->Descripcion);
        printf("duracion: %d\n",tareasR[i]->Duracion);
        
    }
    fflush(stdin);
   



    for (int i = 0; i < nTareas; i++)
    {
        free(tareas[i]->Descripcion);
        free(tareas[i]); 
    }
    free(tareas);
    return 0;
}