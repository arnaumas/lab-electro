#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359
#define TOL 100

void puntos(double **phi, double **Ex, double **Ey) {
  int i,j,k,a,b;

	double fix = 9;

  // Iterarem amb el mètode de Jacobi
  for(k = 0; k < 3000; k++) {
    for(i = 1; i < 279; i++) {
      for(j = 1; j < 199; j++) {
        a = (i-140)*(i-140) + (j-100)*(j-100);
        b = (i-115)*(i-115) + (j-100)*(j-100);
        if((i > 115) && (i < 160)) {
          if(j < 100) {
            if(fabs(j-0.57*i-14.3) < 5) {
            	phi[i][j] = -fix/2.;
            	continue;
            }
          }
          if(j > 100) {
            if(fabs(j+0.57*i-185.7) < 5) {
            	phi[i][j] = -fix/2.;
            	continue;
            }
          }
        }
        if(i < 115) {
          if(abs(b - 400) < 100){ 
          	phi[i][j]= -fix/2.; 
          	continue;
          }
        }
        if(abs(a-3600)<100) {
        	phi[i][j] = fix/2.;
        	continue;
        }
        phi[i][j] = 0.25*(phi[i-1][j] + phi[i+1][j] + phi[i][j-1] + phi[i][j+1]);
      }
    }
  }

 	// Fem el gradient del potencial per calcular el camp
  for(i = 0; i < 279; i += 3) {
    for(j = 0; j < 199; j += 3) {
      Ex[i][j] = -(phi[i+1][j] - phi[i][j])/0.1;
      Ey[i][j] = -(phi[i][j+1] - phi[i][j])/0.1;
    }
  }
  return;
}

int main() {
  int i,j,a;
  int Nx = 280;
  int Ny = 200;

	double fix = 9;

  double **phi;
	double **Ex;
  double **Ey;

  phi = calloc(Nx, sizeof(double*));
  for(i = 0; i < Nx; i++) {
    phi[i] = calloc(Ny, sizeof(double));
  }
  Ex = calloc(Nx, sizeof(double*));
  for(i = 0; i < Nx; i++) {
    Ex[i] = calloc(Ny, sizeof(double));
  }
  Ey = calloc(Nx, sizeof(double*));
  for(i = 0; i < Nx; i++) {
    Ey[i]=calloc(Ny,sizeof(double));
  }

  // Inicialitzem
   for(i = 0; i < Nx; i++) {
    for(j = 0; j < Ny; j++) {
      phi[i][j]=0;
    }
  }

  // Valors del potencial a les plaques. Es mantindran fixos durant la iteració
  for(i = 1; i < 279; i++) {
    for(j = 1; j < 199; j++) {
      a = (i-140)*(i-140) + (j-100)*(j-100);
      if((i > 115) && (i < 160)) {
        if(j < 100) {
          if(fabs(j-0.57*i-14.3) < 5) {
          	phi[i][j] = -fix/2.;
          	continue;
          }
        }
        if(j > 100) {
          if(fabs(j+0.57*i-185.7) < 5) { 
          	phi[i][j] = -fix/2.;
          	continue;
          }
        }
      }
      if(i == 115) {
        if((j > 80) && (j < 120)) {
        	phi[i][j] = -fix/2.;
        	continue;
        }
      }
    }
  }

  puntos(phi, Ex, Ey);
  printf("S'han realitzat amb èxit 3000 iteracions del mètode");

  FILE *potencial;
  FILE *camp;

	// Escrivim el potencial
  potencial = fopen("lliure-potencial.dat","w");
  if (potencial == NULL) {
    fprintf (stderr, "ERROR: L'arxiu no s'ha pogut obrir");
    return 1;
  }
  for(i = 0; i < Nx; i++) {
    for(j = 0; j < Ny; j++) {
      fprintf(potencial, "%d %d %lf\n", i, j, phi[i][j]);
    }
    fprintf(potencial, "\n");
  }
  fclose(potencial);

	// Escrivim el camp
  camp = fopen("lliure-camp.dat","w");
  if(camp == NULL) {
    fprintf (stderr, "ERROR: L'arxiu no s'ha pogut obrir");
    return 1;
  }

  for(i = 0; i < Nx; i++) {
    for(j = 0; j < Ny; j++) {
      fprintf(camp, "%d %d %lf %lf\n",i, j, Ex[i][j], Ey[i][j]);
		}
    fprintf(camp, "\n");
  }
  fclose(camp);
  return 0;
}