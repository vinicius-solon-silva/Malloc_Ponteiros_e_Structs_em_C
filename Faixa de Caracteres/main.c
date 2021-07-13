#include <stdio.h>

typedef struct cell{
  char car;
  int peso;
}cell;

int faixa(struct cell vet[], int n){
  int soma, i=0, j=1;

  for(i=0;i<n;i++){
        vet[i].peso = 0;
  }
  
  printf("\n\nInsira uma letra nas posicoes do vetor criado a seguir: \n");
  for(i=0;i<n;i++){
    printf("\n[%d]: ", i);           
    scanf(" %c", &vet[i].car);
  }

  printf("\n");
  for(i=0;i<n;i++){
    printf("Insira um valor para ser o peso da letra na posicao %d: ", i); 
    scanf("%d", &vet[i].peso);
  }
    
  for(i=0;i<n;i++){                                         
    if(vet[i].car == vet[j].car){
      soma += vet[i].peso;
      }
    if(vet[i].car != vet[j].car && vet[i-1].car == vet[j-1].car){
      soma += vet[i].peso;
      }
    j++;
  }
  
return soma;
}

int main(void) {
  int n,x;

  printf("\nDigite um numero acima de 0 para criar o vetor: ");
  scanf("%d",&n);

  if(n>0){
  struct cell vet[n];
  x = faixa(vet,n);

  printf("\nSoma dos pesos dos elementos : %d",x);
  }
  else printf("\n\nVALOR ABAIXO DO PERMITIDO!");

}