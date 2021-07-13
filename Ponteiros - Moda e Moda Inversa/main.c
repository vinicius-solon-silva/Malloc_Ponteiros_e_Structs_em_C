#include <stdio.h>


void frequencias(int v[], int n, int *f1, int *f2){

  int i=0, j=0, q[n], aux;

  printf("\nInsira o valor dos elementos nas posicoes a seguir: \n");
  for(i=0; i<n; i++){
  printf("\n[%d] = ", i);
  scanf("%d",&v[i]);
  }

  for(i=0; i<n; i++){
   q[i]=0;
  }

  *f1 = v[0];
  *f2 = v[0];

  //Procura maiores:
  for(i=0;i<n;i++){
    for(j=0; j<n; j++){
      if(v[i] == v[j]){
        q[i]++;}
         }
     }

  //Procura menores:
  aux=0;
  for(i=1;i<n;i++){
   if(q[aux]<q[i]){
    *f2 = v[i];}
   if(q[aux]>q[i]){
    *f1 = v[i];}
    aux++;
  }

}

int main(void) {

  int n, menor=0, maior=0;

  printf("\nDefina o tamanho do vetor: ");
  scanf("%d",&n);

  int vetor[n];

  frequencias(vetor, n ,&menor, &maior);

  printf("\n\nNumero com MENOR frequencia (f1): %d", menor);   
  printf("\n\nNumero com MAIOR frequencia (f2): %d", maior);

  
  return 0;
}