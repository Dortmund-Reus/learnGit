#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
    Stack stack;
    stack.push(10);
    stack.push(12);
    stack.push(14);
    cout<< "当前栈顶元素为： " << stack.top() <<endl;
    stack.pop();
    cout<< "当前栈顶元素为： " << stack.top() <<endl;
}
