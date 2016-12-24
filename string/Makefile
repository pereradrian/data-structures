CFLAGS= -Wall -g -Wpedantic -Wextra

all: clean testString

%.o: %.c
	@echo -n Creating object $@ ...
	@gcc -c $^ -o $@ $(CFLAGS)
	@echo "\t[OK]"

clean:
	@echo -n Cleaning ...
	@rm ./*~ > /dev/null 2>&1 || true
	@rm ./*.o > /dev/null 2>&1 || true
	@rm ./testString > /dev/null 2>&1 || true
	@echo "\t[OK]"

testString: testString.o string.o
	@echo -n Creating executable $@ ...
	@gcc -o $@ $^
	@echo "\t[OK]"

