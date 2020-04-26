#include "head.h"
#include <iostream>
using namespace std;

void Chessplace(char pole[][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << pole[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
