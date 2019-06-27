#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(){      	
 	int *num;
	int id_mem;  /* identificador da memória comum */

     //Se liga a uma área de memória compartilhada existente
     if ((id_mem = shmget(200, sizeof(int), 0666)) == -1) {
          perror("Erro no shmget") ;
          exit(0) ;
     }
     // acoplamento do processo a zona de memória 
     num = (int *)shmat(id_mem, 0, 0);
	int cont = 0;
	while (cont <=16){
		if (*(num + cont) != 0){
			printf("\nNumero: %d\n\n" , *(num + cont));
		}
		cont = cont + 4;
        }

	shmctl(id_mem, IPC_RMID, NULL);
}
