# ProyectoFinal
Proyecto de paralelizacion de la interpolacion de lagrange encontrada en: 
https://www.codewithc.com/c-program-for-lagrange-interpolation/

### Instrucciónes de ejecución
Ejecutar make para construir del codigo fuente, el sbatch puede ser ejecutado y automaticamente compilara el codigo, en la carpeta input se encuentrar 2 data sets, el data set big esta dado por:

* y = (1000000\*x - 1000\*x^2 + 200\*x^3 - 10\*x^4 + x^5)^(1/5)

### Tener en cuenta a la hora de correr en guane:
* Cargar el modulo CUDA/8.0.61 ya que el modulo CUDA/9.1 tiene el path mal puesto

