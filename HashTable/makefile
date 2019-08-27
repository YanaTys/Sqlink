CFLAGS	= -pedantic -g -Wall 
aprog	:	hashTable.o hashTableTest.o
	gcc -o aprog hashTable.o hashTableTest.o
hashTable.o	:	hashTable.c hashTable.h
	gcc -c $(CFLAGS) hashTable.c
hashTableTest.o : hashTableTest.c hashTable.h
	gcc -c $(CFLAGS) hashTableTest.c

