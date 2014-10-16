//Ravi Akella
//Feb 9, 2013
#include <iostream>
#include <string>
using namespace std;

string reverseString(string str, int begin, int end);
string reverseWords(string str);

int main()
{
string str, remove;
cout << "Enter the string:" << endl; 
getline(cin, str);
cout << "Reversed string: " << reverseWords(str) << endl;
return 0;
}

string reverseWords(string str)
{
int start=0, pos=0;
string res = reverseString(str, 0, str.length());
//cout << res << endl;
string result;
for(int i=0; i<=res.length(); i++){
if ((res[i] == L' ') || (res[i] =='\0')) {
result = result+reverseString(res, pos, i+1);
}
else{continue;}
pos=i;
}
return result;
}


string reverseString(string str, int begin, int end){
string result;
char s[str.length()];
strcpy(s, str.c_str());
for(int i=end-1; i >= begin; i--){
result = result+s[i];
}
return result;
}
