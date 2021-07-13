/* 
  
  Obs:
  O programa inicializa pre-defininindo os 20 tipos de sapatos diferentes. 
  Temos 5 cores diferentes para cada tipo de sapato, 4 tamanhos diferentes para cada (totalizando os 20 tipos) e 4 codigos para cada (totalizando 20 codigos), tudo listado conforme especificado na tabela abaixo:
  
            |Cor:      |  Tamanhos:       |  Codigo:
            |          | (0) (1) (2) (3)  | (0) (1) (2) (3)  
  Sapato 0: |amarelo   |  30, 35, 40, 45  |  01, 02, 03, 04
  Sapato 1: |laranja   |  30, 35, 40, 45  |  05, 06, 07, 08
  Sapato 2: |vermelho  |  30, 35, 40, 45  |  09, 10, 11, 12
  Sapato 3: |azul      |  30, 35, 40, 45  |  13, 14, 15, 16
  Sapato 4: |verde     |  30, 35, 40, 45  |  17, 18, 19, 20
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sapatos{
  char cor[80];
  int tamanho[4];
  int codigo[4];
}sapatos;

void funcao(struct sapatos processa[]){
  printf("\nBem-Vindo(a) a Interface de Producao de Sapatos!\n\nTipo:\tCores:\t\tTamanhos:\t\t\tCodigo de Referencia:\n\t\t\t\t\t(0) (1) (2) (3)\n(0)\t\tAmarelo\t-\t30, 35, 40, 45\t-\t1, 2, 3, 4\n(1)\t\tLaranja\t-\t30, 35, 40, 45\t-\t5, 6, 7, 8\n(2)\t\tVermelho-\t30, 35, 40, 45\t-\t9, 10, 11, 12\n(3)\t\tAzul\t-\t30, 35, 40, 45\t-\t13, 14, 15, 16\n(4)\t\tVerde\t-\t30, 35, 40, 45\t-\t17, 18, 19, 20\n");

  int i, j, contador1, contador2, moda, ana, total=0, qtd[6],aux1[6],aux2[6];
  float percentual;

  for(i=1; i<=6; i++){
    printf("\n---Dia %d---",i);
    printf("\nInforme o tipo de sapato a ser produzido (0,1,2,3 ou 4): ");
    scanf("%d",&aux1[i]);
    printf("Tipo escolhido: %d - Cor: %s",aux1[i],processa[aux1[i]].cor);
    printf("\nInforme o tipo de tamanho do sapato a ser produzido(0,1,2 ou 3): ");
    scanf("%d",&aux2[i]);
    printf("Tamanho escolhido: %d - Codigo: %d",processa[aux1[i]].tamanho[aux2[i]],processa[aux1[i]].codigo[aux2[i]]);
    printf("\nInforme a quantidade a ser produzida no dia %d: ",i);
    scanf("%d",&qtd[i-1]);
    total += qtd[i-1];
  }


  printf("\n\n\n----------Relatorio da Producao Semanal (Ultimos 6 dias)----------");
  printf("\n\n- Quantidade total produzida: %d Sapatos",total);
 
//Percentual
  printf("\n\n- Percentual de tipos de sapatos produzidos em relacao ao total:");
  for(i=1; i<=6; i++){
    percentual = ((float)qtd[i-1]/(float)total)*100;
    printf("\nTipo %d do dia %d: %.2f",aux1[i],i,percentual);
  }

//Media
  printf("\n\n- Media da producao semanal: %d",total/6);

//Mediana 
  for(i=0;i<6-1;i++){
    for(j=i+1;j<6;j++){        	
      if(qtd[i] > qtd[j]){
      ana = qtd[i];
      qtd[i] = qtd[j];
      qtd[j] = ana;}
    }
  }
  printf("\n\n- Mediana da producao semanal: %.0f", ((float)qtd[2]+(float)qtd[3])/2);

//Moda
  for(i=0;i<6-1;i++){
		for(j=i+1; j<6; j++){
			if(qtd[i]==qtd[j])
				contador1++;
			if(contador1>contador2)
				moda=qtd[i];
			contador2=contador1;
			contador1=0;
		}
	}
  printf("\n\n- Moda da producao semanal: %d", moda);

}

int main(void) {
  struct sapatos tipos[5];
  int i,j,aux=0;

// Inserindo os nomes de cores de cada sapato:
  strcpy(tipos[0].cor, "AMARELO");
  strcpy(tipos[1].cor, "LARANJA");
  strcpy(tipos[2].cor, "VERMELHO");
  strcpy(tipos[3].cor, "AZUL");
  strcpy(tipos[4].cor, "VERDE");

// Inserindo o codigo de cada sapato:
for(i=0; i<5; i++){
  for(j=0; j<4; j++){
  aux++;  
  tipos[i].codigo[j] = aux; }}

// Inserindo o tamanho de cada sapato:
for(i=0; i<5; i++){
  for(j=0; j<4; j++){
  tipos[i].tamanho[j] = 30+(5*j); }}

funcao(tipos);
  return 0;
}

