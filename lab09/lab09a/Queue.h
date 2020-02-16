#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab - Queues, part 1       

    author: 

    last modified: 9/7/2017
*/

#include <cstdlib>
#include <iostream>

using namespace std;

class Queue {
public:
	// max elements in queue
	static const size_t ARRAY_SZ = 5;
	int _front=0;
	int _back=0;
	int _size=0;

	Queue() { ; }

	bool enqueue(char c) {
	    if (_size<ARRAY_SZ)
        {
            _data[_back]=c;
            _back++;
            _back=_back%5;
            _size++;
            return true;
        }
	    else
        {
	        return false;
        }
	}
	bool dequeue()  {
	    if (_size==0)
	        return false;
	    _front++;
	    _front=_front%5;
	    _size--;
	    return true;
	}
	char front()    { return _data[_front]; }
	bool is_empty() {
	   // cout<<_front<<" "<<_back<<endl;
        if (_size==0)
	        return true;
        return false;
	}

private:
	char _data[ARRAY_SZ];
};

#endif
