INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g
OTRO = -pthread -lX11


all: $(BIN)/main

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/main : $(OBJ)/main.o $(OBJ)/particula.o $(OBJ)/miniwin.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/simulador.o
	$(CXX) -o $(BIN)/main $(OBJ)/main.o $(OBJ)/particula.o $(OBJ)/miniwin.o $(OBJ)/ConjuntoParticulas.o $(OBJ)/simulador.o $(OTRO)

$(OBJ)/main.o : $(INC)/simulador.h $(INC)/particula.h $(INC)/ConjuntoParticulas.h $(INC)/definiciones.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/particula.o : $(INC)/particula.h $(INC)/definiciones.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/particula.o $(SRC)/particula.cpp

$(OBJ)/ConjuntoParticulas.o : $(INC)/ConjuntoParticulas.h $(INC)/particula.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/ConjuntoParticulas.o $(SRC)/ConjuntoParticulas.cpp

$(OBJ)/simulador.o : $(INC)/ConjuntoParticulas.h $(INC)/miniwin.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/simulador.o $(SRC)/simulador.cpp

$(OBJ)/miniwin.o : $(INC)/miniwin.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/miniwin.o $(SRC)/miniwin.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -rf $(BIN)/* doc/html/* doc/latex/*

	



