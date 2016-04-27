// HW01_131044065_Furkan_Erdol
// reversi.cpp
//
// Created on 02/10/2015 by Furkan Erdol
//
// Description
//
// The Reversi Game    

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int create_beginning_board(char board[20][20]);
void print_board(char board[20][20], int boardSize);
int check_legal(char board[20][20], int boardSize, int x, int y, char player);
void making_move(char board[20][20], int boardSize, int x, int y, char player);
void users_move(char board[20][20], int boardSize);
void find_best_move(char board[20][20], int boardSize, int *x, int *y);
int max_number(int arr[], int size);
void computers_move(char board[20][20], int boardSize);
int control_legal_move(char board[20][20], int boardSize, char player);
int find_location(char arr[], int size, char a);
void end_game(char board[20][20], int boardSize);

int main(int argc, char** argv) {

    char board[20][20]; // Game board
    int boardSize; // Size of game board
    int status = 1; // For checking legal move

    // Creates begining board    
    boardSize = create_beginning_board(board);

    // Prints the screen begining board 
    print_board(board, boardSize);
    cout << endl;

    // Check legal move for user and computer and if it is, the game will be continued
    while (status == 1) {
        status = 0;

        if (control_legal_move(board, boardSize, 'O') == 1) {
            users_move(board, boardSize);
            cout << "###### After user move" << endl << endl;
            print_board(board, boardSize);
            status = 1;

        }

        if (control_legal_move(board, boardSize, 'X') == 1) {
            cout << endl << "###### After computer move";
            computers_move(board, boardSize);
            print_board(board, boardSize);
            status = 1;

        }

    }

    // Calculates who won, user and computer cells and writes end game messages 
    end_game(board, boardSize);

    return 0;
}


// Takes a two dimensional array and fills it according to boardsize 
// Creates begining game board

int create_beginning_board(char board[20][20]) {
    int boardSize;

    cout << endl << "####### WELCOME THE REVERSI GAME #######" << endl;

    cout << endl << "Please enter board size: ";
    cin >> boardSize;


    while (!cin || boardSize != 4 && boardSize != 6 && boardSize != 8 
                && boardSize != 10 && boardSize != 12 && boardSize != 14 
                && boardSize != 16 && boardSize != 18 && boardSize != 20) {
        cout << "Please try again: ";
        cin.clear();
        cin.ignore(512, '\n');
        cin >> boardSize;
    }


    for (int i = 0; i < boardSize; i++) {
        int j;
        for (j = 0; j < boardSize; j++)
            board[i][j] = '.';

        j = 0;
    }

    cout << endl;
    cout << "####### PLAY" << endl << endl;

    board[(boardSize / 2) - 1][(boardSize / 2) - 1] = 'X';
    board[(boardSize / 2) - 1][(boardSize / 2)] = 'O';

    board[(boardSize / 2)][(boardSize / 2) - 1] = 'O';
    board[(boardSize / 2)][(boardSize / 2)] = 'X';

    return boardSize;

}

// Takes game board and prints the screen it according to game board size 

