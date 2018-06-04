#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359

void puntos(double **phi)
{
    int i,j,k;
    
    //Media aritmética: Método de Jacobi
    for(k=0;k<10000;k++)
    {
        for(j=1;j<599;j++)
        {
            for(i=1;i<839;i++)
            {
                if ((i-390)*(i-390)+(j-300)*(j-300)<100) //if (i==110)
                {
                    phi[i][j]=-1;continue;
                }
                if ((i-450)*(i-450)+(j-300)*(j-300)<100) //if (i==170)
                {
                    phi[i][j]=1;continue;
                }
                phi[i][j]=(1-1.8)*phi[i][j]+1.8*0.25*(phi[i-1][j]+phi[i+1][j]+phi[i][j-1]+phi[i][j+1]);
            }
        }
    }
    return;
}

int main(void)
{
    int i,j;
    int Nx=840;
    int Ny=600;
    
    double **phi;
    phi=calloc(Nx,sizeof(double*));
    for(i=0;i<Nx;i++)
    {
        phi[i]=calloc(Ny,sizeof(double));
    }
    //Inicializamos
    //for(i=0;i<Nx;i++)
    //{
    //    for(j=0;j<Ny;j++)
    //    {
    //        phi[i][j]=0;
    //    }
    //}
    //Valores en las placas. Permanecerán fijos durante la iteración
    phi[390][300]=-1;
    phi[450][300]=1;
    
    printf("-CÁLCULO DE LÍNEAS EQUIPOTENCIALES HILOS-\n\n\nHola maricone. Se realizarán 1000 iteraciones \n\n");
    puntos(phi);
    printf("Se han realizado con éxito las iteraciones. En otro documento se ha impreso la lista de puntos.\n\n¡Hasta luego, Maricarmen!\n\n");
    
    FILE *zalida;
    
    zalida=fopen("HILOS2.txt","w");
    if (zalida == NULL)
    {
        fprintf (stderr,"ERROR: El archivo '%s' no se puede abrir...\n\n","puntos.txt");
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
