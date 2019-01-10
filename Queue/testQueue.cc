#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	Queue queue;
	for(int i = 0;i < MAXSIZE;++i)
		queue.push(i);
	queue.push(MAXSIZE);
	for(int i = 0;i <= MAXSIZE;++i)
	    queue.pop();
//	queue.push(1);
//	queue.push(2);
//	queue.push(3);
//	queue.push(4);
//	queue.push(5);
//	queue.pop();
//	queue.pop();
//	cout << "front = " << queue.front() << endl
//		 << "back = " << queue.back() << endl;
	return 0;
}
