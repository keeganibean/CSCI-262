#ifndef _PERSONALITY_TEST_H
#define _PERSONALITY_TEST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class result { //given result class
public:
    string pType;
    string type;
    string category;
    string description;
};

class question { //described class from project page
public:
    int category_id; //variables
    string question;
    char yes_answer;
    char no_answer;
};

class personality_test { //class for personality_test.cpp
    public:
        bool load(istream&);
        void run_test();
        string analyze_personality();
        void categorize_output(string);
        void save_output(vector<result>);
        vector<question> personalityFile;
        vector<result> testOutput;
        void reload();
        
    private:
    int totalE;
    int totalI;
    int totalS;
    int totalN;
    int totalT;
    int totalF;
    int totalJ;
    int totalP;
};


#endif
