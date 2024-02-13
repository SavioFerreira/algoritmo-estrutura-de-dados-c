#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>

#define TAM 100000
#define LIMITERANDOM 100000

void apresentacao();
void finalizacao();
int  tela_menu();
void menu(int array[], int array_ordenado[]);
void registro_tempo_gasto(float tempo_gasto);
void set_portuguese();


int preencher_array(int array[], int tam_array);
float ordenar_bubble_sort(int array[], int tam_array, int array_ordenado[]);
float ordenar_insertion_sort(int array[], int tam_array);
float ordenar_selection_sort(int array[], int tam_array);

float ordenar_heap_sort(int array[], int tam_array);
void cria_heap(int array[], int i, int f);

float ordenar_quick_sort(int array[], int inicio, int fim);
int particiona_quick(int array[], int inicio, int fim);

float ordenar_merge_sort(int array[], int inicio, int fim);
int cria_merge(int array[], int inicio, int meio, int fim);

float ordenar_shell_sort(int array[], int tam_array);
void imprimir_array(int array[], int tam_array);
bool finalizar_sistema();


int main(){

  static int array[TAM];
  static int array_ordenado[TAM];
  set_portuguese();

  apresentacao();
  menu(array, array_ordenado);

  return 0;

}

void apresentacao(){

  system("color 01");
  printf("\n\n\n\n\t\t\t\t Trabalho AED - Métodos de Ordenação ");
  Sleep(1000);
  system("color 01");
  printf("\n\n\n\n\n\n\t\t\t\t Professor  \n");
  printf("\n\t\t\t\t Jedi: Sandro Teixeira..");
  Sleep(1000);
  printf("\n\n\n\n\n\n\t\t\t\t Integrantes  \n");
  printf("\n\t\t\t\t Padawan: Sávio Ferreira..\n");
  printf("\t\t\t\t Padawan: Lucas..\n");
  Sleep(1000);
  system("cls");

}

void finalizacao(){

  system("color 01");
  system("cls");
  printf("\n\n\n\n\n\n\t\t\t\t\t Agradecimentos:  \n\n");
  Sleep(1000);
  printf("\n\t\t Métodos de Ordenação By : Canal Programação Descomplicada -- Apresentação: André Backes\n");
  Sleep(2000);
  printf("\n\t\t Algoritmo & Estrutura de Dados By : Professor Sandro Teixeira..\n");
  Sleep(2000);
  system("cls");
  printf("\n\n\n\n\n\n\n\t\t\t\t\t\t END...\n\n\n\n\n\n");
  Sleep(2000);

}

int tela_menu(){

  int opcao_menu;

    system("color 02");
    printf("\n\n");
    printf("\n\n\n\t\t\t\t\t\t Métodos de Ordenação \n");
    printf("\n\t\t\t\t(1) Preencher o array com números aleatórios\n");
    printf("\n\t\t\t\t(2) Ordenar array com o método Bubble Sort\n");
    printf("\n\t\t\t\t(3) Ordenar array com o método Insertion Sort\n");
    printf("\n\t\t\t\t(4) Ordenar array com o método Selection Sort\n");
    printf("\n\t\t\t\t(5) Ordenar array com o método Heap Sort\n");
    printf("\n\t\t\t\t(6) Ordenar array com o método Quick Sort\n");
    printf("\n\t\t\t\t(7) Ordenar array com o método Merge Sort\n");
    printf("\n\t\t\t\t(8) Ordenar array com o método Shell Sort\n");
    printf("\n\t\t\t\t(9) Imprimir o array\n");
    printf("\n\t\t\t\t(0) finalizar o sistema\n");
    scanf("%i", &opcao_menu);

    return opcao_menu;

}

