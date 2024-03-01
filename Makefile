CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
OBJS=llrec-test.o llrec.o
llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o llrec-test $(OBJS)
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 