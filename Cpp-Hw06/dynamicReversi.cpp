// HW06_131044065_Furkan_Erdol
// dynamicReversi.cpp
//
// Created on 10/12/2015 by Furkan Erdol
//
// Description
//
// Source file Reversi Game

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include "dynamicReversi.h"

using namespace std;


namespace FurkanReversiGame{

    int Reversi::livingCells = 0;
    int Reversi::livingReversiGames = 0;

    Cell::Cell(const int xValue, const int yValue, const char cellValue)
    : xCoordinate(xValue), yCoordinate(yValue), cellType(cellValue) {
        testInput();
    }

    inline void Cell::setX(const int xValue) {
        xCoordinate = xValue;
        testInput();
    }

    inline void Cell::setY(const int yValue) {
        yCoordinate = yValue;
        testInput();
    }

    inline void Cell::setCell(const char cellValue) {
        cellType = cellValue;
        testInput();
    }

    bool Cell::operator>(const Cell& other) const {
        if (getY() > other.getY())
            return true;
        else if (getY() == other.getY() && getX() > other.getX())
            return true;
        else
            return false;
    }

    bool Cell::operator<(const Cell& other) const {
        if (getY() < other.getY())
            return true;
        else if (getY() == other.getY() && getX() < other.getX())
            return true;
        else
            return false;
    }

    bool Cell::operator>=(const Cell& other) const {
        return getY() >= other.getY();
    }

    bool Cell::operator<=(const Cell& other) const {
        return getY() <= other.getY();
    }

    bool Cell::operator==(const Cell& other) const {
        return getY() == other.getY() && getX() == other.getX();
    }

    bool Cell::operator!=(const Cell& other) const {
        return getY() != other.getY() || getX() != other.getX();
    }

    const Cell Cell::operator++() {
        setX(getX() + 1);
        setY(getY() + 1);
        return Cell(getX(), getY(), getCell());
    }

    const Cell Cell::operator++(int value) {
        Cell oldCell(getX(), getY(), getCell());
        setX(getX() + 1);
        setY(getY() + 1);
        return oldCell;

    }

    const Cell Cell::operator--() {
        setX(getX() - 1);
        setY(getY() - 1);
        return Cell(getX(), getY(), getCell());

    }

    const Cell Cell::operator--(int value) {
        Cell oldCell(getX(), getY(), getCell());
        setX(getX() - 1);
        setY(getY() - 1);
        return oldCell;

    }

    ostream& operator<<(ostream& outputStream, const Cell& x) {
        outputStream << "X:" << x.getX() << "  Y:" << x.getY() << "  Cell: '" << x.getCell() << "'";
        return outputStream;
    }

    istream& operator>>(istream& inputStream, Cell& x) {
        int iTemp;
        char cTemp;

        cout << "X:";
        inputStream >> iTemp;
        x.setX(iTemp);
        cout << "Y:";
        inputStream >> iTemp;
        x.setY(iTemp);
        cout << "Cell:";
        inputStream >> cTemp;
        x.setCell(cTemp);

        return inputStream;
    }

    void Cell::testInput() const {
        if (getX() < 0 || getY() < 0 || (getCell() != computer && getCell() != user && getCell() != empty)) {
            cerr << "Invalid coordinate or cell type!";
            exit(1);
        }
    }

    ImportanceMove::ImportanceMove(const int xValue, const int yValue, const int importanceValue)
    : xCoordinate(xValue), yCoordinate(yValue), importance(importanceValue) {
        testInput();
    }

    inline void ImportanceMove::setX(const int xValue) {
        xCoordinate = xValue;
        testInput();
    }

    inline void ImportanceMove::setY(const int yValue) {
        yCoordinate = yValue;
        testInput();
    }

    inline void ImportanceMove::setImportance(const int importanceValue) {
        importance = importanceValue;
        testInput();
    }

    void ImportanceMove::testInput() const {
        if (getX() < 0 || getY() < 0 || getImportance() < 0) {
            cerr << "Invalid coordinate!";
            exit(1);
        }
    }

    Reversi::Reversi(const int vidthValue, const int heightValue)
    : width(vidthValue), height(heightValue) {
        testBoard();
        createBeginningBoard();
        ++livingReversiGames;

    }

