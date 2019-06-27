#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(){      	
 	int *num, aux;
	int id_mem;  /* identificador da memória comum */

     //Cria uma área de memória compartilhada, se ela não existir
     if ((id_mem=shmget(200, 5*sizeof(int), IPC_CREAT|IPC_EXCL|0666)) ==-1) {
          perror("Erro no shmget") ;
          exit(0) ;
     }
     // acoplamento do processo a zona de memória 
     num = shmat(id_mem, 0, 0);
     int cont = 0; 
     while (cont<=16){
	printf("\nDigite um número:");
     	scanf("%d", &aux);
     	*(num+cont) = aux;
	cont = cont + 4;	
     }
} 
