# banderas de compilacion
CFLAGS= -Wall -g -Wpedantic -Wextra

all: clean testSet

%.o: %.c
	@echo -n Creating object $@ ...
	@gcc -c $^ -o $@ $(CFLAGS)
	@echo "\t[OK]"

clean:
	@echo -n Cleaning ...
	@rm ./*~ > /dev/null 2>&1 || true
	@rm ./*.o > /dev/null 2>&1 || true
	@echo "\t[OK]"

testSet: testSet.o set.o
	@echo -n Creating executable $@ ...
	@gcc -o $@ $^
	@echo "\t[OK]"

