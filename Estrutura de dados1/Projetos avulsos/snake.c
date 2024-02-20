#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <ncurses.h>

#define ROWS 20
#define COLS 50
#define MAX_LENGTH 50

int row, col, len, gameover;
int xpos[MAX_LENGTH], ypos[MAX_LENGTH], foodx, foody, score;

void setup()
{
    srand(time(NULL));
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);
    row = ROWS / 2;
    col = COLS / 2;
    len = 5;
    gameover = 0;
    for (int i = 0; i < len; i++) {
        xpos[i] = row;
        ypos[i] = col - i;
    }
    foodx = rand() % ROWS;
    foody = rand() % COLS;
    score = 0;
}

void draw()
{
    clear();
    for (int i = 0; i < len; i++) {
        mvprintw(xpos[i], ypos[i], "o");
    }
    mvprintw(foodx, foody, "*");
    mvprintw(0, 0, "Score: %d", score);
    refresh();
}

void input()
{
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            row--;
            break;
        case KEY_DOWN:
            row++;
            break;
        case KEY_LEFT:
            col--;
            break;
        case KEY_RIGHT:
            col++;
            break;
        case KEY_BACKSPACE:
            gameover = 1;
            break;
        default:
            break;
    }
}

void logic()
{
    if (row < 0 || row > ROWS || col < 0 || col > COLS) {
        gameover = 1;
    }
    if (row == foodx && col == foody) {
        score++;
        len++;
        foodx = rand() % ROWS;
        foody = rand() % COLS;
    }
    for (int i = len - 1; i > 0; i--) {
        xpos[i] = xpos[i - 1];
        ypos[i] = ypos[i - 1];
    }
    xpos[0] = row;
    ypos[0] = col;
    for (int i = 1; i < len; i++) {
        if (xpos[0] == xpos[i] && ypos[0] == ypos[i]) {
            gameover = 1;
        }
    }
}

void cleanup()
{
    endwin();
}

int main()
{
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
    cleanup();
    printf("Game over! Your score is %d.\n", score);
    return 0;
}
