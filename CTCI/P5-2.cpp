//Bin2Decimal
#include<iostream>
#include<bitset>
#include<string>
#include <sstream> 
using namespace std;

string Dec2Bin(int Dec);

string DecToBin(int number);

int main()
{
string NString;
cout << "Enter the decimal representation(int): " << endl;
cin >> NString;
cout << "The Equivalent binary representation: " << DecToBin(atoi(NString.c_str())) << endl;
return 0;
}

string DecToBin(int number)
{
    stringstream result;
    if ( number == 0 ) result << 0;
    else if ( number == 1 ) result << 1;

    else if ( number % 2 == 0 )
        result << DecToBin(number / 2) << 0;
    else
        result << DecToBin(number / 2) << 1;
        
    return (result.str());     
}
