//reverse a C-Style String

#include<iostream>
#include<string>
using namespace std;

void reverseCstring1(char* input);
void reverseCstring2(char* str);

int main()
{
  char str[] = "An Example";
	char *cstr;
	cstr = str;
	cout << "Given C-String: "<< cstr << endl;
	reverseCstring2(cstr);
	cout << "Reversed C-String: "<< cstr << endl;
	return 0;
}

//Using string class features
void reverseCstring1(char* input)
{
  string s(input);
  string r(s.rbegin(), s.rend());
  strcpy(input, r.c_str());
}

//The long way
void reverseCstring2(char* str)
{
  char *end = str;
  char tmp;
  while(*end)
  {
		++end;
  }
  --end;
  while (str < end)
  {
  		tmp = *str;
  		*str++ = *end;
  		*end-- = tmp;
  }
}






