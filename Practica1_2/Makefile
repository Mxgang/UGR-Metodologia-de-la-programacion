INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/mainLed

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/mainLed : $(OBJ)/mainLed.o $(OBJ)/leds.o
	$(CXX) -o $(BIN)/mainLed $(OBJ)/mainLed.o $(OBJ)/leds.o

$(OBJ)/mainLed.o : $(INC)/leds.h $(SRC)/mainLed.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/mainLed.o $(SRC)/mainLed.cpp

$(OBJ)/leds.o : $(INC)/leds.h $(SRC)/leds.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/leds.o $(SRC)/leds.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -rf $(BIN)/* doc/html/* doc/latex/*
