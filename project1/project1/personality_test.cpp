#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>

#include "personality_test.h"
using namespace std;

bool personality_test::load(istream &in) {  //load function
    ifstream win; //second ifstream
    string fileNew;
    string str;
    string answers;
    int i = 0;
    unsigned int length = 1;

    getline(in, str);
    try {
        while (!in.eof()) {
            personalityFile.resize(length++); //resize the vector

            in >> answers;
            stringstream input(answers); //input from the filestream
            getline(in, str);

            input >> personalityFile.at(i).category_id;

            if (typeid(personalityFile.at(i).category_id).name() != typeid(i).name()) {
                return false;
            }
            personalityFile.at(i).no_answer = str.at(str.length() - 1); //yes and no answers
            personalityFile.at(i).yes_answer = str.at(str.length() - 3);
            personalityFile.at(i).question = //printing the questions
                    str.substr(1, str.length() - 5) + (" y/n");
            i++;
        }

        if (personalityFile.empty()) { //if the file is empty ask for a new one (test 1)
            cout << "No words found" << endl;
            cout << "Please enter the input file name, e.g., \"questions.txt\": ";
            cin >> fileNew;
            win.open(fileNew);
            load(win);
        }

    } catch (const out_of_range &oor) { //if file is out of range ask for a new one (test 2)
        cout << "Input file \"" << "file" << "\" appears to not be a proper file!" << endl;
        cout << "Please enter the input file name, e.g., \"questions.txt\": ";
        cin >> fileNew;
        win.open(fileNew);
        load(win);
    }

    personalityFile.pop_back(); //removes the lines at the end
    personalityFile.pop_back();
    cout << endl;

    return true;
}

void personality_test::run_test() { //runs the tests
    string output = analyze_personality();
    categorize_output(output);
    save_output(testOutput);
}


string personality_test::analyze_personality() { //analyzes the file and inputs
    totalE = 0; //sets values of the letter totals
    totalI = 0;
    totalS = 0;
    totalN = 0;
    totalT = 0;
    totalF = 0;
    totalJ = 0;
    totalP = 0;

    string personality;
    string print = "";
    for (int i = 0; i < personalityFile.size(); i++) { //start the output for the personality
        bool b1 = false;
        while (!b1) {
            cout << personalityFile.at(i).question << endl;
            cin >> personality;
            if (personality == "Yes" || personality == "yes" || personality == "Y" || personality == "y" || personality == "YES") { //if user answers yes
                if (personalityFile.at(i).category_id == 1) {
                    if (personalityFile.at(i).yes_answer == 'E') { //for I/E
                        totalE++;
                    } else {
                        totalI++;
                    }
                } else if (personalityFile.at(i).category_id == 2) { //for S/N
                    if (personalityFile.at(i).yes_answer == 'N') {
                        totalN++;
                    } else {
                        totalS++;
                    }
                } else if (personalityFile.at(i).category_id == 3) { //for T/F
                    if (personalityFile.at(i).yes_answer == 'F') {
                        totalF++;
                    } else {
                        totalT++;
                    }
                } else if (personalityFile.at(i).category_id == 4) { //for J/P
                    if (personalityFile.at(i).yes_answer == 'P') {
                        totalP++;
                    } else {
                        totalJ++;
                    }
                }
                b1 = true; //boolean 1 is true because it exits properly
            } else if (personality == "No" || personality == "no" || personality == "N" || personality == "n" || personality == "NO") { //if the answer is no

                if (personalityFile.at(i).category_id == 1) {
                    if (personalityFile.at(i).no_answer == 'E') {
                        totalE++; //increase total E
                    } else {
                        totalI++; //increase total I
                    }
                } else if (personalityFile.at(i).category_id == 2) {

                    if (personalityFile.at(i).no_answer == 'N') {
                        totalN++; //increase total N
                    } else {
                        totalS++; //increase total S
                    }
                } else if (personalityFile.at(i).category_id == 3) {

                    if (personalityFile.at(i).no_answer == 'F') {
                        totalF++; //increase total F
                    } else {
                        totalT++; //increase total T
                    }
                } else if (personalityFile.at(i).category_id == 4) {

                    if (personalityFile.at(i).no_answer == 'P') {
                        totalP++; //increase total P
                    } else {
                        totalJ++; //increase total J
                    }
                }
                b1 = true; //boolean 1 is true because it exits properly
            } else {
                cout << "Sorry, I didn't recognize your input, please type again" << endl; //if the input is invalid(not yes or no)
            }
        }
    }

            if(totalI < totalE) {
                print.push_back('E');
            } else {
                print.push_back('I');
            }

            if(totalS < totalN) {
                print.push_back('N');
            } else {
                print.push_back('S');
            }

            if(totalT < totalF) {
                print.push_back('F');
            } else {
                print.push_back('T');
            }
            if(totalP < totalJ) {
                print.push_back('J');
            } else {
                print.push_back('P');
            }
    return print;
}


