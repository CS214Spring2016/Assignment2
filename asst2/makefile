CC = gcc
CFLAGS = -Wall

all: malloc

malloc: main.o malloc.o
	$(CC) $(CCFLAGS)  -o malloc main.o malloc.o

main.o: main.c malloc.h
	$(CC) $(CCFLAGS) -c main.c

malloc.o: malloc.c malloc.h
	$(CC) $(CCFLAGS) -c malloc.c 

transfer:
	cp malloc.h malloc.c main.c makefile asst2
	tar cfz Asst2.tgz asst2
	scp Asst2.tgz kpb81@java.cs.rutgers.edu:~/CS214

clean:
	@rm -f malloc
	@rm -f *.o