#include<stdio.h>
#include<iostream>
using namespace std;

main()
{
      int y;
      
      int input[9]={1,9,20,20,10,30,72,81,90};
      int sum=40;
      int tempArr[10000];
      
      for(int i=0 ; i < sizeof(input)/sizeof(int); i++)
      {
             tempArr[input[i]]= input[i]; 
      }
     
      for(int i=0 ; i < sizeof(input)/sizeof(int); i++)
      {
              int temp = sum - input[i]; 
              if(temp==tempArr[temp])
                   printf("(%d,%d)\n",input[i],temp);              
      }
}
