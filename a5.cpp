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

using namespace std;

class board {
private:
    int sideLength;
    string content;

public:
    board(int length): sideLength(length) {
        content = "  ";
        for(int i=0; i<sideLength; i++){
            content.push_back('1'+i);
            content.push_back(' ');
        }
        content.push_back('\n');
        // make rows
        for(int i=0; i<sideLength; i++){
            // fill each row
            content.push_back('a'+i);
            content.push_back(' ');
            for(int j=0; j<sideLength; j++){
                content.push_back('.');
                content.push_back(' ');
            }
            content.push_back('\n');
        }
    }

    void printBoard() {
        cout << content << '\n';
    }
};

int main(){
    cout << "Order versus Chaos ...\n";
    board test = board(6);
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