void menu(int array[], int array_ordenado[]){
    bool flag_preencher = false;
    bool * p = &flag_preencher;

    while (true){

    switch (tela_menu()){

        case 1:
            *p = preencher_array(array, TAM);
                printf("\n\n\n\n\a\t\t\t\tArray preechido com sucesso!");
        break;

        case 2:
            if(*p) {
                printf(" feito!\n\a Método Bobble Sort\n Tempo gasto = %f\n\n" ,ordenar_bubble_sort(array, TAM, array_ordenado));
            } else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 3:
            if(*p) {
                printf(" feito!\n\a Método Insertion Sort\n Tempo gasto = %f\n\n" ,ordenar_insertion_sort(array, TAM));
            } else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 4:
            if(*p) {
                printf(" feito!\n\a Método Selection Sort\n Tempo gasto = %f\n\n" ,ordenar_selection_sort(array, TAM));
            } else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 5:
            if(*p) {
                printf(" feito!\n\a Método Heap Sort\n Tempo gasto = %4f\n\n" , ordenar_heap_sort(array, TAM));
            }
            else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 6:
            if(*p) {

                registro_tempo_gasto(printf(" feito!\n\a Método Quick Sort\n Tempo gasto = %f\n\n" , ordenar_quick_sort(array, 0, TAM -1)));
            }
            else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 7:
            if(*p) {
                printf(" feito!\n\a Método Merge Sort\n Tempo gasto = %f\n\n" , ordenar_merge_sort(array, 0, TAM -1));
            } else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 8:
            if(*p) {
                printf(" feito!\n\a  Métofo Shell Sort\n Tempo gasto = %f\n\n", ordenar_shell_sort(array, TAM));
            } else {
                printf("Preencha o vetor primeiro!");
            }
        break;

        case 9:
            if(*p) {
                int valor_digitado = 0;
                printf("(1)\t\t\tImprimir Array Desordenado\n");
                printf("\t\t\t(2)Imprimir Array Ordenado\n");
                scanf("%d", &valor_digitado);
                    if(valor_digitado == 1) {
                        imprimir_array(array, TAM);
                    } else if (valor_digitado == 2) {
                        imprimir_array(array_ordenado, TAM);
                    } else {
                        printf("\nEscolha uma opção valida!");
                    }
            } else {
                printf("Preencha o vetor primeiro!");
            }
        break;
        case 10:
            registro_tempo_gasto(0.0);
        break;

        case 0:
            finalizar_sistema();
        break;

        default :
            printf("\n\t\t\t\t\t\aOpção inválida");
    }
  }

}

void registro_tempo_gasto(float tempo_gasto){

    float a,b,c,d,e,f,g,menor;

    a = tempo_gasto;
    b = a;
    c = b;
    d = e;
    f = g;

    if (a != b){
        if(b < a)
          menor = b;
    }
    if(b != c){
        if(c < b)
          menor = c;
    }
    if(c != d){
        if(d < c)
          menor = d;
    }
    if(d != e){
        if(e < d)
          menor = e;
    }

    printf("\n %f :", a);
    printf("\n %f :", b);
    printf("\n %f :", c);
    printf("\n %f :", d);

}


void set_portuguese(){
    setlocale(LC_ALL, "Portuguese");
}

 int preencher_array(int array[], int tam_array){
  srand(time(NULL));

  for (int i=0; i < tam_array; i++){
   array[i] =  rand() % LIMITERANDOM + 1;
  }

  system("cls");
  Sleep(1000);

 return 1;
}

float ordenar_bubble_sort(int array[], int tam_array, int array_ordenado[]){

    for(int i = 0; i < tam_array; i++) {
        array_ordenado[i] = array[i];
    }

   int i, j, temp;
   float temp_execu;
   clock_t timer;

   timer = clock();
   for (i = 0; i < tam_array- 1; i++){
     for (j = i + 1; j < tam_array; j++){
       if (array_ordenado[i] > array_ordenado[j]) {
         temp = array_ordenado[j];
         array_ordenado[j] = array_ordenado[i];
         array_ordenado[i] = temp;
       }
     }
  }

   timer = clock() - timer;
   temp_execu = ((float) timer / CLOCKS_PER_SEC);



   return temp_execu;

}

float ordenar_insertion_sort(int array[], int tam_array){

  int i, j, temp;
  float temp_execu;
  clock_t timer;

    timer = clock();
    for (i = 1; i <= tam_array; i++){
        temp = array[i];
        for (j = i; (j > 0) && (temp < array[j -1]); j--)
            array[j] = array[j - 1];
        array[j] = temp;
   }

   timer = clock() - timer;
   temp_execu = ((float) timer / CLOCKS_PER_SEC);

   return temp_execu;

}

float ordenar_selection_sort(int array[], int tam_array){

  int i, j, menor, troca;
  float temp_execu;
  clock_t timer;

  timer = clock();
  for (i = 0; i < tam_array-1; i++){
    menor = i;
    for(j = i+1; j < tam_array; j++){
        if(array[j] < array[menor])
            menor = j;
    }

    if (i != menor){
        troca = array[i];
        array[i] = array[menor];
        array[menor] = troca;
    }
  }

   timer = clock() - timer;
   temp_execu = ((float) timer / CLOCKS_PER_SEC);

   return temp_execu;

}

