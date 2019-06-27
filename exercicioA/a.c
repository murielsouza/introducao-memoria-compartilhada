#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(){      	

int *soma, *controle;
int idMemSoma;  /* identificador da memória comum */
int idMemControle;
        	//Cria uma área de memória compartilhada
        	idMemSoma = shmget(100,sizeof(int),IPC_CREAT|0666);
		idMemControle = shmget(200,sizeof(int),IPC_CREAT|0666);
if (idMemSoma == -1) {
                perror("Erro no shmget de soma") ;
                exit(0) ;
        	}
if (idMemControle == -1) {
                perror("Erro no shmget de Controle") ;
                exit(0) ;
        	}

        	// acoplamento do processo a zona de memória 
        	soma = shmat(idMemSoma, 0, 0);
		controle = shmat(idMemControle, 0, 0);

       		*soma = 0;
		*controle = -1;

        	while (*controle != 1){
        	}

		printf("\n\nSoma = %d", *soma); puts(" ");		
 	     
  		//Apaga a área de memória
       	shmctl(idMemSoma, IPC_RMID, NULL);
	shmctl(idMemControle, IPC_RMID, NULL);
}
