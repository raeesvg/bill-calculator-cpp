CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRC = src/Question-1.cpp
BIN = bin/billcalc

all: $(BIN)

$(BIN): $(SRC)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf bin
