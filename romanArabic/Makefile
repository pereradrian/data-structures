CFLAGS= -Wall -g -Wpedantic -Wextra

all: clean arabic2latin

%.o: %.c
	@echo -n Creating object $@ ...
	@gcc -c $^ -o $@ $(CFLAGS)
	@echo "\t[OK]"

clean:
	@echo -n Cleaning ...
	@rm ./*~ > /dev/null 2>&1 || true
	@rm ./*.o > /dev/null 2>&1 || true
	@rm ./testSet > /dev/null 2>&1 || true
	@echo "\t[OK]"

arabic2latin: arabic2latin.o
	@echo -n Creating executable $@ ...
	@gcc -o $@ $^
	@echo "\t[OK]"

