#include<bits/stdc++.h>
using namespace std;
#include "Board.cpp"
#include "Player.cpp"
#include "WinningStrategy.cpp"
#include "GameStatus.cpp"
#pragma once
#include "Move.cpp"

class TicTacToeGame {
    private:
        Board board;
        vector<Player> players;
        WinningStrategy* winningStrategy;
        GameStatus gameStatus;
        int currentPlayerIndex;
        vector<Move> movesHistory;

    public:
        TicTacToeGame(int boardSize, const vector<Player>& gamePlayers, WinningStrategy* strategy)
            : board(boardSize), players(gamePlayers), winningStrategy(strategy), gameStatus(GameStatus::IN_PROGRESS), currentPlayerIndex(0) {}
        void startGame() {
            while (gameStatus == GameStatus::IN_PROGRESS) {
                board.display();
                Player currentPlayer = players[currentPlayerIndex];
                int row, col;
                cout << currentPlayer.getName() << "'s turn. Enter row and column: ";
                cin >> row >> col;
                if (board.isValidMove(row, col)) {
                    board.placeSymbol(row, col, currentPlayer.getSymbol());
                    movesHistory.emplace_back(row, col, currentPlayer);
                    if (winningStrategy->checkWinner(board, currentPlayer.getSymbol())) {
                        gameStatus = GameStatus::WON;
                        cout << currentPlayer.getName() << " wins!" << endl;
                        break;
                    } else if (board.isFull()) {
                        gameStatus = GameStatus::DRAW;
                        cout << "The game is a draw!" << endl;
                        break;
                    }
                    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
        }
        void makeMove(int row, int col) {
            Player currentPlayer = players[currentPlayerIndex];
            if (board.isValidMove(row, col)) {
                board.placeSymbol(row, col, currentPlayer.getSymbol());
                movesHistory.emplace_back(row, col, currentPlayer);
                if (winningStrategy->checkWinner(board, currentPlayer.getSymbol())) {
                    gameStatus = GameStatus::WON;
                    cout << currentPlayer.getName() << " wins!" << endl;
                } else if (board.isFull()) {
                    gameStatus = GameStatus::DRAW;
                    cout << "The game is a draw!" << endl;
                } else {
                    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
        void switchTurn() {
            currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        }
        GameStatus getGameStatus() const {
            return gameStatus;
        }  
    
};