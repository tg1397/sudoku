/*

NAME:Trisha Gagnon
FILE:sudokuboard.h
DESC:Header file for the sudokuboard class
DATE:Last updated 10/06

*/

#include <iostream>

using namespace std;

class sudokuboard {
  
public:
  sudokuboard(std::istream & input);
  
  void place(int r, int c, char n);
  
  void print();
  
  char get(int r, int c);
  
  void remove(int r, int c);

  bool isBlank(int r, int c);

  string placeableChars(int r, int c);
  
  bool canPlace(int r, int c, char n);
  
  bool solved();
  
 private:
  string board[9];
};