#ifndef _MAIN_H_
#define _MAIN_H_
#include "structures.h"

int makePossibleMoves(state **board, movementList* moveList);
int moveNb(state **board);
void initBoard(state **board);
int ballNb(state **board);
int correctMove(state **board, movement* move);
int possibleMove(state **board);
void doMove(state **board, movement* move);
void userMove(state **board, int* pquit);
void printBoard(state **board);

typedef struct trajectory trajectory;
struct trajectory {
    //Remembers the different steps
    state** board;
    trajectory* next;
};

//data.c
void saveGame (state** board, int turn, double time);
void loadGame (state** board, long long int returned[2]);
int isThereASavedGame();
int readNumberOfGames();
double totalPlayingTime();
void implementStats(double time);

//readBoard.c
void printBoardV(state **board, char lineNb, char colNb);
state** readBoard (char* fileName, char* lineNb, char* colNb);

int userGame(int* pquit, trajectory** pTrajectory, state** board, int* turn);

trajectory* consT (state** board, trajectory* pTrajectory) {
    //Add a board on the top of the list
    trajectory* tmp = malloc(sizeof(trajectory));
    if (tmp == NULL) {
        printf("ERREUR");
        return NULL;
    }
    tmp->board = board;
    tmp->next = pTrajectory;

    return tmp;
}

typedef struct node node;
movementList* consML (movement* move, movementList* moveList);

void copyBoard (state** boardI, state** boardO) {
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            boardO[i][j] = boardI[i][j];
        }
    }
}
#endif