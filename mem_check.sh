!#/bin/sh

# you must compile the program beforehand with debug symbols 

valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./prog
