#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int long numSteps = 1000000000;

int main(int argc, char **argv){
  double x = 0 ;
  double pi = 0 ;
  double step = 1.0/(double) numSteps;

#pragma omp parallel reduction(+:pi)
  { 
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    
    for ( int i = tid ; i < numSteps ; i += numT){
	double x = (i + 0.5 ) * step ;
	pi += 4./(1. + x*x);
    
    }
  }
    pi += step;

   

    printf("Ahmet Anil Dindar %f burada super\n",pi);
  return 0;


}
