#ifndef __DULNODE_H__
#define __DULNODE_H__

class DuLNode
{
public:
	int data;
	DuLNode * pre;
	DuLNode * next;
};

class List
{
private:
	DuLNode * _head;
	DuLNode * _tail;
	int _size;
//	DuLNode * _dn;

public:
	List();
	~List();

	void push_back(int value);

	void push_front(int value);

	void pop_back();

	void pop_front();

	void insert(DuLNode*, int);

	void erase(DuLNode*);

	void display() const;

	DuLNode* getNodeFront(int);

	DuLNode* getNodeBack(int);

};

#endif
