# compile and build
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lmariadb -ldiscord -pthread -ldiscord -lcurl

# development environment
BUILD = build
SRC = src
NAME = bot
BIN = bin

# general
CFILES := ${shell find ${SRC} -name '*.c'}
OBJ := ${patsubst ${SRC}/%.c, ${BUILD}/%.o, ${CFILES}}


# == RULES
all : ${OBJ}
	${CC} ${CFLAGS} $^ -o ${BIN}/${NAME} ${LDFLAGS}
	@echo "done :)" 

${BUILD}/%.o : ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	@rm -f ${BUILD}/*/*.o ${BUILD}/main.o ./bot