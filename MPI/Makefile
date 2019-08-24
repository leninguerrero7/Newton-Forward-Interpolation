build : bin/LagrangeInterpolation 

bin/LagrangeInterpolation : src/LagrangeInterpolation.c
	mpicc src/LagrangeInterpolation.c -o bin/LagrangeInterpolation 

run : bin/LagrangeInterpolation
	./bin/LagrangeInterpolation < input/dataset.big

clean : 
	rm bin/*
