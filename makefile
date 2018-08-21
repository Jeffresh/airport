CXX = clang++
OBJS =  airport.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o airport

clean:
	-rm -f *.o core *.core
