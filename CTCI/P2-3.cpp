//delete a node in the middle of a single linked list, given only access to that node 

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
  		void deleteMiddle(Node* node);
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

//The problem setting looks like they ask to delete any given node
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

//Not sure if the problem asks to delete the middle element
//However, this is the solution if they meant so
// If length is even, then it returns the last of the 2 middle elements
void List::deleteMiddle(Node* node)
{
	Node* forward = node;
	int length=0;	
//  while(forward != NULL)
//		{
//			forward = forward->getNext();
//			length++;
//		}
//	forward = node;
//	int middle = length/2; 	

//	while(forward != NULL && middle > 0)
//		{
//			forward = forward->getNext();
//			middle--;
//		}
  Node* mid = node;
  while(forward != NULL)
		{
			forward = forward->getNext();
			if(length%2) mid = mid->getNext();
			length++;
		} 	
	cout << mid->getValue() << endl;	
	Delete(mid);
}


int main()
{
  List L;
  L.Insert(3);
  L.Insert(4);
  L.Insert(5);
  L.Insert(6);
  L.Insert(7);
  L.Insert(8);  
  L.Insert(9);   
  L.Insert(19); 
  //L.Insert(29);   
  L.printList();
  //L.Delete(L.getRoot()->getNext());
  L.deleteMiddle(L.getRoot());
  L.printList();
	return 0;
}

