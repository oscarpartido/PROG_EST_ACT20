/*autor:Oscar Vivaldi Partido Ramirez    fecha:17/03/2022
programa que las calificaciones de un alumno y sus faltas
para un grupo de 10 alumnos 
	el programa tendra las siguientes opcioens:
		0.salir
		1.Introducir datos del alumno(calificaciones y faltas)
		2.Imprimir
		3.Promedio del grupo
		4.Cuantos aprobaron
		5.Porcentaje de asistencia de cada alumno(32 asistencias)
	*/
	#include<stdio.h>	
	#include<stdlib.h>
	#define MAX 10
	//Prototipos
	int menu();
	float validarFlotantes(float inferior, float superior);
	int validarEnteros(int inferior, int superior);
	void llenar(float x[], int y[]);
	void imprimir(float x[], int y[]);
	void promedio(float x[]);
	void aprobados(float x[], int y[]);
	void asistencias(int y[]);
	
	//principal
	int main(){
		float cal[MAX];
		int faltas[MAX];
		int opcion, centinela=0;
		do{
			opcion=menu();
			switch(opcion){
			case 0: printf("Adios...\n");
						break;
			case 1: llenar(cal,faltas);
						centinela=1;
						break;
			case 2: if(centinela==1){
					imprimir(cal,faltas);
					}
					else{
						printf("primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 3: if(centinela==1){
					promedio(cal);
					}
					else{
						printf("primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break; 
			case 4: if(centinela==1){
					aprobados(cal,faltas);
					}
					else{
						printf("primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 5: if(centinela==1){
					asistencias(faltas);
					}
					else{
						printf("primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			}
		}while(opcion!=0);
		return 0;
	}
	//funciones 
	//funcion que muestra el menu, pide una opcion, la valida y la regresa
	int menu(){
		int opcion;
		printf("-----MENU PRINCIPAL------\n");
		printf("0. salir \n");
		printf("1. introducir datos \n");
		printf("2. Imprimir \n");
		printf("3. Promedio \n");
		printf("4. Cuantos aprobaron \n");
		printf("5. Porcentaje de asistencia \n");
		printf("---------------------------------\n");
		printf("Selecciona una opcion: ");
		opcion=validarEnteros(0,5);
		return opcion;
	}
		
	
	void llenar(float x[],int  y[]){
			printf("introducir datos de los alumnos\n");
			for (int i=0; i<MAX; i++){
				printf("Alumno #%d--------------------------\n",i);
				printf("calificacion:   ");
				x[i]=validarFlotantes(0,10);
				printf("Faltas: ");
				y[i]=validarEnteros(0,32);
			}
		}
	
	float validarFlotantes(float inferior, float superior){
		float valor;
		do {
			scanf("%f",&valor);
			if(valor<inferior || valor>superior){
				printf("Dato invalido!!! debe estar entre (%.2f- %.2f). vuelva a introducirlo:\n",inferior,superior);
			}
		}while(valor<inferior ||valor>superior);
		return valor;
	}
	
	int validarEnteros(int inferior, int superior) {
		int valor;
		do {
			scanf("%d",&valor);
			if(valor<inferior || valor>superior){
				printf("Dato invalido!!! debe estar entre (%d- %d). vuelva a introducirlo:\n",inferior,superior);
			}
		}while(valor<inferior ||valor>superior);
		return valor;
	}
		
	void imprimir(float x[], int y[]){
			printf("DATOS DEL GRUPO\n");
			printf("----------------------------\n");
			printf("No.\tcal\tFaltas\n");
			printf("----------------------------\n");
			for (int i=0; i<MAX; i++){
				printf("%d\t%.1f\t%d \n",i,x[i],y[i]);
			}
			printf("----------------------------\n");
		}
		
	void promedio(float x[]) {
		float suma=0,  prom;
		for (int i=0; i<MAX; i++){
			suma=suma+x[i];
		}
		prom=suma/MAX;
		printf("PROMEDIO DEL GRUPO\n");
		printf("----------------------------\n");
		printf("El promedio es %.1f\n",prom);
		printf("----------------------------\n");
	}
		
	void aprobados(float x[], int y[]) {
		int apro=0;
		float porcentaje;
		for(int i=0; i<MAX; i++){
			porcentaje=y[i]*100/32;
			if(x[i]>=7 && porcentaje<=20) {
				apro++;
			}
		}
		printf("TOTAL DE APROBADOS DEL GRUPO\n");
		printf("----------------------------\n");
		printf("Aprobados:  %.d\n",apro);
		printf("----------------------------\n");
	}
	
	void asistencias(int y[]) {
		int porcentaje;
		printf("%% DE ASISTENCIAS DEL GRUPO \n");
		printf("----------------------------\n");
		printf("No.\tAsistencias\n");
		printf("----------------------------\n");
		for(int i=0; i<MAX; i++) {
			porcentaje=100-(y[i]*100/32);
			printf("%d \t %d%% \n",i, porcentaje);
		}
		printf("----------------------------\n");
	}
	

