#include<bits/stdc++.h>
using namespace std;
#include "Symbol.cpp"
#include "Player.cpp"
#pragma once

class Board {
    private:
        vector<vector<Symbol>> board;
        int size;
    
    public:
        Board(int n) : size(n) {
            board.resize(size, vector<Symbol>(size, Symbol::EMPTY));
        }

        void display() {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    char c = (board[i][j] == Symbol::X) ? 'X'
                        : (board[i][j] == Symbol::O) ? 'O' : ' ';
                    cout << " " << c << " ";
                    if (j < size - 1) cout << "|";
                }
                cout << endl;
                if (i < size - 1) {
                    for (int j = 0; j < size; ++j) {
                        cout << "---";
                        if (j < size - 1) cout << "+";
                    }
                    cout << endl;
                }
            }
        }
        bool isValidMove(int row, int col) {
            return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == Symbol::EMPTY;
        }
        void placeSymbol(int row, int col, Symbol symbol) {
            if (isValidMove(row, col)) {
                board[row][col] = symbol;
            }
        }
        bool isFull() {
            for (const auto& row : board) {
                for (const auto& cell : row) {
                    if (cell == Symbol::EMPTY) return false;
                }
            }
            return true;
        }
        const vector<vector<Symbol>>& getBoard() const {
            return board;
        }
        Symbol getSymbol(int row, int col) {
            return board[row][col];
        }        
};