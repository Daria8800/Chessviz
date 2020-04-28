#include "head.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int x_1 = 0, x_2 = 0;
int y_1 = 0, y_2 = 0;

void move(char turn[], char pole[][9])
{
    if (strlen(turn) == 5) {
        if (CheckCorrect(turn, pole)) {
            movePawn(pole);
        }
    } else {
        cout << "neverniy vvod, primer vernogo vvoda: e2-e4, f7-f6" << endl;
    }
}

void movePawn(char pole[][9])
{
    if (pole[y_1 - 1][x_1] == 'p') {
        pole[y_1 - 1][x_1] = ' ';
        pole[y_2 - 1][x_2] = 'p';
    } else if (pole[y_1 - 1][x_1] == 'P') {
        pole[y_1 - 1][x_1] = ' ';
        pole[y_2 - 1][x_2] = 'P';
    }
}

bool CheckCorrect(char turn[], char pole[][9])
{
    if (turn[2] == '-' || turn[2] == 'x') {
    } else {
        cout << "neverniy vvod" << endl;
        return false;
    }
    string transformIntoInt = " ";
    int outOfBoard1 = 0, outOfBoard2 = 9;
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

    if (y_1 <= outOfBoard1 || y_1 >= outOfBoard2 || x_1 <= outOfBoard1
        || x_1 >= outOfBoard2 || x_2 <= outOfBoard1 || x_2 >= outOfBoard2
        || y_2 <= outOfBoard1 || y_2 >= outOfBoard2) {
        cout << "Figura ne mozet nahoditsya za predelami polya" << endl;
        return false;
    }
    return true;
}
