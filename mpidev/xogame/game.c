#include "stdio.h"
#include "string.h"
#include "mpi.h"
#include <stdlib.h>
#include <time.h>

/*
* Initializes the board with blanks to better represent that the board is empty!
*/
int init_board(char board[][3], char* blank) {
    int i,j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = *blank; 
        }
    }
    return 0;
}

/*
* Prints out the board in the console.
*/
int print_board(char board[][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

/*
* Checks whether the board is full and the game is over.
*/
int is_board_full(char board[][3]) {
    int board_size = 9;
    int i = 0;
    while(i < board_size) {
        if(board[i / 3][i % 3] == '-') {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_game_over(char board[][3]) {
    int i = 0;
    while(i < 3) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
        i++;
    }
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    return 0;
}

char determine_winner(char board[][3]) {
    int i = 0;
    while(i < 3) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
        i++;
    }
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    return '-';
}
/*
* Gets a random empty box to fill.
*/
int get_random_free_box(char board[][3]) {
    srand(time(NULL));
    int empty = rand() % 9;
    while(board[empty / 3][empty % 3] != '-') {
        empty = rand() % 9;
    }
    return empty;
}

int main(int argc, char** argv) {
    int myrank, size;
    int choice;
    // init everything about MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Status status;

    // the two possible values
    char player1 = 'X';
    char player2 = 'O';
    char winner;
    char blank = '-';

    char board[3][3];
    init_board(board, &blank);
    MPI_Barrier(MPI_COMM_WORLD);

    while(!is_board_full(board) && !is_game_over(board)) {
        if(myrank == 0) {
            // player1's move
            choice = get_random_free_box(board);
            board[choice / 3][choice % 3] = player1;
            MPI_Send(&choice, 1, MPI_INT, 1, 42, MPI_COMM_WORLD);
            print_board(board);
            if(is_board_full(board) || is_game_over(board)) {
                break;
            }
            // after player2's move
            MPI_Recv(&choice, 1, MPI_INT, 1, 42, MPI_COMM_WORLD, &status);
            board[choice / 3][choice % 3] = player2;
            print_board(board);
        } else if (myrank == 1) {
            // must wait for player1's move first
            MPI_Recv(&choice, 1, MPI_INT, 0, 42, MPI_COMM_WORLD, &status);
            board[choice / 3][choice % 3] = player1;
            if(is_board_full(board) || is_game_over(board)) {
                break;
            }
            // player2's move
            choice = get_random_free_box(board);
            board[choice / 3][choice % 3] = player2;
            MPI_Send(&choice, 1, MPI_INT, 0, 42, MPI_COMM_WORLD);
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }

    // end of game
    if(myrank == 0 && (is_board_full(board) || is_game_over(board))){
        printf("GAME OVER!\n");
        winner = determine_winner(board);
        if(winner == '-') {
            printf("No winner.\n");
        } else {
            printf("Winner is %c meaning thread %i\n", winner, winner == player1 ? 0 : 1);
        }
        
    }

    MPI_Finalize();
    return 0;
}
