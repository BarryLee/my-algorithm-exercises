CPP = g++
.SUFFIXES: .o .cpp 
.cpp.o :
	$(CPP) -c -g $<

test_target = a.out
test: \
	$(test_target)

$(test_target): test_heap.o heap.o
	$(CPP) test_heap.o heap.o

