#include <algorithm>
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
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
using namespace std;
ll n,l,ar[1005],maxi;
int main()
{
cin>>n>>l;
f(i,0,n) cin>>ar[i];
sort(ar,ar+n);
f(i,1,n)
  maxi=max(maxi,ar[i]-ar[i-1]);
  printf("%.12lf\n",max((double)maxi/2.0,max((double)l-ar[n-1],(double)ar[0]-0)));

return 0;
}