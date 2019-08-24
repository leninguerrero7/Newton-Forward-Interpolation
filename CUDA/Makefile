build : bin/LagrangeInterpolation

bin/LagrangeInterpolation : src/LagrangeInterpolation.cu
	nvcc src/LagrangeInterpolation.cu -o bin/LagrangeInterpolation 

clean : 
	rm bin/*
