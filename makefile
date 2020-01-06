braille: main.o braille.o
	g++ -Wall -g main.o braille.o -o braille

main.o: main.cpp braille.h
	g++ -Wall -c main.cpp

braille.o: braille.cpp braille.h
	g++ -Wall -c braille.cpp

clean:
	rm -rf braille *.o