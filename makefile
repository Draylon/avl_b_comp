all: prog cleanw

prog: main avl b
	gcc -o main main.o avl.o b.o

main: main.c
	gcc -c main.c

avl: avl.h avl.c
	gcc -c avl.c

b: b.h b.c
	gcc -c b.c

clean:
	rm *.o main

cleanw:
	del *.o

delmain:
	del main.exe

run: delmain all
	cls
	main.exe