float ordenar_heap_sort(int array[], int tam_array){
    int i, aux;
    float temp_execu;
    clock_t timer;


     timer = clock();
    for (i=(tam_array- 1)/2; i >= 0; i--){
        cria_heap(array, i, tam_array-1);
    }
    for(i = tam_array-1; i >= 1; i--){
        aux = array[0];
        array[0] = array [i];
        array[i] = aux;
        cria_heap(array, 0, i - 1 );
    }

   timer = clock() - timer;
   temp_execu = ((float) timer / CLOCKS_PER_SEC);

   return temp_execu;

}

void cria_heap(int array[], int inicio, int fim){
    int aux = array[inicio];
    int j = inicio * 2 + 1;
    while (j <= fim){
        if(j < fim){
            if(array[j] < array[j + 1]){
                j = j + 1;
            }
        }
        if (aux < array[j]){
            array[inicio] = array[j];
            inicio = j;
            j = 2 * inicio + 1;
        } else {
            j = fim + 1;
        }
    }
    array[inicio] = aux;

}

float ordenar_quick_sort(int array[], int inicio, int fim){
    int pivo;
    float temp_execu;
    clock_t timer;

    timer = clock();
    if (fim > inicio){
        pivo = particiona_quick(array, inicio, fim);
        ordenar_quick_sort(array, inicio, pivo -1);
        ordenar_quick_sort(array, pivo+1, fim);
    }

    timer = clock() - timer;
    temp_execu = ((float) timer / CLOCKS_PER_SEC);

  return temp_execu;

}

int particiona_quick(int array[], int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = array[inicio];

    while (esq < dir){
        while(esq <= fim && array[esq] <= pivo){
            esq++;
        }
        while(dir >= 0 && array[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = array[esq];
            array[esq] = array[dir];
            array[dir] = aux;
        }
    }
    array[inicio] = array[dir];
    array[dir] = pivo;

    return dir;

}

float ordenar_merge_sort(int array[], int inicio, int fim){

    int meio;
    float temp_execu;
    clock_t timer;

    timer = clock();
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        ordenar_merge_sort(array, inicio, meio);
        ordenar_merge_sort(array, meio+1, fim);
        cria_merge(array, inicio, meio, fim);
    }

    timer = clock() - timer;
    temp_execu = ((float) timer / CLOCKS_PER_SEC);

  return temp_execu;

}

int cria_merge(int array[], int inicio, int meio, int fim){
    int *temp, p1, p2, tam_array, i, j, k;
    int fim1 = 0, fim2 = 0;
    tam_array= fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tam_array*sizeof(int));
    if(temp != NULL){
        for(i=0; i< tam_array; i++){
            if(!fim1 && !fim2){
                if(array[p1] < array[p2])
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];
            }
        }
        for(j=0, k=inicio; j<tam_array; j++, k++)
            array[k] = temp[j];
    }
    free(temp);

}

float ordenar_shell_sort(int array[], int tam_array){
    int i, j, h, aux;
    h =1;
    float temp_execu;
    clock_t timer;

    timer = clock();
    while(h < tam_array/3)
        h= 3 * h + 1;
    while(h > 0){
        for(i = h; i < tam_array; i++){
            aux = array[i];
            j = i;
            while(j >= h && aux < array[i - h]){
                array[j] = array[j - h];
                j = j - h;
            }
            array[j] = aux;
        }
        h = (h-1)/3;
    }

    timer = clock() - timer;
    temp_execu = ((float) timer / CLOCKS_PER_SEC);
    return temp_execu;

}

void imprimir_array(int array_ordenado[], int tam_array){
    int f = tam_array- 100;
    system("cls");
    printf("\n\t\t\t\t\tPrimeiras 100 posições\n");
    printf("\n");
    for (int i = 0; i < 100; i++){
      printf(" |%d| ", array_ordenado[i]);
   }

    printf("\n\n\n\n");
    printf("\n\t\t\t\t\tÚltimas 100 posições\n\n");
    for (int i = 0; i < 100; i++){
      printf(" |%d| ", array_ordenado[f]);
      f++;
   }
   printf("\n");
   Sleep(2000);

}

bool finalizar_sistema(){

    char pergunta_de_saida[] = "\n\t\t\t\tFinalizar sistema?\a Y/N\n";

    fflush(stdin);
    char sair;
    bool pode_sair, nao_pode_sair, flag;
    flag = false;

    while(!flag){

        printf(pergunta_de_saida);
        scanf("%c", &sair);

        pode_sair = (sair == 'y' || sair == 'Y');
        nao_pode_sair = (sair == 'n' || sair == 'N');

        if(pode_sair){
          flag = true;
          finalizacao();
          exit(0);

        }
        if(nao_pode_sair){
          system("cls");
          return (0);
        }
    }

  return flag;

}
