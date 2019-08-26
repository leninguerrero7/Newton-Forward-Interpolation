.PHONY: run clean build

build : src/newtonforwardinterpolation.cu
	nvcc src/newtonforwardinterpolation.cu -o bin/newtonforwardinterpolation 

bin/newtonforwardinterpolation : src/newtonforwardinterpolation.cu
	nvcc src/newtonforwardinterpolation.cu -o bin/newtonforwardinterpolation 

run: bin/newtonforwardinterpolation
	./bin/newtonforwardinterpolation < input/dataset.big

clean : 
	rm bin/*
