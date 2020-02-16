/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Keegan Bean

   Modified: 10/24/2019
*/

#include <cstdlib>
#include <vector>
#include <map>
#include "word_model.h"

using namespace std;

void word_model::initialize(string text, int order) { //initialize function for the word model
    //read in the characters from a file
    istringstream infile(text); //reading in to place into a vector very similar to previous projects
    while (!infile.eof()) {
        string character;
        infile >> character;
        _data.push_back(character);
    }
    for (int i = 0; i < order; i++) {
        _data.push_back(_data.at(i));
    }
    _order = order;

    for (int i = 0; i < (_data.size() - _order); i++) {  //placing into a vector called wordVector
        vector<string> wordVector;
        for (int j = i; j < (i + _order); j++) {
            wordVector.push_back(_data.at(j));
        }
        word_model_map[wordVector].push_back(_data.at(i + order));
    }
}

string word_model::generate(int sz) { //generate function for the word model
    int start = rand() % (_data.size() - _order);
    vector <string> idx;
    for (int i = start ; i < start + _order ; i++ ){
        idx.push_back( _data.at(i) );
    }

    string wordModel;

    for (int i = 0; i < sz; i++) { //choosing new characters
        string word = word_model_map[idx].at( rand() % word_model_map[idx].size() );
        wordModel += word; //changed because string concatenated
        wordModel += ' ';

        idx.erase(idx.begin() );//erase the current index
        idx.push_back(word); //reset index
    }
    return wordModel; //return the answer like the brute model
}

/*NOTES
 * implement the initialize function
 * place into a vector(within initialize)
 * generate function
 * access the strings and return a text in the style of the example
 */
