//to determine if a string has all unique characters
//2:55PM - 3:05PM

#include<iostream>
#include<string>
using namespace std;

bool isUnique(string input);
bool isUnique2(string input);

int main()
{
	string NString;
	cout << "Enter String: ";
	cin >> NString;
	if(isUnique2(NString)) cout << "Unique" << endl;
	else cout << "NOT unique" << endl;
	return 0;
}

//Time:O(n), Space:O(n)
bool isUnique(string input)
{
	bool check[256];
  bool unique = true;
  if(input.length() > 256) return false;
	for(int i=0; i<input.length(); i++)
	{
		if(!check[input.at(i)])
			check[input.at(i)] = true;
		else 
		{
			unique = false; 
			break;
		}
	}
	return (unique ? true: false);
}

//Without additional space
//Use bitwise operators
bool isUnique2(string input)
{
  int check = 0;
	for(int i=0; i < input.length(); i++)
	{
	  int val = input.at(i) - '0';
	  cout << input.at(i) <<endl;
    if(check & (1 << val)) return false;
    check = check | (1 << val);    
	}
	return true;
}


