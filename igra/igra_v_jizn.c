#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // ����� ��� ����� ����� ����� �� ������
#define ROWS 20 // ����� ����� � ������� ����
#define COLS 20 // ����� �������� � ������� ����
#define ALIVE '*' // ������ ��� ����� ������
#define DEAD ' ' // ������ ��� ������� ������
// ������� ��� �������� ������ �������� ����
int isValidCell(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}
// ������� ��� ������������� �������� ����
void initGameBoard(char gameBoard[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = DEAD;
        }
    }
}
// ������� ��� ������ �������� ���� �� �����
void printGameBoard(char gameBoard[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// ������� ��� ���������� ��������� ������ �� ������ ������ ���� "�����"
void updateGameBoard(char gameBoard[][COLS]) {
    char newGameBoard[ROWS][COLS]; // ��������� ���� ��� �������� ������ ���������
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int aliveNeighbors = 0;

            // ��������� ���� ������� ������� ������
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        continue; // ���������� ������� ������
                    }

                    int neighborX = i + k;
                    int neighborY = j + l;

                    if (isValidCell(neighborX, neighborY) && gameBoard[neighborX][neighborY] == ALIVE) {
                        aliveNeighbors++;
                    }
                }
            }

            // ��������� ��������� ������ �� ������ ������ ����
            if (gameBoard[i][j] == ALIVE) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGameBoard[i][j] = DEAD;  // ������� ������ ��-�� ���������� ��� �������������
                }
                else {
                    newGameBoard[i][j] = ALIVE;  // ���������� ���� �����
                }
            }
            else {
                if (aliveNeighbors == 3) {
                    newGameBoard[i][j] = ALIVE;  // ��������� ����� ������
                }
                else {
                    newGameBoard[i][j] = DEAD;  // ������ �������� �������
                }
            }
        }
    }

    // �������� ����� ��������� ������ � ������������ ����
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = newGameBoard[i][j];
        }
    }

}
int main() {
    char gameBoard[ROWS][COLS];
    initGameBoard(gameBoard);

    // ������ ��������� ��������� ����
    gameBoard[4][5] = ALIVE;
    gameBoard[5][4] = ALIVE;
    gameBoard[5][5] = ALIVE;
    gameBoard[5][6] = ALIVE;
    gameBoard[5][7] = ALIVE;
    gameBoard[4][6] = ALIVE;
    gameBoard[4][7] = ALIVE;
    gameBoard[9][9] = ALIVE;
    gameBoard[8][9] = ALIVE;
    gameBoard[8][10] = ALIVE;

    // ������� ����
    while (1) {
        system("cls"); // ������� ����� (��� UNIX-�������� ������)
        printGameBoard(gameBoard);
        updateGameBoard(gameBoard);
        Sleep(500);
    }

    return 0;

}