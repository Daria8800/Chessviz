#include "header.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int x_1 = 0, x_2 = 0;
int y_1 = 0, y_2 = 0;
int BoundMin = 0, BoundMax = 9;
int Qualifier;

void move(char turn[], char pole[][9]) {
  if (strlen(turn) == 5) {
    Qualifier = 0;
    if (Check(turn, pole, Qualifier)) {
      movePawn(pole);
    }
  } else {
    Qualifier = 1;
    if (Check(turn, pole, Qualifier)) {
      moveFigure(turn, pole);
    }
  }
}

void movePawn(char pole[][9]) {
  if (pole[x_1 - 1][y_1] == 'p') {
    pole[x_1 - 1][y_1] = ' ';
    pole[x_2 - 1][y_2] = 'p';
  } else if (pole[x_1 - 1][y_1] == 'P') {
    pole[x_1 - 1][y_1] = ' ';
    pole[x_2 - 1][y_2] = 'P';
  } else
    cout << "Entry incorrect, you tried to go not a pawn" << endl << endl;
}

void moveFigure(char turn[], char pole[][9]) {
  if (pole[x_1 - 1][y_1] == turn[0]) {
    pole[x_1 - 1][y_1] = ' ';
    pole[x_2 - 1][y_2] = turn[0];
  } else
    cout << "Entry incorrect, you tried to go not by figures from the back row"
         << endl
         << endl;
}

bool Check(char turn[], char pole[][9], int Qualifier) {
  string s = " ";
  switch (turn[0 + Qualifier]) {
  case 'a':
    y_1 = 1;
    break;
  case 'b':
    y_1 = 2;
    break;
  case 'c':
    y_1 = 3;
    break;
  case 'd':
    y_1 = 4;
    break;
  case 'e':
    y_1 = 5;
    break;
  case 'f':
    y_1 = 6;
    break;
  case 'g':
    y_1 = 7;
    break;
  case 'h':
    y_1 = 8;
    break;
  default: {
    cout << "ERROR" << endl << endl;
    return false;
  }; break;
  }

  switch (turn[3 + Qualifier]) {
  case 'a':
    y_2 = 1;
    break;
  case 'b':
    y_2 = 2;
    break;
  case 'c':
    y_2 = 3;
    break;
  case 'd':
    y_2 = 4;
    break;
  case 'e':
    y_2 = 5;
    break;
  case 'f':
    y_2 = 6;
    break;
  case 'g':
    y_2 = 7;
    break;
  case 'h':
    y_2 = 8;
    break;
  default: {
    cout << "Entry incorrect" << endl << endl;
    return false;
  }; break;
  }

  s[0] = turn[1 + Qualifier];
  x_1 = atoi(s.c_str());

  s[0] = turn[4 + Qualifier];
  x_2 = atoi(s.c_str());

  if (x_1 <= BoundMin || x_1 >= BoundMax ||
      y_1 <= BoundMin || y_1 >= BoundMax ||
      x_2 <= BoundMin || x_2 >= BoundMax ||
      y_2 <= BoundMin || y_2 >= BoundMax ||
      (pole[x_1 - 1][y_1] == ' ')) {
    cout << "Entry incorrect" << endl << endl;
    return false;
  }
  return true;
}