    Reversi::Reversi(const int boardSize)
    : width(boardSize), height(boardSize) {
        testBoard();
        createBeginningBoard();
        ++livingReversiGames;

    }

    Reversi::Reversi()
    : width(8), height(8) {
        testBoard();
        createBeginningBoard();
        ++livingReversiGames;

    }

    Reversi::Reversi(const Reversi& other) {

        setHeight(other.getHeight());
        setWidth(other.getWidth());

        gameCells = new Cell[getHeight() * getWidth()];

        for (int i = 0; i < getHeight() * getWidth(); ++i) {
            gameCells[i].setX(other.gameCells[i].getX());
            gameCells[i].setY(other.gameCells[i].getY());
            gameCells[i].setCell(other.gameCells[i].getCell());

            if (gameCells[i].getCell() == user || gameCells[i].getCell() == computer)
                ++livingCells;
        }

        ++livingReversiGames;


    }

    // Creates begining game board

    void Reversi::createBeginningBoard() {

        gameCells = new Cell[getHeight() * getWidth()];
        int counter = 0;
        for (int i = 0; i < getHeight(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {

                gameCells[counter].setX(i);
                gameCells[counter].setY(j);
                gameCells[counter].setCell(empty);

                ++counter;
            }
        }


        gameCells[(getWidth() / 2 - 1)+(getWidth()*(getHeight() / 2 - 1))].setCell(computer);
        ++livingCells;
        gameCells[((getWidth() / 2 - 1)+(getWidth()*(getHeight() / 2 - 1))) + 1].setCell(user);
        ++livingCells;
        gameCells[(getWidth() / 2 - 1)+(getWidth()*(getHeight() / 2))].setCell(user);
        ++livingCells;
        gameCells[((getWidth() / 2 - 1)+(getWidth()*(getHeight() / 2))) + 1].setCell(computer);
        ++livingCells;




    }

    void Reversi::testBoard() const {
        if (getWidth() < 1 || getHeight() < 1) {
            cerr << "Invalid game board!";
            exit(1);
        }
    }

    //Prints the screen game board

    void Reversi::printGame() const {

        int leftEdge = 1;
        char topEdge = 'A';

        cout << "  ";
        for (int i = 0; i < getWidth(); ++i)
            cout << topEdge++;

        for (int i = 0; i < getWidth() * getHeight(); ++i) {

            if (gameCells[i].getY() == 0) {
                cout << endl;

                if (leftEdge < 10)
                    cout << " ";

                cout << leftEdge++;
            }

            cout << gameCells[i].getCell();
        }

        cout << endl;
    }

    //Destructer for killing living cells

    Reversi::~Reversi() {

        delete [] gameCells;

        for (int i = 0; i < getHeight() * getWidth(); ++i)
            if (gameCells[i].getCell() == user || gameCells[i].getCell() == computer)
                --livingCells;

        --livingReversiGames;
    }

    inline void Reversi::setWidth(const int widthValue) {
        width = widthValue;
        testBoard();
    }

    inline void Reversi::setHeight(const int heightValue) {
        height = heightValue;
        testBoard();
    }

    const Reversi Reversi::operator++() {
        play();
        printGame();

        return Reversi(getWidth(), getHeight());
    }

    const Reversi Reversi::operator++(int value) {
        Reversi oldGame(getWidth(), getHeight());
        play();
        printGame();

        return oldGame;
    }

    
    Cell Reversi::operator[](const string position) const {
        int xCoordinate, yCoordinate;

        xCoordinate = position[1] - 49;

        yCoordinate = position[0];
        yCoordinate -= 65;

        if ((getHeight() * getWidth())> ((getWidth() * xCoordinate) + yCoordinate))
            return gameCells[(getWidth() * xCoordinate) + yCoordinate];
        else
            return Cell(-1000, -1000);

    }

    Cell Reversi::operator()(const char yCoor, const int xCoor) const {
        int xCoordinate, yCoordinate;

        xCoordinate = xCoor - 1;

        yCoordinate = yCoor;
        yCoordinate -= 65;

        if ((getHeight() * getWidth())> ((getWidth() * xCoordinate) + yCoordinate))
            return gameCells[(getWidth() * xCoordinate) + yCoordinate];
        else
            return Cell(-1000, -1000);

    }

    ostream& operator<<(ostream &outputStream, const Reversi &x) {
        x.printGame();
        return outputStream;
    }

    istream& operator>>(istream &inputStream, Reversi &x) {
        x.inputBoard();
        return inputStream;
    }

    void Reversi::operator+=(const Cell& x) {
        play(x);
        printGame();
    }

    Reversi& Reversi::operator=(const Reversi& rtSide) {
        if (this == &rtSide)
            return *this;
        else {

            for (int i = 0; i < getHeight() * getWidth(); ++i)
                if (gameCells[i].getCell() == user || gameCells[i].getCell() == computer)
                    --livingCells;

            delete[] gameCells;

            setHeight(rtSide.getHeight());
            setWidth(rtSide.getWidth());

            gameCells = new Cell[getHeight() * getWidth()];

            for (int i = 0; i < getHeight() * getWidth(); ++i) {
                gameCells[i].setX(rtSide.gameCells[i].getX());
                gameCells[i].setY(rtSide.gameCells[i].getY());
                gameCells[i].setCell(rtSide.gameCells[i].getCell());

                if (gameCells[i].getCell() == user || gameCells[i].getCell() == computer)
                    ++livingCells;
            }

            return *this;
        }
    }

    void Reversi::inputBoard() {
        int widthValue;
        int heightValue;

        cout << "Please enter width of game board : ";
        cin >> widthValue;

        cout << "Please enter height of game board : ";
        cin >> heightValue;

        setWidth(widthValue);
        setHeight(heightValue);

        livingCells -= 4;
        delete [] gameCells;
        createBeginningBoard();
    }

    //Saves game board to txt file

    void Reversi::saveGame() const {

        ofstream saveFile;

        saveFile.open("reversi.txt");
        if (saveFile.is_open() == false) {
            cerr << "File couldn't open..!";
            exit(1);
        }

        for (int i = 0; i < getHeight() * getWidth(); ++i) {

            saveFile << gameCells[i].getCell();

            if (gameCells[i].getY() == getWidth() - 1)
                saveFile << endl;
        }

        saveFile.close();

    }

    //Loads game board from txt file

    void Reversi::loadGame() {

        ifstream loadFile;
        string line;
        char temp;
        Cell * newGameCells;

        int widthCounter = 0;
        int heightCounter = 0;

        loadFile.open("reversi.txt");
        if (loadFile.is_open() == false) {
            cerr << "File couldn't open..!";
            exit(1);
        }

        //Calculates width and height of game board
        while (!loadFile.eof()) {

            getline(loadFile, line);

            if (heightCounter == 0)
                widthCounter = line.size();

            ++heightCounter;
        }

        --heightCounter; //EOF

        loadFile.close();

        loadFile.open("reversi.txt");
        if (loadFile.is_open() == false) {
            cerr << "File couldn't open..!";
            exit(1);
        }

        newGameCells = new Cell[heightCounter * widthCounter];

        int counter = 0;
        // Reads cells characters
        while (!loadFile.eof()) {
            loadFile>>temp;
            newGameCells[counter++].setCell(temp);
        }

        // Assigns coordinate values to cells
        counter = 0;
        for (int i = 0; i < widthCounter; ++i) {
            for (int j = 0; j < heightCounter; ++j) {
                newGameCells[counter].setX(i);
                newGameCells[counter].setY(j);
                counter++;
            }
        }

        // Killing living cells
        for (int i = 0; i < getHeight() * getWidth(); ++i)
            if (gameCells[i].getCell() == user || gameCells[i].getCell() == computer)
                --livingCells;

        setWidth(widthCounter);
        setHeight(heightCounter);
        delete [] gameCells;
        gameCells = newGameCells;

        // Counts living cells
        for (int i = 0; i < getHeight() * getWidth(); ++i)
            if (gameCells[i].getCell() == user || gameCells[i].getCell() == computer)
                ++livingCells;

    }

    //Plays user single game step

    void Reversi::play(const Cell& userCell) {

        if (checkLegal(userCell, user) == true) {

            makingMove(userCell, user);
            gameCells[(userCell.getX() * getWidth()) + userCell.getY()].setCell(user);
            //save yap
            ++livingCells;
            // Prints the screen players move
            char move;
            move = userCell.getY() + 65;
            cout << endl << "###### After user move";
            cout << "   (User move >> " << userCell.getX() + 1 << move << ")" << endl;

        } else
            cout << ">>> This move is not legal!" << endl;

    }

    //Plays computer single game step

    void Reversi::play() {
        if (controlLegalMove(computer) == true) {
            Cell bestMove = findBestMove();
            makingMove(bestMove, computer);
            gameCells[(bestMove.getX() * getWidth()) + bestMove.getY()].setCell(computer);
            //save yap
            ++livingCells;
            // Prints the screen computers move
            char move;
            move = bestMove.getY() + 65;
            cout << endl << "###### After computer move";
            cout << "   (Computer move >> " << bestMove.getX() + 1 << move << ")" << endl;
        }
    }

    // Checks legal moves on coordinate of cell for user or computer according to input
    // If cell coordinate is legal this function returns 1 otherwise returns 0

    bool Reversi::checkLegal(Cell singleCell, char player) const {

        int legal = false;
        int X, Y; // To go forward in loops

        char player_two; // If input player is 'O' player2 is computer
        // If input player is 'X' player2 is user

        // Player determination
        if (player == 'O')
            player_two = 'X';
        else if (player == 'X')
            player_two = 'O';


        // Checks around the cell according to whether legal move
        if (singleCell.getCell() == empty) {


            // Horizontally to the right
            if (player_two == gameCells[(singleCell.getX() * getWidth())+(singleCell.getY() + 1)].getCell())
                for (Y = singleCell.getY() + 2; Y < getWidth() && gameCells[(singleCell.getX() * getWidth()) + Y].getCell() != empty; ++Y)
                    if (player == gameCells[(singleCell.getX() * getWidth()) + Y].getCell())
                        legal = true;

            // Horizontally to the left
            if (singleCell.getY() > 0)
                if (player_two == gameCells[(singleCell.getX() * getWidth())+(singleCell.getY() - 1)].getCell())
                    for (Y = singleCell.getY() - 2; Y >= 0 && gameCells[(singleCell.getX() * getWidth()) + Y].getCell() != empty; --Y)
                        if (player == gameCells[(singleCell.getX() * getWidth()) + Y].getCell())
                            legal = true;

            // Vertically to the down        
            if (player_two == gameCells[((singleCell.getX() + 1) * getWidth())+(singleCell.getY())].getCell())
                for (X = singleCell.getX() + 2; X < getHeight() && gameCells[(X * getWidth())+(singleCell.getY())].getCell() != empty; ++X)
                    if (player == gameCells[(X * getWidth())+(singleCell.getY())].getCell())
                        legal = true;

            // Vertically to the up        
            if (singleCell.getX() > 0)
                if (player_two == gameCells[((singleCell.getX() - 1) * getWidth())+(singleCell.getY())].getCell())
                    for (X = singleCell.getX() - 2; X >= 0 && gameCells[(X * getWidth())+(singleCell.getY())].getCell() != empty; --X)
                        if (player == gameCells[(X * getWidth())+(singleCell.getY())].getCell())
                            legal = true;

            // Upper right cross
            if (singleCell.getX() > 0)
                if (player_two == gameCells[((singleCell.getX() - 1) * getWidth())+(singleCell.getY() + 1)].getCell())
                    for (X = singleCell.getX() - 2, Y = singleCell.getY() + 2; X >= 0 && Y < getWidth() && gameCells[(X * getWidth()) + Y].getCell() != empty; --X, ++Y)
                        if (player == gameCells[(X * getWidth()) + Y].getCell())
                            legal = true;

            // Bottom right cross
            if (singleCell.getY() > 0)
                if (player_two == gameCells[((singleCell.getX() + 1) * getWidth())+(singleCell.getY() - 1)].getCell())
                    for (X = singleCell.getX() + 2, Y = singleCell.getY() - 2; X < getHeight() && Y >= 0 && gameCells[(X * getWidth()) + Y].getCell() != empty; ++X, --Y)
                        if (player == gameCells[(X * getWidth()) + Y].getCell())
                            legal = true;

            // Upper left cross
            if (singleCell.getX() > 0 && singleCell.getY() > 0)
                if (player_two == gameCells[((singleCell.getX() - 1) * getWidth())+(singleCell.getY() - 1)].getCell())
                    for (X = singleCell.getX() - 2, Y = singleCell.getY() - 2; X >= 0 && Y >= 0 && gameCells[(X * getWidth()) + Y].getCell() != empty; --X, --Y)
                        if (player == gameCells[(X * getWidth()) + Y].getCell())
                            legal = true;

            // Bottom left cross        
            if (player_two == gameCells[((singleCell.getX() + 1) * getWidth())+(singleCell.getY() + 1)].getCell())
                for (X = singleCell.getX() + 2, Y = singleCell.getY() + 2; X < getHeight() && Y < getWidth() && gameCells[(X * getWidth()) + Y].getCell() != empty; ++X, ++Y)
                    if (player == gameCells[(X * getWidth()) + Y].getCell())
                        legal = true;

        }

        return legal;
    }

    // Takes cell and plays according to player type

    void Reversi::makingMove(Cell x, char player) {

        int X, Y, X2, Y2; // X and Y to go forward in loops
        // X2 and Y2 to go backwards in loops

        char player_two; // If input player is 'O' player2 is computer
        // If inout player is 'X' player2 is user

        // Player determination
        if (player == 'O')
            player_two = 'X';
        else if (player == 'X')
            player_two = 'O';


        // Horizontally to the right
        if (player_two == gameCells[(x.getX() * getWidth())+(x.getY() + 1)].getCell())
            for (Y = x.getY() + 2; Y < getWidth() && gameCells[(x.getX() * getWidth()) + Y].getCell() != empty; ++Y)
                if (player == gameCells[(x.getX() * getWidth()) + Y].getCell()) {
                    for (Y2 = Y - 1; Y2 > x.getY(); --Y2)
                        gameCells[(x.getX() * getWidth()) + Y2].setCell(player);
                    Y = getWidth();
                }

        // Horizontally to the left
        if (x.getY() > 0)
            if (player_two == gameCells[(x.getX() * getWidth())+(x.getY() - 1)].getCell())
                for (Y = x.getY() - 2; Y >= 0 && gameCells[(x.getX() * getWidth()) + Y].getCell() != empty; --Y)
                    if (player == gameCells[(x.getX() * getWidth()) + Y].getCell()) {
                        for (Y2 = Y + 1; Y2 < x.getY(); ++Y2)
                            gameCells[(x.getX() * getWidth()) + Y2].setCell(player);
                        Y = -1;
                    }

        // Vertically to the down        
        if (player_two == gameCells[((x.getX() + 1) * getWidth())+(x.getY())].getCell())
            for (X = x.getX() + 2; X < getHeight() && gameCells[(X * getWidth())+(x.getY())].getCell() != empty; ++X)
                if (player == gameCells[(X * getWidth()) + x.getY()].getCell()) {
                    for (X2 = X - 1; X2 > x.getX(); --X2)
                        gameCells[(X2 * getWidth()) + x.getY()].setCell(player);
                    X = getHeight();
                }

        // Vertically to the up
        if (x.getX() > 0)
            if (player_two == gameCells[((x.getX() - 1) * getWidth())+(x.getY())].getCell())
                for (X = x.getX() - 2; X >= 0 && gameCells[(X * getWidth())+(x.getY())].getCell() != empty; --X)
                    if (player == gameCells[(X * getWidth()) + x.getY()].getCell()) {
                        for (X2 = X + 1; X2 < x.getX(); ++X2)
                            gameCells[(X2 * getWidth()) + x.getY()].setCell(player);
                        X = -1;
                    }

        // Upper right cross
        if (x.getX() > 0)
            if (player_two == gameCells[((x.getX() - 1) * getWidth())+(x.getY() + 1)].getCell())
                for (X = x.getX() - 2, Y = x.getY() + 2; X >= 0 && Y < getWidth() && gameCells[(X * getWidth()) + Y].getCell() != empty; --X, ++Y)
                    if (player == gameCells[(X * getWidth()) + Y].getCell()) {
                        for (X2 = X + 1, Y2 = Y - 1; X2 < x.getX() && Y2 > x.getY(); ++X2, --Y2)
                            gameCells[(X2 * getWidth()) + Y2].setCell(player);
                        Y = getWidth();
                    }

        // Bottom right cross
        if (x.getY() > 0)
            if (player_two == gameCells[((x.getX() + 1) * getWidth())+(x.getY() - 1)].getCell())
                for (X = x.getX() + 2, Y = x.getY() - 2; X < getHeight() && Y >= 0 && gameCells[(X * getWidth()) + Y].getCell() != empty; ++X, --Y)
                    if (player == gameCells[(X * getWidth()) + Y].getCell()) {
                        for (X2 = X - 1, Y2 = Y + 1; X2 > x.getX() && Y2 < x.getY(); --X2, ++Y2)
                            gameCells[(X2 * getWidth()) + Y2].setCell(player);
                        X = getHeight();
                    }

        // Upper left cross
        if (x.getX() > 0 && x.getY() > 0)
            if (player_two == gameCells[((x.getX() - 1) * getWidth())+(x.getY() - 1)].getCell())
                for (X = x.getX() - 2, Y = x.getY() - 2; X >= 0 && Y >= 0 && gameCells[(X * getWidth()) + Y].getCell() != empty; --X, --Y)
                    if (player == gameCells[(X * getWidth()) + Y].getCell()) {
                        for (X2 = X + 1, Y2 = Y + 1; X2 < x.getX() && Y2 < x.getY(); ++X2, ++Y2)
                            gameCells[(X2 * getWidth()) + Y2].setCell(player);
                        X = -1;
                    }

        // Bottom left cross        
        if (player_two == gameCells[((x.getX() + 1) * getWidth())+(x.getY() + 1)].getCell())
            for (X = x.getX() + 2, Y = x.getY() + 2; X < getHeight() && Y < getWidth() && gameCells[(X * getWidth()) + Y].getCell() != empty; ++X, ++Y)
                if (player == gameCells[(X * getWidth()) + Y].getCell()) {
                    for (X2 = X - 1, Y2 = Y - 1; X2 > x.getX() && Y2 > x.getY(); --X2, --Y2)
                        gameCells[(X2 * getWidth()) + Y2].setCell(player);
                    X = -1;
                }

    }

    // Finds best computer's move on game board and returns best moves cell

    Cell Reversi::findBestMove() const {

        int X, Y; // X and Y to go forward in loops
        int counter = 0; // Number of cell
        vector <ImportanceMove> saves;


        for (int i = 0; i < getHeight() * getWidth(); ++i) {

            if (checkLegal(gameCells[i], computer) == true) {

                Cell checkCell = gameCells[i];

                // Horizontally to the right
                if (user == gameCells[(checkCell.getX() * getWidth())+(checkCell.getY() + 1)].getCell())
                    for (Y = checkCell.getY() + 1; Y < getWidth()
                            && gameCells[(checkCell.getX() * getWidth()) + Y].getCell() == user
                            && gameCells[(checkCell.getX() * getWidth())+(Y + 1)].getCell() != empty; ++Y)
                        ++counter;

                // Horizontally to the left
                if (checkCell.getY() > 0)
                    if (user == gameCells[(checkCell.getX() * getWidth())+(checkCell.getY() - 1)].getCell())
                        for (Y = checkCell.getY() - 1; Y > 0
                                && gameCells[(checkCell.getX() * getWidth()) + Y].getCell() == user
                                && gameCells[(checkCell.getX() * getWidth())+(Y - 1)].getCell() != empty; --Y)
                            ++counter;

                // Vertically to the right        
                if (user == gameCells[((checkCell.getX() + 1) * getWidth())+(checkCell.getY())].getCell())
                    for (X = checkCell.getX() + 1; X < getHeight()
                            && gameCells[(X * getWidth())+(checkCell.getY())].getCell() == user
                            && gameCells[((X + 1) * getWidth())+(checkCell.getY())].getCell() != empty; ++X)
                        ++counter;

                // Vertically to the left 
                if (checkCell.getX() > 0)
                    if (user == gameCells[((checkCell.getX() - 1) * getWidth())+(checkCell.getY())].getCell())
                        for (X = checkCell.getX() - 1; X > 0
                                && gameCells[(X * getWidth())+(checkCell.getY())].getCell() == user
                                && gameCells[((X - 1) * getWidth())+(checkCell.getY())].getCell() != empty; --X)
                            ++counter;

                // Upper right cross
                if (checkCell.getX() > 0)
                    if (user == gameCells[((checkCell.getX() - 1) * getWidth())+(checkCell.getY() + 1)].getCell())
                        for (X = checkCell.getX() - 1, Y = checkCell.getY() + 1; X > 0 && Y < getWidth()
                                && gameCells[(X * getWidth()) + Y].getCell() == user
                                && gameCells[((X - 1) * getWidth())+(Y + 1)].getCell() != empty; --X, ++Y)
                            ++counter;

                // Bottom right cross 
                if (checkCell.getY() > 0)
                    if (user == gameCells[((checkCell.getX() + 1) * getWidth())+(checkCell.getY() - 1)].getCell())
                        for (X = checkCell.getX() + 1, Y = checkCell.getY() - 1; X < getHeight() && Y > 0
                                && gameCells[(X * getWidth()) + Y].getCell() == user
                                && gameCells[((X + 1) * getWidth())+(Y - 1)].getCell() != empty; ++X, --Y)
                            ++counter;

                // Upper left cross
                if (checkCell.getX() > 0 && checkCell.getX() > 0)
                    if (user == gameCells[((checkCell.getX() - 1) * getWidth())+(checkCell.getY() - 1)].getCell())
                        for (X = checkCell.getX() - 1, Y = checkCell.getY() - 1; X > 0 && Y > 0
                                && gameCells[(X * getWidth()) + Y].getCell() == user
                                && gameCells[((X - 1) * getWidth())+(Y - 1)].getCell() != empty; --X, --Y)
                            ++counter;

                // Bottom left cross        
                if (user == gameCells[((checkCell.getX() + 1) * getWidth())+(checkCell.getY() + 1)].getCell())
                    for (X = checkCell.getX() + 1, Y = checkCell.getY() + 1; X < getHeight() && Y < getWidth()
                            && gameCells[(X * getWidth()) + Y].getCell() == user
                            && gameCells[((X + 1) * getWidth())+(Y + 1)].getCell() != empty; ++X, ++Y)
                        ++counter;

                // Records moves
                ImportanceMove move;

                move.setX(gameCells[i].getX());
                move.setY(gameCells[i].getY());
                move.setImportance(counter);

                saves.push_back(move);

                counter = 0;

            }

        }

        // Finds best move
        Cell bestCell;

        bestCell.setX(saves[findBestImportanceMove(saves)].getX());
        bestCell.setY(saves[findBestImportanceMove(saves)].getY());

        return bestCell;

    }

    // Takes ImportanceMove vector
    // Finds best importance move in vector and returns its index

    int Reversi::findBestImportanceMove(vector<ImportanceMove> saves) const {

        int maxNumber = 0;
        int maxNumbeLocation = 0;

        for (int i = 0; i < saves.size(); ++i)
            if (saves[i].getImportance() > maxNumber) {
                maxNumber = saves[i].getImportance();
                maxNumbeLocation = i;
            } else if (saves[i].getImportance() == maxNumber) {
                srand(time(0));
                if (rand() % 10 >= 5)
                    maxNumbeLocation = i;
            }

        return maxNumbeLocation;

    }

    // Checks whether the legal moves. If found legal move returns 1

    bool Reversi::controlLegalMove(char player) const {

        int legalMove = false;

        for (int i = 0; i < getHeight() * getWidth(); ++i)
            if (checkLegal(gameCells[i], player) == 1)
                legalMove = true;

        return legalMove;

    }

    // If no legal move for computer or user returns 0 otherwise returns 1

    bool Reversi::controlEndGame() const {

        int gameStatus = true;

        if (controlLegalMove(user) == false && controlLegalMove(computer) == false)
            gameStatus = false;

        return gameStatus;

    }

    //Plays all game

    void Reversi::playGame() {

        int widthValue;
        int heightValue;

        cout << endl << "####### WELCOME THE REVERSI GAME #######" << endl << endl;
        cout << "-Required by the rules of the game, you can not play reversi game less than four cells";
        cout << endl << "-You can enter the size of the board as you want";
        cout << endl << "-Recommended game board is 8x8" << endl << endl;

        cout << "Please enter width of game board : ";
        cin >> widthValue;

        cout << "Please enter height of game board : ";
        cin >> heightValue;

        while (!cin || widthValue < 1 || heightValue < 1 || widthValue * heightValue < 4) {
            cout << endl << "#####Invalid game board please try again" << endl << endl;
            cin.clear();
            cin.ignore(512, '\n');

            cout << "Please enter width of game board : ";
            cin >> widthValue;
            cout << "Please enter height of game board : ";
            cin >> heightValue;

        }

        setWidth(widthValue);
        setHeight(heightValue);

        livingCells -= 4;
        delete[] gameCells;
        createBeginningBoard();

        printGame();

        int xCoor;
        int yCoor;
        char tempInput;
        int status = 0;

        while (controlEndGame() != false) {

            if (controlLegalMove(user) == true) {

                do {
                    cout << endl << "Please enter your move ( 1A, 3D, 4B etc ) : ";
                    cin.clear();
                    cin.ignore(512, '\n');
                    cin >> xCoor >> tempInput;


                    --xCoor;
                    yCoor = tempInput;
                    yCoor -= 65;

                    if (xCoor >= 0 && yCoor >= 0 && checkLegal(gameCells[(getWidth() * xCoor) + yCoor], user) == true) {
                        play(gameCells[(getWidth() * xCoor) + yCoor]);
                        status = 1;
                    } else
                        cout << endl << "###This move is not legal, please try again!" << endl;

                } while (status == 0 || !cin);

                status = 0;

                printGame();

            }

            if (controlLegalMove(computer) == true) {
                play();

                printGame();
            }

        }

        endGame();

    }

    //Returns number of living cells

    int Reversi::numberOfLivingCells() {
        return livingCells;
    }

    int Reversi::numberOfLivingReversiGames() {
        return livingReversiGames;
    }

    //Compares two reversi games
    //If first game is better for the user returns true, otherwise returns false

    bool Reversi::compare(const Reversi &other) const {

        int counterUser = 0;
        int counterComputer = 0;
        for (int i = 0; i < getHeight() * getWidth(); ++i) {
            if (gameCells[i].getCell() == user)
                ++counterUser;
            else if (gameCells[i].getCell() == computer)
                ++counterComputer;
        }

        int counterUserOther = 0;
        int counterComputerOther = 0;
        for (int i = 0; i < (other.getHeight() * other.getWidth()); ++i) {
            if (other.gameCells[i].getCell() == user)
                ++counterUserOther;
            else if (other.gameCells[i].getCell() == computer)
                ++counterComputerOther;
        }

        if ((counterUser - counterComputer)>(counterUserOther - counterComputerOther))
            return true;
        else
            return false;

    }

    // Calculates user and computer cells. Prints the screen who won and number of cells

    void Reversi::endGame() const {

        int userCounter = 0; // Number of users cells
        int comCounter = 0; // Number of computers cells

        for (int i = 0; i < getHeight() * getWidth(); ++i)
            if (gameCells[i].getCell() == user)
                ++userCounter;
            else if (gameCells[i].getCell() == computer)
                ++comCounter;

        // End game message 
        if (userCounter > comCounter)
            cout << endl << "####### USER WON! #######";
        else if (comCounter > userCounter)
            cout << endl << "####### COMPUTER WON! #######";
        else if (comCounter == userCounter)
            cout << endl << "####### DRAW! #######";

        cout << endl << endl << "User: " << userCounter;
        cout << endl << "Computer: " << comCounter << endl << endl;


    }

    //To resize the board. When the board is resized, the game starts from the beginning

    void Reversi::resizeBoard() {

        cout << ">>>>>>>>Game is resizing..." << endl;
        inputBoard();
    }

}
