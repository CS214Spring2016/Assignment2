CC = gcc
CFLAGS = -Wall

all: malloc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

malloc: main.o malloc.o
	$(CC) $(CCFLAGS)  -o malloc main.o mymalloc.o

main.o: main.c mymalloc.h
	$(CC) $(CCFLAGS) -c main.c

malloc.o: mymalloc.c mymalloc.h
	$(CC) $(CCFLAGS) -c mymalloc.c 

test0: test0.o malloc.o
	$(CC) $(CCFLAGS) -o test0 test0.o malloc.o
test1: test1.o malloc.o
	$(CC) $(CCFLAGS) -o test1 test1.o malloc.o
test2: test2.o malloc.o
	$(CC) $(CCFLAGS) -o test2 test2.o malloc.o
test3: test3.o malloc.o
	$(CC) $(CCFLAGS) -o test3 test3.o malloc.o
test4: test4.o malloc.o
	$(CC) $(CCFLAGS) -o test4 test4.o malloc.o
test5: test5.o malloc.o
	$(CC) $(CCFLAGS) -o test5 test5.o malloc.o


transfer:
	cp mymalloc.h mymalloc.c main.c makefile asst2
	tar cfz Asst2.tgz asst2
	scp Asst2.tgz kpb81@java.cs.rutgers.edu:~/CS214

clean:
	@rm -f malloc
	@rm -f *.o