void print_board(char board[20][20], int boardSize) {
    char top_edge[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u'};
    int left_edge[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int i, j;
    int counter = 0;

    cout << "   ";
    for (i = 0; i < boardSize; i++)
        cout << top_edge[i];

    cout << endl;
    for (i = 0; i < boardSize; i++) {
        if (++counter < 10)
            cout << " ";

        cout << left_edge[i] << " ";

        for (j = 0; j < boardSize; j++)
            cout << board[i][j];

        cout << endl;

        j = 0;
    }

}

// Checks legal moves on coordinate of xy for user or computer according to input
// If xy coordinate is legal this function returns 1 otherwise returns 0

int check_legal(char board[20][20], int boardSize, int x, int y, char player) {
    int legal = 0;
    int X, Y, X2, Y2; // X and Y to go forward in loops
                      // X2 and Y2 to go backwards in loops

    char player_two; // If input player is 'O' player2 is computer
                     // If inout player is 'X' player2 is user

    // Player determination
    if (player == 'O')
        player_two = 'X';
    else if (player == 'X')
        player_two = 'O';


    // Checks around the point according to whether legal move
    if (board[x][y] == '.') {

        // Horizontally to the right
        if (player_two == board[x][y + 1])
            for (Y = y + 2; Y < boardSize && board[x][Y] != '.'; Y++)
                if (player == board[x][Y])
                    legal = 1;

        // Horizontally to the left
        if (player_two == board[x][y - 1])
            for (Y = y - 2; Y >= 0 && board[x][Y] != '.'; Y--)
                if (player == board[x][Y])
                    legal = 1;

        // Vertically to the right
        if (player_two == board[x + 1][y])
            for (X = x + 2; X < boardSize && board[X][y] != '.'; X++)
                if (player == board[X][y])
                    legal = 1;

        // Vertically to the left
        if (player_two == board[x - 1][y])
            for (X = x - 2; X >= 0 && board[X][y] != '.'; X--)
                if (player == board[X][y])
                    legal = 1;

        // Upper right cross
        if (player_two == board[x - 1][y + 1])
            for (X = x - 2, Y = y + 2; X >= 0 && Y < boardSize && board[X][Y] != '.'; X--, Y++)
                if (player == board[X][Y])
                    legal = 1;

        // Bottom right cross
        if (player_two == board[x + 1][y - 1])
            for (X = x + 2, Y = y - 2; X < boardSize && Y >= 0 && board[X][Y] != '.'; X++, Y--)
                if (player == board[X][Y])
                    legal = 1;

        // Upper left cross
        if (player_two == board[x - 1][y - 1])
            for (X = x - 2, Y = y - 2; X >= 0 && Y >= 0 && board[X][Y] != '.'; X--, Y--)
                if (player == board[X][Y])
                    legal = 1;

        // Bottom left cross
        if (player_two == board[x + 1][y + 1])
            for (X = x + 2, Y = y + 2; X < boardSize && Y < boardSize && board[X][Y] != '.'; X++, Y++)
                if (player == board[X][Y])
                    legal = 1;

    }

    return legal;
}

// Takes xy coordinate as input and it changes points in between
// xy point must be legal

void making_move(char board[20][20], int boardSize, int x, int y, char player) {
    int legal = 0;
    int Y, X, Y2, X2; // X and Y to go forward in loops
                      // X2 and Y2 to go backwards in loops
    char player_two; // If input player is 'O' player2 is computer
                     // If inout player is 'X' player2 is user

    // Player determination
    if (player == 'O')
        player_two = 'X';
    else if (player == 'X')
        player_two = 'O';


    // Horizontally to the right
    if (player_two == board[x][y + 1])
        for (Y = y + 2; Y < boardSize && board[x][Y] != '.'; Y++)
            if (player == board[x][Y]) {
                for (Y2 = Y - 1; Y2 > y; Y2--)
                    board[x][Y2] = player;
                Y = boardSize; // To exit the loop
            }

    // Horizontally to the left
    if (player_two == board[x][y - 1])
        for (Y = y - 2; Y >= 0 && board[x][Y] != '.'; Y--)
            if (player == board[x][Y]) {
                for (Y2 = Y + 1; Y2 < y; Y2++)
                    board[x][Y2] = player;
                Y = -1; // To exit the loop
            }

    // Vertically to the right
    if (player_two == board[x + 1][y])
        for (X = x + 2; X < boardSize && board[X][y] != '.'; X++)
            if (player == board[X][y]) {
                for (X2 = X - 1; X2 > x; X2--)
                    board[X2][y] = player;
                X = boardSize; // To exit the loop
            }

    // Vertically to the left 		
    if (player_two == board[x - 1][y])
        for (X = x - 2; X >= 0 && board[X][y] != '.'; X--)
            if (player == board[X][y]) {
                for (X2 = X + 1; X2 < x; X2++)
                    board[X2][y] = player;
                X = -1; // To exit the loop  
            }

    // Upper right cross
    if (player_two == board[x - 1][y + 1])
        for (X = x - 2, Y = y + 2; X >= 0 && Y < boardSize && board[X][Y] != '.'; X--, Y++)
            if (player == board[X][Y]) {
                for (X2 = X + 1, Y2 = Y - 1; X2 < x && Y2 > y; X2++, Y2--)
                    board[X2][Y2] = player;
                Y = boardSize; // To exit the loop
            }

    // Bottom right cross
    if (player_two == board[x + 1][y - 1])
        for (X = x + 2, Y = y - 2; X < boardSize && Y >= 0 && board[X][Y] != '.'; X++, Y--)
            if (player == board[X][Y]) {
                for (X2 = X - 1, Y2 = Y + 1; X2 > x && Y2 < y; X2--, Y2++)
                    board[X2][Y2] = player;
                X = boardSize; // To exit the loop    
            }

    // Upper left cross
    if (player_two == board[x - 1][y - 1])
        for (X = x - 2, Y = y - 2; X >= 0 && Y >= 0 && board[X][Y] != '.'; X--, Y--)
            if (player == board[X][Y]) {
                for (X2= X + 1, Y2 = Y + 1; X2 < x && Y2 < y; X2++, Y2++)
                    board[X2][Y2] = player;
                X = -1; // To exit the loop
            }

    // Bottom left cross
    if (player_two == board[x + 1][y + 1])
        for (X = x + 2, Y = y + 2; X < boardSize && Y < boardSize && board[X][Y] != '.'; X++, Y++)
            if (player == board[X][Y]) {
                for (X2 = X - 1, Y2 = Y - 1; X2 > x && Y2 > y; X2--, Y2--)
                    board[X2][Y2] = player;
                X = boardSize; // To exit the loop
            }

}

// This function makes the user's move
// Takes xy coordinate from user and calls check_legal and making_move functions 

void users_move(char board[20][20], int boardSize) {
    int x; // x coordinate as a integer number
    char y; // y coordinate as a character
    int integer_y; // y coordinate as a integer number
    int status = 0; // Control of making legal move
    char top_edge[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U'};


    do {
        cout << endl << "Please enter your move ( 1A, 3D, 4B etc ) : ";
        cin.clear();
        cin.ignore(512, '\n');
        cin >> x >> y;
        cout << endl;

        // Converts the equivalent number of characters	according to game board
        integer_y = find_location(top_edge, 21, y);

        // Status of made the legal moves
        if ((x <= 20 && x >= 0) && check_legal(board, boardSize, x - 1, integer_y, 'O') == 1) {
            making_move(board, boardSize, x - 1, integer_y, 'O');
            board[x - 1][integer_y] = 'O';
            status = 1;
        } else
            cout << ">>> This move is not legal, please try again!" << endl;
    
    } while (status == 0 || !cin);


}


// This function makes the computer's move
// Finds best move (call find_best_move function) and calls making_move function

void computers_move(char board[20][20], int boardSize) {
    int x, y;
    char top_edge[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U'};

    // Finds best move
    find_best_move(board, boardSize, &x, &y);

    // Plays computer's move
    making_move(board, boardSize, x, y, 'X');
    board[x][y] = 'X';

    cout << "   (Computer move >> " << x + 1 << top_edge[y] << ")" << endl << endl;

}

// Finds best computer's move on game board
// x and y input-output parameter

void find_best_move(char board[20][20], int boardSize, int *x, int *y) {
    int X, Y, X2, Y2; // X and Y to go forward in loops
                      // X2 and Y2 to go backwards in loops
    int coordinate_records[20][2];
    int number_of_cells[20];
    char com = 'X';
    char user = 'O';
    int counter = 0; // Number of cell
    int recordSize = 0;
    int largest_number_of_cells; // Location of maximum number


    for (int i = 0; i < boardSize; i++) {

        int j;
        for (j = 0; j < boardSize; j++) {

            // If ij coordinate is legal
            if (check_legal(board, boardSize, i, j, 'X') == 1) {

                // Horizontally to the right
                if (user == board[i][j + 1])
                    for (Y = j + 1; Y < boardSize && board[i][Y] == user && board[i][Y + 1] != '.'; Y++)
                        counter++;

                // Horizontally to the left       	
                if (user == board[i][j - 1])
                    for (Y = j - 1; Y > 0 && board[i][Y] == user && board[i][Y - 1] != '.'; Y--)
                        counter++;

                // Vertically to the right    
                if (user == board[i + 1][j])
                    for (X = i + 1; X < boardSize && board[X][j] == user && board[X + 1][j] != '.'; X++)
                        counter++;

                // Vertically to the left        
                if (user == board[i - 1][j])
                    for (X = i - 1; X > 0 && board[X][j] == user && board[X - 1][j] != '.'; X--)
                        counter++;

                // Upper right cross        
                if (user == board[i - 1][j + 1])
                    for (X = i - 1, Y = j + 1; X > 0 && Y < boardSize && board[X][Y] == user && board[X - 1][Y + 1] != '.'; X--, Y++)
                        counter++;

                // Bottom right cross        
                if (user == board[i + 1][j - 1])
                    for (X = i + 1, Y = j - 1; X < boardSize && Y > 0 && board[X][Y] == user && board[X + 1][Y - 1] != '.'; X++, Y--)
                        counter++;

                // Upper left cross        
                if (user == board[i - 1][j - 1])
                    for (X = i - 1, Y = j - 1; X > 0 && Y > 0 && board[X][Y] == user && board[X - 1][Y - 1] != '.'; X--, Y--)
                        counter++;

                // Bottom left cross        
                if (user == board[i + 1][j + 1])
                    for (X = i + 1, Y = j + 1; X < boardSize && Y < boardSize && board[X][Y] == user && board[X + 1][Y + 1] != '.'; X++, Y++)
                        counter++;

                // Saves the move
                coordinate_records[recordSize][0] = i;
                coordinate_records[recordSize][1] = j;
                number_of_cells[recordSize++] = counter;

                counter = 0;

            }
        }

        j = 0;

    }

    largest_number_of_cells = max_number(number_of_cells, recordSize);

    // Sends best move coordinates
    *x = coordinate_records[largest_number_of_cells][0];
    *y = coordinate_records[largest_number_of_cells][1];

}

// Takes a one dimensional array (int) and finds maximum number in array.
// Returns location of maximum number (first or last)

int max_number(int arr[], int size) {
    int maxNumber = 0;
    int maxNumber_ofLocation;

    for (int i = 0; i < size; i++) {
        
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
            maxNumber_ofLocation = i;
        }
		
		else if(arr[i] == maxNumber) {
			srand(time(0));
			if(rand()%10 >= 5)
				maxNumber_ofLocation = i;
		}		
	}
    
    return maxNumber_ofLocation;
}

// Checks whether the legal moves. If found legal move returns 1

int control_legal_move(char board[20][20], int boardSize, char player) {

    for (int i = 0; i < boardSize; i++) {
        int j;
        for (j = 0; j < boardSize; j++) {
            if (check_legal(board, boardSize, i, j, player) == 1)
                return 1;
        }

        j = 0;
    }


    return 0;
}

// Takes a one dimensional array (char) and a character. It searches character in array. 
// If it found returns character's location. Otherwise returns -1

int find_location(char arr[], int size, char a) {
    for (int i = 0; i < size; i++)
        if (arr[i] == a)
            return i;

    return -1;
}

// Calculates user and computer cells. Prints the screen who won and number of cells

void end_game(char board[20][20], int boardSize) {
    int user_count = 0; // Number of user cells
    int com_count = 0; // Number of computer cells


    for (int i = 0; i < boardSize; i++) {
        int j;
        for (j = 0; j < boardSize; j++) {
            if (board[i][j] == 'O')
                user_count++;
            else if (board[i][j] == 'X')
                com_count++;
        }

        j = 0;
    }

    // End game message 
    if (user_count > com_count)
        cout << endl << "####### USER WON! #######";
    else if (com_count > user_count)
        cout << endl << "####### COMPUTER WON! #######";
    else if (com_count == user_count)
        cout << endl << "####### DRAW! #######";

    cout << endl << endl << "User: " << user_count;
    cout << endl << "Computer: " << com_count << endl << endl;

}