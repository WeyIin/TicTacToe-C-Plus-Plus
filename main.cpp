#include <iostream>
#include <string>
#include "Player.h"
#include "Field.h"

using namespace std;

    void Turn(Player player);

    const string questionName = "What is your name?\n";
    const string questionSymbol = "What about symbol?\n";
    const string askAboutXCord = "Insert X cord: \n";
    const string askAboutYCord = "Insert Y cord: \n";

    bool doWeHaveAWinner = false;
    bool isADraw = false;
    int numberOfTurns = 0;
    Field field;


int main()
{
    string playerName;
    char playerSymbol;
    //string welcomePlayer = "Welcome "+ &playerName +", your symbol is "+ &playerSymbol + ". Good luck! \n\n";


    //welcome message takoj ko se igra zazene
    cout << "*******************\n Tic Tac Toe \n*******************\n";

    //uprasamo za player 1
    cout << "Player 1: " << endl;
    cout << questionName;
    cin >> playerName;

    cout << questionSymbol;
    cin >> playerSymbol;

    Player p1(playerName, playerSymbol);

    cout << "Welcome "+ playerName +", your symbol is "+ playerSymbol + ". Good luck! \n\n";




/*
    p1.printName();
    cout << p1.getSymbol();*/

    //uprasamo za player 2
    cout << "Player 2: " << endl;
    cout << questionName;
    cin >> playerName;

    cout << questionSymbol;
    cin >> playerSymbol;

    Player p2(playerName, playerSymbol);

    cout << "Welcome "+ playerName +", your symbol is "+ playerSymbol + ". Good luck! \n\n";


    cout << "Good luck to both of you!\n\n";

    //sprintamo si field ze na zacetku, da ima player predstavo kam ustavit simbol.
    field.ShowField();

    //ce ni winnerja oz ni drawa, nenehno sprasuje za naredit turn.
    while(doWeHaveAWinner == false || isADraw == false){
        if (field.victory(p1) == false){
            Turn(p1);
        }

        if (field.victory(p2) == false){
            Turn(p2);
        }

    }





    return 0; //ker je int main returna int
}

void Turn(Player player) {

    Player currentPlayer = player;
    bool done = false;

    //zanka se vrti dokler ni winnerja dokler ni drawa in da ni 9 turnov narejenih
    while (done == false && doWeHaveAWinner == false && isADraw == false && numberOfTurns < 9){
    int x, y;

    cout << "Your turn ";
    currentPlayer.printName();
    cout << endl;
    cout << askAboutXCord;
    cin >> x;
    if (x == 0 || x > 4)
    {
        cout << "X must be HIGHER than 0 and LOWER than 4 \n";
        cout << askAboutXCord;
        cin >> x;
    }

    cout << askAboutYCord;
    cin >> y;

    if (y == 0 || y > 4)
    {
        cout << "Y must be HIGHER than 0 and LOWER than 4 \n";
        cout << askAboutYCord;
        cin >> y;
    }

    if(field.emptySpace(x, y)){
        field.insertSymbol(x, y, currentPlayer.getSymbol());
        // najlazje je pogledat ce je draw,.
        numberOfTurns++;

        //cout << "dodoano " << x  << " " << y;
        field.ShowField();


        //if victory
        if (field.victory(currentPlayer))
        {
        currentPlayer.printName();
        cout << " won!" << endl;
        doWeHaveAWinner = true;
        break;
        }
        done = true;
    }
    //ce je narejenih 9 turnov in ni blo se winnerja, je zagotovvo draw.
    if (numberOfTurns == 9){
        isADraw == true;
        cout << "DRAW NOBODY WON!" << endl;

    }




    }



}
