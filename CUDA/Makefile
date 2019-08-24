build : bin/LagrangeInterpolation

bin/LagrangeInterpolation : src/LagrangeInterpolation.cu
	nvcc src/LagrangeInterpolation.cu -o bin/LagrangeInterpolation 

.PHONY: run clean

run: bin/LagrangeInterpolation
	./bin/LagrangeInterpolation < input/dataset.big

clean : 
	rm bin/*
