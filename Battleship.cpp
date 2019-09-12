#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    //size constraints of the matrix
    int row = 3;
    int column = 3;

    bool sunk = false;      //has the ship been found?
    int guessCount = 0;     //counts the number of user guesses

    //initialize the matrix
    vector< vector<int> > matrix;                      //declares the matrix
    matrix.resize(row,vector<int>(column,-1));   //resize the matrix to size constraints and initialize to -1

    //randomize the location of the battleship
    srand(time(nullptr)); //random seed
    int hiddenRow = ((rand() % 3)); //random row
    int hiddenColumn = ((rand() % 3)); //random column

    /*
     * Sets the value of ships position in the matrix
     * -1 represents blank, not guessed
     * 0 represents blank, guessed (incorrect)
     * 1 represents ship, not guessed
     * 2 represents ship, guessed (correct)
     */
    matrix[hiddenRow][hiddenColumn] = 1;

    //accept user guesses until the ship is sunk
    do{
        //user input
        int userRow;
        int userColumn;

        //ask for and accept input
        cout << "Enter a location (one through three) in the format: row column." << endl;
        cin >> userRow;
        cin >> userColumn;

        //prevents repeat guesses
        while(matrix[userRow - 1][userColumn - 1] == 0){
            cout << "You have already guessed that location. Enter a new location." << endl;
            cin >> userRow;
            cin >> userColumn;
        }

        //updates matrix and increments guessCount
        matrix[userRow - 1][userColumn - 1] ++;
        guessCount++;

        //print the matrix
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                //correct guess
                if (matrix[i][j] == 2) {
                    cout << " X ";
                    sunk = true;
                }
                //incorrect guess
                else if (matrix[i][j] == 0) {
                    cout << " O ";
                }
                //not guessed
                else {
                    cout << "   ";
                }
                if (j < column - 1){
                    cout << "|";
                }
            }
            cout << endl;
            if (i < row - 1){
                cout << "~~~~~~~~~~~~";
                cout << endl;
            }
        }
    } while(!sunk);

    cout << "You sunk my battleship in " << guessCount << " guesses!" << endl;
    return 0;
}