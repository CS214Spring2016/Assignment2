CC = gcc
CFLAGS = -Wall

all: test0 test1 test2 test3 test4 test5


mymalloc.o: mymalloc.c mymalloc.h
	$(CC) $(CCFLAGS) -c mymalloc.c

test0: test0.o mymalloc.o
	$(CC) $(CCFLAGS) -o test0 test0.o mymalloc.o 
test1: test1.o mymalloc.o
	$(CC) $(CCFLAGS) -o test1 test1.o mymalloc.o
test2: test2.o mymalloc.o
	$(CC) $(CCFLAGS) -o test2 test2.o mymalloc.o
test3: test3.o mymalloc.o
	$(CC) $(CCFLAGS) -o test3 test3.o mymalloc.o
test4: test4.o mymalloc.o
	$(CC) $(CCFLAGS) -o test4 test4.o mymalloc.o
test5: test5.o mymalloc.o
	$(CC) $(CCFLAGS) -o test5 test5.o mymalloc.o

 

malloc: main.o mymalloc.o
	$(CC) $(CCFLAGS)  -o malloc main.o mymalloc.o

test0.o: test0.c mymalloc.h
	$(CC) $(CCFLAGS) -c test0.c
test1.o: test1.c mymalloc.h
	$(CC) $(CCFLAGS) -c test1.c
test2.o: test2.c mymalloc.h
	$(CC) $(CCFLAGS) -c test2.c
test3.o: test3.c mymalloc.h
	$(CC) $(CCFLAGS) -c test3.c
test4.o: test4.c mymalloc.h
	$(CC) $(CCFLAGS) -c test4.c
test5.o: test5.c mymalloc.h
	$(CC) $(CCFLAGS) -c test5.c





transfer:
	cp mymalloc.h mymalloc.c main.c makefile test0.c test1.c test2.c test3.c test4.c test5.c hwextra-testcases.txt readme.pdf asst2
	tar cfz Asst2.tgz asst2
	scp Asst2.tgz kpb81@java.cs.rutgers.edu:~/CS214

clean:
	@rm -f malloc
	@rm -f *.o