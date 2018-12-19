CFLAGS = -Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=512 -Wfloat-equal -Waggregate-return -Winline

all: driver

driver.o: driver.c 
	gcc -c $(CFLAGS) driver.c 

header.o: header.h
	gcc -c $(CFLAGS) header.c

driver: driver.o header.o
	gcc  driver.o header.o -lpthread -o driver

debug: CFLAGS += -g
debug: driver

profile: LDFLAGS += -pg
profile: CFLAGS += -pg
profile: driver

clean:
	rm -rf *.o
	rm -rf driver

.PHONY: debug profile clean
