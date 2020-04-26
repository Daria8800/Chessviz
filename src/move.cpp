#include "head.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int move1 = 0, move2 = 0;
<<<<<<< HEAD
int h = 0, k1 = 0;

void move(char turn[], char pole[][9])
{
    if (CheckCorrect(turn, pole)) {
        movePawn(pole);
    }
}

void movePawn(char pole[][9])
{
    if (pole[move1 - 1][h] == 'p') {
        pole[move1 - 1][h] = ' ';
        pole[move2 - 1][k1] = 'p';
    } else if (pole[move1 - 1][h] == 'P') {
        pole[move1 - 1][h] = ' ';
        pole[move2 - 1][k1] = 'P';
    }
}

bool CheckCorrect(char turn[], char pole[][9])
{
    string s = " ";
    cout << "Do move:" << endl;
    cin >> turn;
    cout << endl;
    switch (turn[0]) {
    case 'a':
        h = 1;
        break;
    case 'b':
        h = 2;
        break;
    case 'c':
        h = 3;
        break;
    case 'd':
        h = 4;
        break;
    case 'e':
        h = 5;
        break;
    case 'f':
        h = 6;
        break;
    case 'g':
        h = 7;
        break;
    case 'h':
        h = 8;
        break;
    }

    switch (turn[3]) {
    case 'a':
        k1 = 1;
        break;
    case 'b':
        k1 = 2;
        break;
    case 'c':
        k1 = 3;
        break;
    case 'd':
        k1 = 4;
        break;
    case 'e':
        k1 = 5;
        break;
    case 'f':
        k1 = 6;
        break;
    case 'g':
        k1 = 7;
        break;
    case 'h':
        k1 = 8;
        break;
    }
    s[0] = turn[1];
    move1 = atoi(s.c_str());

    s[0] = turn[4];
    move2 = atoi(s.c_str());

    if (move1 <= 0 || move1 >= 9 || h <= 0 || h >= 9 || move2 <= 0 || move2 >= 9
        || k1 <= 0 || k1 >= 9) {
        cout << "entry incorrect, za predelami polya" << endl;
        return false;
    }
    return true;
    == == == = int h = 0, k1 = 0;

    void move(char turn[], char pole[][9])
    {
        if (Check(turn, pole)) {
            movePawn(pole);
        }
    }

    void movePawn(char pole[][9])
    {
        if (pole[move1 - 1][h] == 'p') {
            pole[move1 - 1][h] = ' ';
            pole[move2 - 1][k1] = 'p';
        } else if (pole[move1 - 1][h] == 'P') {
            pole[move1 - 1][h] = ' ';
            pole[move2 - 1][k1] = 'P';
        }
    }

    bool CheckCorrect(char turn[], char pole[][9])
    {
        string s = " ";
        cout << "Do move:" << endl;
        cin >> turn;
        cout << endl;
        switch (turn[0]) {
        case 'a':
            h = 1;
            break;
        case 'b':
            h = 2;
            break;
        case 'c':
            h = 3;
            break;
        case 'd':
            h = 4;
            break;
        case 'e':
            h = 5;
            break;
        case 'f':
            h = 6;
            break;
        case 'g':
            h = 7;
            break;
        case 'h':
            h = 8;
            break;
        }

        switch (turn[3]) {
        case 'a':
            k1 = 1;
            break;
        case 'b':
            k1 = 2;
            break;
        case 'c':
            k1 = 3;
            break;
        case 'd':
            k1 = 4;
            break;
        case 'e':
            k1 = 5;
            break;
        case 'f':
            k1 = 6;
            break;
        case 'g':
            k1 = 7;
            break;
        case 'h':
            k1 = 8;
            break;
        }
        s[0] = turn[1];
        move1 = atoi(s.c_str());

        s[0] = turn[4];
        move2 = atoi(s.c_str());

        if (move1 <= 0 || move1 >= 9 || h <= 0 || h >= 9 || move2 <= 0
            || move2 >= 9 || k1 <= 0 || k1 >= 9) {
            cout << "entry incorrect, za predelami polya" << endl;
            return false;
        }
        return true;
>>>>>>> develop
    }
