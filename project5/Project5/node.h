//
// Created by keeganbean on 11/29/2019.
//

#ifndef ANIMALGAME_NODE_H
#define ANIMALGAME_NODE_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>
#include "node.h"

using namespace std;
//class to tidy up animal.cpp
//node class
//function definitions
class node {
    public:
        string data;
        node* left;
        node* right;
    };

//provided functions
void play_game(node* root, queue<string> &idx); //play game function definition
node* read_game_tree(); //read_game_tree function definition
void write_game_tree(node* root, ofstream &write); //write_game_tree function definition
void delete_game_tree(node*); //delete_game_tree function definition

//helper functions
void read_preorder(node* tree, ifstream &fin); //as per the project prompt(mostly)
void tree_extended(node* root, queue<string> twentyQuestions);  //for extending the tree
void save_tree(node* root); //save output

#endif //ANIMALGAME_NODE_H
