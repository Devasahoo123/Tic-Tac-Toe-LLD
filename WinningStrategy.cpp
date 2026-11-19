#pragma once
#include<bits/stdc++.h>
using namespace std;
#include "Board.cpp"
#include "Symbol.cpp"

class WinningStrategy {
    public:
        virtual bool checkWinner(const Board& board, Symbol symbol) = 0;
        virtual ~WinningStrategy() {}
};