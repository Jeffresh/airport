CXX = clang++
OBJS = aeroplane.hpp

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o airport

clean:
	-rm -f *.o core *.core
