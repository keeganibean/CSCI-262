//
#include "hangman.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
void printGame( vector<char> word, int is_won, bool display_word,
                set<char> chars_guessed, set<string>& hangman )
{
    ret_word_vector(word);
    cout << "You have already guessed these letters: ";
    ret_word_set( chars_guessed );
    cout << endl;

    if ( display_word ) {
        cout << "Words in chosen family: " << hangman.size() << endl << endl;
    }
    cout << "You have " << is_won << " guesses remaining." << endl;
}

/* Update the Blank Word with the Guessed Letter */
int get_display_word( string wordCode, string wrongGuess, char letter, vector<char>& word)
{
    if ( wordCode == wrongGuess )
        return 0;

    int count = 0;
    for (int i = 0; i < wordCode.length(); i++){
        if ( wordCode[i] == '1') {
            word[i] = letter;
            count++;
        }
    }
    return count;
}

void Word_Families( char letter, set<string> hangman, dictionary_map& wordFamilies)
{
    // move through the words
    string tempWord;
    for (set<string>::iterator itr = hangman.begin(); itr != hangman.end(); ++itr) {
        tempWord = *itr;
        //change dash position
        for (int i = 0; i < tempWord.length(); i++) {
            if (tempWord[i] == letter)
                tempWord[i] = '1';
            else tempWord[i] = '0';
        }

        if ( wordFamilies.find(tempWord) == wordFamilies.end() ) {
            Chosen_word_family wordFamily;

            wordFamily.count = 1;
            wordFamily.game.insert( *itr );
            wordFamilies.insert( pair<string, Chosen_word_family> (tempWord, wordFamily) );
        } else {
            wordFamilies[tempWord].count++;
            wordFamilies[tempWord].game.insert( *itr);
        }
    }


}

//process the users guess
bool process_guess(const pair<string, Chosen_word_family >& chars1,
                   const pair<string, Chosen_word_family >& chars2)
{
    return chars1.second.count < chars2.second.count;
}

void ret_word_set( set<char> setOfChar )
{
    for ( set<char>::iterator itr = setOfChar.begin(); itr != setOfChar.end(); ++itr ){
        cout << *itr << ", ";
    }
    cout << "\b\b " << endl; //from the cplusplus forum for moving back a cursor
}

void ret_word_vector( vector<char> word)
{
    for (size_t i = 0; i < word.size(); i++) {
        cout << word[i];
    }
    cout << '\n' << endl;
}

bool already_guessed( char letter, set<char> chars_guessed )
{
    if ( chars_guessed.find(letter) == chars_guessed.end() ) return 0;
    else return false;
}

//downsizing the dictionary throughout the game
void trim( size_t size_of_word, set<string>& hangman, set<string>& dict,
           string prompt)
{
    while( hangman.empty() ) {
        for( set<string>::iterator itr = dict.begin(); itr != dict.end(); ++itr) {
            if ( (*itr).length() == size_of_word ) {   // must include paran.s around #itr b/c . has higher precendence than *
                hangman.insert(*itr);
            }
        }

        if( hangman.empty()) {
            cout << "Too Long try again" << endl;
            size_of_word = get_integer( prompt);
        }
    }
    return; //pointless remove later
}

string was_char_guessed( int size_of_word )
{
    string dashes;
    for (int i = 0; i < size_of_word; i++ ) {
        dashes += '0';
    }
    return dashes;
}

//places the dictionary into a set
void read_file( ifstream& words, set<string>& dict)
{
    string dictionary;
    while( getline(words, dictionary))
        dict.insert( dictionary);
}
//combinations of yes and no inputs
void user_responses( set<string>& Yes, set<string>& No)
{
    string answerList[] =  {"y", "yes", "Y", "Yes"};
    int answerListSize = sizeof answerList / sizeof(string);
    Yes.insert( answerList, answerList+ answerListSize);
    string answerList1[] = {"n", "no", "N", "No"};
    answerListSize = sizeof answerList1 / sizeof(string);
    No.insert( answerList1, answerList1+ answerListSize);
}

//main prompt variable
char get_letter( string prompt)
{
    string guess;

    while(true){
        cout << prompt;
        getline(cin, guess);
        if (guess[guess.size() - 1] == '\r') guess.resize(guess.size() - 1);
        if (guess.length()>1 || !isalpha(guess[0])) {
            cout << "Sorry, that letter isn't in the word." << endl;
        } else {
            cout<< endl;
            return guess[0];
        }
    }
}
//user input yes or no
bool get_yesno( string& prompt, set<string> Yes, set<string> No )
{
    string answer;
    while (true) {
        cout << prompt;
        getline( cin, answer);
        if (answer[answer.size() - 1] == '\r') answer.resize(answer.size() - 1);
        for (string::iterator itr = answer.begin(); itr != answer.end(); ++itr)
            *itr = tolower(*itr);

        if (Yes.find(answer) != Yes.end())
            return 1;
        else if ( No.find(answer) != No.end() )
            return 0;
        cout << "answer yes or no" << endl;
    }
}

int get_integer( string& prompt) {
    string msg;
    int num;
    while (true) {
        cout << prompt;
        getline(cin, msg);
        istringstream input(msg);
        input >> num;
        if (input.fail() || num < 0)
            cout << "I didn't understand that. Please enter a positive integer." << endl;
        else
            return num;
    }
}