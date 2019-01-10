#ifndef __QUEUE_H__
#define __QUEUE_H__
#define MAXSIZE 10
class Queue
{
public:
	Queue();
	~Queue();
	void push(int);
	void pop();
	int front();
	int back();
	bool empty();
	bool full();
private:
	int _data[MAXSIZE];
	int _length;
	int _front;
	int _rear;
};
#endif
