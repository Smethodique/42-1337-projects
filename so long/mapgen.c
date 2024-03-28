#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WALL '1'
#define PLAYER 'P'
#define COIN 'C'
#define EXIT 'E'
#define EMPTY '0'

#define GEN_PATH "maps/generated/"
#define WALL_PROBABILITY 0.80
#define COIN_PROBABILITY 0.80

void generate_coins(char contents[][10], int x, int y) {
   int num_coins = rand() % (int)((x > y ? x : y) * COIN_PROBABILITY);

    printf("Num coins: %d\n", num_coins);

    for (int i = 0; i < num_coins; i++) {
        int cx = rand() % (x - 2) + 1;
        int cy = rand() % (y - 2) + 1;

        if (contents[cy][cx] == EMPTY) {
            contents[cy][cx] = COIN;
        }
    }
}

void generate_player_and_exit(char contents[][10], int x, int y) {
    int px = rand() % (x - 2) + 1;
    int py = rand() % (y - 2) + 1;
    contents[py][px] = PLAYER;

    int ex = rand() % (x - 2) + 1;
    int ey = rand() % (y - 2) + 1;
    contents[ey][ex] = EXIT;
}

void randomized_dfs(char contents[][10], int x, int y, bool visited[][10]) {
    visited[y][x] = true;
    contents[y][x] = EMPTY;

    int directions[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (int i = 0; i < 4; i++) {
        int new_x = x + directions[i][0];
        int new_y = y + directions[i][1];

        if (!visited[new_y][new_x]) {
            randomized_dfs(contents, new_x, new_y, visited);
        }
    }
}

void generate_walls(char contents[][10], int x, int y) {
    bool visited[12][10] = {false};

    int start_x = rand() % (x - 2) + 1;
    int start_y = rand() % (y - 2) + 1;
    randomized_dfs(contents, start_x, start_y, visited);
}

void generate_map(char* filename, int x, int y) {
    char contents[12][10];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            contents[i][j] = WALL;
        }
    }

    generate_walls(contents, x, y);
    generate_coins(contents, x, y);
    generate_player_and_exit(contents, x, y);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (contents[i][j] == WALL) {
                printf("\033[34m%c\033[0m", contents[i][j]);  // Blue for walls
            } else if (contents[i][j] == COIN) {
                printf("\033[33m%c\033[0m", contents[i][j]);  // Yellow for coins
            } else if (contents[i][j] == EXIT) {
                printf("\033[32m%c\033[0m", contents[i][j]);  // Green for exit
            } else if (contents[i][j] == PLAYER) {
                printf("\033[31m%c\033[0m", contents[i][j]);  // Red for player
            } else {
                printf("%c", contents[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\t --- The map was generated. ---\n\n");
}

int main() {
    srand(time(NULL));
    int n = 1;
    int x = -1, y = -1;

    while (y < 3 || x < 3) {
        printf("Width: ");
        scanf("%d", &x);
        printf("Height: ");
        scanf("%d", &y);

        if (y < 3 || x < 3) {
            printf("\n\t===== INPUT MUST BE BIGGER THAN 2 =====\n\n");
        }
    }

    char filename[100];
    sprintf(filename, "%smap%d.ber", GEN_PATH, n);

    while (fopen(filename, "r") != NULL) {
        n++;
        sprintf(filename, "%smap%d.ber", GEN_PATH, n);
    }

    generate_map(filename, x, y);

    return 0;
}
