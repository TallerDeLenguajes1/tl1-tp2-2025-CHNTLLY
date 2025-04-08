#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};


void listarPCs(struct compu pcs[], int cantidad);

void mostrarMasVieja(struct compu pcs[], int cantidad);

void mostrarMasVeloz(struct compu pcs[], int cantidad);


int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};
    struct compu PC[5];
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
    {
        int random = 0 + rand() % (5 - 0 + 1); //genera los indices del arreglo bidimensional tipos
        PC[i].velocidad = 1 + rand() % (3 - 1 + 1); //min + rand() % (max - min + 1)
        PC[i].anio = 2015 + rand() % (2024 - 2015 - 1);
        PC[i].cantidad_nucleos = 1 + rand() % (8 - 1 + 1);
        PC[i].tipo_cpu = tipos[random];
    };
    listarPCs(PC,5);
    mostrarMasVieja(PC,5);
    mostrarMasVeloz(PC,5);
}



void listarPCs(struct compu pcs[], int cantidad)
{
    for(int i = 0; i < cantidad ; i++)
    {
        printf("PC numero %d:\n",i+1);
        printf("Anio: %d  --  Cantidad de nucleos: %d  --  Velocidad: %d Ghz\nTipo de procesador: ", pcs[i].anio,pcs[i].cantidad_nucleos,pcs[i].velocidad);
        puts(pcs[i].tipo_cpu);
        printf("\n\n");
    };
};


void mostrarMasVieja(struct compu pcs[], int cantidad)
{
    int menor=2030,indice=0; //preparo la variable donde se almacena el indice de la compu mas vieja
    for(int i=0; i< cantidad; i++)
    {
        if(pcs[i].anio<menor)
        {
            menor = pcs[i].anio;
            indice=i;
        }
    }
    printf("PC mas vieja encontrada:\n");
    printf("PC numero %d:\n",indice+1);
    printf("Anio: %d  --  Cantidad de nucleos: %d  --  Velocidad: %d Ghz\nTipo de procesador: ", pcs[indice].anio,pcs[indice].cantidad_nucleos,pcs[indice].velocidad);
    puts(pcs[indice].tipo_cpu);
    printf("\n\n");
};

void mostrarMasVeloz(struct compu pcs[], int cantidad)
{
    int mayor=0,indice=0; //preparo la variable donde se alamcenara el indice de la compu mas veloz
    for(int i=0; i< cantidad; i++)
    {
        if(pcs[i].velocidad>mayor)
        {
            mayor = pcs[i].velocidad;
            indice=i;
        }
    }
    printf("PC mas veloz encontrada:\n");
    printf("PC numero %d:\n",indice+1);
    printf("Anio: %d  --  Cantidad de nucleos: %d  --  Velocidad: %d Ghz\nTipo de procesador: ", pcs[indice].anio,pcs[indice].cantidad_nucleos,pcs[indice].velocidad);
    puts(pcs[indice].tipo_cpu);
    printf("\n\n");
};