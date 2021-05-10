SOURCE = TablasDeConversion.c Conversion.c Conversion.h PrintTabla.c PrintTabla.h
BIN = TablasDeConversion.exe
OBJ = TablasDeConversion.o Conversion.o PrintTabla.o
CC = gcc
CFLAGS = -std=c99
RM= rm -f
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)
run: $(BIN)
	$(BIN)

all:$(OBJ)
	$(OBJ)=$(SOURCE)
	$(CC) -c $(SOURCE) -o $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
