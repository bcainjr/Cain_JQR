CFLAGS = -Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=512 -Wfloat-equal -Waggregate-return -Winline

all: driver

driver.o:
	gcc -c $(CFLAGS) driver.c 

header.o:
	gcc -c $(CFLAGS) header.c

driver: driver.o header.o
	gcc driver.o header.o -lpthread -o driver

clean:
	rm -rf *.o
	rm -rf driver

.PHONY: debug profile clean
