dir = exec

all: dir opdr1 clean

dir:
	mkdir -p ${dir}

opdr1: opdr1.cc
	g++ -c opdr1.cc
	g++ -o ${dir}/$@ $@.o

clean:
	rm -f *.o
