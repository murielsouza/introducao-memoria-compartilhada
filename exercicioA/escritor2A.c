#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(){      	
 	int *soma, *controle, num;
	int idMemSoma, idMemControle;  /* identificador da memória comum */

     //Se liga a uma área de memória compartilhada existente
     if ((idMemSoma = shmget(100, sizeof(int), 0666)) == -1) {
          perror("Erro no shmget de soma") ;
          exit(0) ;
     }
	if ((idMemControle = shmget(200, sizeof(int), 0666)) == -1) {
          perror("Erro no shmget de controle") ;
          exit(0) ;
     }
     // acoplamento do processo a zona de memória 
     soma = shmat(idMemSoma, 0, 0);
     controle = shmat(idMemControle, 0, 0);
     
     printf("\nDigite um número:");
     scanf("%d", &num);
     *soma = *soma + num;
     *controle = *controle + 1;	
	
}
