#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359

void puntos(double **phi, double **Ex, double **Ey) {
  int i,j,k;

	double fix = 9;

	// Iterarem amb el mètode de Jacobi
  for(k = 0; k < 3000; k++) {
    for(j = 1; j < 199; j++) {
      for(i = 1; i < 279; i++) {
        if (i == 120) {
          if(abs(100-j) < 40){
          	phi[i][j] = -fix/2.;
          	continue; 
          }
        }
        if(i == 160) {
          if(abs(100-j) < 40) {
          	phi[i][j] = fix/2.;
          	continue;
          }
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
}

int main() {
  int i,j;
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
  for(j = 60; j < 140; j++) {
    phi[160][j] = fix/2.;
    phi[120][j] = -fix/2.;
  }

  puntos(phi, Ex, Ey);
  printf("S'han realitzat amb èxit 3000 iteracions del mètode");

  FILE *potencial;
  FILE *camp;

	// Escrivim el potencial
  potencial = fopen("condensador-potencial.dat","w");
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
  camp = fopen("condensador-camp.dat","w");
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

