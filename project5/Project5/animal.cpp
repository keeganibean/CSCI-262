/*
	animal.cpp

	author: Keegan Bean
	date: 11/29/19

	Animal/20 questions program for CSCI 262
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include "node.h"

using namespace std;
//variables
string tmp;
int choice;

string answer, selection; //play game
string userInput; //play game
string ans;      //#Q or #A
string gameTree;      //Question
string user_animal; //extended
string user_question; //extended

//queue
queue<string> twentyQuestions;

/**
 * Handles showing the main menu/basic UI
 */
int main() {
    node* root = read_game_tree();
    if (root == nullptr)
        return -1;
    while (true) {
        cout << "Welcome to 20 questions!" << endl;
        cout << "  1) Play the game" << endl;
        cout << "  2) Save the game file" << endl;
        cout << "  3) Quit" << endl;
        cout << "Please make your selection:";
        getline(cin, tmp);
        choice = atoi(tmp.c_str());
        switch (choice) {
            case 1:
                play_game(root, twentyQuestions);
                break;
            case 2:
                save_tree(root);
                break;
            case 3:
                break;
            default:
                cout << "Please select an option 1-3, thanks!" << endl << endl;
        }
        if (choice == 3)
            break;
    }
    delete_game_tree(root);
    return 0;
}

/**
 * Sets up the recursive call to the read_preorder
 * @return root of the tree
 */
node* read_game_tree() {
    ifstream fin("animal_game_tree.txt"); //find animal_game_tree.txt
    if (!fin) {
        cerr << "File does not exist try again" << endl; //output error
        return nullptr; //exits
    }
    node* root = new node;
    read_preorder(root, fin); //starting preorder function
    fin.close();
    return root; //original node
}

/**
 * Plays the game
 * @param root Root of the game tree
 */
 void play_game(node* root, queue<string> &idx) { //function to play the game
     node* root_node = root; //set to root node

     cout << root_node->data << " [y/n]:"; //cout the questions
     getline(cin, answer);

    if(answer == "y" && root_node->left != nullptr && root_node->right != nullptr) {   //recursion checks for yes
        selection = root_node->data;
        selection += " y";
        root_node = root_node->left;
        idx.push(selection);
        play_game(root_node, idx);

    } else if(answer == "n" && root_node->left != nullptr && root_node->right != nullptr) { //recursion checks for no
        selection = root_node->data;
        selection += " n";
        root_node = root_node->right;
        idx.push(selection);
        play_game(root_node, idx);

    } else if(answer == "y" && root_node->left == nullptr && root_node->right == nullptr) {     //case 1
        selection = root_node->data;
        selection += " y";
        idx.push(selection);
        cout << endl << "YAY! I guess your animal!";
        cout << endl;
        cout << endl;

    } else if(answer == "n" && root_node->left == nullptr && root_node->right == nullptr){
        selection = root_node->data;
        selection += " n";
        idx.push(selection);
        cout << endl << "BOO! I don't know." << endl;
        cout << endl;

        cout << "Would you like to expand the game tree [y/n]? "; //if the user answers yes then run the extended game tree
        getline(cin, userInput);
        if(userInput == "y" || userInput == "Y") tree_extended(root_node, idx);
        else
            return;
    }
 }

void read_preorder(node* tree, ifstream &fin) {
    fin >> ans;
    getline(fin, gameTree);
    tree->data = gameTree;

    if(ans == "#A") {       //root case of input
        tree->left = nullptr;
        tree->right = nullptr;
        return;
    } else {
        node* left_child = new node;     //assigning new nodes to the tree
        node* right_child = new node;
        tree->left = left_child;
        tree->right = right_child;
        read_preorder(left_child, fin); //user input for left
        read_preorder(right_child, fin); //user input for right
    }
}

void tree_extended(node* root, queue<string> twentyQuestions) {    //expand the game
    cout << "I asked the following: " << endl; //outputting the previous per assignment UI
    while(!twentyQuestions.empty()) { //if its not empty pop the remaining elements
        cout << twentyQuestions.front() << endl;
        twentyQuestions.pop();
    }
    cout << "Enter a new animal in the form of a question (e.g., 'Is it a shark?'): ";//prompt for new question
    getline(cin, user_animal); //prompt for question

    cout << endl << "Now enter a question for which the answer is 'yes' for your new animal, and which does not contradict your previous answers: ";
    getline(cin, user_question); //user input for the new question
    string rootAnimal = root->data;

    node* left_node = new node;     //new nodes for the question
    node* right_node = new node;    //implementing the new questions for the game
    left_node->data = user_animal;
    right_node->data = rootAnimal;
    left_node->left = nullptr;
    left_node->right = nullptr;
    right_node->left = nullptr;
    right_node->right = nullptr;

    root->data = user_question;      //user_question
    root->left = left_node;
    root->right = right_node;
}

void save_tree(node* root) {
    ofstream fout("save_animal.txt"); //output to a save file for case 2
    write_game_tree(root, fout);
    fout.close(); //close the file after done writing
    cout << "Game file saved in 'save_animal.txt'\n" << endl;
}

/**
 * Writes the game tree, sets up a recursive call to write_preorder();
 * @param root The root of the tree
 */
void write_game_tree(node* root, ofstream &write) { //outputting the game tree
    if(root->left == nullptr && root->right == nullptr) {
        write << "#A " << root->data << endl; //#A
        return;
    } else {
        write << "#Q " << root->data << endl; //#Q
        write_game_tree(root->left, write); //write left
        write_game_tree(root->right, write); //write right
    }
}

/**
 * Deletes the game tree
 * @param root Root of the game tree
 */
void delete_game_tree(node* root) {
    // Optional. Do a post-order deletion of the game tree.
    // This isn't strictly needed as the program exits after this is called,
    // which frees up all the memory anyway.
    if(root->left == nullptr && root->right == nullptr) { //post order deletion
        delete root;
    } else {
        delete_game_tree(root->left);
        delete_game_tree(root->right);
        delete root;
    }
}