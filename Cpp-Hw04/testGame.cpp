// HW04_131044065_Furkan_Erdol
// testGame.cpp
//
// Created on 24/11/2015 by Furkan Erdol
//
// Description
//
// Test file The Reversi Game    

#include <iostream>
#include "reversiGame.h"

using namespace std;

int main(int argc, char** argv) {
 
    cout << endl << "###################### SAMPLE OUTPUTS" << endl << endl; 
    Reversi gameOne, 
            gameTwo(4,4), 
            gameThree(6), 
            gameFour(10, 7), 
            gameFive(15, 6);
    
    cout << "gameOne   -> 8x8" << endl << "gameTwo   -> 4x4" << endl;
    cout << "gameThree -> 6x6" << endl << "gameFour  -> 10x7" << endl << "gameFive  -> 15x5";
    
    cout << endl << endl;
    cout << "Number of total living cells : " << Reversi::numberOfLivingCells();
    cout << endl << endl;
    
    cout << "####SAMPLE PLAY FOR GAMEONE" << endl << endl;
    gameOne.printGame();
    gameOne.play(Cell(2,3));
    gameOne.printGame();
    gameOne.play();
    gameOne.printGame();
    
    cout << endl << endl;
    cout << "Number of total living cells : " << Reversi::numberOfLivingCells();
    cout << endl << endl;
    
    cout << "####SAMPLE SAVE AND LOAD"<< endl << endl;
    cout << "GameThree" << endl << endl;
    gameThree.printGame();
    cout << endl << "Save gameOne and load it to gameThree" << endl << endl;
    gameOne.saveGame();
    gameThree.loadGame();
    cout << "New gameThree" << endl << endl;
    gameThree.printGame();
    
    cout << endl <<"####SAMPLE PLAY GAMEONE AND COMPARE GAMEFIVE " << endl << endl;
    gameOne.printGame();
    gameOne.play(Cell(3,2));
    gameOne.printGame();
    gameOne.play();
    gameOne.printGame();
    
    cout << endl << "GameFive" << endl << endl;
    gameFive.printGame();
    
    if(gameOne.compare(gameFive)==true)
        cout << endl << "GameOne is better for the user than gamFive" << endl;
    else
        cout << endl << "GameFive is better for the user than gamOne" << endl;
    
    cout << endl << endl;
    cout << "Number of total living cells : " << Reversi::numberOfLivingCells();
    cout << endl << endl;
    
    
    
    cout << endl << "###################### SAMPLE GAMEPLAY" << endl;
    Reversi sample;
    sample.playGame();


    return 0;
}

