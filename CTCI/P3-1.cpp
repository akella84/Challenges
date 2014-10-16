// use a single array to implement three stacks 

#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;


class Node
{
	public:
	  Node(){next = this;}
		Node(int val) 
		{
			value = val; next = this;
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
  		Node* findLoop(Node* node);
  		void setRoot(Node* node) {root = node;}
  		Node* getRoot() {return root;}
  		
	private:
  		Node* root;
};

void List::printList()
{
  Node* node = getRoot()->getNext();
  cout << getRoot()->getValue();
	while(node != getRoot()) 
	{
		cout << " -> " << node->getValue();
		node = node->getNext();
  }
  cout << " -> " << node->getValue() << endl;
}

void List::Insert(int val)
{
  Node* node1 = new Node(val);
  Node* node = getRoot();
  if (node == NULL) {setRoot(node1);}
  else
  {  		
		while(node->getNext() != getRoot()) 
			{
				node = node->getNext();
 		  }
  		node->setNext(node1);
  		node1->setNext(getRoot());
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

// Main solution function for this problem 
Node* List::findLoop(Node* node)
{
  Node* speed1 = node; 
  Node* speed2 = node; 		
  int k=0;
  while(speed2->getNext() != NULL)
  {
  	  speed1 = speed1->getNext();
    speed2 = (speed2->getNext())->getNext();
    cout << "speed1: " << speed1->getValue() << " speed2: " << speed2->getValue()  << endl;
    if(speed2 == speed1) break;
    k++;
  }
  cout << "# Steps: " << k << endl;

  if(speed2->getNext() == NULL) return NULL;

  speed1 = node;
  while(speed1 != speed2)
  {
		speed1 = speed1->getNext();
		speed2 = speed2->getNext();
		cout << "speed1: " << speed1->getValue() << " speed2: " << speed2->getValue()  << endl;
  }  
	return speed2;
}

//Driver to corrupt the nth link
void CorruptN(Node* head, int n)
{
  Node* loopNode = head;
  while((loopNode != NULL) && (n > 1))
  {
		loopNode = loopNode->getNext();
  		n--;
  }
  // Corrupt Node points to the root's next`s next, node
  // This can be changed to generalize
  loopNode->setNext(head->getNext()->getNext()->getNext());
  cout << "Successfully corrupted node " << loopNode->getValue() << endl;
}

int main()
{
  List L1;
  L1.Insert(3);
  L1.Insert(1);
  L1.Insert(5);  
  L1.Insert(4);
  L1.Insert(7);
  L1.Insert(8);
  L1.Insert(9);
  L1.Insert(10);
  
  L1.printList();

  CorruptN(L1.getRoot(), 6);

  //L1.printList();
  Node* loopNode = L1.findLoop(L1.getRoot());
  if(loopNode == L1.getRoot()) 
  		cout << "No Loop" << endl; 
  else 	
  		cout << "Loop at: " << loopNode->getValue() << endl;
	return 0;
}

