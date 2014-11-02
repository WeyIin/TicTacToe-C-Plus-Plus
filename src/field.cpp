#include <iostream>
#include <string>
#include "Player.h"
#include "Field.h"

using namespace std;

Field::Field()
{
    //ctor
}


// sprintamo field (board)
void Field::ShowField() {

    cout << "---------------" << endl;
    for(int y = 0; y < 4; y++){
        if (y != 0){
                cout << y << " | ";
        }

        for(int x = 0; x < 4; x++){
            if (y == 0){
                if (x == 0) {
                    cout << "y/x ";
                }
                else {
                    cout << x << " | ";
                }

            } else if (x !=0){
                cout << _field[y][x] << " | ";
            }

        }
        cout << endl;
    }
    cout << "--------------- \n\n\n";

}

bool Field::victory(Player player) {
    //1 row ---
    if ((_field[1][1] == player.getSymbol()) && (_field[1][2] == player.getSymbol()) && _field[1][3] == player.getSymbol())
     { return true; }

   //2 row ---
    if ((_field[2][1] == player.getSymbol()) && (_field[2][2] == player.getSymbol()) && _field[2][3] == player.getSymbol())
     { return true; }

   //3 row ---
    if ((_field[3][1] == player.getSymbol()) && (_field[3][2] == player.getSymbol()) && _field[3][3] == player.getSymbol())
     { return true; }

   //\      /
    if ((_field[3][1] == player.getSymbol()) && (_field[2][2] == player.getSymbol()) && _field[1][3] == player.getSymbol())
     { return true; }

   /*        \ */
    if ((_field[3][3] == player.getSymbol()) && (_field[2][2] == player.getSymbol()) && _field[1][1] == player.getSymbol())
     { return true; }

   //\  1    |
    if ((_field[1][1] == player.getSymbol()) && (_field[2][1] == player.getSymbol()) && _field[3][1] == player.getSymbol())
     { return true; }

   //\  2    |
    if ((_field[1][2] == player.getSymbol()) && (_field[2][2] == player.getSymbol()) && _field[3][2] == player.getSymbol())
     { return true; }

   //\  3    |
    if ((_field[1][3] == player.getSymbol()) && (_field[2][3] == player.getSymbol()) && _field[3][3] == player.getSymbol())
     { return true; }

}

//ustavi simbol v mrezo
void Field::insertSymbol(int x, int y, char playerSymbol) {

    _field[y][x] = playerSymbol;

}

// pogleda ce je vtipkana koordinata prosta
bool Field::emptySpace(int x, int y) {
    if(_field[y][x] == ' ')
    {
        return true;
    } else {
        return false;
    }

}
