//Method to set bits from i to j in N equal to M
#include<iostream>
#include<bitset>
#include<string>
using namespace std;

string setBits(string NString, string MString, int i, int j);

int main()
{
string NString, MString;
int i, j;
cout << "Enter N: " << endl;
cin >> NString;
cout << "Enter M: " << endl;
cin >> MString; 
cout << "Enter i: " << endl;
cin >> i; 
cout << "Enter j: " << endl;
cin >> j; 
cout << "Updated bits in N to: " << setBits(NString, MString, i, j) << endl;
return 0;
}

string setBits(string NString, string MString, int i, int j)
{
 bitset<32> M(MString);
 bitset<32> N(NString);
 string result;
 if((M.size() > N.size()) || ((j-i+1) > M.size())) return NULL;
 else
 {
  //set bits from i to j in N to 0 
  for(int k=i; k<=j; k++)
  {
   N.reset(k); 
  } 

  //left shift M by i positions
  M <<= i;

  //set bits from j+1 to 32 to 0
  for(int k=j+1; k<32; k++)
  {
   M.reset(k); 
  } 

  //OR N and M and assign result to N
  N |= M;
  
  result = N.to_string();
  return (result);
 }
}
