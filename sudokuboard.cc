/*

NAME:Trisha Gagnon
FILE:sudokuboard.cc
DESC:Implementation of all methods within the sudokuboard class
DATE:Last updated 10/06

*/

#include <iostream>
#include "sudokuboard.h"


using namespace std;

sudokuboard::sudokuboard(std::istream & input) {

  size_t rows = 0;
  string one_row = "";
  

  for (; rows < 9; rows++) {
    input >> one_row;
    board[rows] = one_row;
  }
}


void sudokuboard::place(int r, int c, char n) {
  
  board[r][c] = n;
}


void sudokuboard::print() {

  for (size_t i = 0; i < 9; i++) 
    cout << board[i] << endl;
}

bool sudokuboard::isBlank(int r, int c) {
  return (board[r][c] == '_');
}

char sudokuboard::get(int r, int c) {
  return board[r][c];
}

void sudokuboard::remove(int r, int c) {
  board[r][c] = '_';
}

bool sudokuboard::canPlace(int r, int c, char n) {
  if (!isBlank(r, c))
    return false;
  
  //Makes the tinybox! 
  int tinyRow = r - (r % 3);
  int tinyCol = c - (c % 3);
  int rowEnd = tinyRow + 3;
  int colEnd = tinyCol + 3;
  //checking only the small box
  for(int row = tinyRow; row < rowEnd; row++) {
    for(int col = tinyCol; col < colEnd; col++) {
      if (get(row, col) == n) {
	return false;
      }
    }
  }
  
  //Checking the entire row
  for(int row = 0; row < 9; row++) {
    if (get(row, c) == n)
	return false;
  }
  //Checking the entire col
  for(int col = 0; col < 9; col++){
      if (get(r, col) == n)
	return false;
 }
    
    return true;
}

string sudokuboard::placeableChars(int r, int c) {
  //returns a string of characters that are placeable in a spot on board
  string chars = "";
  
  for (char test = '1'; test <= '9'; test++) {
    
    if (canPlace(r, c, test))
      chars += test;
  }
  return chars;
}

bool sudokuboard::solved() {
  for(size_t r = 0; r < 9; r++) {
    for(size_t c = 0; c < 9; c++) {
      if (board[r][c] == '_')
        return false;
    }
  }
  return true;
}
