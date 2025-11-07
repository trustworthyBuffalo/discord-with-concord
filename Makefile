# compile and build
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lmariadb -ldiscord -pthread -ldiscord -lcurl
CCDEBUGFLAG =  -g

# development environment
BUILD = build
SRC = src
NAME = bot
DEBUG_NAME = botg
BIN = bin
DEBUG = debug

# general
CFILES := ${shell find ${SRC} -name '*.c'}
OBJ := ${patsubst ${SRC}/%.c, ${BUILD}/%.o, ${CFILES}}
DEBUGOBJ := ${patsubst ${SRC}/%.c, ${DEBUG}/%.o, ${CFILES}} 


# == RULES
all : ${OBJ}
	${CC} ${CFLAGS} $^ -o ${BIN}/${NAME} ${LDFLAGS}
	@echo "done :)" 

debug : ${DEBUGOBJ}
	${CC} ${CFLAGS} ${CCDEBUGFLAG} $^ -o ${BIN}/${DEBUG_NAME} ${LDFLAGS}
	@echo "with debug done :)" 

${DEBUG}/%.o : ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}/%.o : ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	@rm -fR ${BUILD}/*.o ./bot ${BIN}/bot