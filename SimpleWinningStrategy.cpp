#pragma once
#include<bits/stdc++.h>
using namespace std;
#include "WinningStrategy.cpp"
#include "Board.cpp"

class SimpleWinningStrategy : public WinningStrategy {
    public:
        bool checkWinner(const Board& board, Symbol symbol) override {
            const auto& b = board.getBoard();
            int n = b.size();

            // Check rows and columns
            for (int i = 0; i < n; ++i) {
                bool rowWin = true, colWin = true;
                for (int j = 0; j < n; ++j) {
                    if (b[i][j] != symbol) rowWin = false;
                    if (b[j][i] != symbol) colWin = false;
                }
                if (rowWin || colWin) return true;
            }

            // Check diagonals
            bool diag = true, antiDiag = true;
            for (int i = 0; i < n; ++i) {
                if (b[i][i] != symbol) diag = false;
                if (b[i][n - 1 - i] != symbol) antiDiag = false;
            }
            return diag || antiDiag;
        }
};