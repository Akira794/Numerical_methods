#Makefile

#$B%W%m%8%'%/%HL>$H%*%V%8%'%/%H%U%!%$%kL>(B
program = output
objs = \
	dichotomy.o \


#$BDj5A:Q%^%/%m$N:FDj5A(B
CC = gcc
CXX = g++
CFLAGS = -g -Wall

# $B%5%U%#%C%/%9%k!<%kE,MQBP>]$N3HD%;R$NDj5A(B
.SUFFIXES: .c .o

#$B%W%i%$%^%j%?!<%2%C%H(B
$(program): $(objs)
	$(CXX) -o $@ $(objs)

#$B%5%U%#%C%/%9%k!<%k(B
.c.o:
	$(CXX) $(CFLAGS) -c $<

#$B%X%C%@%U%!%$%k$N0MB84X78(B
#func.o: func.h #(ex.)

#$B%U%!%$%k:o=|MQ%?!<%2%C%H(B*.o 
.PHONY: clean
clean:
	$(RM) $(program) $(objs)


