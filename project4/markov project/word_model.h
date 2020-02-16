/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Keegan Bean

   Modified: 10/24/2019
*/

#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include "model.h"

using namespace std;

class word_model : public markov_model {
public:
    // give the model the example text and the model order; the model
    // should do any preprocessing in this call
    virtual void initialize(string text, int order);

    // produce a text in the style of the example
    virtual string generate(int size);

    string to_string();

protected:
    //consistent variables _data and _order
    vector <string> _data;
    int _order;
    map < vector<string>, vector <string> > word_model_map;
};

#endif
