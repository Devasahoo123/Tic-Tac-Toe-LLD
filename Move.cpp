#include<bits/stdc++.h>
using namespace std;
#include "Player.cpp"

class Move {
    private:
        int row;
        int col;
        Player player;
    
    public:
        Move(int r, int c, Player p) : row(r), col(c), player(p) {}
        Player getPlayer() const { return player; }
        int getRow() const { return row; }
        int getCol() const { return col; }
};