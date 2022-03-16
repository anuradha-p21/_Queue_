#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

void fibseries(int n)
{
    int t1 = 0, t2 =1 , nextterm;
    for(int i = 1; i<=10 ;i++)
    {
     if(i ==1){
     cout << t1 << " ";
     continue;
     }
     if(i ==2){ 
     cout<< t2 << " ";
     continue;
     }
     nextterm = t1+t2;
     t1 = t2;
     t2 = nextterm;
     cout << i << ": " << nextterm << " ";
    }
}
int main()
{
    int n = 10;
    fibseries(10);
}