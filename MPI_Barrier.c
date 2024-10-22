#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);  // Initialisation de MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Récupérer le rang du processus
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Récupérer le nombre total de processus

    // Avant la barrière, chaque processus affiche son rang
    printf("Process %d before barrier\n", rank);

    // Synchronisation : tous les processus doivent attendre ici
    MPI_Barrier(MPI_COMM_WORLD);

    // Après la barrière, chaque processus continue
    printf("Process %d after barrier\n", rank);

    MPI_Finalize();  // Finalisation de MPI
    return 0;
}
