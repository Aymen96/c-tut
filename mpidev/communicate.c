#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main (int argc, char** argv){
    char msg[20];
    int myrank, tag=42;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if(myrank == 0) {
        strcpy(msg, "Hello student!");
        MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
    } else if(myrank == 1) {
        MPI_Recv(msg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
        printf("received: %s \n", msg);
    }
    MPI_Finalize();

    return 0;
}