#include "DuLNode.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	List *list1 = new List();
	list1->push_back(1);
//	list1->display();
	list1->push_front(2);
//	list1->display();
	list1->push_front(3);
	list1->display();

//	DuLNode* s1 = list1->getNodeFront(2);
//	cout<< s1->data << endl;
//	DuLNode* s2 = list1->getNodeFront(3);
//	cout<< s2->data << endl;
//	DuLNode* s3 = list1->getNodeFront(4);
//	cout<< s3->data << endl;

	DuLNode* s4 = list1->getNodeBack(1);
	cout<< s4->data << endl;
	DuLNode* s5 = list1->getNodeBack(2);
	cout<< s5->data << endl;
//	DuLNode* s6 = list1->getNodeBack(4);
//	cout<< s6->data << endl;

	cout<<endl;

	list1->insert(s4,5);
	list1->display();

	list1->erase(s5);
	list1->display();

	list1->erase(s4);
	list1->display();

//	list1->pop_back();//1
//	list1->display();
//	list1->pop_back();//2
//	list1->display();
//	list1->pop_back();//3
//	list1->display();
//	list1->pop_back();//fail
//	list1->display();
	
	delete list1;
}
