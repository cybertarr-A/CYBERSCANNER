CXX = g++
CXXFLAGS = -std=c++17 -pthread

SRC = main.cpp cli/cli.cpp scanner/scanner.cpp utils/resolver.cpp

OUT = cyberscanner

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)