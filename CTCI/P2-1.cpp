//Remove duplicates from an unsorted linked list

#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;

class Node
{
	public:
	  Node(){next = NULL;}
		Node(int val) {value = val; next = NULL;}
		int getValue(){return value;}
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
  		void removeDups();
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

//Main solution to the above problem
void List::removeDups()
{
	Node* node = getRoot();
	while(node != NULL) 
		{
		  Node* tmp = node->getNext();
			while(tmp != NULL) 
				{ 
        		if (node->getValue() == tmp->getValue()) 
          {
          		Node* tmp2 = tmp;            
				    Delete(tmp2); 
          }
				  tmp = tmp->getNext();
 		  		}
 		  		node = node->getNext();  	
 		}
}

//Solution using a temporary buffer - Hash Table
/****




****/
int main()
{
  List L;
  L.Insert(3);
  L.Insert(4);
  L.Insert(5);
  L.Insert(4);
  L.Insert(9);
  L.Insert(10);
  L.Insert(3);
  L.printList();
  L.removeDups();
  L.printList();
	return 0;
}

