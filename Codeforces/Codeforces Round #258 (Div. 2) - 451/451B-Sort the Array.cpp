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
#include <algorithm>
#include <vector>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define ll long long
using namespace std;
ll ar[100005];ll n,temp,counter,up,low;
int main()
{
    f(i,1,100004) ar[i]=1e15;
    cin>>n;
    f(i,1,n+1)
    cin>>ar[i];
  f(i,2,n+1)
  {
      if(ar[i]<ar[i-1]){
            low=i-1;counter++;
            while(ar[i]<=ar[i-1]) i++;
            up=i-1; break;
       }

  }
if(counter==0)
{
     cout<<"yes"<<endl<<"1"<<" "<<"1"<<endl;
     return 0;
}
sort(ar+low,ar+up+1);
 f(i,2,n+1)
 if(ar[i]<ar[i-1])
 {
     puts("no");
     return 0;
 }
 cout<<"yes"<<endl<<low<<" "<<up<<endl;
//f(i,1,5) cout<<ar[i]<<" ";
//cout<<endl<<low<<" "<<up;
return 0;
}