#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

#define tam 500
//#define tam 1000
//#define tam 50000
//#define tam 100000

/*Integrantes do Grupo:
	Carlos Eduardo de Sousa Pereira, RA: F23BIB4, Turma: CC4Q06
	Guilherme Dionízio feitoza, RA: F23260, Turma: CC4Q06
	Guilherme Silva Oliveira, RA: F314057, Turma: CC4P06
	Pedro Matheus Lopes dos Reis, RA: F23FGJ0, Turma: CC4P06
*/

long  get_current_time_with_ns (void)
{
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    return spec.tv_nsec;
}

//Ordenação QuickSort
void quick_sort(int *a, int left, int right);
//Ordenação InsertionSort
void insertion_sort(int *a);
//Ordenação SelectionSort
void selection_sort(int *a, int tamanho);

int main(int argc, char** argv){
	int i, vetor[tam], vetor_insert[tam], vetor_select[tam];
	long inicio1, inicio2;
	
	inicio1 = get_current_time_with_ns();
	
	//Recebe o maximo de "tam" valores	
	//Recebe o arquivo a ser ordenado pelos algoritimos
	for(int i=0; i < tam ; i++){
      scanf(" %d", vetor+i);
      scanf(" %d", vetor_insert+i);
      scanf(" %d", vetor_select+i);
    }
    
	printf (" \n\n\nTempo leitura valores para algoritimos de ordenacao: %ld \n" ,get_current_time_with_ns() - inicio1 );
       
	// ------------------------------ INICIO QUICKSORT-----------------------------------------------------------------------------
	printf("\n\n----------------- Inicio QuickSort -----------------\n\n");
	
	inicio2 = get_current_time_with_ns();
	
	quick_sort(vetor, 0, tam - 1);
	
	printf("\n\nValores Ordenados por QuickSort: \n \n");
	

	for(i = 0; i< tam; i++){
		printf(" %d", vetor[i]);
	}
	
	printf (" \n\n\nTempo imprimir valores com Algoritimo QuickSort: %ld ",get_current_time_with_ns() - inicio2 );
  	printf (" \nTempo Total com Algoritimo QuickSort: %ld ",get_current_time_with_ns() - inicio1 );
	printf("\n\n----------------- Fim QuickSort -----------------\n");
	inicio2 = 0;
	// ------------------------------ FIM QUICKSORT-----------------------------------------------------------------------------
	
	// ---------------- Inicio InsertionSort -------
	printf("\n\n----------------- Inicio InsertionSort -----------------\n\n");
	
	inicio2 = get_current_time_with_ns();
	
	insertion_sort(vetor_insert);
	
	printf("\n\nValores Ordenados por InsertionSort: \n \n");
	
	for(i = 0; i< tam; i++){
		printf(" %d", vetor[i]);
	}
	
	printf (" \n\n\nTempo imprimir valores com Algoritimo InsertionkSort: %ld ",get_current_time_with_ns() - inicio2 );
  	printf (" \nTempo Total com Algoritimo insertionSort: %ld ",get_current_time_with_ns() - inicio1 );
	
	printf("\n\n----------------- Fim InsertionSort -----------------");
	inicio2 = 0;
	//-----------------------------Fim InsertionSort ------------------
	
	//----------------------- Inicio SelectSort -------------------
	printf("\n\n----------------- Inicio SelectSort -----------------\n\n");
	
	inicio2 = get_current_time_with_ns();
	
	selection_sort(vetor_select, tam);
	
	printf("\n\nValores Ordenados por SelectSort: \n \n");
	
	for(i = 0; i< tam; i++){
		printf(" %d", vetor[i]);
	}
	
	printf (" \n\n\nTempo imprimir valores com Algoritimo SelectSort: %ld ",get_current_time_with_ns() - inicio2 );
  	printf (" \nTempo Total com Algoritimo SelectSort: %ld ",get_current_time_with_ns() - inicio1 );
	
	printf("\n----------------- Fim SelectSort -----------------");
	//----------------------- Fim SelectSort --------------------
	
	return 0;
}

//Algoritimo de ordenação QuickSort
void quick_sort(int *a, int inicio, int fim) {
    int i, j, x, y;
     
    i = inicio;
    j = fim;
    x = a[(inicio + fim) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < fim) {
            i++;
        }
        while(a[j] > x && j > inicio) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > inicio) {
        quick_sort(a, inicio, j);
    }
    if(i < fim) {
        quick_sort(a, i, fim);
    }
}

//Algoritimo de ordenação InsertionSort
void insertion_sort(int *a)
{
	int i, j, tmp;
  
	for(i = 1; i < tam; i++)
	{
		tmp = a[i];
  		for(j = i-1; j >= 0 && tmp < a[j]; j--)
  		{
   			a[j+1] = a[j];
  		}
  		a[j+1] = tmp;
 	}
}

//Algortitimo de ordenação SelectioSort
void selection_sort (int vetor[],int max) {
	int i, j, min, aux;
  
	for (i = 0; i < (max - 1); i++) {
    	// O minimo é o primeiro número não ordenado ainda
    	min = i;
    	for (j = i+1; j < max; j++) {
      	//Caso tenha algum numero menor ele faz a troca do minimo
      		if (vetor[j] < vetor[min]) {
   				min = j;
      		}
    	}
    	// Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los
    	if (i != min) {
    	  	aux = vetor[i];
	      	vetor[i] = vetor[min];
      		vetor[min] = aux;
    	}
  	}
}
