#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // фишки дл€ винды чтобы мозги не шатало
#define ROWS 20 // число строк в игровом поле
#define COLS 20 // число столбцов в игровом поле
#define ALIVE '*' // символ дл€ живой клетки
#define DEAD ' ' // символ дл€ мертвой клетки
// функци€ дл€ проверки границ игрового пол€
int isValidCell(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}
// функци€ дл€ инициализации игрового пол€
void initGameBoard(char gameBoard[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = DEAD;
        }
    }
}
// функци€ дл€ вывода игрового пол€ на экран
void printGameBoard(char gameBoard[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// функци€ дл€ обновлени€ состо€ни€ клеток на основе правил игры "∆изнь"
void updateGameBoard(char gameBoard[][COLS]) {
    char newGameBoard[ROWS][COLS]; // временное поле дл€ хранени€ нового состо€ни€
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int aliveNeighbors = 0;

            // провер€ем всех соседей текущей клетки
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        continue; // пропускаем текущую клетку
                    }

                    int neighborX = i + k;
                    int neighborY = j + l;

                    if (isValidCell(neighborX, neighborY) && gameBoard[neighborX][neighborY] == ALIVE) {
                        aliveNeighbors++;
                    }
                }
            }

            // обновл€ем состо€ние клетки на основе правил игры
            if (gameBoard[i][j] == ALIVE) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGameBoard[i][j] = DEAD;  // мертва€ клетка из-за недостатка или перенаселени€
                }
                else {
                    newGameBoard[i][j] = ALIVE;  // продолжает быть живой
                }
            }
            else {
                if (aliveNeighbors == 3) {
                    newGameBoard[i][j] = ALIVE;  // рождаетс€ нова€ клетка
                }
                else {
                    newGameBoard[i][j] = DEAD;  // клетка остаетс€ мертвой
                }
            }
        }
    }

    // копируем новое состо€ние клеток в оригинальное поле
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = newGameBoard[i][j];
        }
    }

}
int main() {
    char gameBoard[ROWS][COLS];
    initGameBoard(gameBoard);

    // задаем начальное состо€ние пол€
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

    // игровой цикл
    while (1) {
        system("cls"); // очищаем экран (дл€ UNIX-подобных систем)
        printGameBoard(gameBoard);
        updateGameBoard(gameBoard);
        Sleep(500);
    }

    return 0;

}