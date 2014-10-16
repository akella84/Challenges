//Ravi Akella
//Feb 9, 2013

#include <iostream>
#include <string>
using namespace std;


char fnc (string str);
string removeChars(string str, string remove);


int main()
{
string str, remove;
cout << "Enter the string:" << endl; 
//cin >> str;
getline(cin, str);
cout << "Enter the remove string:" << endl; 
cin >> remove;
//cout << "First non-repeated character is: " << fnc(str) << endl; 
cout << "Result: " << removeChars(str, remove) << endl; 
return 0;
}


//PIE 4th ed. Pg. 91
//First non-repeated character in a string

// Dumb Solution of O(n^2)
char fnc( string str )
{
 char c; 
 int i, j;
 for(i=0,j=i+1; i < str.length(), j < str.length(); ){
 if (str[i] != str[j]) { 
 j++;
 cout << "Flag 0 " << str[i] << str[j] << endl;
 if (j == str.length()-1)
  {
     c = str[i]; 
     cout<< "Flag 2" << endl;
     return c;
  }
 }
 else if ((str[i] == str[j])) 
 {i++; cout<< "Flag 1" << endl;}

 //else {cout<< "No non-repeating character found." << endl;} 
 }
}

//PIE 4th ed. Pg. 94
//Remove string from a string
// Dumb Solution of O(n^2)
string removeChars(string str, string remove)
{
char s[str.length()];
char r[remove.length()];
int j=0;
strcpy(s, str.c_str());
strcpy(r, remove.c_str());
bool flagger[128];
for(int i=0; i<r.length(); ++i){
flagger[r[i]] = true;
}

for(int i=0; i < s.length(); i++){
if(!flagger[s[i]]) s[j++] = s[i];
}

return s.substr(0,j);

//cout<< "Marker.. " << marker[remove[j]]<<endl;



//Maintain a marker to flag the elements to be removed
//But this is O(n^2) solution
//string result = str;
//int j=0;
//bool marker[str.length()];
//for(int i=0; i < str.length(); i++){
//marker[i] =false;
//}

//for(int i=0; i < str.length(); i++){
//for(int j=0; j < remove.length(); j++){
//if(str[i] == remove[j]) marker[i]=true;
//}
//}

//for(int i=0; i < str.length(); i++){
//if(!marker[i]) {result[j] = str[i]; j++;}
//}
//return result.substr(0, j);
}
