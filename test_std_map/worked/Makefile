CXX=g++
CFLAGS=-Wall --std=c++11

first: Source.cpp
	$(CXX) $(CFLAGS) Source.cpp -o Source

all: first

clear:
	del *.0 *.gch *.txt

run: all
	Source
	python3 test_dict_py.py
	python3 plot_py.py