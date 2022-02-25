CXX=g++
CFLAGS=-Wall --std=c++11

first: Source_1.cpp
	$(CXX) $(CFLAGS) Source_1.cpp -o Source_1

second: Source_2.cpp
	$(CXX) $(CFLAGS) Source_2.cpp -o Source_2

all: first second

clear:
	del *.0 *.gch *.txt

run_first:
	Source_1 13 out.txt

run_second:
	Source_2 out.txt

run: all
	Source_1 13 out.txt
	Source_2 out.txt