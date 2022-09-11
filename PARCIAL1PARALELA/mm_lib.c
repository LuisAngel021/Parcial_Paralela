/************************************************
*Fecha: 10/08/2022
*Autor: Luis Angel Rodriguez
*Materia: Computacion paralela y distribuida
*Topico: Diseño de BenchMark
*Fase 01: Multiplicacion de matrices clasica
************************************************/

#include "mm_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <unistd.h> 

struct timespec punto_inicio, punto_final;

void tiempo_inicial(){
	clock_gettime(CLOCK_MONOTONIC, &punto_inicio);
}

void tiempo_final(){
	double suma_tiempo;
	clock_gettime(CLOCK_MONOTONIC, &punto_final);
	//sumar segundos y pasarlos a nanosegundos
	suma_tiempo = (punto_final.tv_sec - punto_inicio.tv_sec)*1e9;
	//sumar nanosegundos
	suma_tiempo = (suma_tiempo + punto_final.tv_nsec - punto_inicio.tv_nsec)*1e-9;

	printf("%f \n", suma_tiempo);
}

/***********************Benchmark 02 DOUBLE y Aleatorios*******************/
//Función generadora de numeros aleatorios
//Numeros entre 0 y 9 <Como prueba>
double funcionRandom(){
	int min=0, max=9;
	static int flag = -1;
	if((flag = (flag<0))){
		//Se genera la semilla <al usar la funcuón
		srand(time(NULL)+getpid());
	}
	if(min>max)
		return errno = EDOM, NAN;
	return min + (int) rand()/((int)RAND_MAX/(max-min));

}

//Función de numeros aleatorios
//Numeros entre 0 y 9 en double
double funcionRandom_double(){
	double min=0, max=9;
	static int flag = -1;
	if((flag = (flag<0))){
		//Se genera la semilla <al usar la funcuón
		srand(time(NULL)+getpid());
	}
	if(min>max)
		return errno = EDOM, NAN;
	return min + (int) rand()/((int)RAND_MAX/(max-min));

}

/***********************Benchmark 02 DOUBLE*******************/
void inicializar_matrices_double(int n, double *a, double *b, double *c){
	int i,j;
	//Se inicializa las matrices
	for ( i=0; i<n; i++){
		for ( j=0; j<n; j++){
			a[i+j*n]=3.7*(i+j);
			b[i+j*n]=2.9*j +3.1*i;
			c[i+j*n]=0;
		}
	}
}

/***********************Benchmark 02 DOUBLE RANDOM*******************/
void inicializar_matrices_double_rnd(int n, double *a, double *b, double *c){
	int i,j;
	//Se inicializa las matrices
	for ( i=0; i<n; i++){
		for ( j=0; j<n; j++){
			a[i+j*n]=funcionRandom_double();
			b[i+j*n]=funcionRandom_double();
			c[i+j*n]=0;
		}
	}
}

/***********************Benchmark 02 DOUBLE mostrar*******************/
//Función imprimir matriz double
void imprimir_matriz_double(int n,double *m){

	//printf("\nMatriz A: \n");
	//Se imprime la matriz A
	int i,j;
	if(n<5)
	{
	for ( i=0; i<n; i++){
		for ( j=0; j<n; j++){
			printf(" %f", m[i+j*n]);
		}
		printf("\n");
	}
	printf("\n");
	}
}

/***********************Benchmark 01 INT RANDOM*******************/
void inicializar_matrices_int_rnd(int n, int *a, int *b, int *c){
	int i,j;

	//Se inicializa las matrices
	for ( i=0; i<n; i++){
		for ( j=0; j<n; j++){
			a[i+j*n]= funcionRandom();
			b[i+j*n]= funcionRandom();
			c[i+j*n]= 0;
		}
	}
}



/***********************Benchmark 01 INT*******************/
//Funcion inicializar matrices
void inicializar_matrices_int(int n, int *a, int *b, int *c){
	int i,j;
	//Se inicializa las matrices
	for ( i=0; i<n; i++){
		for ( j=0; j<n; j++){
			a[i+j*n]=3*(i+j);
			b[i+j*n]=2*j +3*i;
			c[i+j*n]=0;
		}
	}
}
/***********************Benchmark 01 Imprimir INT*******************/
//Función para imprimir matrices
void imprimir_matriz_int(int n,int *m){

	//printf("\nMatriz A: \n");
	//Se imprime la matriz A
	int i,j;
	if(n<5)
	{
	for ( i=0; i<n; i++){
		for ( j=0; j<n; j++){
			printf(" %d", m[i+j*n]);
		}
		printf("\n");
	}
	printf("\n");
	}
}

void producto_matrices_int(int n, int *a, int *b, int *c){

	int i,j,k,suma_parcial;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//Auxiliares
			suma_parcial=0;
			int *pA, *pB;
			pA = (a + i*n);
			pB = (b +j);
		for(k=0;k<n;k++, pA++, pB+=n){
			suma_parcial += (*pA * *pB);
		}
		c[j+i*n] = suma_parcial;
		}
	}
}

//Producto matrices double
void producto_matrices_double(int n, double *a, double *b, double *c){

	int i,j,k;
	double suma_parcial;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//Auxiliares
			suma_parcial=0;
			double *pA, *pB;
			pA = (a + i*n);
			pB = (b +j);
		for(k=0;k<n;k++, pA++, pB+=n){
			suma_parcial += (*pA * *pB);
		}
		c[j+i*n] = suma_parcial;
		}
	}
}


