CPP = g++
.SUFFIXES: .o .cpp 
.cpp.o :
	$(CPP) -c -g $<

test_target = a.out
test: \
	$(test_target)

$(test_target): big_num_test.o big_num.o
	$(CPP) big_num_test.o big_num.o

