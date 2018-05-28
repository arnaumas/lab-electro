#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,k;
    char * commandsForGnuplot[] = {"set title \"Plot\"", "plot [0:1000] [0:1000] 'data.temp' with points pointsize 0.01 pointtype 20, 'data2.temp' with points pointsize 0.01 pointtype 20, 'data3.temp' with points pointsize 0.01 pointtype 20,'data4.temp' with points pointsize 0.01 pointtype 20"};
    int *y,*x;
    int n=0;
    FILE * temp = fopen("data.temp", "w");
    FILE * temp2 =fopen("data2.temp", "w");
    FILE * temp3 =fopen("data3.temp", "w");
    FILE * temp4 =fopen("data4.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    
    
    double phi[1000][1000];

    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            phi[i][j]=10;
        }
    }
    
    for (k=0;k<1000;k++){
        for (i=0;i<1000;i++){
            for (j=0;j<1000;j++){
                if (i<450 && i>400 && j<800 && j>200){
                    phi[i][j]=0;
                }
                else if (i<600 && i>550 && j>200 && j<800){
                    phi[i][j]=0;
                }
                else if (i==0){
                    phi[i][j]=(1/3)*(phi[i+1][j]+phi[i][j+1]+phi[i][j-1]);
                }
                else if (i==999){
                    phi[i][j]=(1/3)*(phi[i-1][j]+phi[i][j+1]+phi[i][j-1]);
                }
                else if (j==0){
                    phi[i][j]=(1/3)*(phi[i][j+1]+phi[i-1][j]+phi[i+1][j]);
                }
                else if (j==999){
                    phi[i][j]=(1/3)*(phi[i][j-1]+phi[i-1][j]+phi[i+1][j]);
                }
                else{
                    phi[i][j]=0.25*(phi[i-1][j]+phi[i][j-1]+phi[i+1][j]+phi[i][j+1]);
                }
            }
        }
    }
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]>9.5 && phi[i][j]<9.50001){
                n++;
            }
        }
    }
    
    k=0;
    
    x=(int *)malloc(n*sizeof(int));
    y=(int *)malloc(n*sizeof(int));

    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]>9 && phi[i][j]<9.50001){
                fprintf(temp, "%d %d \n", i, j);
            }
        }
    }
    
    n=0;
    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]==0){
                n++;
            }
        }
    }
    
    k=0;
    
    x=(int *)malloc(n*sizeof(int));
    y=(int *)malloc(n*sizeof(int));
    
    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]==0){
                fprintf(temp2, "%d %d \n", i, j);
            }
        }
    }
    
    n=0;
    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]>7.5 && phi[i][j]<7.50001){
                n++;
            }
        }
    }
    
    k=0;
    
    x=(int *)malloc(n*sizeof(int));
    y=(int *)malloc(n*sizeof(int));
    
    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]>7 && phi[i][j]<7.50001){
                fprintf(temp3, "%d %d \n", i, j);
            }
        }
    }
    
    n=0;
    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]>4.5 && phi[i][j]<4.50001){
                n++;
            }
        }
    }
    
    k=0;
    
    x=(int *)malloc(n*sizeof(int));
    y=(int *)malloc(n*sizeof(int));
    
    
    for (i=0;i<1000;i++){
        for (j=0;j<1000;j++){
            if (phi[i][j]>4 && phi[i][j]<4.50001){
                fprintf(temp4, "%d %d \n", i, j);
            }
        }
    }
    
    for (i=0; i < 2; i++)
    {
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
    
    return 0;
}



