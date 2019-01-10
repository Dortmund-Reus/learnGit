#include "Stack.h"
#include <iostream>

using std::cout;
using std::endl;
using std::abort;
Stack::Stack()          //无参构造函数
{
//	for(int i= 0;i < 9; ++i)
 //   _data = {0};
    _top = -1;   //top == -1表示栈空，== 10表示溢出
}
void Stack::push(int x) //入栈操作
{
    if(!full())
	{
        _data[++_top] = x;
		cout << x << " is in." << endl;
		cout <<"top is " << _top << endl;
	}
    else
	{
		cout << "The stack is full... " << endl
			 << "Program ends... " << endl;
		std::abort();
	}
}
void Stack::pop()
{
    if(!empty())    //栈不空才可以出栈
	{
		cout << _data[_top--] << " is out." << endl;
	}
}
int Stack::top()    //读取栈顶元素
{
    return _data[_top];
}
bool Stack::empty()
{
    if(_top == -1)return true;
    else return false;
}
bool Stack::full()
{
    if(_top == 9)return true;
    else return false;
}
