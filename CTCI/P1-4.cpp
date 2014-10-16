//Remove duplicate chartacters in a string without using additional buffer

#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;

string removeDupsNO(string& input);
string removeDups1(string& input);
string removeDups2(string& input);

int main()
{
	string NString;
	cout << "Enter string: ";
	getline(cin, NString);	
	cout << "String without dups: " << removeDups2(NString) << endl;
	return 0;
}


//!!This is just an attempt- not even a solution!!
//Highly undesirable though O(lgn) since it returns unique
//characters NOT in the same order as original string
string removeDupsNO(string& input)
{
	sort(input.begin(), input.end());
	cout << input <<endl;
	for(int i=0; i<input.length()-1; i++)
	{
		if(input[i] == input[i+1]){
     string l = input.substr(0, i+1);
     string r = input.substr(i+2, input.length()-i);   
     cout << "l: " << l << " r: " << r << endl;  
		 input =  l + r;
		 }
	}
	return input;
}

//Using additional space of constant size
string removeDups1(string& input)
{
	bool check[256] = {false};
	int len = input.length();
	if(len < 2) return input;
	int next = 1;
	//To ignore the case, set both upper & lower case equivalents
	check[tolower(input[0])] = true;
	check[toupper(input[0])] = true;
	//detect and replace dups
	for(int i=1; i < len; ++i)
	{
		if(!check[input[i]])
		{
			input[next] = input[i];
			++next;
			//To ignore the case, set both upper & lower case equivalents
			check[tolower(input[i])] = true; 
			check[toupper(input[i])] = true;
		}
	}
	return input.substr(0, next);
}

// W/O using additional space
//Actual solution that matches problem description
//but it has O(n^2) complexity
string removeDups2(string& input)
{
	int len = input.length();
	if(len < 2) return input;
	int next = 1;
	//detect and replace dups
	for(int i = 1; i<len ; i++)
	{
	  int j;
	 	for(j = 0; j < next; j++)
		{
			if(tolower(input[j]) == tolower(input[i])) break;	
		}

		if(j == next)
		{
		  input[next] = input[i];
			++next;    		 
		}
	}	
	return input.substr(0, next);
}


