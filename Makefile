CC := gcc
OS := MAC # Cambiar por uno de los siguientes valores MAC / LINUX / WINDOWS  / CYGWIN
CFLAGS := -D$(OS) -Ilibrerias/
OBJETOS := sudoku.o librerias/gnrlslib.o librerias/sudokulib.o librerias/printlib.o librerias/mistrlib.o
FUENTES := sudoku.c librerias/gnrlslib.c librerias/sudokulib.c librerias/printlib.c librerias/mistrlib.c

.PHONY: clean

sudoku: $(OBJETOS)
	$(CC) $(CFLAGS) $(OBJETOS) -o sudoku

sudoku.o: sudoku.c
	$(CC) $(CFLAGS) -c sudoku.c

gnrlslib.o: gnrlslib.c
	$(CC) $(CFLAGS) -c gnrlslib.c

sudokulib.o: sudokulib.c
	$(CC) $(CFLAGS) -c sudokulib.c

printlib.o: printlib.c
	$(CC) $(CFLAGS) -c printlib.c

mistrlib.o: mistrlib.c
	$(CC) $(CFLAGS) -c mistrlib.c

clean:
	rm -f *.o librerias/*.o
