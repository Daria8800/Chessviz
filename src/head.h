#ifndef ADD_H
#define ADD_H
void move(char turn[], char pole[][9]);
void Chessplace(char pole[][9]);
void movePawn(char pole[][9]);
void moveFigure(char turn[], char pole[][9]);
bool Check(char turn[], char pole[][9], int Qualifier);
#endif
