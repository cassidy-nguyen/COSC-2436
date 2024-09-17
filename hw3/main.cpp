#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include "Stack.h"

using namespace std;

void DrawBoard(int rows, int cols, int** board, ofstream& fout) {
  fout << "+";
  for (int c = 0; c < cols; c++) {
    fout << "--+";
  }
  fout << endl;
  for (int r = 0; r < rows; r++) {
    fout << "|";
    for (int c = 0; c < cols; c++) {
      if (board[r][c] == 0) {
        fout << "  |";
      }
      else if (board[r][c] == -1) {
        fout << "XX|";
      }
      else {
        if (board[r][c] < 10)
          fout << " " << board[r][c] << "|";
        else
          fout << board[r][c] << "|";
      }
    }
    fout << endl;
    fout << "+";
    for (int c = 0; c < cols; c++) {
      fout << "--+";
    }
    fout << endl;
  }
}

// checking if the move is valid on the game board
bool CheckMove(int new_row, int new_col, int rows, int cols, int** board) {
  return (new_row < rows && new_row >= 0 && new_col < cols && new_col >=0 && board[new_row][new_col] == 0);
}

bool KnightTour(int curr_row, int curr_col, int rows, int cols, int moveCount, int** board, int possibleSquares, int& end_row, int& end_col, ofstream& fout) {
  int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int yMove[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
  
  if (moveCount == possibleSquares) {
    return true;
  }

  for (int i = 0; i < 8; i++) {
    int new_row = curr_row + yMove[i];
    int new_col = curr_col + xMove[i];
    if (CheckMove(new_row, new_col, rows, cols, board)) {
      board[new_row][new_col] = moveCount + 1;
      if (KnightTour(new_row, new_col, rows, cols, moveCount + 1, board, possibleSquares, end_row, end_col, fout)) {
        return true;
      }
      board[new_row][new_col] = 0; // backtrack
    }
  }
  end_row = curr_row;
  end_col = curr_col;
  return false;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));
  //ifstream fin("input1.txt");
  //ofstream fout("output1.txt");

  int rows, cols;
  fin >> rows >> cols;
  
  // creating game board with row x cols dimensions
  int** board = new int*[rows];
  for (int r = 0; r < rows; r++) {
    board[r] = new int[cols];
  }

  int start_row, start_col; // initial row, initial column
  fin >> start_row >> start_col;
  // initialize all values to 0
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      board[r][c] = 0;
    }
  }
  // marking initial position
  board[start_row][start_col] = 1;
  
  int holes;
  fin >> holes;
  if (holes > 0) {
    int holeX, holeY;
    for (int i = 0; i < holes; i++) {
      fin >> holeX >> holeY;
      board[holeX][holeY] = -1; // marking holes with int -1
    }
  }

  int possibleSquares = (rows * cols) - holes;

  int moveCount = 1;
  int end_row = 0;
  int end_col = 0;
  if (KnightTour(start_row, start_col, rows, cols, 1, board, possibleSquares, end_row, end_col, fout)) {
    if (end_row == start_row && end_col == start_col) {
      fout << "A closed tour exists!" << endl;
      DrawBoard(rows, cols, board, fout);
    }
    else {
      fout << "A closed tour does not exist!" << endl;
      //DrawBoard(rows, cols, board, fout);
    }
  }
  else {
    fout << "A closed tour does not exist!" << endl;
  }

  // free up memory
  for (int i = 0; i < rows; i++) {
    delete[] board[i];
  }
  delete[] board;

  fin.close();
  fout.close();

  return 0;
}