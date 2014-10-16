//delete a node in the middle of a single linked list, given only access to that node 

#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;


class Node
{
	public:
	  Node(){next = NULL;}
		Node(int val) 
		{
			if(val>=10){cout<<"Object cannot be created" << endl;} 
			else{value = val; next = NULL;}
		}
		int getValue(){return value;}
		void setValue(int val){value=val;}
		void setNext(Node* node) {next = node;}
		Node* getNext(){ return next;}

	private:
		int value;
		Node* next;
};

class List:public Node
{
  public:
    List(){root = NULL;}
  		void printList();
  		void Insert(int val);
  		void Delete(Node* node);
  		void setRoot(Node* node) {root = node;}
  		Node* getRoot() {return root;}
  		
	private:
  		Node* root;
};

void List::printList()
{
  Node* node = getRoot();
	while(node != NULL) 
	{
		cout << node->getValue() << " -> ";
		node = node->getNext();
  }
  cout << "NULL" << endl;
}

void List::Insert(int val)
{
  Node* node1 = new Node(val);
  Node* node = getRoot();
  if (node == NULL) {setRoot(node1);}
  else
  {  		
		while(node->getNext() != NULL) 
			{
				node = node->getNext();
 		  }
  		node->setNext(node1);
  }
}

void List::Delete(Node* node)
{
  if (node == NULL) {cout << "Delete Failed" << endl;}
  else if (node == getRoot()) {setRoot(getRoot()->getNext()); delete node;}
  else
  {  		
    Node* tmp = getRoot();
		while(tmp->getNext() != node) 
			{
				tmp = tmp->getNext();
 		  }
  		tmp->setNext(node->getNext());
  		delete node;
  }
}

Node* Sum(Node* n1, Node* n2)
{
  int carry = 0;
	while((n1 != NULL) && (n2 != NULL))
	{
		int sum = n1->getValue() + n2->getValue() + carry;
		carry = 0;
    if(sum >= 10)
    {
			carry = sum/10;
			sum = sum%10;
		}
		n2->setValue(sum);	
		n1 = n1->getNext();
		n2 = n2->getNext();

	  if((carry != 0) && (n2->getNext() == NULL)) 
	  {
			Node* nc = new Node(carry);
			n2->setNext(nc);
    }
	}
	//Need to fix this case
	if((n1 != NULL) || (n2 != NULL) ) 
	{
		cout << "Both lists should be of same length: NEED TO FIX THIS" << endl;
		//return NULL;
	}
	return n2;
}

int main()
{
  List L1;
  List L2;
  L1.Insert(3);
  L1.Insert(1);
  L1.Insert(5);
  L2.Insert(5);
  L2.Insert(9);
  L2.Insert(6);  
  L1.printList();
  L2.printList();
  Sum(L1.getRoot(), L2.getRoot());
  L2.printList();
	return 0;
}

