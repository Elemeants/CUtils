CC = gcc
CC_FLAGS = -Os -Wall

BIN_FOLDER = ./bin

configure:
	@mkdir ${BIN_FOLDER}

clean:
ifeq ($(OS),Windows_NT)
	@del ${BIN_FOLDER}/*.exe
else
	@rm -f ${BIN_FOLDER}/*
endif

all: float2hex modbus_crc16_calc

float2hex:
	@echo Compiling Float2Hex...
	
ifeq ($(OS),Windows_NT)
	@${CC} ${CC_FLAGS} $@.c -o ${BIN_FOLDER}/$@.exe
else
	@${CC} ${CC_FLAGS} $@.c -o ${BIN_FOLDER}/$@
endif

modbus_crc16_calc:
	@echo Compiling Modbus CRC16 Calculation...
	
ifeq ($(OS),Windows_NT)
	@${CC} ${CC_FLAGS} $@.c -o ${BIN_FOLDER}/$@.exe
else
	@${CC} ${CC_FLAGS} $@.c -o ${BIN_FOLDER}/$@
endif
