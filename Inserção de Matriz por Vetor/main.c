#include <stdio.h>
#define MAX 100


void funcao (int mat[MAX][MAX], int m, int n);


int main(void) {

  int m=0,n=0;

  printf("\nDigite o valor de m: ");
  scanf("%d",&m);
  printf("Digite o valor de n: ");
  scanf("%d",&n);
  int mat[m][n];

  if(m<MAX && n<MAX){

  funcao(mat,m,n);
  
  }else
   printf("\n\nVALOR DE m OU n ACIMA DO PERMITIDO!!!");
  return 0;
}

void funcao (int mat[MAX][MAX], int m, int n){

  int vet[m*n];
  int i,j;
  int aux;

  printf("\n");

  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      printf("Insira na matriz um valor na posição [%d][%d]: ",i,j);
      scanf("%d",&mat[i][j]);
      vet[aux] = mat[i][j];
      aux++;
    }
  }

  printf("\nMatriz:\n");
  for(i=0; i<m; i++){
    printf("|");
    for(j=0; j<n; j++){
      printf("\t%d\t|",mat[i][j]);
    }
    printf("\n");
  }

  printf("\nVetor: |");
  for(i=0; i<m*n; i++){
    printf("%d|",vet[i]);
  }

}

