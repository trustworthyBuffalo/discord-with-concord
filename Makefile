CC = gcc
CFLAGS = -Wall

name = bot-discord
build = build
bin = bin
src = src
files = main.c tool.c src.c

object_files = ${patsubst %.c, ${build}/%.o, ${files}}

all: ${object_files}
	${CC} ${CFLAGS} $^ -o ${bin}/${name} -pthread -ldiscord -lcurl

${build}/%.o : ${src}/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${build}/*.o main