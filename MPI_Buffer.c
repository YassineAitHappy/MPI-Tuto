#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Attacher un buffer de communication
        int buffer_size = MPI_BSEND_OVERHEAD + sizeof(int);  // Besoin de MPI_BSEND_OVERHEAD en plus des données
        void *buffer = malloc(buffer_size);
        MPI_Buffer_attach(buffer, buffer_size);

        int message = 42;
        // Envoi bufferisé
        MPI_Bsend(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        printf("Process 0: Message bufferisé envoyé\n");

        // Détacher le buffer une fois terminé
        MPI_Buffer_detach(&buffer, &buffer_size);
        free(buffer);
    } else if (rank == 1) {
        int received_message;
        // Réception normale
        MPI_Recv(&received_message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process 1: Message reçu: %d\n", received_message);
    }

    MPI_Finalize();
    return 0;
}
