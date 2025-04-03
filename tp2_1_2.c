// codigo a completar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){
srand(time(NULL));    
int i;
double vt[N];
double *punt;
punt=vt;
for(i = 0;i<N; i++)
{
    punt[i]=1+rand()%100;
    printf("%.2f ", punt[i]);
};
return(0);
}

