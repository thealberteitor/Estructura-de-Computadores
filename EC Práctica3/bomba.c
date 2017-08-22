//Orden usada para compilar: gcc -m32 bomba.c -o bomba

#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval


char texto[]="ORDENADOR\n";
char password[9];
int  passcode;

void boom(){
	printf("***************\n");
	printf("*** BOOM!!! ***\n");
	printf("***************\n");
	exit(-1);
}

void defused(){
	printf("········································\n");
	printf("··· BOMBA NEUTRALIZADA, ENHORABUENA! ···\n");
	printf("········································\n");
	exit(0);
}

int main(int argc, char argv[]){

#define SIZE 100
#define TLIMITE 60

  int  codigo,i, contador;
  struct timeval tiempo1, tiempo2;	// gettimeofday() secs-usecs
  char cadena[SIZE];

  if(argc==1){

		//Guardamos el valor del tiempo1
		gettimeofday(&tiempo1,NULL);

		printf("Introduzca la contraseña de la bomba: ");
	  fgets(cadena, SIZE, stdin);
	  printf("\n");

		//Guardamos el valor del tiempo2
	  gettimeofday(&tiempo2,NULL);

///////////////////////////////////////////////////////////////

		//Modificación de nuestra BOMBA

		if(strlen(texto)>10){

			for(i=0; i<strlen(texto); i++){
				password[i]=texto[i]+1;
				contador+=80;
			}
			passcode=contador+1000;
		}
		else{
			contador=9999;
			for(i=strlen(texto); i>=0; i--){
				password[i]=texto[i];
				contador-=25;
			}
			passcode=contador;
		}



///////////////////////////////////////////////////////////////
	  if(!strncmp(cadena, password, strlen(password)))
	  	boom();
	  if((tiempo2.tv_sec-tiempo1.tv_sec)>TLIMITE)
	  	boom();

		printf("Introduzca el código secreto de la bomba: ");
	  scanf("%i", &codigo);

		if(codigo!=passcode)
			boom();

		defused();

  }else{
    printf("Número de parámetros incorrecto.");
		printf("\n");
    exit(-1);
  }
}
