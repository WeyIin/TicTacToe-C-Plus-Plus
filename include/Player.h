#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player
{
    public:
        Player(); //constructor
        Player(string name, char symbol); //constructor dobi ime in simbol
        void printName();
        char getSymbol();
    private:
        string _playerName;
        char _playerSymbol;
};

#endif // PLAYER_H
