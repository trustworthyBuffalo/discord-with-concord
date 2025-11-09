# compile and build
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lmariadb -ldiscord -pthread -ldiscord -lcurl
CCDEBUGFLAG =  -g -O0

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


# == build
all : ${OBJ}
	${CC} ${CFLAGS} $^ -o ${BIN}/${NAME} ${LDFLAGS}
	@echo "done :)" 


${BUILD}/%.o : ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@

# === debug build

debug : ${DEBUGOBJ}
	${CC} ${CFLAGS} ${CCDEBUGFLAG} $^ -o ${BIN}/${DEBUG_NAME} ${LDFLAGS}
	@echo "with debug done :)" 

${DEBUG}/%.o : ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@

# == clean rule

clean :
	@rm -fR ${BUILD}/*.o ./bot ${BIN}/bot