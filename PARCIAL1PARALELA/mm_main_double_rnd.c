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

#define RESERVA_MEMORIA (1024*1024*64*3)
	static double MEM_CHUNK[RESERVA_MEMORIA];

	int main(int argc, char **argv){

//Se pide la dimension de la matriz
	int N, SIZE;
	double *matrizA, *matrizB, *matrizC; //Tengo 3 punteros (en este caso vectores) a los que no les he definido tamaño
	N = (double)atoi(argv[1]);

//Se declaran las matrices
	SIZE = N*N;

/*** Se apuntan los punteros a la direccion reservada,
segun el tamaño de la matriz N*N ***/

	matrizA = MEM_CHUNK;
	matrizB = matrizA + SIZE;
	matrizC = matrizB + SIZE;

//se inicializan las matrices
	inicializar_matrices_double_rnd(N,matrizA,matrizB,matrizC);

	tiempo_inicial();

//Se multiplican las matrices: Algoritmo Clasico FilasxColumnas
	producto_matrices_double(N,matrizA,matrizB,matrizC);

	
	imprimir_matriz_double(N,matrizA);
	imprimir_matriz_double(N,matrizB);
	//se imprime el resultado del producto matrizA * matrizB
	imprimir_matriz_double(N,matrizC);

	tiempo_final();

return 0;
}
