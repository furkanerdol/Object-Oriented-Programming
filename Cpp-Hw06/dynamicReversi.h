// HW06_131044065_Furkan_Erdol
// dynamicReversi.h
//
// Created on 10/12/2015 by Furkan Erdol
//
// Description
//
// Header file Reversi Game

#ifndef DYNAMICREVERSI_H
#define	DYNAMICREVERSI_H

#include <iostream>
#include <vector>

using namespace std;

namespace FurkanReversiGame{

    // This class represent the single game cell

    class Cell {
    public:
        Cell(const int xValue = 0, const int yValue = 0, const char cellValue = empty);

        int getX() const {return xCoordinate;}
        int getY() const {return yCoordinate;}
        char getCell() const {return cellType;}

        void setX(const int xValue);
        void setY(const int yValue);
        void setCell(const char cellValue);

        // Overloads for comparing two Cells. One Cell object is smaller than the
        // other if the Y components is smaller. If Y components are equal, 
        // then check the X component
        bool operator>(const Cell &other) const;
        bool operator<(const Cell &other) const;
        bool operator>=(const Cell &other) const;
        bool operator<=(const Cell &other) const;
        bool operator==(const Cell &other) const;
        bool operator!=(const Cell &other) const;
        // Operators ++ and - - that increment and decrement the X and Y components by one
        const Cell operator++();
        const Cell operator++(int value);
        const Cell operator--();
        const Cell operator--(int value);
        friend ostream& operator<<(ostream& outputStream, const Cell& gameCell);
        friend istream& operator>>(istream& inputStream, Cell& gameCell);

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

        int getX() const {return xCoordinate;}
        int getY() const {return yCoordinate;}
        int getImportance() const {return importance;}

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
        Reversi(const Reversi& other); 

        int getWidth() const {return width;}
        int getHeight() const {return height;}

        void setWidth(const int widthValue);
        void setHeight(const int heightValue);

        //Prints the screen game board
        void printGame() const;

        //Takes inputs from user. Used as a resizing function
        void inputBoard();

        //Saves game board to txt file
        void saveGame() const;

        //Loads game board from txt file
        void loadGame();

        //Plays computer single game step
        void play();

        //Plays user single game step
        void play(const Cell& user);

        //Plays all game
        void playGame();

        //To resize the board. When the board is resized, the game starts from the beginning
        void resizeBoard();

        //Returns number of living cells
        static int numberOfLivingCells();

        //Returns number of living reversi games
        static int numberOfLivingReversiGames();

        //Compares two reversi games
        //If first game is better for the user returns true, otherwise returns false
        bool compare(const Reversi &other) const;

        // Operator++ (both posfix and prefix) will advance the game by one step 
        // for computer. It will return the reversi game
        const Reversi operator++();
        const Reversi operator++(int value);

        // [] operator such that if g is a Reversi object, g[“A5”] will return the Cell at row
        Cell operator[](const string position) const;
        Cell operator()(const char yCoor, const int xCoor) const;

        // Operator+= that takes another a Cell object and plays the game for the user.
        void operator+=(const Cell& gameCell);

        friend ostream& operator<<(ostream &outputStream, const Reversi &reversiGame);
        friend istream& operator>>(istream &inputStream, Reversi &reversiGame);

        // Assignmet operator
        Reversi& operator =(const Reversi& rtSide);

        //For killing living reversi games and killing living cells
        //Cleans allocated memory
        ~Reversi();

    private:
        int width; // Width of game board
        int height; // Height of game board
        Cell * gameCells; // This pointer holds game cells
        static int livingCells;
        static int livingReversiGames;
        static const char user = 'O';
        static const char computer = 'X';
        static const char empty = '.';

        void testBoard() const;

        // Creates begining game board
        void createBeginningBoard();

        // Checks legal moves on coordinate of cell for user or computer according to input
        // If cell coordinate is legal this function returns 1 otherwise returns 0
        bool checkLegal(const Cell checkCell, char player) const;

        // Takes cell and plays according to player type
        void makingMove(const Cell playCell, const char player);

        // Finds best computer's move on game board and returns best moves cell
        Cell findBestMove() const;

        // Takes ImportanceMove vector
        // Finds best importance move in vector and returns its index
        int findBestImportanceMove(const vector<ImportanceMove> saves) const;

        // Checks whether the legal moves. If found legal move returns 1
        bool controlLegalMove(const char player) const;

        // If no legal move for computer or user returns 0 otherwise returns 1
        bool controlEndGame() const;

        // Calculates user and computer cells. Prints the screen who won and number of cells
        void endGame() const;
    };

}

#endif	/* DYNAMICREVERSI_H */

