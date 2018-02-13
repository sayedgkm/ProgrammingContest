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
int ar[100005],counter=1;
int main()
{
  int n,from,to,s;
  cin>>n>>from>>to;
  f(i,1,n+1)
      cin>>ar[i];
      s=from;
if(from==to) {cout<<"0";return 0;}
  int j=0,check=0;
  while(1)
  {

         from=ar[from];
         j++;
       if(from==to){check=1;break;}
       if(from==s) break;

  }

  if(check)cout<<j;
     else puts("-1");
return 0;
}