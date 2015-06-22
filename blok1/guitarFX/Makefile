dir = exec
CFLAGS = -Wall

OBJ = main.o amplifier.o tremolo.o distortion.o

all: dir main clean

dir:
	mkdir -p ${dir}

main: ${OBJ}
	g++ -o ${dir}/$@ ${CFLAGS} ${OBJ}

.cc.o:
	g++ -c $< ${CFLAGS}

clean:
	rm -f *.o
