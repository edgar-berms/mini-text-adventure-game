all : main.exe

main.exe : main.o entite.o heros.o ennemi.o carte.o utile.o
	clang++ main.o entite.o heros.o ennemi.o carte.o utile.o -o main.exe
	./main.exe

main.o : main.cpp entite.hpp heros.hpp ennemi.hpp carte.hpp utile.hpp
	clang++ -c main.cpp

entite.o : entite.hpp
	clang++ -c entite.cpp

heros.o : heros.hpp entite.hpp
	clang++ -c heros.cpp

ennemi.o : ennemi.hpp entite.hpp 
	clang++ -c ennemi.cpp

carte.o : carte.hpp
	clang++ -c carte.cpp

utile.o : utile.hpp	
	clang++ -c utile.cpp

clear : 
	rm -f *.o
	rm -f main.exe