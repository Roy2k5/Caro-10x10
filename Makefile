TARGET = app.exe
GXX = g++
SRC = main.cpp caro.cpp
CXXFLAGS = -Wall -std=c++17
all:
	$(GXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
	./app.exe
clean:
	rm -f $(TARGET)

