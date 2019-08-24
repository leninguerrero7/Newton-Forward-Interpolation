#!/bin/bash
#SBATCH --partition=normal
#SBATCH --output=log/LagrangeInterpolation-%j.log
#SBATCH --error=log/LagrangeInterpolation-%j.log
#SBATCH --nodes=1
#SBATCH --ntasks=8

make run

#/opt/ohpc/pub/compiler/cuda/gcc-5.3.0/8.0.61/extras/demo_suite/deviceQuery
