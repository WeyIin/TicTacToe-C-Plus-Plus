#ifndef FIELD_H
#define FIELD_H

#include "Player.h"
#include "Field.h"
#include <iostream>

using namespace std;

class Field
{
    public:
        Field();
        void ShowField();
        bool emptySpace(int x, int y);
        bool victory(Player player);
        void insertSymbol(int x, int y, char playerSymbol);
    private:
        char _field[4][4] =
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '}
        };
};

#endif // FIELD_H
