#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>


#define TAM 100000
#define LIMITERANDOM 200

void menu_de_opcoes();
void preencher_array();
void ordenar_bubble_sort();
void ordenar_insertion_sort();
void ordenar_selection_sort();
void ordenar_heap_sort();
void ordenar_quick_sort();
void ordenar_merge_sort();
void ordenar_shell_sort();

int main(void){

   menu_de_opcoes();

 return 0;
}

void menu_de_opcoes(){

  int a=0;
  int opcao;
  char sair = 'n';

  setlocale(LC_ALL, "Portuguese");

  while (sair == 'n'){

        printf("\n\a_________________________________________________\n");
        printf("\n__________________Menu de Opções_________________\n");
        printf("(1) Preencher o array com números aleatórios\n");
        printf("(2) Ordenar o array pelo método Bubble Sort\n");
        printf("(3) Ordenar o array pelo método Insertion Sort\n");
        printf("(4) Ordenar o array pelo método Selection Sort\n");
        printf("(5) Ordenar o array pelo método Heap Sort\n");
        printf("(6) Ordenar o array pelo método Quick Sort\n");
        printf("(7) Ordenar o array pelo método Merge Sort\n");
        printf("(8) Ordenar o array pelo método Shell Sort\n");
        printf("(9) Imprimir o array\n");
        printf("\n_________________________________________________\n");
        scanf("%d", &opcao);

        switch (opcao){

          case 1:
              preencher_array();
          break;

          case 2:
              ordenar_bubble_sort();
          break;

          case 3:
              ordenar_insertion_sort();
          break;

          case 4:
              ordenar_selection_sort();
          break;

          case 5:
              ordenar_heap_sort();
          break;

          case 6:
              ordenar_quick_sort();
          break;

          case 7:
              ordenar_merge_sort();
          break;

          case 8:
              ordenar_shell_sort();
          break;

          case 9:
              imprimir_array();
          break;

        }
  }

}

void preencher_array(int array[]){

  int i;
  srand(time(NULL));

  for ( i=0; i < TAM ; i++){
   array[i] =  (rand() % LIMITERANDOM) + 1;
  }

}

void ordenar_bubble_sort(int array[]){

    int i, j, temp;
     printf("Metodo 1\n");

     for (i = 0; i < TAM - 1; i++)
          for (j = i + 1; j < TAM; j++)
               if (array[i] > array[j]) {
                   temp = aNum[j];
                   array[j] = array[i];
                   array[i] = temp;
               }

}

void ordenar_insertion_sort(){

}

void ordenar_selection_sort(){

}

void ordenar_heap_sort(){

}

void ordenar_quick_sort(){

}

void ordenar_merge_sort(){

}

void ordenar_shell_sort(){

}


void imprimir_array(int vetor[]){
    int f = TAM - 100;

    for (int i = 0; i < 100; i++){
      printf("%d \n", vetor[i]);
      if( i == 100) {
        printf("---------\n");
      }
   }

    for (int i = f; i < 100; i++){
      printf("%d \n", vetor[i]);
   }

}

