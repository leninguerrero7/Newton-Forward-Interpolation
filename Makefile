build:
	make -C CUDA
	make -C MPI
	make -C OpenMP
	make -C C
clean: 
	make clean -C CUDA
	make clean -C MPI
	make clean -C OpenMP
	make clean -C C
