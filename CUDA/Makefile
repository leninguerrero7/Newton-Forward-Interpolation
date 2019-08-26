.PHONY: run clean build

build : src/LagrangeInterpolation.cu
	nvcc src/LagrangeInterpolation.cu -o bin/LagrangeInterpolation 

bin/LagrangeInterpolation : src/LagrangeInterpolation.cu
	nvcc src/LagrangeInterpolation.cu -o bin/LagrangeInterpolation 

run: bin/LagrangeInterpolation
	./bin/LagrangeInterpolation < input/dataset.big

clean : 
	rm bin/*
