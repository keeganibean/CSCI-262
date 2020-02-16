/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Keegan Bean

   Modified: 10/24/2019
*/


#include <cstdlib>
#include <map>
#include "map_model.h"

using namespace std;

void map_model::initialize(string text, int order) { //initialize function for map model
        // copy first order characters to back to simulate wrap-around
        // from brute model
        _data = text + text.substr(0, order);
        _order = order;

        //for map model
        for( int i=0; i<(_data.length() - order); i++ ){ //placing into a map called map_model_map
            string idx = _data.substr(i,order);
            map_model_map[idx].push_back(_data.at(i + order));
        }
}

string map_model::generate(int sz) { //generate function for map model

    // pick random k-character substring as initial seed
    // from brute model
    int start = rand() % (_data.length() - _order);
    string idx = _data.substr(start, _order);

    string mapModel;
    mapModel.reserve(sz);

    //for map model
    for (int i = 0; i < sz; i++) { //choosing new characters
        char letter = map_model_map[idx].at( rand() % map_model_map[idx].size() );
        mapModel.push_back(letter);
        idx = idx.substr(1) + letter; //new index at 1
    }
    return mapModel; //return the answer like brute model
}

/*NOTES
 * implement the initialize function
 * place into a map(within initialize)
 * generate function
 * access the characters and return a text in the style of the example
 */