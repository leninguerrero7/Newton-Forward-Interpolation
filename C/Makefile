.PHONY: run clean build

build : src/newtonforwardinterpolation.c
	gcc src/newtonforwardinterpolation.c -o bin/newtonforwardinterpolation 

bin/newtonforwardinterpolation : src/newtonforwardinterpolation.c
	gcc src/newtonforwardinterpolation.c -o bin/newtonforwardinterpolation 

run: bin/newtonforwardinterpolation
	./bin/newtonforwardinterpolation < input/dataset.small

clean : 
	rm bin/*
