#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "../src/head.h"
#include "../thirdparty/catch.hpp"
#include <string>

using namespace std;

char pole[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                   {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST_CASE("MovePawn_1", "Correct_pawn_move") {
  int Qualifier = 0;
  char turn[6] = "e2-e4";
  REQUIRE(Check(turn, pole, Qualifier) == true);
}

TEST_CASE("MovePawn_2", "Incorrect_pawn_move_from_outside_the_MaxBound") {
  int Qualifier = 0;
  char turn[6] = "e9-e4";
  REQUIRE(Check(turn, pole, Qualifier) == false);
}

TEST_CASE("MovePawn_3", "Incorrect_pawn_move_from_outside_the_MinBound") {
  int Qualifier = 0;
  char turn[6] = "e2-e0";
  REQUIRE(Check(turn, pole, Qualifier) == false);
}

TEST_CASE("MovePawn_4", "Incorrect_move_ with_an_empty_cage") {
  int Qualifier = 0;
  char turn[6] = "e4-e2";
  REQUIRE(Check(turn, pole, Qualifier) == false);
}

TEST_CASE("MoveFigure_1", "Correct_figure_move") {
  int Qualifier = 1;
  char turn[7] = "Qd8-d4";
  REQUIRE(Check(turn, pole, Qualifier) == true);
}

TEST_CASE("MoveFigure_2", "Incorrect_figure_move_from_outside_the_MinBound") {
  int Qualifier = 1;
  char turn[7] = "Nd0-d3";
  REQUIRE(Check(turn, pole, Qualifier) == false);
}

TEST_CASE("MoveFigure_3", "Incorrect_figure_move_from_outside_the_MaxBound") {
  int Qualifier = 1;
  char turn[7] = "Nd9-d3";
  REQUIRE(Check(turn, pole, Qualifier) == false);
}

TEST_CASE("MoveFigure_4", "Incorrect_move_with_an_empty_cage") {
  int Qualifier = 1;
  char turn[7] = "Nd6-d4";
  REQUIRE(Check(turn, pole, Qualifier) == false);
}
