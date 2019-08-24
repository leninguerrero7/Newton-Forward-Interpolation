build : bin/LagrangeInterpolation

bin/LagrangeInterpolation : src/LagrangeInterpolation.c
	gcc -fopenmp src/LagrangeInterpolation.c -o bin/LagrangeInterpolation 

run :
	./bin/LagrangeInterpolation < input/dataset.big

clean : 
	rm bin/*
