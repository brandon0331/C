#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<Windows.h>

#define ROW 3
#define COL 3


int turn = 1;
int tictactoe[ROW][COL] = { 0 };
int count = 0;
int player1 = 0, player2 = 0;

void wait() {
    int bbuff;
    char ch = _getch();
    fflush(stdin);
    scanf("%c", &bbuff);
}

void drawGrid(int grid[ROW][COL]) {
    char row0[COL] = { 0 }, row1[COL] = { 0 }, row2[COL] = { 0 };

    system("cls");

    for (int i = 0; i < COL; i++) {
        row0[i] = ' ';
        row1[i] = ' ';
        row2[i] = ' ';
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0) {
                if (grid[i][j] == 1) row0[j] = 'O';
                else if (grid[i][j] == 2) row0[j] = 'X';
            }
            else if (i == 1) {
                if (grid[i][j] == 1) row1[j] = 'O';
                else if (grid[i][j] == 2) row1[j] = 'X';
            }
            else if (i == 2) {
                if (grid[i][j] == 1) row2[j] = 'O';
                else if (grid[i][j] == 2) row2[j] = 'X';
            }
        }
    }
    printf("\n");
    printf(" + - + - + - +\n");
    printf(" | %c | %c | %c |\n", row0[0], row0[1], row0[2]);
    printf(" + - + - + - +\n");
    printf(" | %c | %c | %c |\n", row1[0], row1[1], row1[2]);
    printf(" + - + - + - +\n");
    printf(" | %c | %c | %c |\n", row2[0], row2[1], row2[2]);
    printf(" + - + - + - +\n");
    printf("\n");
}

int winCheck() {
    if (tictactoe[0][0] == 1 && tictactoe[1][1] == 1 && tictactoe[2][2] == 1 ||
        tictactoe[0][2] == 1 && tictactoe[1][1] == 1 && tictactoe[2][0] == 1 ||
        tictactoe[0][0] == 1 && tictactoe[1][0] == 1 && tictactoe[2][0] == 1 ||
        tictactoe[0][1] == 1 && tictactoe[1][1] == 1 && tictactoe[2][1] == 1 ||
        tictactoe[0][2] == 1 && tictactoe[1][2] == 1 && tictactoe[2][2] == 1 ||
        tictactoe[0][0] == 1 && tictactoe[0][1] == 1 && tictactoe[0][2] == 1 ||
        tictactoe[1][0] == 1 && tictactoe[1][1] == 1 && tictactoe[1][2] == 1 ||
        tictactoe[2][0] == 1 && tictactoe[2][1] == 1 && tictactoe[2][2] == 1) {
        return player1 = 1;
    }
    if (tictactoe[0][0] == 2 && tictactoe[1][1] == 2 && tictactoe[2][2] == 2 ||
        tictactoe[0][2] == 2 && tictactoe[1][1] == 2 && tictactoe[2][0] == 2 ||
        tictactoe[0][0] == 2 && tictactoe[1][0] == 2 && tictactoe[2][0] == 2 ||
        tictactoe[0][1] == 2 && tictactoe[1][1] == 2 && tictactoe[2][1] == 2 ||
        tictactoe[0][2] == 2 && tictactoe[1][2] == 2 && tictactoe[2][2] == 2 ||
        tictactoe[0][0] == 2 && tictactoe[0][1] == 2 && tictactoe[0][2] == 2 ||
        tictactoe[1][0] == 2 && tictactoe[1][1] == 2 && tictactoe[1][2] == 2 ||
        tictactoe[2][0] == 2 && tictactoe[2][1] == 2 && tictactoe[2][2] == 2) {
        return player2 = 1;
    }
}

void overlapCheck(int row, int col) {
    if (turn == 1) {
        if (tictactoe[row][col] == 2 || tictactoe[row][col] == 1) {
            printf("Choose another spot.\n");
            wait();
            turn--;
        }
        else if (tictactoe[row][col] == 0) {
            tictactoe[row][col] = 1;
            count++;
        }
    }
    if (turn == 2) {
        if (tictactoe[row][col] == 1 || tictactoe[row][col] == 2) {
            printf("Choose another spot.\n");
            wait();
            turn++;
        }
        else if (tictactoe[row][col] == 0) {
            tictactoe[row][col] = 2;
            count++;
        }
    }
}

int main()
{
    int row, col;

    drawGrid(tictactoe);

    while (count < 9) {
        if (turn == 1) {
            printf("Player 1> ");
            scanf("%d %d", &row, &col);
            overlapCheck(row, col);
            turn++;
            printf("\n");
            goto grid;
        }

        if (turn == 2) {
            printf("Player 2> ");
            scanf("%d %d", &row, &col);
            overlapCheck(row, col);
            turn--;
            printf("\n");
            goto grid;
        }

    grid:
        drawGrid(tictactoe);

        winCheck();
        if (player1 == 1) {
            printf("Player 1 Wins!\n");
            return 0;
        }
        if (player2 == 1) {
            printf("Player 2 Wins\n");
            return 0;
        }
    }
    printf("Tie!\n");
    return 0;
}
