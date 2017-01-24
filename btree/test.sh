make -f Makefile
valgrind ./testString -v --leak-check=full