void personality_test::categorize_output(string my_personality) {
    string input;
    int num;
    cout << "Please enter the analysis file name, e.g., \"analysis.txt\": "; //calling for the analysis file
    cout << endl;
    cin >> input;
    ifstream analysis(input);

    while (!analysis) { //while it isn't open keep asking
        analysis.clear();
        cerr << "Error opening file \"" << input << "\"" << endl; //display error
        cout << endl << "Please enter the analysis file name, e.g., \"analysis.txt\": "; //ask again
        cin >> input;
        analysis.open(input);
        cout << endl;
    }
    cout << "===============" << endl; //aesthetic
    testOutput.resize(18); //resize the vector for output
    analysis >> num;
    // reads analysis data into a vector
    while(!analysis.eof()) { //finding type, category, and description
        for(unsigned int i = 0; i < num; i++) {
            analysis >> testOutput.at(i).pType;
            analysis >> testOutput.at(i).category;
            analysis >> testOutput.at(i).type;
            getline(analysis, testOutput.at(i).description);
        }
    }

    for(unsigned int i = 0; i < num; i++) { //outputting everything in the lines
        if (my_personality == testOutput.at(i).pType) {
            cout << "Your personality type is: " << testOutput.at(i).pType << endl; //type
            testOutput.at(17).pType = testOutput.at(i).pType;

            cout << "Your category is: " << testOutput.at(i).category << endl; //category
            testOutput.at(17).category = testOutput.at(i).category;

            cout << "Your type is: " << testOutput.at(i).type << endl; //type
            testOutput.at(17).type = testOutput.at(i).type;

            cout << "Your description is: " << testOutput.at(i).description << endl; //description
            testOutput.at(17).description = testOutput.at(i).description;
        }
    }
    analysis.close();
    cout << "===============" << endl << endl; //aesthetic
}

void personality_test::save_output(vector<result> resultList) {
    string results;
    ofstream save;
    string file;
    cout << "Would you like to save your results?" << endl;
    cin >> results;
    if (results == "No" || results == "no" || results == "N" || results == "n" || results == "NO") {
        return;
    }

    if (results == "Yes" || results == "yes" || results == "Y" || results == "y" || results == "YES") {
        cout << "Please enter a file name" << endl;
        cin >> file;
        save.open(file);
        while (save.fail()) { //keep asking for a save file
            cout << "Error opening file \"" << file << "\"" << endl; //prompting the user
            cout << "Please enter a file name" << endl; //asking for a file name
            cin >> file;
            save.open(file); //saving it
            save.close();
        }
    }
    //final output
    save << "Your personality type is: " << resultList.at(17).pType << endl;
    save << "Your category is: " << resultList.at(17).category << endl;
    save << "Your type is: " << resultList.at(17).type << endl;
    save << "Your description is: " << resultList.at(17).description << endl;
}


void personality_test::reload() { //reloading the program to run it again
    totalE = 0;//set totals back to zero
    totalI = 0;
    totalS = 0;
    totalN = 0;
    totalT = 0;
    totalF = 0;
    totalJ = 0;
    totalP = 0;
    personalityFile.clear(); //clear both vectors
    testOutput.clear();
}
