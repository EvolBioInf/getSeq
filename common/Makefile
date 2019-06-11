CF  = -O3 -Wall -Wshadow -pedantic -std=gnu99 -g
LIBS = -libsd
CC  = gcc $(CF) $(LIBS)
OBJ = eprintf.o
libcommon.a: $(OBJ)
	ar -cvq $@ $^ 
	ranlib $@
.PHONY: clean
clean:
	rm -f *.o libcommon.a
