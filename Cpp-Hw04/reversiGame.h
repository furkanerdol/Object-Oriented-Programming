// HW04_131044065_Furkan_Erdol
// reversiGame.h
//
// Created on 24/11/2015 by Furkan Erdol
//
// Description
//
// Header file The Reversi Game

#ifndef REVERSIGAME_H
#define	REVERSIGAME_H

#include <iostream>
#include <vector>

using namespace std;

// This class represent the single game cell

class Cell {
public:
    Cell(const int xValue = 0, const int yValue = 0, const char cellValue = empty);

    int getX() const {
        return xCoordinate;
    }

    int getY() const {
        return yCoordinate;
    }

    char getCell() const {
        return cellType;
    }

    void setX(const int xValue);
    void setY(const int yValue);
    void setCell(const char cellValue);

private:
    int xCoordinate;
    int yCoordinate;
    char cellType;
    static const char user = 'O';
    static const char computer = 'X';
    static const char empty = '.';
    void testInput() const;

};

// This class represent the single game cell and holds its importance

class ImportanceMove {
public:
    ImportanceMove(const int xValue = 0, const int yValue = 0, const int importanceValue = 0);

    int getX() const {
        return xCoordinate;
    }

    int getY() const {
        return yCoordinate;
    }

    int getImportance() const {
        return importance;
    }

    void setX(const int xValue);
    void setY(const int yValue);
    void setImportance(const int importanceValue);

private:
    int xCoordinate;
    int yCoordinate;
    int importance;
    void testInput() const;
};

class Reversi {
public:
    Reversi(const int vidthValue, const int heightValue);
    Reversi(const int boardSize);
    Reversi();

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    void setWidth(const int widthValue);
    void setHeight(const int heightValue);

    //Prints the screen game board
    void printGame() const;

    //Saves game board to txt file
    void saveGame() const;

    //Loads game board from txt file
    void loadGame();

    //Plays computer single game step
    void play();

    //Plays user single game step
    void play(const Cell user);

    //Plays all game
    void playGame();

    //Returns number of living cells
    static int numberOfLivingCells();

    //Compares two reversi games
    //If first game is better for the user returns true, otherwise returns false
    bool compare(const Reversi &other) const;

    //Destructer for killing living cells
    ~Reversi();

private:
    int width; // Width of game board
    int height; // Height of game board
    vector < vector<Cell> > gameCells; // Vector of vector holds game cells
    static int livingCells;
    static const char user = 'O';
    static const char computer = 'X';
    static const char empty = '.';

    void testBoard() const;

    // Creates begining game board
    void createBeginningBoard();

    // Checks legal moves on coordinate of cell for user or computer according to input
    // If cell coordinate is legal this function returns 1 otherwise returns 0
    int checkLegal(const Cell checkCell, char player) const;

    // Takes cell and plays according to player type
    void makingMove(const Cell playCell, const char player);

    // Finds best computer's move on game board and returns best moves cell
    Cell findBestMove() const;

    // Takes ImportanceMove vector
    // Finds best importance move in vector and returns its index
    int findBestImportanceMove(const vector<ImportanceMove> saves) const;

    // Checks whether the legal moves. If found legal move returns 1
    int controlLegalMove(const char player) const;

    // If no legal move for computer or user returns 0 otherwise returns 1
    int controlEndGame() const;

    // Calculates user and computer cells. Prints the screen who won and number of cells
    void endGame() const;

};

#endif	/* REVERSIGAME_H */

