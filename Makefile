build:
	make build -C CUDA
	make build -C MPI
	make build -C OpenMP
	make build -C C
clean: 
	make clean -C CUDA
	make clean -C MPI
	make clean -C OpenMP
	make clean -C C
