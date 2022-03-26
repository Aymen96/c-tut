#include <mpi.h>
#include <string.h>
#include <stdio.h>

// THIS PROGRAM NEVER TERMINATES BECAUSE OF THE BLOCKING PROPERTY OF MPI_RECV
int main(int argc, char** argv) {
    int myrank;
    char msg[20];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    strcpy(msg, "Hello Student!");
    if(myrank == 0){
        MPI_Recv(msg, 20, MPI_CHAR, 1, 42, MPI_COMM_WORLD, &status);
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 1, 42, MPI_COMM_WORLD);
        printf("Received: %s\n", msg);
    } else {
        MPI_Recv(msg, 20, MPI_CHAR, 0, 42, MPI_COMM_WORLD, &status);
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 0, 42, MPI_COMM_WORLD);
        printf("Received: %s\n", msg);
    }

    MPI_Finalize();
    
    return 0;
}