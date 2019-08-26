.PHONY: run clean build

build : src/LagrangeInterpolation.c
	gcc src/LagrangeInterpolation.c -o bin/LagrangeInterpolation 

bin/LagrangeInterpolation : src/LagrangeInterpolation.c
	gcc src/LagrangeInterpolation.c -o bin/LagrangeInterpolation 

run: bin/LagrangeInterpolation
	./bin/LagrangeInterpolation < dataset.big

clean : 
	rm bin/*
