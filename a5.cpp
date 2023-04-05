// a5.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Dominic Botelho, Lucas Jaeckel
// St.# : 301393131, 301405897
// Email: dbotelho@sfu.ca, ljaeckel@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

//
// You can use any other C++17 standard #includes that you need.
//
#include <iostream>
#include <vector>

using namespace std;

class board {
private:
    int sideLength;
    vector<string> content;

public:
    board(int length): sideLength(length){
        content.push_back("  ");
        // initialize first row
        for(int i=0; i<sideLength; i++){
            content[0].push_back('1'+i);
            content[0].push_back(' ');
        }
        // initialize other rows
        for(int i=0; i<sideLength; i++){
            content.push_back("");
            content[i+1].push_back('a'+i);
            content[i+1].push_back(' ');
            // fill rows
            for(int j=0; j<sideLength; j++){
                content[i+1].push_back('.');
                content[i+1].push_back(' ');
            }
        }
    }

    void printBoard() const {
        for(int i=0; i<=sideLength; i++){
            cout << content[i] << '\n';
        }
    }
    
    // setter
    void setPiece(int row, int column, char piece){
        content[row-'a'+1][column*2] = piece;
    }
};

void welcomeMsg(){
    cout << "Order versus Chaos ...\n";

    cout << "Goal:Achieve 5 alike characters in a row either vertically, horizontally or digonally\n"; 
    cout << "Instructions:" << endl;
    cout << "  1. Choose a square grid size between 6 to 9" << endl;
    cout << "  2. The first player is to enter either an x or o" << endl;
    cout << "  3. The second player can then place an x or o on the board" << endl;
    cout << "  4. The players must rotate turns" << endl;
    cout << "  5. The game is complete after achieving five alike characters in a row" << endl;
}

int main(){
    welcomeMsg();
    board test = board(6);
    test.printBoard();
    test.setPiece('b', 5, 'o');
    test.printBoard();
} // main


/*

Assignment 5 Report
===================

Description of Computers Playing Strategy
-----------------------------------------

(Discuss the strategy your computer player uses to play the game.)


Extra Features
--------------

(Describe all extra features your program has that were not required by the
assignment; if there are no extra features, then say that.)


Known Bugs and Limitations
--------------------------

(If your program is perfect and unlimited, then say so!)


Acknowledgements of All Help
----------------------------

(Cite all websites, books, people, etc. that you got help from, including what
sort of help you got. Each citation should be about 1 to 2 lines long.)

*/
