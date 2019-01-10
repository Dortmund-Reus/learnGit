#include "DuLNode.h"
#include <iostream>

using std::cout;
using std::endl;

List::List()
	: _head(nullptr)
	, _tail(nullptr)
	, _size(0)
{
	cout << "constructing List..." << endl;
}

List::~List()
{
	while(_size > 0)
	{
		pop_back();
	}
	_head = nullptr;
	_tail = nullptr;
	cout << "destructing List..." << endl;
}

void List::push_back(int value)
{
	DuLNode* dn = new DuLNode();
	dn->data = value;
	dn->pre = nullptr;
	dn->next = nullptr;

	if(_size == 0)
	{
		_head = dn;
		_tail = dn;
	}
	else
	{
		_tail->next = dn;
		dn->pre = _tail;
		_tail = dn;
	}
	++_size;
	cout << "DuLNode " << value << " is in." << endl;
	cout << "Now size = " << _size <<endl;
//	delete dn;
}

void List::push_front(int value)
{
	DuLNode* dn = new DuLNode();
	dn->data = value;
	dn->pre = nullptr;
	dn->next = nullptr;

	if(_size == 0)
	{
		_head = dn;
		_tail = dn;
	}
	else
	{
		_head->pre = dn;
		dn->next = _head;
		_head = dn;
	}
	++_size;
	cout << "DuLNode " << value << " is in." << endl;
	cout << "Now size = " << _size << endl;
//	delete dn;
}
void List::pop_back()
{
	if(_size == 0)
		cout<<"Cannot pop! The list is empty! "<<endl;
	else if(_size == 1)
	{
		DuLNode* dn = _tail;
		cout << "DuLNode " << _head->data << " is out." << endl;
		free(dn);
		_head = nullptr;
		_tail = nullptr;
		--_size;
		cout << "Now size = " << _size << endl;
	}
	else 
	{
		DuLNode* dn = _tail;
		dn->pre->next = nullptr;
		_tail = dn->pre;
		dn->pre = nullptr;
		--_size;
		cout << "DuLNode " << dn->data << " is out." << endl;
		cout << "Now size = " << _size << endl;
		free(dn);
	}
}

void List::pop_front()
{
	if(_size == 0)
		cout<<"Cannot pop! The list is empty! "<<endl;
	else if(_size == 1)
	{
		DuLNode* dn = _head;
		cout << "DuLNode " << _head->data << " is out." << endl;
		free(dn);
		_head = nullptr;
		_tail = nullptr;
		--_size;
		cout << "Now size = " << _size << endl;
	}
	else
	{
		DuLNode* dn = _head;
		dn->next->pre = nullptr;
		_head = dn->next;
		dn->next = nullptr;
		--_size;
		cout << "DuLNode " << dn->data << " is out." << endl;
		cout << "Now size = " << _size << endl;
		free(dn);

	}
}


void List::insert(DuLNode* ld, int value)
{
	if(ld == _head)	//选择的结点是_head，相当于在头部增加一个结点
	{
		push_front(value);
	}
	else if(ld == nullptr)//选择的结点是tail后面，相当于在尾部增加一个结点
	{
		push_back(value);
	}
	else 
	{
		DuLNode* dn = new DuLNode();				//新建一个结点
		dn->data = value;							//为其赋值
		dn->pre = ld->pre;							//新结点的pre指向ld的前面
		ld->pre->next = dn;
		ld->pre = dn;								//ld的pre指向dn
		dn->next = ld;								//dn的next指向ld
													//错因：ld前面没有与dn连起来！
		//把这句加在前面：ld->pre->next = dn;
//		delete dn;
		++_size;
		cout << "DuLNode " << dn->data << " is in." << endl;
		cout << "Now size = " << _size << endl;
	}
}

void List::erase(DuLNode* ld)
{
	
	if(ld != nullptr)
	{
		if(ld->next == nullptr)//如果ld是最后一个结点，则相当于在尾部删除一个结点
			pop_back();
		else if(ld->pre == nullptr)
			pop_front();
		else
		{
			DuLNode* dn = ld->pre;						//用新建的dn指向ld前一个结点
			dn->next = ld->next;						//dn的next指向ld的next
			ld->next->pre = dn;							//ld的next结点的pre指向dn
			ld->pre = nullptr;							//ld脱链
			ld->next = nullptr;
			--_size;
			cout << "DuLNode " << ld->data << " is out." <<endl;
			cout << "Now size = " << _size << endl;
			free(ld);
		}
	}
}

void List::display() const
{
	cout << "Size of printList = " << _size << endl;
	cout << "start of display()." << endl;
	DuLNode* dn = _head;
	int counter = 1;
	while(dn != nullptr)
	{
		cout << "DuLNode " << counter << " = " << dn->data << endl;
		dn = dn->next; 
		++counter;
	}
	free(dn);
	cout << "end of display()." << endl;
	cout << endl;
}

DuLNode* List::getNodeFront(int index)
{
	if(index > _size)
	{
		cout << "Fail to get the node! It is out of range!" << endl;
		return nullptr;
	}
	else 
	{
		DuLNode* dn = _head;
		int counter = 1;
		while(counter < index)
		{
			dn = dn->next; 
			++counter;
		}
		//return dn;//这是一个栈对象！
		return dn;
	}
}
DuLNode* List::getNodeBack(int index)
{
	if(index > _size)
	{
		cout << "Fail to get the node! It is out of range!" << endl;
		return nullptr;
	}
	else 
	{
		DuLNode* dn = _tail;
		int counter = 1;
		while(counter < index)
		{
			dn = dn->pre; 
			++counter;
		}
		return dn;
	}
}
