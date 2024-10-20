#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);  // Initialiser MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtenir le rang du processus
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtenir le nombre de processus

    printf("Hello world from process %d of %d\n", rank, size);

    MPI_Finalize();  // Finaliser MPI
    return 0;
}
