CC = gcc
CFLAGS = -Wall

all: malloc

malloc: main.o malloc.o
	$(CC) $(CCFLAGS)  -o malloc main.o mymalloc.o

main.o: main.c mymalloc.h
	$(CC) $(CCFLAGS) -c main.c

malloc.o: mymalloc.c mymalloc.h
	$(CC) $(CCFLAGS) -c mymalloc.c 

transfer:
	cp mymalloc.h mymalloc.c main.c makefile asst2
	tar cfz Asst2.tgz asst2
	scp Asst2.tgz kpb81@java.cs.rutgers.edu:~/CS214

clean:
	@rm -f malloc
	@rm -f *.o