cc = g++
CFLAGS = -Wall -o
SRC = main.cpp
EXE = tema2

build:
	$(cc) $(CFLAGS) $(EXE) $(SRC)
clean:
	rm $(EXE)
