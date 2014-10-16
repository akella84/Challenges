//Generate nth Fibonacci
#include<iostream>
using namespace std;

int fib(int n);

int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
	  std::cerr << "Usage: " << argv[0] << " Value" << std::endl;
    return 1;
  }
  int n = atoi(argv[1]);
	cout << "The fibonacci number (" << n << "): " << fib(n) << endl;
	return 0;
}

int fib(int n)
{
		if ( n == 0) return 0;
		else if (n == 1) return 1;
		else if (n > 1) return fib(n-1)+fib(n-2);
		else return -1;   
}
