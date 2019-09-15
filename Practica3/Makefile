INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/main

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/main : $(OBJ)/main.o $(OBJ)/calculo.o
	$(CXX) -o $(BIN)/main $(OBJ)/main.o $(OBJ)/calculo.o

$(OBJ)/main.o : $(INC)/calculo.h $(SRC)/main.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/calculo.o : $(INC)/calculo.h $(SRC)/calculo.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/calculo.o $(SRC)/calculo.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -rf $(BIN)/* doc/html/* doc/latex/*
