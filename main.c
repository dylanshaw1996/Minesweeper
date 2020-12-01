// Dylan Shaw



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_funtions.h"

int main(){
    int no_of_bombs = 2;
    struct locations * bombs = (struct locations * ) malloc(sizeof(struct locations)  * 2) ;

    bombs[0].x = 1;
    bombs[0].y = 1;
    bombs[0].found = false;

    bombs[1].x = 3;
    bombs[1].y  = 3;
    bombs[1].found = false;

    int bomb_location_info[4][4] = {1,1,1,0,1,-2,1,0,1,1,2,1,0,0,1,-2};
    int known_location_info[4][4] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    start_game(bombs, bomb_location_info, DIM, known_location_info, no_of_bombs);

    free(bombs);

}





