#!/bin/bash
#SBATCH --partition=normal
#SBATCH --output=log/newtonforwardinterpolation-%j.log
#SBATCH --error=log/newtonforwardinterpolation-%j.log
#SBATCH --nodes=2
#SBATCH --ntasks=16

module load mpi/openmpi/gcc-5.3.0/Ethernet/4.0.1
make run

#/opt/ohpc/pub/compiler/cuda/gcc-5.3.0/8.0.61/extras/demo_suite/deviceQuery
