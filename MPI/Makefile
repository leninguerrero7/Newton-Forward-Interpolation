.PHONY: run clean build

build : src/newtonforwardinterpolation.c
	mpicc src/newtonforwardinterpolation.c -o bin/newtonforwardinterpolation 	

bin/newtonforwardinterpolation : src/newtonforwardinterpolation.c
	mpicc src/newtonforwardinterpolation.c -o bin/newtonforwardinterpolation 

run : bin/newtonforwardinterpolation
	./bin/newtonforwardinterpolation < input/dataset.big

clean : 
	rm bin/*
