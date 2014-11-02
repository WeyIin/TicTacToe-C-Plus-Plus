#include <iostream>
#include <string>
#include "Player.h"
#include "Field.h"

using namespace std;

Player::Player(string name, char symbol)
{
    _playerName = name;
    _playerSymbol = symbol;
}

void Player::printName()
{
    cout << _playerName;

}

char Player::getSymbol()
{
    return _playerSymbol;
}
