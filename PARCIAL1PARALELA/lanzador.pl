#!/usr/bin/perl

=begin

Fecha: 26 - 08 - 2022
Autor: Luis Ángel Rodriguez
Tema: Automatizacion de bateria de experimentos
Materia: Parallel and Distributed Computing
Requerimientos: 
	- Vector de benchmarks <ejecutables>
	- Vector de cargas
	- N: repeticiones 
	- La idea es iterar por ejecutables*cargas*repeticiones
=cut


$PATH=`pwd`; # get the current path
chomp($PATH); # remove the last character (\n)
$N =10; # number of processes
system "make clean"; # clean the previous compilation
system "make all"; # compile the program

$machineFile = "$PATH/machine.txt"; # machine file
open(MACHINE, '<', $machineFile) or die $!; # open the file to get the machine name
$machineName="";
while(<MACHINE>){
   $machineName= $_;
}
close($machineFile);
#Vector of executables
chomp($machineName);



#Se crea el vector de ejecutables
@Ejecutables = ("mm_main_int", "mm_main_int_rnd", "mm_main_double", "mm_main_double_rnd");
#Se crea el vector de cargas
@Cargas = ("280", "320","480","580","1280","1380","1480","1580","2280","3280","4280","4800");
#Se crea la variable del numero de repeticiones
$N =30;
#Se crea un fichero

foreach $exes (@Ejecutables){
	
	foreach $carga (@Cargas){
		$File = "soluciones/soluciones-$machinename.csv";
		#print"$File \n";
		open(FILE,">>",$File) or die "Could not open file $File";
		print FILE "Node,Load,Algorithm,Time\n";
		for($i=0;$i<$N;$i++){
			print FILE "$machineName,$carga,$exes,";
			#print("./$exes $carga\n");
			system "$PATH/$exes $carga >> $File";
			print FILE "\n";
		}
		close($File);
	
	}
}

