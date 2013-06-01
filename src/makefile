

%.o : %.c
	gcc -std=c99 -c $< -o $@

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

gpssim : $(OBJECTS)
	gcc $(OBJECTS) -o gpssim 

clean :
	rm -rf *.o

