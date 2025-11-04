CC = gcc
CFLAGS = -Wall

name = bot-discord
build = bin
src = src
object_file = main.o tool.o src.o


all: ${object_file}
	${CC} ${CFLAGS} $^ -o ${build}/${name} -pthread -ldiscord -lcurl

	@echo "cleanning ..."
	@${MAKE} clean 1> /dev/null

%.o : ${src}/%.c
	${CC} ${CFLAGS} -c $<

clean:
	@rm -f *.o main