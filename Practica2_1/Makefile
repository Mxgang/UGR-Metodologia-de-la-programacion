INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/mainDescifra

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/mainDescifra : $(OBJ)/mainDescifra.o $(OBJ)/descifra.o
	$(CXX) -o $(BIN)/mainDescifra $(OBJ)/mainDescifra.o $(OBJ)/descifra.o

$(OBJ)/mainDescifra.o : $(INC)/descifra.h $(SRC)/mainDescifra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/mainDescifra.o $(SRC)/mainDescifra.cpp

$(OBJ)/descifra.o : $(INC)/descifra.h $(SRC)/descifra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/descifra.o $(SRC)/descifra.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -rf $(BIN)/* doc/html/* doc/latex/*
