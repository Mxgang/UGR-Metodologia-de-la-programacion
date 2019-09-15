INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/compra

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/compra : $(OBJ)/compra.o $(OBJ)/fruteria.o
	$(CXX) -o $(BIN)/compra $(OBJ)/compra.o $(OBJ)/fruteria.o

$(OBJ)/compra.o : $(INC)/fruteria.h $(SRC)/compra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/compra.o $(SRC)/compra.cpp

$(OBJ)/fruteria.o : $(INC)/fruteria.h $(SRC)/fruteria.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/fruteria.o $(SRC)/fruteria.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -rf $(BIN)/* doc/html/* doc/latex/*
