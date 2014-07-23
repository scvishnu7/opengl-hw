all: circle
install:
	install circle /usr/bin
circle: circle.o
	gcc -o circle circle.o -lm -lGL -lglut -lGLU
circle.o: circle.c
	gcc -c circle.c
