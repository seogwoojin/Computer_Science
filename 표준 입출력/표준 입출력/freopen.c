#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define BOARD_SIZE 15

char board[BOARD_SIZE][BOARD_SIZE];
int currentPlayer; // 0: �÷��̾�, 1: ��ǻ��
int currentRow, currentCol; // ���� ��ġ

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    system("cls");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == currentRow && j == currentCol) {
                printf("[%c]", board[i][j]);
            }
            else {
                printf(" %c ", board[i][j]);
            }
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("---");
                if (j < BOARD_SIZE - 1) {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}

int isWin(int row, int col, char symbol) {
    // ���� �¸� ������ Ȯ���ϴ� ������ ���⿡ �����ϼ���.
    // �� ���������� �¸� ������ Ȯ������ �ʾҽ��ϴ�.
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void moveCursor(int direction) {
    switch (direction) {
    case 0: // Up
        if (currentRow > 0) {
            currentRow--;
        }
        break;
    case 1: // Down
        if (currentRow < BOARD_SIZE - 1) {
            currentRow++;
        }
        break;
    case 2: // Left
        if (currentCol > 0) {
            currentCol--;
        }
        break;
    case 3: // Right
        if (currentCol < BOARD_SIZE - 1) {
            currentCol++;
        }
        break;
    }
}

void playerMove() {
    int key;
    do {
        printBoard();
        key = _getch();
        if (key == 224) {
            key = _getch();
            switch (key) {
            case 72: // Up
                moveCursor(0);
                break;
            case 80: // Down
                moveCursor(1);
                break;
            case 75: // Left
                moveCursor(2);
                break;
            case 77: // Right
                moveCursor(3);
                break;
            }
        }
        else if (key == 32 && board[currentRow][currentCol] == ' ') {
            board[currentRow][currentCol] = 'X';
            return;
        }
    } while (key != 27); // 27 is the ASCII code for the Escape key
}

void computerMove() {
    int row, col;
    printf("��ǻ���� �����Դϴ�.\n");
    // ��ǻ���� �������� �����ϼ���.
    // �� ���������� ���� ��ġ�� �����մϴ�.
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}

int main() {
    initializeBoard();
    srand(time(NULL));

    currentPlayer = 0;
    currentRow = BOARD_SIZE / 2;
    currentCol = BOARD_SIZE / 2;

    while (1) {
        printBoard();
        if (currentPlayer == 0) {
            playerMove();
            if (isWin(currentRow, currentCol, 'X')) {
                printBoard();
                printf("�÷��̾ �̰���ϴ�!\n");
                break;
            }
        }
        else {
            computerMove();
            if (isWin(currentRow, currentCol, 'O')) {
                printBoard();
                printf("��ǻ�Ͱ� �̰���ϴ�!\n");
                break;
            }
        }

        if (isBoardFull()) {
            printBoard();
            printf("������ �����ϴ�!\n");
            break;
        }

        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}
