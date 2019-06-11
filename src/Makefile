CC=gcc
export VERSION = $(shell bash ../scripts/version.sh) # The single, trailing blank is essential
export DATE    = $(shell bash ../scripts/date.sh) #    The single, trailing blank is essential
CFLAGS         = -DVERSION=\"$(VERSION)\" -DDATE=\"$(DATE)\" -O3 -Wall -Wshadow -pedantic -std=gnu99 -g -I../common/ -L../common/ #-pg

SRCFILES  = getSeq.c interface.c
OBJFILES  = getSeq.o interface.o
LIBS      = -lcommon -lm -lbsd
EXECFILE  = getSeq

.PHONY : all
all : $(EXECFILE)
$(EXECFILE) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECFILE) $(OBJFILES) $(LIBS)
interface.o: interface.h
getSeq.c: getSeq.org
	bash ../scripts/org2nw getSeq.org | notangle -RgetSeq.c > getSeq.c

clean:
	rm -f *.o *~
test:
	bash ../scripts/getSeq.sh 
