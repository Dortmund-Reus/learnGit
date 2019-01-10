#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

Queue::Queue()
	: _length(0)
	, _front(0)
	, _rear(0)  
{
	cout << "constructing Queue... " << endl;
}

Queue::~Queue()
{
	cout << "destructing Queue..." << endl; 
}

bool Queue::full()
{
	if(MAXSIZE == _length)
		return true;
	else return false;
}

bool Queue::empty()
{
	if(0 == _length)
		return true;
	else return false;
}

void Queue::push(int x)
{
	if(!full())
	{
		++_length;
		_data[_rear] = x;
		_rear = (_rear + 1)%MAXSIZE;
		cout << x << " is in." << endl ;
	}
	else cout << "The queue is full ! "<< endl;
}

void Queue::pop()
{
	if(!empty())
	{
		--_length;
		cout << _data[_front] << " is out. " << endl;
		_front = (_front + 1)%MAXSIZE;
	}
    else cout << "The queue is empty ! " << endl;
}

int Queue::front()
{
	return _data[_front];
}

int Queue::back()
{
	int back = (_rear-1 + MAXSIZE)%MAXSIZE;
	return _data[back];
}
