#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359

void puntos(double **phi) {

  int i,j,k;

  double fix = 9;

  // Iterarem amb el metode de Jacobi
  for(k = 0; k < 10000; k++) {
    for(j = 1; j < 599; j++) {
      for(i = 1; i < 839; i++) {
        if((i-390)*(i-390)+(j-300)*(j-300) < 100) {
          phi[i][j] = -fix/2; 
          continue;
        }
        if((i-450)*(i-450)+(j-300)*(j-300) < 100) {
          phi[i][j] = fix/2;
          continue;
        }
        phi[i][j] = (1-1.8)*phi[i][j] + 1.8*0.25*(phi[i-1][j] + phi[i+1][j] + phi[i][j-1] + phi[i][j+1]);
      }
    }
  }
}

int main() {
  int i,j;
  int Nx = 840;
  int Ny = 600;

  double fix = 9;

  double **phi;

  phi = calloc(Nx,sizeof(double*));
  for(i = 0; i < Nx; i++) {
    phi[i] = calloc(Ny,sizeof(double));
  }

  // Valors del potencial als fils. Es mantindran fixos durant la iteracio
  phi[390][300] = -fix/2.;
  phi[450][300] = fix/2.;


  puntos(phi);
  printf("S'han realitzat amb exit 10000 iteracions del metode");

  FILE *potencial;

  // Escrivim el potencial
  potencial = fopen("fils-potencials.dat","w");
  if (potencial == NULL) {
    fprintf (stderr,"ERROR: L'arxiu no s'ha pogut obrir");
    return 1;
  }

  for(i = 0; i < Nx; i++) {
    for(j = 0; j < Ny; j++) {
      fprintf(potencial, "%d %d %lf\n", i, j, phi[i][j]);
    }
    fprintf(potencial, "\n");
  }

  fclose(potencial);

  return 0;
}
