OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
program.exe: Areadeespera.o Cluster.o Proceso.o Procesador.o program.o
	g++ -o program.exe Areadeespera.o Cluster.o Proceso.o Procesador.o program.o
Areadeespera.o: Areadeespera.cc Areadeespera.hh
	g++ -c Areadeespera.cc -I / $(OPCIONS) 
Cluster.o: Cluster.cc Cluster.hh
	g++ -c Cluster.cc -I / $(OPCIONS)
Procesador.o: Procesador.cc Procesador.hh
	g++ -c Procesador.cc -I / $(OPCIONS)
Proceso.o: Proceso.cc Proceso.hh
	g++ -c Proceso.cc -I / $(OPCIONS)
program.o: program.cc Proceso.hh Procesador.hh Areadeespera.hh Cluster.hh
	g++ -c program.cc -I / $(OPCIONS)
practica.tar: program.exe
	tar -cvf practica.tar program.exe *.cc *.hh html.zip Makefile
clean:
	rm -f *.o
	rm -f *.exe