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

del_main:
	del main.exe

run: del_main all
	cls
	main.exe