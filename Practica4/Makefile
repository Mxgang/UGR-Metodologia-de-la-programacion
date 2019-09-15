BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include
CXX = g++

all: clean ejercicio5 ejercicio7 ejercicio10 ejercicio14 ejercicio15 ejercicio16 

ejercicio5: $(BIN)/ejercicio5

ejercicio10: $(BIN)/ejercicio10

ejercicio14: $(BIN)/ejercicio14

ejercicio15: $(BIN)/ejercicio15

ejercicio16: $(BIN)/ejercicio16

ejercicio7: $(BIN)/ejercicio7



$(BIN)/ejercicio5: $(OBJ)/ejercicio5.o $(OBJ)/myIO.o
	$(CXX) -g -o $(BIN)/ejercicio5 $(OBJ)/ejercicio5.o $(OBJ)/myIO.o

$(OBJ)/ejercicio5.o: $(SRC)/ejercicio5.cpp $(INCLUDE)/myIO.h
	$(CXX) -g -c -o $(OBJ)/ejercicio5.o $(SRC)/ejercicio5.cpp -I$(INCLUDE)



$(BIN)/ejercicio7:
	$(CXX) -g -o $(BIN)/ejercicio7 $(SRC)/ejercicio7.cpp
	
	
	
$(BIN)/ejercicio15:
	$(CXX) -g -o $(BIN)/ejercicio15 $(SRC)/ejercicio15.cpp
	


$(BIN)/ejercicio10:
	$(CXX) -g -o $(BIN)/ejercicio10 $(SRC)/ejercicio10.cpp
	
$(BIN)/ejercicio14:
	$(CXX) -g -o $(BIN)/ejercicio14 $(SRC)/ejercicio14.cpp
	



$(BIN)/ejercicio16: $(OBJ)/ejercicio16.o $(OBJ)/myIO.o
	$(CXX) -g -o $(BIN)/ejercicio16 $(OBJ)/ejercicio16.o $(OBJ)/myIO.o

$(OBJ)/ejercicio16.o: $(SRC)/ejercicio16.cpp $(INCLUDE)/myIO.h
	$(CXX) -g -c -o $(OBJ)/ejercicio16.o $(SRC)/ejercicio16.cpp -I$(INCLUDE)



$(OBJ)/myIO.o: $(SRC)/myIO.cpp $(INCLUDE)/myIO.h
	$(CXX) -c -o $(OBJ)/myIO.o $(SRC)/myIO.cpp -I$(INCLUDE)

clean: 
	rm -rf $(BIN)/* $(OBJ)/*

cleanobj: 
	rm -rf $(OBJ)/*
