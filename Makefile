all: jsoncreator.cpp
	g++ -std=c++11 -o jsoncreator jsoncreator.cpp

.PHONY: clean
clean:
	rm jsoncreator

.PHONY: test
test:
	./jsoncreator
