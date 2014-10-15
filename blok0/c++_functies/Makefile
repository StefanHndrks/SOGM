dir = exec

all: dir opdr1 opdr2 opdr3 opdr4 clean

dir:
	mkdir -p ${dir}

opdr1: opdr1.cc
	g++ -c opdr1.cc
	g++ -o ${dir}/$@ $@.o

opdr2: opdr2.cc
	g++ -c opdr2.cc
	g++ -o ${dir}/$@ $@.o

opdr3: opdr3.cc
	g++ -c opdr3.cc
	g++ -o ${dir}/$@ $@.o

opdr4: opdr4.cc
	g++ -c opdr4.cc
	g++ -o ${dir}/$@ $@.o

clean:
	rm -f *.o
