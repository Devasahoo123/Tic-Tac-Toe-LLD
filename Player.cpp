#include<bits/stdc++.h>
using namespace std;
#pragma once
#include "Symbol.cpp"


class Player {
    private:
        string name;
        Symbol symbol;
    
    public:
        Player(string n, Symbol s) : name(n), symbol(s) {}
        
        string getName() const { return name; }
        Symbol getSymbol() const { return symbol; }
};