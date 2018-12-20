CFLAGS = -Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=512 -Wfloat-equal -Waggregate-return -Winline

all: driver

driver: driver.c
	$(CC) $(CFLAGS) driver.c -o $@

clean:
	rm -rf *.o
	rm -rf driver

.PHONY: clean
