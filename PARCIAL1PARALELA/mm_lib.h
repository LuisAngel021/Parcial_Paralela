/************************************************
*Fecha: 10/08/2022
*Autor: Luis Angel Rodriguez
*Materia: Computacion paralela y distribuida
*Topico: Diseño de BenchMark
*Fase 01: Multiplicacion de matrices clasica
************************************************/
#ifndef MM_LIB_INCLUDED
#define MM_LIB_INCLUDED


void tiempo_inicial();
void tiempo_final();

/** BENCMARK 02: MM clasico con enteros y aleatorios****/
void inicializar_matrices_int_rnd(int n, int *a, int *b, int *c);
/** BENCMARK 03: MM clasico con edouble****/
void inicializar_matrices_double(int n, double *a, double *b, double *c);
/** BENCMARK 04: MM clasico con doubles aleatorios****/
void inicializar_matrices_double_rnd(int n, double *a, double *b, double *c);
/**Benchmark 01: NN Clásico con enteros**/
void inicializar_matrices_int(int n, int *a, int *b, int *c);
void imprimir_matriz_int(int N, int *m);
void imprimir_matriz_double(int n,double *m);
void producto_matrices_int(int n, int *a, int *b, int *c);
void producto_matrices_double(int n, double *a, double *b, double *c);

#endif
