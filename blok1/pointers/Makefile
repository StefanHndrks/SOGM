dir = exec
CFLAGS = -Wall

OBJ1 = pointers1
OBJ2 = pointers2

all: dir ${OBJ1} ${OBJ2} clean

dir:
	mkdir -p ${dir}

${OBJ1}: ${OBJ1}.o
	g++ -o ${dir}/$@ ${CFLAGS} ${OBJ1}.o

${OBJ2}: ${OBJ2}.o
	g++ -o ${dir}/$@ ${CFLAGS} ${OBJ2}.o

.cc.o:
	g++ -c $< ${CFLAGS}

clean:
	rm -f *.o
