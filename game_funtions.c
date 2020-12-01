// Dylan Shaw


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_funtions.h"





void start_game(struct locations* bombs, int bomb_location_info[][DIM], int size_of_grid, int known_location_info[][DIM], int no_of_bombs){

    enum game_status  {STILL_ALIVE, GAME_OVER};
    enum game_status status = STILL_ALIVE;
    int numGuesses = 0;

    display(known_location_info, DIM);
    printf("Would you like clues Y/N: ");
    char clues = toupper(getUserChar());

    if (clues - 'Y' == 0) {
        srand(time(0));
        int numClues = 0;

        while (numClues < 2){
            int col = rand() % DIM;
            int row = rand() % DIM;

        if(bomb_location_info[row][col] >= 0 && known_location_info[row][col] == UNKNOWN){
            update_known_info(row, col, bomb_location_info, known_location_info);
            numClues++;
        }
        numGuesses = 2;
    }

display(known_location_info, DIM);

}


    bool gameStatus = true;
    int col;
    int row;
    while (gameStatus == true){

    bool check = false;
    while(!check)
    {
    printf("Enter a col: ");
    col = toupper(getUserChar()) - 65;
    printf("Enter a row: ");
    row = toupper(getUserChar()) - 65;

    bool validate = checkUserInput( row,  col,  known_location_info);
    if(validate == true){
        check = true;
        numGuesses ++;
    }
    }

    update_known_info(row, col, bomb_location_info, known_location_info);
    display(known_location_info, DIM);
    checkUserInput( row,  col,  known_location_info);

    int phase = 1;

    if (phase == 1){
        if ( numGuesses > 4){
        gameStatus = true;
        printf("Welcome to phase 2  \n");

        phase = 2;
        }
        else if (bomb_location_info[row][col] < 0){
            gameStatus = false;
            printf("Better luck next time \n");

        }
    }

    if (phase == 2 ){
        int bombsFound = 0;
        while ( bombsFound < no_of_bombs){


    bool check = false;
    while(!check)
    {
        printf("Enter a col: ");
        col = toupper(getUserChar()) - 65;
        printf("Enter a row: ");
        row = toupper(getUserChar()) - 65;

        bool validate = checkUserInput( row,  col,  known_location_info);
        if(validate == true){
            check = true;
    }
    }

    update_known_info(row, col, bomb_location_info, known_location_info);
    display(known_location_info, DIM);
    checkUserInput( row,  col,  known_location_info);



        if ( bomb_location_info[row][col] < 0){
            printf("You have found a bomb \n");
            bombsFound++;
        }
        else{
            printf("Game Over \n");
            gameStatus = false;
            break;
        }
    }

    if (bombsFound == 2){
        gameStatus = false;
        printf("You have won");

    }

    }
}
}


bool checkUserInput(int row, int col, int known_location_info[][DIM]){
    if(row < 0 || row > 3 || col < 0 || col > 3){
        printf("That is an incorrect move \n");
        return false;
    }
    else{
        return true;
    }

}



void display(int known_location_info[][DIM], int size){

         int i = 0;
         int l = 0;
         char sideLetters = 'A';

         printf("  A B C D \n");

         for (i=0; i < size; i++){
                printf("%c", sideLetters);
                for (l = 0; l < size; l++){

                    if( known_location_info[i][l] == UNKNOWN){
                        printf(" *");
                    }
                    else if ( known_location_info[i][l] < UNKNOWN){
                        printf(" B");
                    }
                    else{
                        printf(" %d", known_location_info[i][l]);
                    }

                }
                printf(" \n");
                sideLetters ++;
         }


    }


char getUserChar(){

    char res = getchar();
    bool finish = false;
    char dummy_char = ' ';
    while ( finish == false){
        dummy_char = getchar();
        if ( dummy_char == '\n')
            finish = true;
    }
    return res;
}



void update_known_info(int row, int col, int bomb_info[][DIM], int known[][DIM]){

    int newNum = bomb_info[row][col];
    known[row][col] = newNum;

}

void check_found(int row, int col, struct locations bombs[], int size, bool* found){

        for ( int i = 0; i < size; i++){
            if(row == bombs[i].y && col == bombs[i].x){
                bombs[i].found = true;
            }
        }



}






