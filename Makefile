all: sum-nbo

sum-nbo: sum-nbo.o
	g++ -o sum-nbo sum-nbo.o

sum-nbo.o: sum-nbo.cpp
	g++ -c sum-nbo.cpp

clean:
	rm -f sum-nbo
	rm -f *.o
	rm -f *.bin
