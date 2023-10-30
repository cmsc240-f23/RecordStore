main: main.o Genre.o Artist.o GenericAPI.o
	g++ -lpthread main.o Genre.o Artist.o GenericAPI.o -o main

main.o: main.cpp Artist.h Genre.h GenericAPI.h persistence.h
	g++ -Wall -c main.cpp 

Arist.o: Artist.cpp Artist.h
	g++ -Wall -c Artist.cpp 

Genre.o: Genre.cpp Genre.h
	g++ -Wall -c Genre.cpp 

GenericAPI.o: GenericAPI.cpp GenericAPI.h Genre.h Artist.h
	g++ -Wall -c GenericAPI.cpp 

clean:
	rm -f *.o main