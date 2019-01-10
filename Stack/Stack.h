#ifndef __STACK_H__
#define __STACK_H__

//#include<iostream>
//using std::cout;
//using std::endl;

class Stack
{
private:
    int _data[10];
    int _top;
public:
    Stack();
    void push(int);
    void pop();
    int top();
    bool empty();
    bool full();
};

#endif
