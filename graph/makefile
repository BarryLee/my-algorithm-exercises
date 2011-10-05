CPP = g++
.SUFFIXES: .o .cpp 
.cpp.o :
	$(CPP) -c $<

test_target = a.out
test: \
	$(test_target)

$(test_target): graph_test.o graph.o
	$(CPP) graph_test.o graph.o
