all: code

code: main.cpp
	$(CXX) -std=c++17 -O2 -pipe -static -s -o $@ $<

clean:
	rm -f code

.PHONY: all clean

