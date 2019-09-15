BIN = bin
INCLUDE = include
OBJ = obj
SRC = src

CXX = g++

all: clean $(BIN)/matrizDinamica

problema3: clean $(BIN)/problema3

matrizDinamica: $(BIN)/matrizDinamica

problema1y2: clean $(BIN)/problema1y2



$(BIN)/matrizDinamica: $(OBJ)/matrizDinamica.o $(OBJ)/myIO.o
	$(CXX) -g -o $(BIN)/matrizDinamica $(OBJ)/matrizDinamica.o $(OBJ)/myIO.o
	
$(OBJ)/matrizDinamica.o: $(SRC)/matrizDinamica.cpp $(INCLUDE)/myIO.h
	$(CXX) -c -o $(OBJ)/matrizDinamica.o $(SRC)/matrizDinamica.cpp -I$(INCLUDE)
	


$(OBJ)/myIO.o: $(SRC)/myIO.cpp $(INCLUDE)/myIO.h
	$(CXX) -c -o $(OBJ)/myIO.o $(SRC)/myIO.cpp -I$(INCLUDE)
	


$(BIN)/problema3: 
	$(CXX) -g -o $(BIN)/problema3 $(SRC)/Punto2D.cpp
	

$(BIN)/problema1y2: 
	$(CXX) -g -o $(BIN)/problema1y2 $(SRC)/problema1y2.cpp



clean: 
	rm -rf $(BIN)/* $(OBJ)/*

cleanobj: 
	rm -rf $(OBJ)/*
	
	



