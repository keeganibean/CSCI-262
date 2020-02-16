#include "hangman.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;



// helper function prototypes


int main() {

    //placing the words from the scrabble dictionary into a set
    ifstream words("dictionary.txt");
    if (!words) {
        cerr << "Error opening dictionary.txt, exiting." << endl;
        return -1;
    }

    set<string> dict;
    read_file( words, dict);

    bool start_new_game = true;

    while(start_new_game) {

        //Yes or no answers
        set<string> Yes, No;
        user_responses( Yes, No);
        //start with asking for how may guesses they want
        string prompt = "How many guesses would you like?\n";
        int is_won = get_integer( prompt);

        if (!is_won) {
            prompt = "Would You Like To Play Again (y/n)? ";
            start_new_game = get_yesno( prompt, Yes, No);
            if (start_new_game)
                continue;
            else
                break;
        }

        //then ask for the word length they want
        prompt = "How long of a word would you like? \n";
        size_t size_of_word = get_integer(prompt);
        //ask if they want to see the size of the word families
        prompt = "Show running total of words? (y/n)  \n";
        bool display_word = get_yesno(prompt, Yes, No);
        string wrongGuess = was_char_guessed(size_of_word);
        //trim the dictionary to size down to new family size
        set<string> hangman;
        trim(size_of_word, hangman, dict, prompt);
        //start the game and display until the game is won or lost
        cout << "Your word is:";
        vector<char> word(size_of_word, '-');
        set<char> chars_guessed;
        ret_word_vector(word); //prints the word

        while(size_of_word > 0 && is_won > 0) { //go until the size of the word equals correct guesses or they run out
            prompt = "What is your next guess? \n";
            char letter = get_letter( prompt); //next guesses
            cout << "Your word is:";
            bool isBadCh = already_guessed( letter, chars_guessed ); //checking if the char was guessed
            if (isBadCh) {
                cout << "You have already guessed this letter" << endl;
                continue;
            } else
                chars_guessed.insert( letter );
            dictionary_map new_words;
            Word_Families( letter, hangman, new_words); //updating the map of word families
            pair<string, Chosen_word_family> chosen_word = *max_element(new_words.begin(), new_words.end(), process_guess);
            hangman.clear();
            hangman = chosen_word.second.game; //changing to the highest count family
            //make the user lose the game
            string str= chosen_word.first;
            int lettersGuessed = get_display_word( str, wrongGuess, letter,  word); //update the vector and words
            if( lettersGuessed == 0 )
                is_won--;
            else
                size_of_word = size_of_word-lettersGuessed;
            printGame( word, is_won, display_word, chars_guessed, hangman );

        }
        //outcome of the game
        if ( is_won == 0 ) {
            cout << "Thank you for playing Hangman. \n" << endl;
            cout << "You lose, try again. \n" << endl;
            cout << "The Word was: " << *hangman.begin() << "\n" << endl;
        } else
            cout << "Thank you for playing Hangman. \n" << endl;

        //starting a new game
        prompt = "Would you like to play again (y/n)? ";
        start_new_game = get_yesno( prompt, Yes, No);
        cout << endl;
    }

    return 0;
}

