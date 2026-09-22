#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define W 20
#define H 20

int gOver, score;
int x, y, fX, fY;
int tX[100], tY[100], nT;
enum eDir { STOP = 0, L, R, U, D } dir;

void Setup() {
    gOver = 0;
    dir = STOP;
    x = W / 2;
    y = H / 2;
    fX = rand() % W;
    fY = rand() % H;
    score = 0;
    nT = 0;
}

void Draw() {
    COORD c = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    for (int i = 0; i < W + 2; i++) printf("#");
    printf("\n");
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j == 0) printf("#");
            if (i == y && j == x) printf("O");
            else if (i == fY && j == fX) printf("F");
            else {
                int p = 0;
                for (int k = 0; k < nT; k++) {
                    if (tX[k] == j && tY[k] == i) {
                        printf("o");
                        p = 1;
                    }
                }
                if (!p) printf(" ");
            }
            if (j == W - 1) printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < W + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': if(dir != R) dir = L; break;
            case 'd': if(dir != L) dir = R; break;
            case 'w': if(dir != D) dir = U; break;
            case 's': if(dir != U) dir = D; break;
            case 'x': gOver = 1; break;
        }
    }
}

void Logic() {
    int pX = tX[0], pY = tY[0], p2X, p2Y;
    tX[0] = x; tY[0] = y;
    for (int i = 1; i < nT; i++) {
        p2X = tX[i]; p2Y = tY[i];
        tX[i] = pX; tY[i] = pY;
        pX = p2X; pY = p2Y;
    }
    switch (dir) {
        case L: x--; break;
        case R: x++; break;
        case U: y--; break;
        case D: y++; break;
        default: break;
    }
    if (x >= W) x = 0; else if (x < 0) x = W - 1;
    if (y >= H) y = 0; else if (y < 0) y = H - 1;
    for (int i = 0; i < nT; i++)
        if (tX[i] == x && tY[i] == y) gOver = 1;
    if (x == fX && y == fY) {
        score += 10;
        fX = rand() % W;
        fY = rand() % H;
        nT++;
    }
}

int main() {
    Setup();
    while (!gOver) {
        Draw();
        Input();
        Logic();
        Sleep(40);
    }
    return 0;
}
