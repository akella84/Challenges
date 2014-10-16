//Ravi Akella
//Feb 12, 2013
#include <iostream>
#include <string>
using namespace std;

class Node{
int value;
public:
int setVal(int n){
value = n;
}
int getValue(){
return value;
}
};

class binNode: public Node {
private:
Node *left;
Node *right;

public:
binNode(){
left = NULL;
right = NULL;
};
binNode(Node *left, Node *right, int value){
this->setVal(value);
this->left = left;
this->right = right;
}
Node getLeft(){ return *left;}
Node getRight(){ return *right;}
void setLeft(Node *left){ this->left = left;}
void setRight(Node *right){ this->right = right;}
};

int main()
{
Node A;
A.setVal(2);
cout << A.getValue() << endl;
binNode B(NULL, NULL, 3);
return 0;
}
