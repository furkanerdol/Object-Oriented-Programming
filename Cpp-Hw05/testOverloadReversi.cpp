// HW05_131044065_Furkan_Erdol
// testOverloadReversi.cpp
//
// Created on 25/11/2015 by Furkan Erdol
//
// Description
//
// Test file overloaded Reversi Game

#include <iostream>
#include "overloadReversi.h"

using namespace std;

int main(int argc, char** argv) {

    cout << "################ SAMPLE FOR GAME CELLS" << endl;
    Cell gameCellOne(5, 8), gameCellTwo(6, 8);

    cout << "Game cell one" << endl << gameCellOne;
    cout << endl << "Game cell two" << endl << gameCellTwo << endl;

    if (gameCellOne != gameCellTwo)
        cout << endl << "Game cell one not equal to game cell two";
    if (gameCellOne < gameCellTwo)
        cout << endl << "Game cell one smaller than game cell two";

    ++gameCellOne;
    cout << endl << endl << "++gameCellOne =  " << gameCellOne;
    gameCellTwo--;
    cout << endl << "--gameCellTwo =  " << gameCellTwo;

    cout << endl << endl << "################ SAMPLE FOR REVERSI GAMES" << endl;
    Reversi reversiGame(4, 4);

    cout << "Reversi game is: 4x4" << endl << reversiGame;

    cout << endl << "*****Sample for ++ operator" << endl;
    ++reversiGame;
    reversiGame++;

    cout << endl << "*****Sample for -- operator" << endl << endl;
    --reversiGame;
    reversiGame--;

    cout << endl << "*****Sample for [] and () operators" << endl << endl;
    cout << "reversiGame[""B2""] is" << endl << reversiGame["B2"];
    cout << endl << "reversiGame(B, 3) is" << endl << reversiGame('B', 3);

    cout << endl << endl << "*****Sample for += operator" << endl << endl;
    cout << "Play reversiGame += reversiGame('C',4)" << endl;
    reversiGame += reversiGame('C', 4);


    return 0;
}

