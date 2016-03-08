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
	cp sorted-list.h sorted-list.c main.c makefile testplan.txt readme.pdf asst1
	tar cfz Asst1.tgz asst1
	scp Asst1.tgz kpb81@java.cs.rutgers.edu:~/CS214

clean:
	@rm -f malloc
	@rm -f *.o