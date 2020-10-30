CC = gcc
CFLAGS=-Wall --std=c99 -g
OBJECTS= main.o header.o stat_sorting.o

pokecomp:$(OBJECTS)
	$(CC) $(CFLAGS) -o pokecomp $(OBJECTS)

clean:
	rm pokecomp  main.o header.o stat_sorting.o -f

%.o: %.c 
		$(CC) $(CFLAGS) $< -o $@ -c

