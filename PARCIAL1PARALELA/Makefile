#/************************************************
#*Fecha: 10/08/2022
#Autor: Carlos ANdres ROjas Rocha
#*Materia: Computacion paralela y distribuida
#*Topico: Diseño de BenchMark
#*Fase 01: Multiplicacion de matrices clasica
#************************************************/

GCC = gcc
GFLAGS = -ansi -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L
PROGRAMAS = mm_main_int mm_main_int_rnd mm_main_double mm_main_double_rnd
all: $(PROGRAMAS)
mm_main_int:
	$(GCC) $(GFLAGS) -c $@.c
	$(GCC) $(GFLAGS) -c mm_lib.c
	$(GCC) $(GFLAGS) -o $@ $@.o mm_lib.o
	
mm_main_int_rnd:
	$(GCC) $(GFLAGS) -c $@.c
	$(GCC) $(GFLAGS) -c mm_lib.c
	$(GCC) $(GFLAGS) -o $@ $@.o mm_lib.o
	
mm_main_double:
	$(GCC) $(GFLAGS) -c $@.c
	$(GCC) $(GFLAGS) -c mm_lib.c
	$(GCC) $(GFLAGS) -o $@ $@.o mm_lib.o
	
mm_main_double_rnd:
	$(GCC) $(GFLAGS) -c $@.c
	$(GCC) $(GFLAGS) -c mm_lib.c
	$(GCC) $(GFLAGS) -o $@ $@.o mm_lib.o
	
clean:
	$(RM) *.o $(PROGRAMAS)
	
	
	
	
	
	
