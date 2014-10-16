//Ravi Akella
//Feb 9, 2013
#include <iostream>
#include <string>
using namespace std;
//string to int and vice-versa

int toInt(string str);
string toString(int number);

int main()
{
string str;
int num;
cout << "Enter the string:" << endl; 
getline(cin, str);
cout << "Int:  " << toInt(str) << endl;

cout << "Enter the signed integer:" << endl; 
cin>> num;
cout << "String: " << toString(num) << endl;
return 0;
}

int toInt(string str)
{
int num=0;
bool flag;
if (str[0] == '-') {flag = true;}
for(int i=1; i<str.length(); i++){
num = str.data();
//num += str[i]*10^(str.length()-i);
cout << num <<" ";
}
return num;
}


string toString(int number)
{
string numstr;

return numstr;
}
