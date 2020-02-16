#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
using namespace std;

/*
    Queue.h

    A working implementation of a fixed-size circular queue
    meeting the requirements of the Queue, part 1 lab.  Use
    or replace as you wish.
*/

class Queue {
public:
	// max elements in queue


    // constructor
	Queue() {
	    _front = 0;
	    _back = 0;
	    _size = 0;
	    _capacity=5;
	    _size=0;
	    _data=new char[_capacity];
	}

    // enqueue: add a char to the end of the queue if room and return true;
    // if not enough room, return false
	bool enqueue(char c) {
        if (_size == _capacity)
        {
            _capacity=_capacity*2;
            char * _newdata;
            _newdata=new char[_capacity];
            for (int i=_front;i<_front+_size;i++)
            {
                _newdata[i-_front]=_data[i%_size];
            }
            delete[] _data;
            _data=_newdata;
            _front=0;
            _back=_size+1;
        }
		_data[_back] = c;
		_back = (_back + 1) % _capacity;
        _size++;

		return true;
	}

    // dequeue: if queue is not empty, remove the front element from the queue;
    // if queue is empty, return false and do nothing.
	bool dequeue()  {
		if (is_empty()) return false;
		_front = (_front + 1) % _capacity;
        _size--;
		return true;
	}

    // front: return the front element in the queue
	char front()    {
	    return _data[_front];
	    //return _front;
	    //return 0;
	}

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _size == 0; }

	int size() {
		return _size;
	}

private:
    unsigned int ARRAY_SZ = 5;
	char* _data;
    int  _size;
	int  _front;
	int  _back;
	int _capacity;

};

#endif
