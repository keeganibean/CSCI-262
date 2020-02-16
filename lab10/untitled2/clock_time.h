//
// Created by nwkeith on 11/1/2019.
//

#ifndef UNTITLED2_CLOCK_TIME_H
#define UNTITLED2_CLOCK_TIME_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class clock_time {
public:
    int get_hour();
    int get_minute();
    int get_second();
    void set_time(int h, int m, int s);
    clock_time();
    clock_time(int h, int m, int s);
    friend bool & operator==(clock_time c1, clock_time c2);
    friend bool & operator!=(clock_time c1, clock_time c2);
    friend clock_time & operator+(clock_time c1, clock_time c2);
    //void p();

private:
    int _seconds;

};

string to_string(clock_time c);
ostream & operator<<(ostream &out, clock_time &c);



#endif //UNTITLED2_CLOCK_TIME_H
