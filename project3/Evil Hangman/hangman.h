//
// Created by keeganbean on 10/25/2019.
//

#ifndef PROJECT3_HANGMAN_H
#define PROJECT3_HANGMAN_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
//Word Families Struct
struct Chosen_word_family {
    int count;
    set<string> game;
};

typedef map <string, Chosen_word_family>  dictionary_map;
int get_integer(string& prompt);
char get_letter(string prompt);
bool get_yesno(string& prompt, set<string> Yes, set<string> No);
void trim(size_t size_of_word, set<string>& game, set<string>& dict, string prompt);
bool process_guess(const pair<string, Chosen_word_family >& chars1, const pair<string, Chosen_word_family >& chars2);
string was_char_guessed(int size_of_word );
int get_display_word(string wordCode, string wrongGuess, char letter, vector<char>& word);

//my functions
void user_responses(set<string>& Yes, set<string>& No );
bool already_guessed(char letter, set<char> chars_guessed );
void read_file(ifstream& words, set<string>& dict);
void Word_Families(char letter, set<string> hangman, dictionary_map& new_words);
void ret_word_vector(vector<char> word );
void ret_word_set(set<char> setOfChar );
void printGame(vector<char> word, int is_won, bool display_word, set<char> chars_guessed, set<string>& hangman );
#endif //PROJECT3_HANGMAN_H
