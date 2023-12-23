# the compiler
CXX = g++

# compiler flags:
#  -g     adds debugging information to the executable file
#  -Wall  turns on most, but not all, compiler warnings
CXXFLAGS  = -g -Wall -std=c++98

# the build target executable:
TARGET = fixedpoint

all: $(TARGET)

$(TARGET): main.o Fixed.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Fixed.o

main.o: main.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Fixed.o: Fixed.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c Fixed.cpp

clean:
	$(RM) $(TARGET) *.o
