#include <bits/stdc++.h>
using namespace std;

#include "TicTacToeGame.cpp"
#include "SimpleWinningStrategy.cpp"

int main() {
    int boardSize = 3;

    vector<Player> players = {
        Player("Alice", Symbol::X),
        Player("Bob",   Symbol::O)
    };

    WinningStrategy* strategy = new SimpleWinningStrategy();

    TicTacToeGame game(boardSize, players, strategy);
    game.startGame();

    delete strategy;
    return 0;
}