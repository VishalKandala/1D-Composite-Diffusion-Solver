CC=g++
CFLAGS= -g -Wall 
#DEPS = 
OBJ = main.o init.o solver.o 

%.o: %.cpp #$(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

1dheat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	$(RM) *.o
all: 1dheat clean

