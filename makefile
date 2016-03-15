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

test0: test0.c mymalloc.h
	$(CC) $(CCFLAGS) -c test0.c
test1: test1.c mymalloc.h
	$(CC) $(CCFLAGS) -c test1.c
test2: test2.c mymalloc.h
	$(CC) $(CCFLAGS) -c test2.c
test3: test3.c mymalloc.h
	$(CC) $(CCFLAGS) -c test3.c
test4: test4.c mymalloc.h
	$(CC) $(CCFLAGS) -c test4.c
test5: test5.c mymalloc.h
	$(CC) $(CCFLAGS) -c test5.c


transfer:
	cp mymalloc.h mymalloc.c main.c makefile asst2
	tar cfz Asst2.tgz asst2
	scp Asst2.tgz kpb81@java.cs.rutgers.edu:~/CS214

clean:
	@rm -f malloc
	@rm -f *.o