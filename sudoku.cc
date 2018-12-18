/*

NAME:Trisha Gagnon
FILE:sudoku.cc
DESC:Uses sudokuboard and stack classes to solve a sudoku puzzle, including
     backtracking.
DATE:Last updated 10/06

*/

#include <iostream>
#include "sudokuboard.h"
#include "stack.h"

//CITE: Eric
//DESC: The makefile was missing stack.o
//DESC: Also the constructor for a struct within a class
//DESC: There are apparently magic chars that can't be seen, found and fixed w/

//CITE: Alexei
//DESC: Letting me talk at her to form ideas

//CITE: Mitchel
//DESC: Completing the base puzzle, fixing canPlace, placeableChars etc.

//CITE: Ben Drebbing, other Ben, Lia Jundt
//DESC: Working through backtracking, clarifying algorithm 

using namespace std;


int main() {


  //Creating the sudokuboard
  sudokuboard board(cin);

  stack rowColPlaced;
  size_t lowest; 
  int placed;
  
  while (!board.solved()) {
    
    //Creates the new row and col that will hopefully be placed on
    int constrainedRow;
    int constrainedCol;
    //A string of all placeable characters in a spot
    string chars;
    //lowest -- the number of characters placeable in a spot
    lowest = 10; 
    //How many times a value has been placed in that spot
    placed = 1;    
    
    for(int row = 0; row < 9; row++) {
      for(int col = 0; col < 9; col++) {

	//placeableChars -- returns a string of numerals that can fit
	string toPlace = board.placeableChars(row, col);

	//This is where things get fun
	//The length has to be lower than the lowest but greater than 0
	//Because 0 would be "" which creates invisible chars
	if (toPlace.length() < lowest && toPlace.length() > 0) {
	
	  //Updates values for next itteration
	  constrainedRow = row;
	  constrainedCol = col;
	  chars = toPlace;
	  lowest = toPlace.length();
	}

	bool keepBacktrack = toPlace.length() == 0 && board.isBlank(row, col);
	//This works similarly to an else statement
	//If any square is blank and has nothing placeable, this runs
	while (keepBacktrack) {
	 
	  //top and pops to get the values
	  //next becomes the indexer and...
	  int next = rowColPlaced.top();
	  rowColPlaced.pop();
	  int co = rowColPlaced.top();
	  rowColPlaced.pop();
	  int ro = rowColPlaced.top();
	  rowColPlaced.pop();
	  //Allows placeableChars to work
	  board.place(ro, co, '_');
	  
	  toPlace = board.placeableChars(ro, co);
	  	  
	  if((int)(toPlace.length()) > next) {
	    ///... indexes the string of characters returned by placeableChars
	    board.place(ro, co, toPlace[next]);
	    rowColPlaced.push(ro);
	    rowColPlaced.push(co);
	    
	    //Adds one to next for future potential itterations
	    rowColPlaced.push(++next);
	    keepBacktrack = false;
	    
	    //Reset values
	    lowest = 10;
	    row = 0;
	    col = 0;
	  }
	}
      }
    }
    
    //Stops the program
    if (!board.canPlace(constrainedRow, constrainedCol, chars[0])) { 
      cout << "ERROR" << endl;
      return 0;
    }
    
    //The basic version of placing and pushing
    board.place(constrainedRow, constrainedCol, chars[0]);
    rowColPlaced.push(constrainedRow);
    rowColPlaced.push(constrainedCol);
    rowColPlaced.push(placed);
    
  	
  }
      
  board.print();
  
  return 0;
}
