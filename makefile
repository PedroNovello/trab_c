all: 
	gcc -o exe registers.c hardware.c

clear: 
	rm -rf *.o 