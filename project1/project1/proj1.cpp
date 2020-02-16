//By: Keegan Bean
//Project description: running a program that takes an input for yes or no questions and returns your personality type
//Date finished: 9/6/19
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "personality_test.h"
using namespace std;

void load_file(personality_test&);
void reload_file(personality_test&);

int main () {
    cout << "====================================" << endl;
    cout << "Welcome to CSCI262 Personality Test!" << endl;
    cout << "====================================" << endl << endl;

    personality_test test;

    //main function calls
    load_file(test);
    test.run_test();
    reload_file(test);

}

void load_file(personality_test& test) { //loading the file
    string fileName;
    cout << "Please enter the input file name, e.g., \"questions.txt\": "; //prompt user

    cin >> fileName;
    ifstream userInput(fileName);

    while (!userInput) { //keep asking till valid
        userInput.clear();
        cerr << "Error opening file \"" << fileName << "\"" << endl;
        cout << "Please enter the input file name, e.g., \"questions.txt\": ";
        cin >> fileName;
        userInput.open(fileName);
    }

    test.load(userInput); //run the load function
}

void reload_file(personality_test& test) { //play again
    string play;
    cout << "Would you like to play again?" << endl;
    cin >> play;
    if (play == "Y" || play =="y" ||play == "yes" ||play == "Yes" ||play == "YES") { //if yes run it again
        test.reload(); //reload from personality_test.cpp
        load_file(test);
        test.run_test();
        reload_file(test);
    }
    if (play == "N" ||play == "n" ||play == "no" ||play == "No" ||play == "NO") { //dont play if no
        return;
    }

}
