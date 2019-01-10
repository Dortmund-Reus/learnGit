#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
    Stack stack;
   // stack.push(1);
   // stack.push(2);
   // stack.push(3);
   // stack.push(4);
   // stack.push(5);
   // stack.push(6);
   // stack.push(7);
   // stack.push(8);
   // stack.push(9);
   // stack.push(10);
   // stack.push(11);
	stack.push(10);
    stack.push(12);
	stack.push(14);
    cout<< "当前栈顶元素为： " << stack.top() <<endl;
    stack.pop();
    cout<< "当前栈顶元素为： " << stack.top() <<endl;
}
