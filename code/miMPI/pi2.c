#include <stdio.h>
#include <time.h>
#include <mpi.h>

static int long numSteps = 1000000000;

int main(int argc, char **argv) {

  double pi   = 0;
  double stepSize = 1.0/(double) numSteps;

  int procID, numP;
  MPI_Status status;
  MPI_Init( &argc, &argv);
  MPI_Comm_size( MPI_COMM_WORLD, &numP);
  MPI_Comm_rank( MPI_COMM_WORLD, &procID);

  for (int i=0; i<numSteps; i++) {
    double x = (i+0.5)*stepSize;
    pi += 4./(1.+x*x);
  }
  
  pi *= stepSize;
  
  printf("PI = %16.14f\n",pi);
  MPI_Finalize();
  return 0;
}
