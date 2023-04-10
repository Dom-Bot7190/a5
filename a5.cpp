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
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class board {
private:
    int sideLength;
    vector<string> content;

public:
    // initialize empty board
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

    // check for 5 in a horizontal row
    int horiz(const int& line, const char& c){
        int charsFound = 0;
        for(int i=2; i<content[line].size(); i+=2){
            if(charsFound < 5){
                if(content[line][i] == c){
                    charsFound++;
                } else {
                    charsFound = 0;
                }
            }
        }
        return charsFound;
    }

    // check for 5 in a vertical row
    int vert(const int& col, const char& c){
        int charsFound = 0;
        for(int i=1; i<=sideLength; i++){
            if(charsFound < 5){
                if(content[i][col] == c){
                    charsFound++;
                } else {
                    charsFound = 0;
                }
            }
        }
        return charsFound;
    }

    // check for 5 in a diagonal row starting from top left and moving right
    int rightSide(int col, const char& c) const {
        int charsFound = 0;
        for(int i=1; i<=sideLength; i++){
            if(charsFound < 5 && (col < content[1].size())){
                if(content[i][col] == c){
                    charsFound++;
                } else {
                    charsFound = 0;
                }
                col+=2;
            }
        }
        return charsFound;
    }

    // check for 5 in a diagonal row starting from top right and moving left
    int leftSide(int col, const char& c) const {
        int charsFound = 0;
        for(int i=1; i<=sideLength; i++){
            if(charsFound < 5 && col > 1){
                if(content[i][col] == c){
                    charsFound++;
                } else {
                    charsFound = 0;
                }
                col-=2;
            }
        }
        return charsFound;
    }

    // check for 5 in a diagonal row starting from row below top left and moving down
    int rightDown(int row, const char& c) const {
        int charsFound = 0;
        int col = 2;
        for(int i=row; i<=(sideLength); i++){
            if(charsFound < 5){
                if(content[i][col] == c){
                    charsFound++;
                } else {
                    charsFound = 0;
                }
                col+=2;
            }
        }
        return charsFound;
    }

    // check for 5 in a diagonal row starting from row below top right and moving down
    int leftDown(int row, const char& c) const {
        int charsFound = 0;
        int col = content[1].size()-2;
        for(int i=row; i<=(sideLength); i++){
            if(charsFound < 5){
                if(content[i][col] == c){
                    charsFound++;
                } else {
                    charsFound = 0;
                }
                col-=2;
            }
        }
        return charsFound;
    }

    // check if order wins
    bool fiveInRow(const char& c){
        // check for 5 in a horizontal row in each row
        for(int i=1; i<=sideLength; i++){
            if(horiz(i, c) >= 5){
                return true;
            }
        }
        // check for 5 in a vertical row in each column
        for(int i=2; i<=content[1].size(); i+=2){
            if(vert(i, c) >= 5){
                return true;
            }
        }
        // check for five diagonally
        for(int i=2; i<(content[1].size()-8); i+=2){
            if(rightSide(i, c) >= 5){
                return true;
            }
        }
        for(int i=content[1].size()-2; i>9; i-=2){
            if(leftSide(i, c) >= 5){
                return true;
            }
        }
        for(int i=2; i<=(sideLength-4); i++){
            if(rightDown(i, c) >= 5 || leftDown(i, c) >= 5){
                return true;
            }
        }
        // if no 5 in a rows were found, return false
        return false;
    }

    // check if board is filled and chaos character wins
    bool isOver(const int& start) const {
        if(content[start].find('.') != content[start].npos){
            return false;
        } else if(start >= sideLength) {
            return true;
        }
        // recursively check each row
        return isOver(start+1);
    }

    int checkWinner(){
        if(fiveInRow('X') || fiveInRow('O')){
            // 1 = order player wins
            return 1;
        } else if(isOver(0)){
            // 2 = chaos player wins
            return 2;
        }
        // 0 = no winner yet
        return 0;
    }

    void randPlace(){
        srand(time(0));
        int col = 0;
        int row = 0;
        char randChar = 'X';
        while(content[row][col] != '.'){
            row = (rand() % sideLength)+1;
            col = ((rand() % sideLength)+1)*2;
        }
        int randInt = rand() % 2;
        if(randInt == 0){
            randChar = 'O';
        }
        content[row][col] = randChar;
    }

    // getter
    int getGridSz() const {
        return sideLength;
    }

    // setter
    void setPiece(const string& input){
        content[input[0]-'a'+1][(input[1]-'0')*2] = input[2];
    }

    // for testing
    void fillBoard(){
        for(int i=0; i<content.size(); i++){
            for(int j=0; j<content[i].length(); j++){
                if(content[i][j] == '.'){
                    content[i][j] = 'X';
                }
            }
        }
    }
};

void welcomeMsg(){
    cout << "Order versus Chaos ...\n";

    cout << "Goal:Achieve 5 alike characters in a row either vertically, horizontally or diagonally\n"; 
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
    // test.setPiece("a6X");
    // test.setPiece("b5X");
    // test.setPiece("c4X");
    // test.setPiece("e2X");
    // test.setPiece("f1X");
    test.fillBoard();
    test.setPiece("f1.");
    test.randPlace();
    test.printBoard();
    cout << test.checkWinner() << endl;
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
