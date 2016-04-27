// HW06_131044065_Furkan_Erdol
// testDynamicReversi.cpp
//
// Created on 10/12/2015 by Furkan Erdol
//
// Description
//
// Test file Reversi Game

#include <iostream>
#include "dynamicReversi.h"

using namespace std;
using namespace FurkanReversiGame;

int main(int argc, char** argv) {

    Reversi x;
    cout << "<><><><><><><>Reversi game x: " << endl << x << endl;
    cout << "*Living reversi games : " << Reversi::numberOfLivingReversiGames() << endl << endl;
    Reversi y(6);
    cout << "<><><><><><><>Reversi game y: " << endl << y << endl;
    cout << "*Living reversi games : " << Reversi::numberOfLivingReversiGames() << endl << endl;

    cout << "<><><><><><><>Play one step for game x" << endl;
    x.play();
    cout << x << endl;

    // Test assignment
    cout << "<><><><><><><>Test assignment    ( y = x )" << endl;
    y = x;
    cout << "<><><><><><><>Reversi game y: " << endl << y << endl;
    
    cout << "<><><><><><><>Play one step for game y" << endl;
    y.play();
    cout << y << endl;

    // Test copy constructor
    cout << "<><><><><><><>Test copy constructor    ( Reversi z(y) )" << endl;
    Reversi z(y);
    cout << "<><><><><><><>Reversi game z: " << endl << z << endl;
    cout << "*Living reversi games : " << Reversi::numberOfLivingReversiGames() << endl << endl;

    // Test resize function
    cout << "<><><><><><><>Test resize function" << endl;
    z.resizeBoard();
    cout << endl << "<><><><><><><>Reversi game z: " << endl << z << endl;

    // Test gameplay
    cout << "<><><><><><><>PLAY FULL GAME" << endl;
    z.playGame();

    return 0;
}

