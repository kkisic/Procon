CXX=clang++-10
SUPPRESS_WARN=-Wno-keyword-macro -Wno-unused-const-variable -Wno-logical-op-parentheses
CXXFLAGS=-std=c++14 -Wall -Wextra -Wpedantic -g $(SUPPRESS_WARN)

SOURCES=$(wildcard *.cpp)
TARGET=$(SOURCES:.cpp=)

all: $(TARGET)

debug:
	echo $(SOURCES)
	echo $(TARGET)

clean:
	$(RM) $(TARGET)
