//
//  simulacions.c
//  
//
//  Created by Sandro Barissi Marín on 29/5/18.
//

#include "simulacions.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359

void puntos(double **phi, double **Ex, double **Ey)
{
    int i,j,k;
    
    //Media aritmética: Método de Jacobi
    for(k=0;k<3000;k++)
    {
        for(j=1;j<199;j++)
        {
            for(i=1;i<279;i++)
            {
                if (i==120)
                {
                    if(abs(100-j)<40){phi[i][j]=-1;continue;}
                }
                if (i==160)
                {
                    if(abs(100-j)<40){phi[i][j]=1;continue;}
                }
                phi[i][j]=0.25*(phi[i-1][j]+phi[i+1][j]+phi[i][j-1]+phi[i][j+1]);
            }
        }
    }
    
    //Cálculo del campo: Gradiente
    for(i=0;i<279;i++)
    {
        for(j=0;j<199;j++)
        {
            Ex[i][j]=-(phi[i+1][j]-phi[i][j])/0.1;
            Ey[i][j]=-(phi[i][j+1]-phi[i][j])/0.1;
        }
    }
    return;
}

int main(void)
{
    int i,j;
    int Nx=280;
    int Ny=200;
    
    double **phi;
    double **Ex;
    double **Ey;
    phi=calloc(Nx,sizeof(double*));
    for(i=0;i<Nx;i++)
    {
        phi[i]=calloc(Ny,sizeof(double));
    }
    Ex=calloc(Nx,sizeof(double*));
    for(i=0;i<Nx;i++)
    {
        Ex[i]=calloc(Ny,sizeof(double));
    }
    Ey=calloc(Nx,sizeof(double*));
    for(i=0;i<Nx;i++)
    {
        Ey[i]=calloc(Ny,sizeof(double));
    }
    //Inicializamos
    for(i=0;i<Nx;i++)
    {
        for(j=0;j<Ny;j++)
        {
            phi[i][j]=0;
        }
    }
    //Valores en las placas. Permanecerán fijos durante la iteración
    for(j=60;j<140;j++)
    {
        phi[160][j]=1;
        phi[120][j]=-1;
    }
    printf("-CÁLCULO DE LÍNEAS EQUIPOTENCIALES CONDENSADOR-\n\n\nHola maricone. Se realizarán 3000 iteraciones \n\n");
    puntos(phi,Ex,Ey);
    printf("Se han realizado con éxito las iteraciones. En el documento puntos.txt se ha impreso la lista de puntos para el potencial.\nEn el documento campocon.txt, el campo Ex, Ey.\n\n¡Hasta luego, Maricarmen!\n\n");
    
    FILE *zalida;
    FILE *kkk;
    
    zalida=fopen("puntos.txt","w");
    if (zalida == NULL)
    {
        fprintf (stderr,"ERROR: El archivo '%s' no se puede abrir...\n\n","puntos.txt");
        return 0;
    }
    for(i=0;i<Nx;i++)
    {
        for(j=0;j<Ny;j++)
        {
            fprintf(zalida, "%d %d %lf\n",i, j, phi[i][j]);
        }
        fprintf(zalida, "\n");
    }
    fclose(zalida);
    kkk=fopen("campocon.txt","w");
    if (kkk == NULL)
    {
        fprintf (stderr,"ERROR: El archivo '%s' no se puede abrir...\n\n","campocon.txt");
        return 0;
    }
    for(i=0;i<Nx;i++)
    {
        for(j=0;j<Ny;j++)
        {
            fprintf(kkk, "%d %d %lf %lf\n",i, j, Ex[i][j], Ey[i][j]);
        }
        fprintf(kkk, "\n");
    }
    fclose(kkk);
    return 1;
}

