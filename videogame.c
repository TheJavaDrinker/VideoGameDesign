#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

int main() {
    int x = WIDTH / 2;
    int y = HEIGHT - 1;
    int bullet_x = -1;
    int bullet_y = -1;
    int enemy_x = rand() % WIDTH;
    int enemy_y = 0;
    int score = 0;

    srand(time(NULL));

    while (1) {
        // Clear the screen
        system("cls");

        // Draw the player
        for (int i = 0; i < x; i++) {
            printf(" ");
        }
        printf("A\n");

        // Draw the bullet
        if (bullet_y >= 0) {
            for (int i = 0; i < bullet_x; i++) {
                printf(" ");
            }
            printf("|\n");
        }

        // Draw the enemy
        for (int i = 0; i < enemy_x; i++) {
            printf(" ");
        }
        printf("V\n");

        // Move the bullet
        if (bullet_y >= 0) {
            bullet_y--;
            if (bullet_y == enemy_y && bullet_x == enemy_x) {
                score++;
                bullet_y = -1;
                enemy_x = rand() % WIDTH;
                enemy_y = 0;
            }
            else if (bullet_y == 0) {
                bullet_y = -1;
            }
        }

        // Move the enemy
        enemy_y++;
        if (enemy_y == HEIGHT) {
            enemy_x = rand() % WIDTH;
            enemy_y = 0;
        }

        // Check for input
        if (_kbhit()) {
            char c = _getch();
            if (c == 'a') {
                x--;
                if (x < 0) {
                    x = 0;
                }
            }
            else if (c == 'd') {
                x++;
                if (x >= WIDTH) {
                    x = WIDTH - 1;
                }
            }
            else if (c == ' ') {
                if (bullet_y < 0) {
                    bullet_x = x;
                    bullet_y = y - 1;
                }
            }
        }

        // Print the score
        printf("Score: %d\n", score);

        // Sleep for a bit to control frame rate
        Sleep(50);
    }

    return 0;
}

