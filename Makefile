CC = gcc
CFLAGS = -Wall

name = mybot
build = build
src = src
object_file = main.o tool.o src.o


all: ${object_file}
	${CC} ${CFLAGS} $^ -o ${build}/${name} -pthread -ldiscord -lcurl
	${MAKE clean}

%.o : ${src}/%.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -f *.o main