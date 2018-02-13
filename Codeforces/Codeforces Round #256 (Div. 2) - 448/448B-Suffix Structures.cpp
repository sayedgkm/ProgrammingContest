#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
using namespace std;
int ar[50],br[50];
int main()
{
   string s1,s2;int j=0;
   cin>>s1>>s2;
   for(int i=0;i<s1.length();i++)
   {
       if(s2[j]==s1[i])
       {
           j++;
       }


   }
   //cout<<j<<endl;
if(j==s2.length())
    cout<<"automaton"<<endl;
else{

    int check=1;
    for(int i=0;i<s1.length();i++)
        ar[s1[i]-96]++;
     for(int i=0;i<s2.length();i++)
        br[s2[i]-96]++;
    for(int i=0;i<=30;i++)
    {
        if(br[i]>ar[i])
        {
            check=0;break;
        }

    }
    if(check==0) cout<<"need tree"<<endl;
    else
    {
        if(s1.length()==s2.length())
            cout<<"array"<<endl;
        else
            cout<<"both"<<endl;

    }
}
return 0;
}