#include "head.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int x_1 = 0, x_2 = 0;
int y_1 = 0, y_2 = 0;

void move(char turn[], char pole[][9])
{
    if (CheckCorrect(turn, pole)) {
        movePawn(pole);
    }
}

void movePawn(char pole[][9])
{
    if (pole[x_1 - 1][y_1] == 'p') {
        pole[x_1 - 1][y_1] = ' ';
        pole[x_2 - 1][y_2] = 'p';
    } else if (pole[x_1 - 1][y_1] == 'P') {
        pole[x_1 - 1][y_1] = ' ';
        pole[x_2 - 1][y_2] = 'P';
    }
}

bool CheckCorrect(char turn[], char pole[][9])
{
    string transformIntoInt = " ";
    cout << "Do move:" << endl;
    cin >> turn;
    cout << endl;
    switch (turn[0]) {
    case 'a':
        x_1 = 1;
        break;
    case 'b':
        x_1 = 2;
        break;
    case 'c':
        x_1 = 3;
        break;
    case 'd':
        x_1 = 4;
        break;
    case 'e':
        x_1 = 5;
        break;
    case 'f':
        x_1 = 6;
        break;
    case 'g':
        x_1 = 7;
        break;
    case 'h':
        x_1 = 8;
        break;
    }

    switch (turn[3]) {
    case 'a':
        x_2 = 1;
        break;
    case 'b':
        x_2 = 2;
        break;
    case 'c':
        x_2 = 3;
        break;
    case 'd':
        x_2 = 4;
        break;
    case 'e':
        x_2 = 5;
        break;
    case 'f':
        x_2 = 6;
        break;
    case 'g':
        x_2 = 7;
        break;
    case 'h':
        x_2 = 8;
        break;
    }
    transformIntoInt[0] = turn[1];
    y_1 = atoi(transformIntoInt.c_str());

    transformIntoInt[0] = turn[4];
    y_2 = atoi(transformIntoInt.c_str());

    if (y_1 <= 0 || y_1 >= 9 || x_1 <= 0 || x_1 >= 9 || x_2 <= 0 || x_2 >= 9
        || y_2 <= 0 || y_2 >= 9) {
        cout << "Figura ne mozet nahoditsya za predelami polya" << endl;
        return false;
    }
    return true;
}
