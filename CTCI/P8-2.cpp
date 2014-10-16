/*Imagine a robot sitting on the upper left hand corner of an NxN grid  
The robot can only move in two directions: right and down.
How many possible paths are there for the robot?*/ 

#include <iostream>
#include <iomanip> 
#include <vector>
using namespace std;

union Point
{
	int x;
	int y;
};

int RoboPathCount(int x, int y);
vector<Point> RoboPathTrack(Point p);
int factorial(int n);


int main(int argc, char *argv[])
{
	if (argc < 3) 
	{
	  std::cerr << "Usage: " << argv[0] << "  X(>0)" << setw(5) << "Y(>0)" << std::endl;
    return 1;
  }
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
	cout << "# paths: " << RoboPathCount(x,y) << endl;
	cout << "**** Possible Paths ****" << endl;
	Point p;
	p.x = x;
	p.y = y;
	vector<Point> v = RoboPathTrack(p);
	for(vector<Point>::iterator it = v.begin(); it != v.end(); ++it)
			cout << "(" << it->x << "," << it->y << ")->"  << endl;
	return 0;
}

int RoboPathCount(int x, int y)
{
    	//Assuming a path starts at 1,1 and ends at x,y
		if (x == 1 && y == 1) return 0;
		//Every step right, we change the column; Do this till we hit a max of y-1
		//Every step down, we change row; Do this till we hit max of x-1
		//This makes total steps x-1+y-1 in each path
		//#total steps in all possible paths is (x-1+y-1)!
		//Pick x-1 moves to obtain a path
		//Therfore, answer is c(x-1+y-1, x-1)
		else if (x*y > 1) return factorial(x-1+y-1)/(factorial(x-1)*factorial(y-1)); 
		else return -1;   
}

vector<Point> RoboPathTrack(Point p)
{
vector<Point> v;
for(int i=0; i<)
v.push_back(p);
return v;
}

int factorial(int n)
{
if(n==0 || n==1) return 1;
else return n*factorial(n-1);
}
