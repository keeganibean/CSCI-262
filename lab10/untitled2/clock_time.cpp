//
// Created by nwkeith on 11/1/2019.
//

#include "clock_time.h"
#include <string>
#include <sstream>


clock_time::clock_time() {
    _seconds=0;
}

clock_time::clock_time(int h, int m, int s) {
    set_time(h,m,s);
}

int clock_time::get_hour()
{
    return _seconds/3600;
}
int clock_time::get_minute()
{
    return (_seconds%3600)/60;
}
int clock_time::get_second()
{
    return _seconds%60;

}
/*
void clock_time::set_time(int h, int m, int s)
{
    _seconds=0;
    _seconds=_seconds+3600*h+60*m+s;
    while (_seconds>(24*3600-1))
        _seconds=_seconds-(24*3600);
    while (_seconds<0)
        _seconds=_seconds+(24*3600);
}
*/
void clock_time::set_time(int h, int m, int s) {
    if (h > 23) {
        h %= 24;
    }
    if (h < 0) {
        h += 24;
    }
    if (m > 59) {
        h += (m - (m % 60)) / 60;
        m %= 60;
    }
    if (m < 0) {
        m += 60;
        h -= 1;
    }
    if (s > 59) {
        m += (s - (s % 60)) / 60;
        s %= 60;
    }
    if (s < 0) {
        s = 60 + s;
        m -= 1;
    }

    int sec = h * 3600 + m * 60 + s;
    _seconds = sec;
}

/*
void clock_time::p()
{
    cout<<get_hour()<<":"<<get_minute()<<':'<<get_second()<<endl;
    cout<<_seconds<<endl;
}

string to_string(clock_time c) {
    string out="";
    out=out+to_string(c.get_hour())+":";
    string min=to_string(c.get_minute());
    if(min.length()<2)
        min="0"+min;
    out=out+min+":";
    string sec=to_string(c.get_second());
    if(sec.length()<2)
        sec="0"+sec;
    out=out+sec;
    return out;
}
*/

string to_string(clock_time c) {
    string str = "", min = "", sec = "";
    int h, m, s;
    //setters and getters
    h = c.get_hour();
    m = c.get_minute();
    s = c.get_second();

    str += to_string(h);
    str += ":";

    if (m < 10) {
        min += "0";
        min += to_string(m);
    }
    else {
        min += to_string(m);
    }

    if (s < 10) {
        sec += "0";
        sec += to_string(s);
    }
    else {
        sec += to_string(s);
    }
//min sec
    str += min;
    str += ":";
    str += sec;

    return str;
}

/*
ostream & operator<<(ostream & out, clock_time c)
{
    out<<to_string(c);
}



bool operator==(clock_time a, clock_time b) {
    return a._seconds==b._seconds;
}
 */

ostream& operator<<(ostream &out, clock_time &c) {
    string s = to_string(c);
    out << s;
    return out;
}

bool & operator==(clock_time c1, clock_time c2) {
    bool v = false;
    if (c1.get_hour() == c2.get_hour() && c1.get_minute() == c2.get_minute() && c1.get_second() == c2.get_second()) {
        v = true;
    }

    return v;
}

bool & operator!=(clock_time c1, clock_time c2) {
    bool v = true;
    if (c1 == c2) {
        v = false;
    }

    return v;
}

clock_time & operator+(clock_time c1, clock_time c2) {
    int h, m, s;

    h = c1.get_hour() + c2.get_hour();
    m = c1.get_minute() + c2.get_minute();
    s = c1.get_second() + c2.get_second();

    clock_time cNew(h,m,s);

    return cNew;
}