//
//  simulibre2.c
//
//
//  Created by Sandro Barissi Marín on 29/5/18.
//

#include "simulibre.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359
#define TOL 100

void puntos(double **phi)
{
    int i,j,k,a,b;
    
    //Media aritmética: Método de Jacobi
    for(k=0;k<3000;k++)
    {
        for(i=1;i<279;i++)
        {
            for(j=1;j<199;j++)
            {
                a=(i-140)*(i-140)+(j-100)*(j-100);
                b=(i-115)*(i-115)+(j-100)*(j-100);
                if ((i>115)&&(i<160))
                {
                    if (j<100)
                    {
                        if(fabs(j-0.57*i-14.3)<5){phi[i][j]=-1;continue;}
                    }
                    if (j>100)
                    {
                        if(fabs(j+0.57*i-185.7)<5){phi[i][j]=-1;continue;}
                    }
                }
                if (i<115)
                {
                    if (abs(b-400)<100){phi[i][j]=-1;continue;}
                }
                if (abs(a-3600)<100){phi[i][j]=1;continue;}
                phi[i][j]=0.25*(phi[i-1][j]+phi[i+1][j]+phi[i][j-1]+phi[i][j+1]);
            }
        }
    }
    return;
}

int main(void)
{
    int i,j,a;
    int Nx=280;
    int Ny=200;
    
    double **phi;
    phi=calloc(Nx,sizeof(double*));
    for(i=0;i<Nx;i++)
    {
        phi[i]=calloc(Ny,sizeof(double));
    }
    //Inicializamos
    for(i=0;i<Nx;i++)
    {
        for(j=0;j<Ny;j++)
        {
            phi[i][j]=1;
        }
    }
    //Valores en las placas. Permanecerán fijos durante la iteración
    for(i=1;i<279;i++)
    {
        for(j=1;j<199;j++)
        {
            a=(i-140)*(i-140)+(j-100)*(j-100);
            if ((i>115)&&(i<160))
            {
                if (j<100)
                {
                    if(fabs(j-0.57*i-14.3)<5){phi[i][j]=-1;continue;}
                }
                if (j>100)
                {
                    if(fabs(j+0.57*i-185.7)<5){phi[i][j]=-1;continue;}
                }
            }
            if (i==115)
            {
                if ((j>80)&&(j<120)){phi[i][j]=-1;continue;}
            }
            //if (abs(a-3600)<10){phi[i][j]=1;continue;}
            //if((j-100)^2+(i-140)^2==3600){phi[i][j]=1;continue;}
        }
    }
    printf("-CÁLCULO DE LÍNEAS EQUIPOTENCIALES MIERDAS-\n\n\nHola maricone. Se realizarán 1000 iteraciones \n\n");
    puntos(phi);
    printf("Se han realizado con éxito las iteraciones. En otro documento se ha impreso la lista de puntos.\n\n¡Hasta luego, Maricarmen!\n\n");
    
    FILE *zalida;
    
    zalida=fopen("LLIURE2.txt","w");
    if (zalida == NULL)
    {
        fprintf (stderr,"ERROR: El archivo '%s' no se puede abrir...\n\n","LLIURE.txt");
        return 0;
    }
    
    //fprintf(zalida, "Los puntos son\n\n");
    for(i=0;i<Nx;i++)
    {
        for(j=0;j<Ny;j++)
        {
            fprintf(zalida, "%d %d %lf\n",i, j, phi[i][j]);
        }
        fprintf(zalida, "\n");
    }
    
    
    fclose(zalida);
    return 1;
}
