SOURCE = TablasDeConversion.c Conversion.c
BIN = TablasDeConversion.exe
OBJ = TablasDeConversion.o Conversion.o
CC = gcc
CFLAGS = -std=c99
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)
run: $(BIN)
	$(BIN)

all:$(OBJ)
	$(OBJ)=$(SOURCE)
	$(CC) -c $(SOURCE) -o $(OBJ) $(CFLAGS)
